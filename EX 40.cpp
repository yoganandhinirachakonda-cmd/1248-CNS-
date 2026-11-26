#include <stdio.h>
#include <string.h>

int main() {
    char c[500], p[500];
    char freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0}, used[26] = {0};
    int i, j, top, temp;

    printf("Enter ciphertext: ");
    fgets(c, sizeof(c), stdin);

    printf("Enter top candidates: ");
    scanf("%d", &top);

    if(top < 1) return 0;

    for(i = 0; c[i]; i++)
        if(c[i] >= 'A' && c[i] <= 'Z')
            count[c[i]-'A']++;

    for(i = 0; i < 26; i++)
        for(j = i+1; j < 26; j++)
            if(count[i] < count[j]) {
                temp = count[i];
                count[i] = count[j];
                count[j] = temp;

                char t = freq[i];
                freq[i] = freq[j];
                freq[j] = t;
            }

    for(i = 0; c[i]; i++) {
        if(c[i] >= 'A' && c[i] <= 'Z') {
            int x = c[i]-'A';
            p[i] = freq[x];
        }
        else
            p[i] = c[i];
    }
    p[i] = '\0';

    printf("\nPossible Plaintext:\n");
    printf("1. %s\n", p);
    printf("Requested top %d candidates.\n", top);

    return 0;
}
