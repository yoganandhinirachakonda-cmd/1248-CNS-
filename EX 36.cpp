#include <stdio.h>
#include <string.h>

int main() {
    char p[100], c[100], d[100];
    int a, b, i, inv = -1;

    printf("Enter plaintext: ");
    scanf("%s", p);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    // Find modular inverse of a
    for(i = 1; i < 26; i++)
        if((a * i) % 26 == 1) {
            inv = i;
            break;
        }

    if(inv == -1) {
        printf("Invalid key! Choose a coprime with 26.\n");
        return 0;
    }

    // Encryption
    for(i = 0; p[i]; i++)
        c[i] = ((a * (p[i]-'A') + b) % 26) + 'A';
    c[i] = '\0';

    // Decryption
    for(i = 0; c[i]; i++)
        d[i] = ((inv * (c[i]-'A'-b+26)) % 26) + 'A';
    d[i] = '\0';

    printf("Encrypted: %s\n", c);
    printf("Decrypted: %s\n", d);

    return 0;
}
