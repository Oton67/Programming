#include <stdio.h>
#include <stdlib.h>

int main()
{
    int niz[1000] = {1,3,5,6,3};
    int N, i, j;
    int ubac_num;
    int pos, broj;
    int tmp = 0;


    scanf("%i", &N);
    for(i = 0; i < N; i++) scanf("%i",&niz[i]);

    scanf("%i", &ubac_num);



    for(i = 0; i < ubac_num; i++)
    {
        scanf("%i",&broj);
        scanf("%i",&pos);

        for(j = N; j >= pos; j--) niz[j] = niz[j-1];
        N+=1;


        niz[pos-1] = broj;


        for(j = 0; j < N; j++) printf("%i ", niz[j]);
        printf("\n");
    }




    return 0;

}
