#include <stdio.h>
#include <stdlib.h>



double opcijaA(int starost_skije, int kvaliteta, char vrsta_skije)
{

    double vrati;
 if(vrsta_skije == 'O') vrati = 100*(10-starost_skije)*kvaliteta*1.2;
 if(vrsta_skije == 'D') vrati = 100*(10-starost_skije)*kvaliteta*0.5;

 return vrati;
}

double opcijaB(int starost_skije, int kvaliteta, char vrsta_skije)
{
    double vrati;
 if(vrsta_skije == 'O') vrati = 30*(15-starost_skije)*kvaliteta*1.2;
 if(vrsta_skije == 'D') vrati = 30*(15-starost_skije)*kvaliteta*0.5;

 return vrati;
}

double opcijaC(int starost_skije, int kvaliteta, char vrsta_skije)
{
    double vrati;
 if(vrsta_skije == 'O') vrati = 50*kvaliteta*1.2;
 if(vrsta_skije == 'D') vrati = 50*kvaliteta*0.5;

 return vrati;
}




int main()
{
    int i, N;
    int kvaliteta;
    int starost_skije;
    int opcija;
    char vrsta_skija;
    int zbroj = 0;


    scanf("%i", &N);
    while(N <= 0)
    {
        printf("Greska! Netko mora ici na zimovanje.\n");
        scanf("%i", &N);
    }

for(i = 0; i < N; i++)
{
    scanf("%i", &opcija);
    while(opcija <= 0 || opcija >= 4)
    {
        printf("Greska! Ne postoji ta opcija.\n");
        scanf("%i", &opcija);
    }
    scanf("%i %i", &starost_skije, &kvaliteta);
    if(kvaliteta == 'O') kvaliteta = 1, vrsta_skija = 'O';
        else if(kvaliteta == 'D') kvaliteta = 1, vrsta_skija = 'D';
            else scanf(" %c", &vrsta_skija);

    if(opcija == 1) zbroj = zbroj + opcijaA(starost_skije, kvaliteta, vrsta_skija);
    if(opcija == 2) zbroj = zbroj + opcijaB(starost_skije, kvaliteta, vrsta_skija);
    if(opcija == 3) zbroj = zbroj + opcijaC(starost_skije, kvaliteta, vrsta_skija);

}
    printf("Ukupna cijena najma: %i novaca. \n", zbroj);



    return 0;
}
