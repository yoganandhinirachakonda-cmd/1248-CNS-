#include <stdio.h>
#include <string.h>

int main() {
    char p[100], c[100], d[100];
    int k[100], i, n;

    printf("Enter plaintext: ");
    scanf("%s", p);

    n = strlen(p);

    printf("Enter key values (0-25):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &k[i]);

    // Encryption
    for(i = 0; i < n; i++)
        c[i] = ((p[i]-'A' + k[i]) % 26) + 'A';
    c[i] = '\0';

    // Decryption
    for(i = 0; i < n; i++)
        d[i] = ((c[i]-'A' - k[i] + 26) % 26) + 'A';
    d[i] = '\0';

    printf("Encrypted text: %s\n", c);
    printf("Decrypted text: %s\n", d);

    return 0;
}
