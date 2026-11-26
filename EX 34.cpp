#include <stdio.h>
#include <openssl/des.h>

int main() {
    DES_cblock key = {1,2,3,4,5,6,7,8};
    DES_cblock iv = {0,0,0,0,0,0,0,0};
    DES_key_schedule ks;
    unsigned char p[8], c[8], d[8];

    printf("Enter 8 characters: ");
    scanf("%8s", p);

    DES_set_key_unchecked(&key, &ks);

    // ECB Mode
    DES_ecb_encrypt((DES_cblock*)p, (DES_cblock*)c, &ks, DES_ENCRYPT);
    printf("\nECB: ");
    for(int i=0;i<8;i++) printf("%02X",c[i]);

    // CBC Mode
    DES_ncbc_encrypt(p,c,8,&ks,&iv,DES_ENCRYPT);
    printf("\nCBC: ");
    for(int i=0;i<8;i++) printf("%02X",c[i]);

    // CFB Mode
    DES_cblock iv2 = {0,0,0,0,0,0,0,0};
    DES_cfb64_encrypt(p,c,8,&ks,&iv2,(int[]){0},DES_ENCRYPT);
    printf("\nCFB: ");
    for(int i=0;i<8;i++) printf("%02X",c[i]);

    return 0;
}
