#include <stdio.h>

int main() {
    int p = 23, q = 11, g = 4;
    int x = 3, h = 7;
    int k1 = 2, k2 = 5;
    int r1, r2, s1, s2;

    // DSA signatures
    r1 = (g * k1) % q;
    s1 = (h + x * r1) % q;

    r2 = (g * k2) % q;
    s2 = (h + x * r2) % q;

    printf("DSA Signature 1: (%d, %d)\n", r1, s1);
    printf("DSA Signature 2: (%d, %d)\n", r2, s2);

    // Simplified deterministic RSA demonstration
    printf("RSA Signature 1: %d\n", h);
    printf("RSA Signature 2: %d\n", h);

    return 0;
}
