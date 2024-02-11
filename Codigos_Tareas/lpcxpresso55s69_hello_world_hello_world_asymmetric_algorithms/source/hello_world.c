/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_power.h"

/* MBEDTLS */
#include "ksdk_mbedtls.h"
#include "mbedtls/platform.h"
#include "mbedtls/platform_util.h"
#include "mbedtls/ecdh.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define Init_cycle_counter()    DWT->CTRL |= DWT_CTRL_EXCTRCENA_Msk
#define Reset_timer() 		    DWT->CYCCNT = 0
#define Enable_cycle_counter()  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk
#define Disable_cycle_counter() DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk
#define Get_cycle_counter()     DWT->CYCCNT

#define BUFSIZE 1024

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static int myrand( void *rng_state, unsigned char *output, size_t len )
{
    size_t use_len;
    int rnd;

    if( rng_state != NULL )
        rng_state  = NULL;

    while( len > 0 )
    {
        use_len = len;
        if( use_len > sizeof(int) )
            use_len = sizeof(int);

        rnd = rand();
        memcpy( output, &rnd, use_len );
        output += use_len;
        len -= use_len;
    }

    return( 0 );
}

/*!
 * @brief Main function
 */
int main(void)
{
//    unsigned char input;
//    mbedtls_mpi z;
    uint32_t u32cycles,i;

//    mbedtls_ecdh_context ecdh;
//    unsigned char buf[BUFSIZE];

    mbedtls_ecdh_context ecdh_srv, ecdh_cli;
    unsigned char buf_srv[BUFSIZE], buf_cli[BUFSIZE];
    const unsigned char * p_srv = buf_srv;

    static const mbedtls_ecp_curve_info curve_info_conf = {MBEDTLS_ECP_DP_SECP256R1,    23,     256,    "secp256r1"};
    const mbedtls_ecp_curve_info *curve_info;
    size_t olen;
    curve_info = &curve_info_conf;

    /* Init board hardware. */
    /* set BOD VBAT level to 1.65V */
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
    /* attach main clock divide to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    CRYPTO_InitHardware();
    PRINTF( "\n\n\r--- Asymmetric Encryption test ---");


    PRINTF( "\n\rECC HW accelerated: ");
#if FSL_FEATURE_SOC_CASPER_COUNT    //See Line 33 from <project>\device\LPC55S69_cm33_core0_features.h
	PRINTF( "TRUE");
#else
	PRINTF( "FALSE");
#endif
    Init_cycle_counter();
	Reset_timer();
	Enable_cycle_counter();

	(void)memset(buf_srv, 0, sizeof(buf_srv));
	(void)memset(buf_cli, 0, sizeof(buf_cli));

    do
    {
    	mbedtls_ecdh_init( &ecdh_srv );
    	mbedtls_ecdh_init( &ecdh_cli );
    	p_srv = buf_srv;
    	Reset_timer();

#define PRINT_BUF 1
#if PRINT_BUF
    	PRINTF("\n\n\r- Server and Client buffers init value - ");
    	PRINTF("\n\rbuffer_server:");
    	for(i=0;i<15;i++)
    		PRINTF(" %x", buf_srv[i]);
    	PRINTF("\n\rbuffer_client:");
    	for(i=0;i<15;i++)
    		PRINTF(" %x", buf_cli[i]);
#endif
    	/*Set the curve type used by the server (MBEDTLS_ECP_DP_SECP256R1)*/
    	mbedtls_ecdh_setup( &ecdh_srv, curve_info->grp_id );
    	/*Generates the parameters for the curve
    	 * -The random number is used as the root of the algorithm
    	 * -The key pair is generated with the parameters
    	 * */
    	mbedtls_ecdh_make_params( &ecdh_srv, &olen, buf_srv, sizeof( buf_srv ), myrand, NULL );

#if PRINT_BUF
    	PRINTF("\n\n\r- Generate Server's Public Key - ");
    	PRINTF("\n\rbuffer_server:");
    	for(i=0;i<15;i++)
    		PRINTF(" %x", buf_srv[i]);
    	PRINTF("\n\rbuffer_client:");
    	for(i=0;i<15;i++)
    		PRINTF(" %x", buf_cli[i]);
#endif
    	/*The client reads the key parameters from the client (it only reads the public key)*/
    	mbedtls_ecdh_read_params( &ecdh_cli, &p_srv, p_srv + olen );
    	/*Generates the client's public key
    	 * -The random number is used as the root of the algorithm
    	 * -The key pair is generated with the parameters
    	 * */
    	mbedtls_ecdh_make_public( &ecdh_cli, &olen, buf_cli, sizeof( buf_cli ), myrand, NULL );

#if PRINT_BUF
    	PRINTF("\n\n\r- Generate Client's Publick Key - ");
    	PRINTF("\n\rbuffer_server:");
    	for(i=0;i<15;i++)
    		PRINTF(" %x", buf_srv[i]);
    	PRINTF("\n\rbuffer_client:");
    	for(i=0;i<15;i++)
    		PRINTF(" %x", buf_cli[i]);
#endif

    	/*Server reads the client's public key*/
    	mbedtls_ecdh_read_public( &ecdh_srv, buf_cli, olen );
    	/*Server and client calculate the secret using the parameters given before and stores it in the buffers*/
    	mbedtls_ecdh_calc_secret( &ecdh_srv, &olen, buf_srv, sizeof( buf_srv ), myrand, NULL );
    	mbedtls_ecdh_calc_secret( &ecdh_cli, &olen, buf_cli, sizeof( buf_cli ), myrand, NULL );

#if PRINT_BUF
    	PRINTF("\n\n\r- Calculate secret common key - ");
    	PRINTF("\n\rbuffer_server:");
    	for(i=0;i<15;i++)
    		PRINTF(" %x", buf_srv[i]);
    	PRINTF("\n\rbuffer_client:");
    	for(i=0;i<15;i++)
    		PRINTF(" %x", buf_cli[i]);
#endif

    	u32cycles = Get_cycle_counter();

    	PRINTF("\n\n\rECDHE-%s: %d cycles\n\n\r", curve_info->name, u32cycles );
    	PRINTF("--------------------------------\n\r");

    	mbedtls_ecdh_free( &ecdh_cli );
    	mbedtls_ecdh_free( &ecdh_srv );

    	GETCHAR();

    }while(1);
}
