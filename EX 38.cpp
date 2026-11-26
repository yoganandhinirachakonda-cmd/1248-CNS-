#include <stdio.h>

int main() {
    int p[2][2], c[2][2], a, b, d, det, inv, k[2][2];

    printf("Enter 4 plaintext values (0-25):\n");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&p[i][j]);

    printf("Enter 4 ciphertext values (0-25):\n");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&c[i][j]);

    a=p[0][0]; b=p[0][1];
    d=p[1][0]; det=(a*p[1][1]-b*d)%26;

    if(det<0) det+=26;

    for(inv=1;inv<26;inv++)
        if((det*inv)%26==1) break;

    if(inv==26) {
        printf("Key cannot be recovered.\n");
        return 0;
    }

    int adj[2][2]={{p[1][1],-p[0][1]},
                   {-p[1][0],p[0][0]}};

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++) {
            int sum=0;
            for(int x=0;x<2;x++)
                sum+=c[i][x]*adj[x][j];
            k[i][j]=(sum*inv)%26;
            if(k[i][j]<0) k[i][j]+=26;
        }

    printf("Recovered Key:\n");
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++)
            printf("%d ",k[i][j]);
        printf("\n");
    }

    return 0;
}
