#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_power.h"

/* MBEDTLS */
#include "mbedtls/des.h"

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

#define KEY_LEN 24 // Tamaño de la clave 3DES (en bytes)
#define BUFSIZE 8  // Tamaño del bloque 3DES (en bytes)
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

    unsigned char buffer_in[BUFSIZE], buffer_out[BUFSIZE], buffer_out2[BUFSIZE];
    unsigned char key[KEY_LEN];
    unsigned char iv[8]; // Vector de inicialización para 3DES
    mbedtls_des3_context des3_ctx;

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

    mbedtls_des3_init(&des3_ctx); // Inicializar el contexto 3DES

    PRINTF("\n\n\r--- Symmetric Encryption  3DES tests ---");

    Init_cycle_counter();
    Reset_timer();
    Enable_cycle_counter();

    do
    {
        // Resto del código permanece sin cambios

        unsigned char iv[8]; // Asegúrate de declarar iv aquí

        // Puedes reemplazar las llamadas a las funciones de AES con funciones de 3DES
        mbedtls_des3_set3key_enc(&des3_ctx, key);

        Reset_timer();
        mbedtls_des3_crypt_cbc(&des3_ctx, MBEDTLS_DES_ENCRYPT, BUFSIZE, iv, buffer_in, buffer_out);
        u32cycles = Get_cycle_counter();

        PRINTF("\n\r3DES_CBC:\n\r Encryption:");
        for (i = 0; i < sizeof(buffer_out); i++)
            PRINTF(" 0x%x", buffer_out[i]);
        PRINTF("\n\r %d cycles", u32cycles);

        mbedtls_des3_set3key_dec(&des3_ctx, key);
        memset(iv, CLEAR_BUFFER_CH, sizeof(iv));
        Reset_timer();
        mbedtls_des3_crypt_cbc(&des3_ctx, MBEDTLS_DES_DECRYPT, BUFSIZE, iv, buffer_out, buffer_out2);
        u32cycles = Get_cycle_counter();
        PRINTF("\n\r Decryption: ");
        for (i = 0; i < sizeof(buffer_out2); i++)
            PRINTF("%c", buffer_out2[i]);
        PRINTF("\n\r %d cycles\n\r", u32cycles);

    } while (1);

    mbedtls_des3_free(&des3_ctx); // Liberar recursos

    return 0;
}
