#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main() {
    DES_cblock key = {1,2,3,4,5,6,7,8};
    DES_key_schedule ks;
    DES_cblock input, encrypted, decrypted;

    printf("Enter 8 characters: ");
    scanf("%8s", input);

    DES_set_key_unchecked(&key, &ks);

    DES_ecb_encrypt(&input, &encrypted, &ks, DES_ENCRYPT);
    DES_ecb_encrypt(&encrypted, &decrypted, &ks, DES_DECRYPT);

    printf("Encrypted: ");
    for(int i=0; i<8; i++)
        printf("%02X", encrypted[i]);

    printf("\nDecrypted: %s\n", decrypted);

    return 0;
}
