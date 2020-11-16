#include <stdio.h>
#include <stdlib.h>

int main()
{
    int B1,B2,n,i,savedB1,savedB2;
    unsigned long connected = 0;
    char znak[100];


    scanf(" %i %i %i ",&B1,&B2,&n);

    scanf("%s", &znak[0]);

    savedB1 = B1;
    savedB2 = B2;

    for(i = 0; i < n; i++)
    {
        B1 = savedB1;
        B2 = savedB2;
        B1 = B1 & 0xFFFFFFAA;
        B2 = B2 & 0xFFFFFF55;

        B1 = B1 | ~(0xFFFFFFFF ^ znak[i]);
        B2 = B2 | ~(0xFFFFFFFF ^ znak[i]);

        connected = B1;
        connected = connected << 16;
        connected = connected | B2;


        printf("%u \n",connected);

    }

    return 0;
}
