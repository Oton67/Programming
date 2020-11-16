#include <stdio.h>
#include <stdlib.h>


void provjeri(int *n, int *m, int lim_min, int lim_max)
{
    while(*n < lim_min || *n > lim_max || *m < lim_min || *m > lim_max)
    {
        scanf("%i %i", n, m);
    }
}

void ispuniLab(char *matrica, int redak, int stupac)
{
    int i,j;
    for(i = 0; i < redak; i++)
    {
        for(j = 0; j < stupac; j++)
        {
            scanf(" %c", &matrica[i * stupac + j]);
        }
    }
}

void printLab(char *matrica, int redak, int stupac)
{
    int i,j;
    for(i = 0; i < redak; i++)
    {
        for(j = 0; j < stupac; j++)
        {
            printf("%c", matrica[i * stupac + j]);
        }

        printf("\n");
    }
}


int provjeraSmjera(char *matrica, int redak, int stupac, int lokacija, int smjer)
{

    int hrana1 = 0, hrana2 = 0;
    int udaljenost1 = 0, udaljenost2 = 0;
    int lo_copy = lokacija;

    /// ---------- Desno ---------- ///
    if(smjer == 0 || smjer == 3)
    {
        /// ----- Dolje ----- ///
        lo_copy = lo_copy + stupac;
        while(lo_copy < redak*stupac)
        {
            lo_copy = lo_copy + stupac;
            if(matrica[lo_copy] == 'h')
            {
                hrana1 = 1;
                break;
            }
            if(matrica[lo_copy] == 'x') break;

            udaljenost1+=1;

        }

        /// ----- Gore ----- ///
        lo_copy = lokacija;
        lo_copy = lo_copy - stupac;
        while(lo_copy > 0)
        {
            lo_copy = lo_copy - stupac;
            if(matrica[lo_copy] == 'h')
            {
                hrana2 = 1;
                break;
            }
            if(matrica[lo_copy] == 'x') break;

            udaljenost2+=1;

        }


        /// ---------- PROVJERE ---------- ///


        //printf("%i %i - %i %i \n", udaljenost1, udaljenost2, hrana1, hrana2);
        if(lokacija - stupac < 0) return 1;
        if(lokacija + stupac >= redak*stupac) return 2;
        if(hrana2 == 0) return 1;
        if(hrana1 == 0 && hrana2 == 1) return 2;
        if(hrana1 == 1 && hrana2 == 1)
        {
            if(udaljenost1 > udaljenost2) return 2;
            else return 1;
        }
    }

    /// ---------- Dolje ---------- ///
    if(smjer == 1 || smjer == 2)
    {
        /// ----- Desno ----- ///
        while((lo_copy + 1) % stupac != 0)
        {
            udaljenost1++;
            if(matrica[lo_copy] == 'h')
            {
                hrana1 = 1;
                break;
            }
            if(matrica[lo_copy] == 'x') break;

            lo_copy = lo_copy + 1;
        }

        /// ----- Lijevo ----- ///
        lo_copy = lokacija;
        while((lo_copy -1) % stupac != 0)
        {
            udaljenost2++;
            if(matrica[lo_copy] == 'h')
            {
                hrana2 = 1;
                break;
            }
            if(matrica[lo_copy] == 'x') break;

            lo_copy = lo_copy - 1;
        }

        /// ---------- PROVJERE ---------- ///
        //printf("%i ", lokacija);
        if(lokacija % stupac == 0) return 0;
        if((lokacija + 1) % stupac == 0) return 3;
        if(hrana2 == 0) return 0;
        if(hrana1 == 0 && hrana2 == 1) return 3;
        if(hrana1 && hrana2)
        {
            if(udaljenost1 > udaljenost2) return 3;
            else return 0;
        }
    }

}

