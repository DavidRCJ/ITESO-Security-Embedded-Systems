#include <stdio.h>
#include "sodium.h"

#define MESSAGE ((const unsigned char *) "Arbitrary data to encrypt")
#define MESSAGE_LEN 25

int main(void)
{
    unsigned char buf[128];
    if (sodium_init() == -1) {
        return 1;
    }

    // Genera una clave aleatoria de 32 bytes
    unsigned char k[crypto_secretstream_xchacha20poly1305_KEYBYTES];
    randombytes_buf(k, sizeof(k));

    // Genera un nonce aleatorio de 24 bytes
    unsigned char n[crypto_secretstream_xchacha20poly1305_NONCEBYTES];
    randombytes_buf(n, sizeof(n));

    printf("Clave generada:\n");
    for (int i = 0; i < sizeof(k); i++) {
        printf("%02x ", (unsigned int)k[i]);
    }
    printf("\n");

    printf("Nonce aleatorio:\n");
    for (int i = 0; i < sizeof(n); i++) {
        printf("%02x ", (unsigned int)n[i]);
    }
    printf("\n");

    // Mensaje original
    printf("Mensaje original: %s\n", MESSAGE);

    // Tamaño del mensaje original
    printf("Longitud del mensaje original: %d\n", MESSAGE_LEN);

    // Espacio para almacenar el mensaje cifrado
    unsigned char c[MESSAGE_LEN + crypto_secretstream_xchacha20poly1305_ABYTES];

    // Cifra el mensaje
    if (crypto_secretstream_xchacha20poly1305_encrypt(c, NULL, MESSAGE, MESSAGE_LEN, n, k) != 0) {
        return 1;
    }

    printf("Mensaje cifrado:\n");
    for (int i = 0; i < sizeof(c); i++) {
        printf("%02x ", (unsigned int)c[i]);
    }
    printf("\n");

    return 0;
}