#include <stdio.h>
#include <stdlib.h>

int main()
{

    int dan, mjesec, godina,suma;

    /*
    dan = 10;
    mjesec = 3;
    godina = 1966;
    */

    scanf("%i",&dan);
    if(dan == 0) return 0;
    else scanf(" %i %i",&mjesec,&godina);


    if(mjesec == 0) return 0;
    while(dan != 0)
    {


    suma = dan;
    if(mjesec == 1) suma = suma + 6;
    if(mjesec == 2) suma = suma + 2;
    if(mjesec == 3) suma = suma + 2;
    if(mjesec == 4) suma = suma + 5;
    if(mjesec == 5) suma = suma + 0;
    if(mjesec == 6) suma = suma + 3;
    if(mjesec == 7) suma = suma + 5;
    if(mjesec == 8) suma = suma + 1;
    if(mjesec == 9) suma = suma + 4;
    if(mjesec == 10) suma = suma + 6;
    if(mjesec == 11) suma = suma + 2;
    if(mjesec == 12) suma = suma + 4;


    if(godina / 10 == 190) suma = suma + 1;
    if(godina / 10 == 191) suma = suma + 6;
    if(godina / 10 == 192) suma = suma + 5;
    if(godina / 10 == 193) suma = suma + 3;
    if(godina / 10 == 194) suma = suma + 2;
    if(godina / 10 == 195) suma = suma + 0;
    if(godina / 10 == 196) suma = suma + 6;
    if(godina / 10 == 197) suma = suma + 4;
    if(godina / 10 == 198) suma = suma + 3;
    if(godina / 10 == 199) suma = suma + 1;
    if(godina / 10 == 200) suma = suma + 0;
    if(godina / 10 == 201) suma = suma + 5;


    suma = suma + (godina%10);
    //printf("%i \n",suma);
    if( (godina%100)/10 % 2 == 0 )
    {
        if( godina % 10 == 0 ) suma = suma + 0;
        if( godina % 10 == 1 ) suma = suma + 0;
        if( godina % 10 == 2 ) suma = suma + 0;
        if( godina % 10 == 3 ) suma = suma + 0;
        if( godina % 10 == 4 ) suma = suma + 1;
        if( godina % 10 == 5 ) suma = suma + 1;
        if( godina % 10 == 6 ) suma = suma + 1;
        if( godina % 10 == 7 ) suma = suma + 1;
        if( godina % 10 == 8 ) suma = suma + 2;
        if( godina % 10 == 9 ) suma = suma + 2;
    }

    else
    {
        if( godina % 10 == 0 ) suma = suma + 0;
        if( godina % 10 == 1 ) suma = suma + 0;
        if( godina % 10 == 2 ) suma = suma + 1;
        if( godina % 10 == 3 ) suma = suma + 1;
        if( godina % 10 == 4 ) suma = suma + 1;
        if( godina % 10 == 5 ) suma = suma + 1;
        if( godina % 10 == 6 ) suma = suma + 2;
        if( godina % 10 == 7 ) suma = suma + 2;
        if( godina % 10 == 8 ) suma = suma + 2
            ;
        if( godina % 10 == 9 ) suma = suma + 2;
    }
     //printf("%i \n",suma);

    suma = suma % 7;

    if(mjesec == 1 || mjesec == 2) if( godina % 4 == 0 )
    {
        suma-=1;
    }


    if(suma == 1) printf("Ponedjeljak\n");
    if(suma == 2) printf("Utorak\n");
    if(suma == 3) printf("Srijeda\n");
    if(suma == 4) printf("Cetvrtak\n");
    if(suma == 5) printf("Petak\n");
    if(suma == 6) printf("Subota\n");
    if(suma == 0) printf("Nedjelja\n");

    scanf("%i", &dan);
    if(dan == 0) return 0;
    else if(dan != 0)
    {
        scanf(" %i %i",&mjesec,&godina);
        if(mjesec == 0 ) return 0;
    }
    }
    return 0;
}
