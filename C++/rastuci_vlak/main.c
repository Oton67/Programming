#include <stdio.h>
#include <stdlib.h>

int main()
{


    /// ----- Varijable ----- ///

    int N,i;
    int vlak[1000] = {2,5,3,2,1};
    int max = 0;
    int novi_vlak[1000];
    int izbac_rast = 0, izbac_pad = 0;


    /// ----- Unos ----- ///
    scanf("%i",&N);
    for(i = 0; i < N; i++) scanf("%i",&vlak[i]);


    /// ----- Provjera za izbacivanje - padajuce ili rastuce ----- ///

    for(i = 0; i < N; i++)
    {
        if(max <= vlak[i]) max = vlak[i];
        else izbac_rast++;
    }


    max = 0;
    for(i = N-1; i >= 0; i--)
    {
        if(max <= vlak[i]) max = vlak[i];
        else izbac_pad++;
    }


    /// ----- Izbacivanje ----- ///


    int brojac = 0;
    int ostaje = 0;
    max = 0;
    if(izbac_rast <= izbac_pad)
    {
        for(i = 0; i < N; i++)
        {
            if(max <= vlak[i])
            {
                max = vlak[i];
                novi_vlak[brojac] = max;
                brojac++;
            }
        }
        ostaje = N - izbac_rast;

        printf("Ostaje %i vagona: ", ostaje);
        for(i = 0; i < brojac; i++) printf("%d ",novi_vlak[i]);
    }


    else
    {
        int max_pos = 0;
        max = 0;
        /// ----- Pronadji max position ----- ///

        for(i = 0 ; i < N; i++)
        {
            if(max < vlak[i]) max = vlak[i], max_pos = i;
        }

        //printf("%i \n",max_pos);
        /// ----- Izbaci ----- ///

        max = 0;
        for(i = N-1; i >= max_pos; i--)
        {
            if(max <= vlak[i])
            {
                max = vlak[i];
                novi_vlak[brojac] = max;
                brojac++;
            }
        }
        ostaje = N - izbac_pad;

        printf("Ostaje %i vagona: ", ostaje);
        for(i = brojac-1; i >= 0; i--) printf("%d ",novi_vlak[i]);
    }


    //printf("Ostaje %i vagona: ", ostaje);
    //for(i = 0; i < brojac; i++) printf("%d ",novi_vlak[i]);

    return 0;
}
