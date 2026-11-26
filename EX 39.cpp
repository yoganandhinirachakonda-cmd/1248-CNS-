#include <stdio.h>
#include <string.h>

int main() {
    char c[500], p[500];
    int count[26] = {0}, key, top;

    printf("Enter ciphertext: ");
    fgets(c, sizeof(c), stdin);

    printf("Enter number of top plaintexts: ");
    scanf("%d", &top);

    if(top < 1 || top > 26) {
        printf("Enter a value between 1 and 26.");
        return 0;
    }

    for(key = 0; key < 26; key++) {
        for(int i = 0; c[i]; i++) {
            if(c[i] >= 'A' && c[i] <= 'Z')
                p[i] = (c[i]-'A'-key+26)%26+'A';
            else if(c[i] >= 'a' && c[i] <= 'z')
                p[i] = (c[i]-'a'-key+26)%26+'a';
            else
                p[i] = c[i];
        }
        p[strlen(c)] = '\0';

        printf("Key %2d: %s", key, p);
    }

    return 0;
}
