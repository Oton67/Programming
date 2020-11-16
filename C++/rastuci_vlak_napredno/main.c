#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, k;
    int vlak[1000] = {9, 2, 3, 2, 9};
    int novi_vlak[1000];
    int izbac, najbolji_izbac;
    int putnici, najbolji_putnici;
    int najbolji_vlak = 0;
    int max = 0;
    int desno_na_lijevo = 0;
    int brojac = 0;
    int broj_vagona = 0;
    int najbolji_broj_vagona = 0;

    scanf("%i", &N);
    for(i = 0; i < N; i++) scanf("%i", &vlak[i]);

    najbolji_izbac = 1000;
    najbolji_putnici = 0;

/// ---- Lijevo na desno -----

    for(i = 0; i < N; i++)
    {
        max = 0;
        izbac = 0;
        putnici = 0;

        broj_vagona = 0;
        for(j = i; j < N; j++)
        {
            if(max <= vlak[j])
            {
                max = vlak[j];
                broj_vagona++;
                putnici = putnici + vlak[j];

            }
            else izbac+=1;

        }

        /// ----- Provjera za najbolje vagone ----- ///
        if(najbolji_izbac > izbac  && broj_vagona > najbolji_broj_vagona)
        {
            najbolji_vlak = i;
            najbolji_izbac = izbac;
            najbolji_putnici = 0;
            najbolji_broj_vagona = broj_vagona;

            max = 0;
            for(k = i; k < N; k++)
            {
                if(max <= vlak[k]) najbolji_putnici = najbolji_putnici + vlak[k], max = vlak[k] ;
            }
        }


        if(najbolji_izbac == izbac) if(putnici > najbolji_putnici)
        {
            najbolji_vlak = i;
            najbolji_putnici = putnici;
        }


    }

    /// ----- Desno na lijevo ----- ///


    for(i = N-1; i >= 0; i--)
    {
        max = 0;
        izbac = 0;
        putnici = 0;

        broj_vagona = 0;
        for(j = i; j >= 0; j--)
        {
            if(max <= vlak[j])
            {
                max = vlak[j];
                broj_vagona++;
                putnici = putnici + vlak[j];

            }
            else izbac+=1;

        }

        /// ----- Provjera za najbolje vagone ----- ///
        if(najbolji_izbac > izbac  && broj_vagona > najbolji_broj_vagona)
        {
            najbolji_vlak = i;
            najbolji_izbac = izbac;
            najbolji_putnici = 0;
            najbolji_broj_vagona = broj_vagona;

            desno_na_lijevo = 1; /// NAJBITNIJE

            max = 0;
            for(k = i; k >= 0; k--)
            {
                if(max <= vlak[k]) najbolji_putnici = najbolji_putnici + vlak[k], max = vlak[k] ;
            }
        }


        if(najbolji_izbac == izbac) if(putnici > najbolji_putnici)
        {
            najbolji_vlak = i;
            najbolji_putnici = putnici;
        }


    }


    /// ----- Novi vlak ----- ///

    if(desno_na_lijevo == 0)
    {
        max = 0;
        brojac = 0;
        for(i = najbolji_vlak; i < N; i++)
        {
            if(max <= vlak[i])
            {
                max = vlak[i];
                novi_vlak[brojac] = max;
                brojac++;
            }
        }
    }

    if(desno_na_lijevo == 1)
    {
        max = 0;
        brojac = 0;

        for(i = najbolji_vlak; i >= 0; i--)
        {
            if(max <= vlak[i])
            {
                max = vlak[i];
                novi_vlak[brojac] = max;
                brojac++;
            }
        }
    }



    /// ----- Ispis ----- ///

    printf("Ostaje %i vagona: ", brojac);

    if(desno_na_lijevo == 0)
    {
        for(i = 0; i < brojac; i++)
        {
            printf("%i ", novi_vlak[i]);
        }
    }

    if(desno_na_lijevo == 1)
    {
        for(i = brojac-1; i >= 0; i--)
        {
            printf("%i ", novi_vlak[i]);
        }
    }




    return 0;
}
