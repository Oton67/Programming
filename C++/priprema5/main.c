#include <stdio.h>
#include <stdlib.h>

int main()
{
    int listic[15][24] = {};
    int broj_popunjavanja;
    int i, j, k, l, br, n;
    int nedjeljno_punjenje[6];
    int stupac = 0;


    //popunjavanja = 1;
    scanf("%i", &broj_popunjavanja);



    /// Unos ///

    int pop[broj_popunjavanja][6];
    int broj_pogodaka[broj_popunjavanja][1];

    for(i = 0; i < broj_popunjavanja; i++) for(j = 0; j < 6; j++) scanf("%i", &pop[i][j]);
    for(i = 0; i < 6; i++) scanf("%i", &nedjeljno_punjenje[i]);


    for(i = 0; i < broj_popunjavanja; i++) broj_pogodaka[i][0] = 0;

    /// Najveca komplikacija u povijesti komplikacija ///
    br = 1;
    for(l = 0; l < broj_popunjavanja; l++)
    {
        for(i = 0; i < 15; i++)
        {
            for(j = stupac; j < stupac + 3; j++)
            {
                listic[i][j] = 0;
                for(n = 0; n < 6; n++) if(br == pop[l][n])
                {
                    listic[i][j] = pop[l][n];
                    for(k = 0; k < 6; k++)
                    {
                        if(nedjeljno_punjenje[k] == pop[l][n]) broj_pogodaka[l][0]++;
                    }
                }
                br++;
            }
        }
        //printf("\n %i \n", br);
        br = br % 46 + 1;
        stupac+=3;

}


    /// Ispis ///

        for(i = 0; i < 15; i++)
        {
            for(j = 0; j < broj_popunjavanja*3; j++)
            {
                //listic[i][j] = (1+j%3) + i * 3;
                printf("%3i ", listic[i][j]);
            }
            printf("\n");
        }

    printf("\n");
    for(k = 0; k < broj_popunjavanja; k++) printf("Broj pogodaka u %i. kombinaciji je: %i \n", k+1, broj_pogodaka[k][0]);



    return 0;
}
