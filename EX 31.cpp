#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t L[16] = {0}, K1[16], K2[16];
    int i, carry;

    printf("Enter 16 bytes of encrypted zero block:\n");
    for(i = 0; i < 16; i++)
        scanf("%hhx", &L[i]);

    // Generate K1
    carry = L[0] >> 7;
    for(i = 0; i < 16; i++)
        K1[i] = (L[i] << 1) | (i < 15 ? L[i+1] >> 7 : 0);

    if(carry) K1[15] ^= 0x87;

    // Generate K2
    carry = K1[0] >> 7;
    for(i = 0; i < 16; i++)
        K2[i] = (K1[i] << 1) | (i < 15 ? K1[i+1] >> 7 : 0);

    if(carry) K2[15] ^= 0x87;

    printf("Subkey K1: ");
    for(i = 0; i < 16; i++) printf("%02X ", K1[i]);

    printf("\nSubkey K2: ");
    for(i = 0; i < 16; i++) printf("%02X ", K2[i]);

    return 0;
}
