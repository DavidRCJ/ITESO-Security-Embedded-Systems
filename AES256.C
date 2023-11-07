#include "sodium.h"
#include <stdio.h>

#define MESSAGE (const unsigned char *) "test"
#define MESSAGE_LEN 4
#define ADDITIONAL_DATA (const unsigned char *) "123456"
#define ADDITIONAL_DATA_LEN 6

unsigned char nonce[crypto_aead_aes256gcm_NPUBBYTES];
unsigned char key[crypto_aead_aes256gcm_KEYBYTES];
unsigned char ciphertext[MESSAGE_LEN + crypto_aead_aes256gcm_ABYTES];
unsigned long long ciphertext_len;

void print_hex(const unsigned char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

int main(void) {
    if (sodium_init() < 0) {
        // Puede que no se pueda inicializar Sodium
        return 1;
    }

    // Definir la clave y el nonce
    randombytes_buf(key, sizeof key);
    randombytes_buf(nonce, sizeof nonce);

    // Mensaje a cifrar
    const char *message = "test";
    const size_t message_len = strlen(message);

    // Cifrar el mensaje
    if (crypto_aead_aes256gcm_encrypt(ciphertext, &ciphertext_len,
                                      (const unsigned char *)message, message_len,
                                      ADDITIONAL_DATA, ADDITIONAL_DATA_LEN, NULL, nonce, key) != 0) {
        printf("Error al cifrar el mensaje.\n");
        return 1;
    }

    // Imprimir el mensaje cifrado en formato hexadecimal
    printf("Mensaje cifrado (hex):\n");
    print_hex(ciphertext, ciphertext_len);

    return 0;
}
