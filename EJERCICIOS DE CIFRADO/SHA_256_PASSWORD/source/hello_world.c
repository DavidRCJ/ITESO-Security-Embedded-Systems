/******************************************************************************************************************************************************************************/
/******************			PASS WORD PARA UN HASH SHA 256			**************************************************/
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_power.h"
#include "mbedtls/platform.h"
#include "mbedtls/platform_util.h"
#include "mbedtls/sha256.h"

// Digest prealmacenado de la contraseña "SHA 256 HASH" LA CONTRASEÑA ES HELLODAVE
const unsigned char correct_password_digest[32] = {
		0xB9,0xBA,0xF6,0x3C,0x97,0xB6,0x86,0x4C,0x8,
		0xAE,0x50,0xD5,0xE6,0xEE,0xD6,0x62,0x66,0x8E,
		0x19,0xBB,0x9C,0x19,0x8F,0xDF,0x21,0x7F,0x26,
		0x9A,0x91,0xC3,0x24,0x83
};

#define BUF_SIZE 128
#define SHA256_SIZE 32

unsigned char sha256sum[SHA256_SIZE];

// Inicialización del contexto de SHA-256
mbedtls_sha256_context sha256_ctx;

void resetPasswordBuffer(char *buffer, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        buffer[i] = '\0';
    }
}

void calculateSHA256(const char *input, size_t size, unsigned char *output)
{
    mbedtls_sha256_starts_ret(&sha256_ctx, 0);
    mbedtls_sha256_update_ret(&sha256_ctx, (const unsigned char *)input, size);
    mbedtls_sha256_finish_ret(&sha256_ctx, output);
}

int compareDigests(const unsigned char *digest1, const unsigned char *digest2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (digest1[i] != digest2[i])
        {
            return 0; // No son iguales
        }
    }
    return 1; // Son iguales
}

int main(void)
{
    char ch;
    char passwordBuffer[BUF_SIZE];
    unsigned char userPasswordDigest[SHA256_SIZE];

    /* Inicialización del hardware y configuraciones iniciales */
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    CRYPTO_InitHardware();

    // Inicialización del contexto SHA-256
    mbedtls_sha256_init(&sha256_ctx);

    while (1)
    {
        resetPasswordBuffer(passwordBuffer, BUF_SIZE);

        PRINTF("Ingrese la contraseña: ");
        uint8_t index = 0;
        while (1)
        {
            ch = GETCHAR();
            if (ch == '\r' || index >= BUF_SIZE - 1)
            {
                break;
            }
            PUTCHAR('*'); // Muestra "*" en lugar del caracter real para mayor seguridad
            passwordBuffer[index++] = ch;
        }

        // Calcula el hash SHA-256 de la contraseña ingresada
        calculateSHA256(passwordBuffer, index, userPasswordDigest);

        // Compara el hash de la contraseña ingresada con el digest prealmacenado
        if (compareDigests(userPasswordDigest, correct_password_digest, SHA256_SIZE))
        {
            PRINTF("\n\rContraseña correcta. Acceso concedido.\r\n");
        }
        else
        {
            PRINTF("\n\rContraseña incorrecta. Acceso denegado.\r\n");
        }
    }
}
