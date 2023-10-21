/*Liga a su repositorio
https://replit.com/@davidricardocru/libsodium-test*/

/*Opcional: copia del código fuente*/
#include <stdio.h>
#include "sodium.h"

#define MESSAGE "Arbitrary data to encrypt"
#define MESSAGE_LEN 26

int main(void)
{
   
  unsigned char buf[128];
  unsigned char nonce[crypto_stream_chacha20_NONCEBYTES];
  unsigned char key[crypto_stream_chacha20_KEYBYTES];
  
    if (sodium_init() == -1) {
        return 1;
    }
    randombytes_buf(buf, sizeof(buf));
    printf("Random data:\n");
    for (int i = 0; i < sizeof(buf); i++)
        printf("%02x ", (unsigned int)buf[i]);
    printf("\n");

   
    randombytes_buf(nonce, sizeof(nonce));
    randombytes_buf(key, sizeof(key));

    printf("Nonce:\n");
    for (int i = 0; i < sizeof(nonce); i++)
        printf("%02x ", (unsigned int)nonce[i]);
    printf("\n");

    printf("Key:\n");
    for (int i = 0; i < sizeof(key); i++)
        printf("%02x ", (unsigned int)key[i]);
    printf("\n");

    unsigned char ciphertext[MESSAGE_LEN];
    crypto_stream_chacha20_xor(ciphertext, (unsigned char *)MESSAGE, MESSAGE_LEN, nonce, key);

    printf("Ciphertext:\n");
    for (int i = 0; i < MESSAGE_LEN; i++)
        printf("%02x ", (unsigned int)ciphertext[i]);
    printf("\n");

    return 0;
}
