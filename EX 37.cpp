#include <stdio.h>
#include <string.h>

int main() {
    char c[500], freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    char plain[500];
    int count[26] = {0}, i, j, top;

    printf("Enter ciphertext: ");
    fgets(c, sizeof(c), stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    for(i = 0; c[i]; i++)
        if(c[i] >= 'A' && c[i] <= 'Z')
            count[c[i]-'A']++;

    for(i = 0; i < 26; i++)
        for(j = i+1; j < 26; j++)
            if(count[i] < count[j]) {
                int t = count[i];
                count[i] = count[j];
                count[j] = t;

                char ch = freq[i];
                freq[i] = freq[j];
                freq[j] = ch;
            }

    printf("\nPossible Plaintext:\n");

    for(i = 0; c[i]; i++) {
        if(c[i] >= 'A' && c[i] <= 'Z')
            plain[i] = freq[c[i]-'A'];
        else
            plain[i] = c[i];
    }
    plain[i] = '\0';

    printf("1. %s\n", plain);

    printf("\nRequested top %d candidates.\n", top);
    printf("Frequency analysis gives one estimated candidate.\n");

    return 0;
}