int pomakni(char *matrica, int redak, int stupac, int *lokacija, int *smjer)
{
    /*
    printf("%x \n", &matrica[0]);
    printf("%x", *lokacija);
    printf("\n");
    */

    if(*smjer == 0) /// Desno
    {

        if(matrica[*lokacija] == 'x')
        {
            *lokacija-=1;
            matrica[*lokacija] = '+';
            *smjer = provjeraSmjera(&matrica[0], redak, stupac, *lokacija, *smjer);

            return 1;
        }
        else if(matrica[*lokacija] == '|')
        {
            *lokacija-=1;
            matrica[*lokacija] = '*';
            return 0;
        }
        else if((*lokacija + 1) % stupac == 0)
        {
            matrica[*lokacija] = '+';
            *smjer = provjeraSmjera(&matrica[0], redak, stupac, *lokacija, *smjer);
            return 1;
        }
        else if(matrica[*lokacija] == '+')
        {
            *lokacija = *lokacija + 1;
            return 1;
        }
        else
        {
            matrica[*lokacija] = '-';
            *lokacija = *lokacija + 1;
            return 1;
        }

    }



    if(*smjer == 3) /// Lijevo
    {
        if(matrica[*lokacija] == 'x')
        {
            *lokacija+=1;
            matrica[*lokacija] = '+';
            *smjer = provjeraSmjera(&matrica[0], redak, stupac, *lokacija, *smjer);

            return 1;
        }
        else if(matrica[*lokacija] == '|')
        {
            *lokacija+=1;
            matrica[*lokacija] = '*';
            return 0;
        }
        else if(*lokacija % stupac == 0)
        {
            matrica[*lokacija] = '+';
            *smjer = provjeraSmjera(&matrica[0], redak, stupac, *lokacija, *smjer);
            return 1;
        }
        else if(matrica[*lokacija] == '+')
        {
            *lokacija = *lokacija - 1;
            return 1;
        }
        else
        {
            matrica[*lokacija] = '-';
            *lokacija = *lokacija - 1;
            return 1;
        }

    }





    if(*smjer == 1) /// Dolje
    {

        if(matrica[*lokacija] == 'x')
        {
            *lokacija = *lokacija - stupac;
            matrica[*lokacija] = '+';
            *smjer = provjeraSmjera(&matrica[0], redak, stupac, *lokacija, *smjer);

            return 1;
        }
        else if(matrica[*lokacija] == '-')
        {
            *lokacija = *lokacija - stupac;
            matrica[*lokacija] = '*';
            return 0;
        }
        else if((*lokacija + stupac) >= redak*stupac)
        {
            matrica[*lokacija] = '+';
            *smjer = provjeraSmjera(&matrica[0], redak, stupac, *lokacija, *smjer);
            return 1;
        }
        else if(matrica[*lokacija] == '+')
        {
            *lokacija = *lokacija + stupac;
            matrica[*lokacija] = '|';
            return 1;
        }
        else
        {
            matrica[*lokacija] = '|';
            *lokacija = *lokacija + stupac;
            return 1;
        }

    }

    if(*smjer == 2) /// Gore
    {

        if(matrica[*lokacija] == 'x')
        {
            *lokacija = *lokacija + stupac;
            matrica[*lokacija] = '+';
            *smjer = provjeraSmjera(&matrica[0], redak, stupac, *lokacija, *smjer);

            return 1;
        }
        else if(matrica[*lokacija] == '-')
        {
            *lokacija = *lokacija + stupac;
            matrica[*lokacija] = '*';
            return 0;
        }
        else if((*lokacija - stupac) < 0)
        {
            matrica[*lokacija] = '+';
            *smjer = provjeraSmjera(&matrica[0], redak, stupac, *lokacija, *smjer);
            return 1;
        }
        else if(matrica[*lokacija] == '+')
        {
            *lokacija = *lokacija - stupac;
            return 1;
        }
        else
        {
            matrica[*lokacija] = '|';
            *lokacija = *lokacija - stupac;
            return 1;
        }

    }

}

int main()
{

    int n,m;
    int i;
    int smjer = 0;


    scanf("%i %i", &n, &m);
    provjeri(&n,&m,1,50);

    char *labirint = NULL;
    int patsov_loc = 0;

    labirint = (char *)malloc(n*m*sizeof(char));

    ispuniLab(labirint, n, m);

    while( pomakni(labirint, n, m, &patsov_loc, &smjer) );
    printLab(labirint, n, m);

    return 0;
}
