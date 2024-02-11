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


#include "mbedtls/platform.h"
#include "mbedtls/platform_util.h"
#include "ksdk_mbedtls.h"

#include "mbedtls/md5.h"
#include "mbedtls/sha1.h"


#include "mbedtls/sha256.h"
#include "mbedtls/sha512.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BUF_SIZE	128
#define MD5_SIZE	16
#define SHA1_SIZE	20

#define SHA256_SIZE	32
#define SHA512_SIZE	64

/*DWT - Data Watchpoint and Trace Unit, Cycle count register*/
#define Init_cycle_counter()	DWT->CTRL |= DWT_CTRL_EXCTRCENA_Msk
#define Reset_timer()			DWT->CYCCNT = 0
#define Enable_cycle_counter()	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk
#define Disable_cycle_counter()	DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk
#define Get_cycle_counter()		DWT->CYCCNT
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
    char ch;
    unsigned char buff[BUF_SIZE];
    unsigned char index = 0, i;
    unsigned char md5sum[MD5_SIZE];
    unsigned char sha1sum[SHA1_SIZE];


    unsigned char sha256sum[SHA256_SIZE];
    unsigned char sha512sum[SHA512_SIZE];

    uint32_t u32cycles;

    mbedtls_sha1_context ctx;
    mbedtls_sha256_context sha256_ctx;
    mbedtls_sha512_context sha512_ctx;


    /* Init board hardware. */
    /* set BOD VBAT level to 1.65V */
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
    /* attach main clock divide to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    CRYPTO_InitHardware();
#if !defined(DONT_ENABLE_FLASH_PREFETCH)
    /* enable flash prefetch for better performance */
    SYSCON->FMCCR |= SYSCON_FMCCR_PREFEN_MASK;
#endif

    Init_cycle_counter();
    Reset_timer();
    Enable_cycle_counter();
    PRINTF("My HASHING\r\n");

    mbedtls_sha1_init( &ctx );

    mbedtls_sha256_init( &ctx );
   mbedtls_sha512_init(&sha512_ctx);


    while (1)
    {

    	index = 0;
    	ch = '\0';

    	PRINTF("Input Buffer: ");

    	while(ch != '\r' && index < BUF_SIZE)
    	{
            ch = GETCHAR();
            PUTCHAR(ch);
            buff[index++] = ch;
    	}

    	Reset_timer();
        mbedtls_md5_ret(buff,index - 1, md5sum );
        u32cycles = Get_cycle_counter();

        PRINTF("\n\rMD5: ");
        for(i=0;i<MD5_SIZE;i++)
        {
        	PRINTF(" 0x%X", md5sum[i]);
        }
        PRINTF("\r\nCycles: %d \r\n",u32cycles);
/*****************		SHA-1      *****************************/
        Reset_timer();
        mbedtls_sha1_starts_ret( &ctx );
        mbedtls_sha1_update_ret( &ctx, buff, index - 1 );
        mbedtls_sha1_finish_ret( &ctx, sha1sum );
        mbedtls_sha1_free( &ctx );
        u32cycles = Get_cycle_counter();

        PRINTF("\n\rSHA1: ");
        for(i=0;i<SHA1_SIZE;i++)
        {
        	PRINTF(" 0x%X", sha1sum[i]);
        }
        PRINTF("\r\nCycles: %d \r\n",u32cycles);

/*****************		SHA-256      *****************************/
        Reset_timer();
        mbedtls_sha256_starts_ret(&sha256_ctx, 0);
        mbedtls_sha256_update_ret(&sha256_ctx, buff, index - 1);
        mbedtls_sha256_finish_ret(&sha256_ctx, sha256sum);
        u32cycles = Get_cycle_counter();

        PRINTF("\n\rSHA256: ");
        for (i = 0; i < SHA256_SIZE; i++)
        {
            PRINTF(" 0x%X", sha256sum[i]);
        }
        PRINTF("\r\nCycles: %d \r\n", u32cycles);
        mbedtls_sha256_free(&sha256_ctx);
/*****************		SHA-512      *****************************/
        Reset_timer();
        mbedtls_sha512_starts_ret(&sha512_ctx, 0);
        mbedtls_sha512_update_ret(&sha512_ctx, buff, index - 1);
        mbedtls_sha512_finish_ret(&sha512_ctx, sha512sum);
        u32cycles = Get_cycle_counter();

        PRINTF("\n\rSHA512: ");
        for (i = 0; i < SHA512_SIZE; i++)
        {
            PRINTF(" 0x%X", sha512sum[i]);
        }
        PRINTF("\r\nCycles: %d \r\n", u32cycles);
        mbedtls_sha512_free(&sha512_ctx);

    }
}
