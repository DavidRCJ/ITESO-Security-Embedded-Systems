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
#include "mbedtls/aes.h"

#include "ksdk_mbedtls.h"
#include "mbedtls/timing.h"
#include "mbedtls/platform.h"
#include "mbedtls/platform_util.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define Init_cycle_counter()    DWT->CTRL |= DWT_CTRL_EXCTRCENA_Msk
#define Reset_timer() 		    DWT->CYCCNT = 0
#define Enable_cycle_counter()  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk
#define Disable_cycle_counter() DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk
#define Get_cycle_counter()     DWT->CYCCNT

#define KEY_LEN 32 //(128->16, 192->24, 256->32)
#define BUFSIZE 16 //The AES being a block cipher, encrypts and decrypts the user provided 128-bit block data. BUFSIZE must be %16

#define CLEAR_BUFFER_CH 0 //'0'

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    unsigned char input;

    unsigned char buffer_in[BUFSIZE],buffer_out[BUFSIZE], buffer_out2[BUFSIZE];
    unsigned char key[KEY_LEN];
    unsigned char iv[16];
    unsigned int keysize;
    mbedtls_aes_context aes;

    uint8_t size_input, i;
    uint32_t u32cycles;

    /* Init board hardware. */
    /* set BOD VBAT level to 1.65V */
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
    /* attach main clock divide to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    CRYPTO_InitHardware();

    mbedtls_aes_init( &aes );                  //Initialize AES context

    PRINTF( "\n\n\r--- Symmetric Encryption tests ---");
    PRINTF( "\n\rAES HW accelerated: ");
#if defined(MBEDTLS_FREESCALE_HASHCRYPT_AES)    //See Line 123 from <project>\mbedtls\port\ksdk\ksdk_mbedtls_config.h
	PRINTF( "TRUE");
#else
	PRINTF( "FALSE");
#endif
    Init_cycle_counter();
	Reset_timer();
	Enable_cycle_counter();

    do
    {
    	memset( buffer_in, CLEAR_BUFFER_CH, sizeof( buffer_in ) );
    	memset( key, CLEAR_BUFFER_CH, sizeof( key ) );
    	memset( iv, CLEAR_BUFFER_CH, sizeof( iv ) );
    	memset( buffer_out,  CLEAR_BUFFER_CH, sizeof( buffer_out ) );
    	memset( buffer_out2, CLEAR_BUFFER_CH, sizeof( buffer_out2) );

    	PRINTF( "\n\n\rEnter string to be encrypted: ");
    	input = 0;
    	size_input = 0;

    	while (input != '\r')
    	{
    		input = GETCHAR();  //Get string
    		PUTCHAR(input);
    		if(input != '\r')
    			buffer_in[size_input++] = input;
    	}
    	PRINTF("\r\n");
    	input = 0;
    	size_input = 0;

    	PRINTF( "Enter key: "); //Key will be adjusted (filled with 0s) depending on mode (128->16, 192->24, 256->32)
    	while (input != '\r')   //Get Key
    	{
    		input = GETCHAR();
    		PUTCHAR(input);
    		if(input != '\r')
    			key[size_input++] = input;
    	}
    	PRINTF("\r\n");

/* AES-CBC-128/192/256​ */
    	for( keysize = 128; keysize <= 256; keysize += 64 )
    	{
    		memset( iv, CLEAR_BUFFER_CH, sizeof( iv ) );                                            //Clear buffers and IV
    		memset( buffer_out,  CLEAR_BUFFER_CH, sizeof( buffer_out ) );
    		memset( buffer_out2, CLEAR_BUFFER_CH, sizeof( buffer_out2) );

    		mbedtls_aes_setkey_enc( &aes, key, keysize);                                            //Configure encryption key

    		Reset_timer();
    		mbedtls_aes_crypt_cbc( &aes, MBEDTLS_AES_ENCRYPT, BUFSIZE, iv, buffer_in, buffer_out);  //Encrypt buffer
    		u32cycles = Get_cycle_counter();

    		PRINTF("\n\rAES_CBC-%d:\n\r Encryption:", keysize);                                     //Print encrypted buffer
    		for(i=0;i<sizeof(buffer_out);i++)
    			PRINTF(" 0x%x", buffer_out[i]);
    		PRINTF("\n\r %d cycles",u32cycles);

    		mbedtls_aes_setkey_dec( &aes, key, keysize);                                            //Configure decryption key
    		memset( iv, CLEAR_BUFFER_CH, sizeof( iv ) );
    		Reset_timer();
    		mbedtls_aes_crypt_cbc( &aes, MBEDTLS_AES_DECRYPT, BUFSIZE, iv, buffer_out, buffer_out2);//Decrypt buffer
    		u32cycles = Get_cycle_counter();
    		PRINTF("\n\r Decryption: ");                                                            //Print decrypted buffer
    		for(i=0;i<sizeof(buffer_out2);i++)
    			PRINTF("%c", buffer_out2[i]);
    		PRINTF("\n\r %d cycles\n\r",u32cycles);
    	}
    	mbedtls_aes_free( &aes );

    }while(1);
}


