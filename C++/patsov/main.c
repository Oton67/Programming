#include <stdio.h>
#include <stdlib.h>

void provjera(int n, int m, int limit_min, int limit_max)
{
    while(n < limit_min || m < limit_min || n > limit_max || m > limit_max)
        scanf("%i %i", &n, &m);
}

void tockice(char *matrica, int redak, int stupac)
{
    int i, j;
    for(i = 0; i < redak; i++)
        for(j = 0; j < stupac; j++)
    {
        scanf(" %c", &matrica[i * stupac + j]);  /// jednostruki indeks
    }
}

void ispis(char *matrica, int redak, int stupac)
{
    int i, j;
    for(i = 0; i < redak; i++)
    {
        for(j = 0; j < stupac; j++)
        {
            printf("%c", *(matrica + i * stupac + j)); /// derefernciranje pokazivaca
        }
        printf("\n");
    }
}

int pomak_patsova(char *matrica, int redak, int stupac, int *patsovX, int *patsovY, char *patsov_location, int *smjer)
{
    if(*smjer == 0) /// desno
    {
        matrica[*patsovY * stupac + *patsovX] = '-';


        /// ----- Gornji desni kut ----- ///
        if(*patsovX + 1 == stupac && *patsovY == 0)
        {
            /// Provjera za dolje
            if(matrica[(*patsovY+1)*stupac + *patsovX] == '.' || matrica[(*patsovY+1)*stupac + *patsovX] == 'h')
            {
                *smjer = 1;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovY+=1;

                return 1;
            }
            else /// ne moze nigdje
            {
                matrica[*patsovY * stupac + *patsovX] = '*';
                patsov_location = matrica[*patsovY*stupac + *patsovX];

                return 0;
            }
        }


        /// ----- Donji desni kut ----- ///
        if(*patsovX + 1 == stupac && *patsovY + 1 == redak)
        {
            /// Provjera za gore
            if(matrica[(*patsovY - 1)*stupac + *patsovX] == '.' || matrica[(*patsovY - 1)*stupac + *patsovX] == 'h')
            {
                *smjer = 2;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovY-=1;

                return 1;
            }
            else
            {
                matrica[*patsovY * stupac + *patsovX] = '*';
                patsov_location = matrica[*patsovY*stupac + *patsovX];

                return 0;
            }
        }

        /// ----- Obstacles ----- ///
        if(*patsovX + 1 >= stupac || matrica[*patsovY*stupac + *patsovX + 1] == 'x')
        {
            ///Provjera za dolje
            if(matrica[(*patsovY + 1)*stupac + *patsovX] == '.' || matrica[(*patsovY + 1)*stupac + *patsovX] == 'h')
            {
                if(*patsovY + 1 < redak)
                {
                *smjer = 1;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovY+=1;
                return 1;
                }

            }

            ///Provjera za gore
            if(matrica[(*patsovY - 1)*stupac + *patsovX] == '.' || matrica[(*patsovY - 1)*stupac + *patsovX] == 'h')
            {
                *smjer = 2;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovY-=1;
                return 1;
            }

            /// Ako ne moze nigdje - gotovo
            matrica[*patsovY*stupac + *patsovX] = '*';
            patsov_location = &matrica[*patsovY*stupac + *patsovX];
            return 0;
        }

        /// ----- Collision ----- ///
        if(matrica[*patsovY*stupac + *patsovX + 1] == '|')
        {
            matrica[*patsovY*stupac + *patsovX] = '*';
            patsov_location = &matrica[*patsovY*stupac + *patsovX];
            return 0;
        }

        patsov_location = matrica[*patsovY * stupac + *patsovX];
        *patsovX+=1;
        return 1;
    }











    if(*smjer == 3) /// lijevo
    {
        matrica[*patsovY * stupac + *patsovX] = '-';


        /// ----- Donji lijevi kut ----- ///
        if(*patsovX == 0 && *patsovY + 1 == redak)
        {
            /// Provjera za gore
            if(matrica[(*patsovY-1)*stupac + *patsovX] == '.' || matrica[(*patsovY-1)*stupac + *patsovX] == 'h')
            {
                *smjer = 2;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovY-=1;

                return 1;
            }
            else /// ne moze nigdje
            {
                matrica[*patsovY * stupac + *patsovX] = '*';
                patsov_location = matrica[*patsovY*stupac + *patsovX];

                return 0;
            }
        }

        /// ----- Obstacles ----- ///
        if(*patsovX - 1 < 0 || matrica[*patsovY*stupac + *patsovX - 1] == 'x')
        {
            ///Provjera za dolje
            if(matrica[(*patsovY + 1)*stupac + *patsovX] == '.' || matrica[(*patsovY + 1)*stupac + *patsovX] == 'h')
            {
                *smjer = 1;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovY+=1;
                return 1;
            }

            ///Provjera za gore
            if(matrica[(*patsovY - 1)*stupac + *patsovX] == '.' || matrica[(*patsovY - 1)*stupac + *patsovX] == 'h')
            {
                *smjer = 2;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovY-=1;
                return 1;
            }

            /// Ako ne moze nigdje - gotovo
            matrica[*patsovY*stupac + *patsovX] = '*';
            patsov_location = &matrica[*patsovY*stupac + *patsovX];
            return 0;
        }

        /// ----- Collision ----- ///
        if(matrica[*patsovY*stupac + *patsovX - 1] == '|')
        {
            matrica[*patsovY*stupac + *patsovX] = '*';
            patsov_location = &matrica[*patsovY*stupac + *patsovX];
            return 0;
        }

        patsov_location = matrica[*patsovY * stupac + *patsovX];
        *patsovX-=1;
        return 1;
    }













    if(*smjer == 1) /// Dolje
    {
        matrica[*patsovY * stupac + *patsovX] = '|';

        /// ----- Donji lijevi kut ----- ///
        if(*patsovX == 0 && *patsovY + 1 == redak)
        {
            /// Provjera za desno
            if(matrica[*patsovY*stupac + *patsovX + 1] == '.' || matrica[*patsovY+1*stupac + *patsovX + 1] == 'h')
            {
                *smjer = 0;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovX+=1;

                return 1;
            }
            else /// ne moze nigdje
            {
                matrica[*patsovY * redak + *patsovX] = '*';
                patsov_location = matrica[*patsovY*stupac + *patsovX];

                return 0;
            }
        }


        /// ----- Donji desni kut ----- ///
        if(*patsovX + 1 == stupac && *patsovY + 1 == redak)
        {
            /// Provjera za lijevo
            if(matrica[*patsovY*stupac + *patsovX - 1] == '.' || matrica[*patsovY*stupac + *patsovX - 1] == 'h')
            {
                *smjer = 3;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovX-=1;

                return 1;
            }
            else
            {
                matrica[*patsovY * redak + *patsovX] = '*';
                patsov_location = matrica[*patsovY*stupac + *patsovX];

                return 0;
            }
        }

        /// ----- Obstacles ----- ///
        if(*patsovY + 1 >= redak || matrica[(*patsovY+1)*stupac + *patsovX] == 'x')
        {
            ///Provjera za desno
            if(matrica[*patsovY*stupac + *patsovX + 1] == '.' || matrica[*patsovY*stupac + *patsovX + 1] == 'h')
            {
                *smjer = 0;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovX+=1;
                return 1;
            }

            ///Provjera za lijevo
            if(matrica[*patsovY*stupac + *patsovX - 1] == '.' || matrica[*patsovY*stupac + *patsovX - 1] == 'h')
            {
                *smjer = 3;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovX-=1;
                return 1;
            }

            /// Ako ne moze nigdje - gotovo
            matrica[*patsovY*stupac + *patsovX] = '*';
            patsov_location = &matrica[*patsovY*stupac + *patsovX];
            return 0;
        }

        /// ----- Collision ----- ///
        if(matrica[(*patsovY+1)*stupac + *patsovX] == '-')
        {
            matrica[*patsovY*stupac + *patsovX] = '*';
            patsov_location = &matrica[*patsovY*stupac + *patsovX];
            return 0;
        }

        patsov_location = matrica[*patsovY * redak + *patsovX];
        *patsovY+=1;
        return 1;
    }








    if(*smjer == 2) /// Gore
    {
        matrica[*patsovY * redak + *patsovX] = '|';

        /// ----- Gornji desni kut ----- ///
        if(*patsovX + 1 == stupac && *patsovY == 0)
        {
            /// Provjera za lijevo
            if(matrica[*patsovY*stupac + *patsovX - 1] == '.' || matrica[*patsovY*stupac + *patsovX - 1] == 'h')
            {
                *smjer = 3;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovX-=1;

                return 1;
            }
            else
            {
                matrica[*patsovY * redak + *patsovX] = '*';
                patsov_location = matrica[*patsovY*stupac + *patsovX];

                return 0;
            }
        }

        /// ----- Obstacles ----- ///
        if(*patsovY < 0 || matrica[(*patsovY-1)*stupac + *patsovX] == 'x')
        {
            ///Provjera za desno
            if(matrica[*patsovY*stupac + *patsovX + 1] == '.' || matrica[*patsovY*stupac + *patsovX + 1] == 'h')
            {
                *smjer = 0;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovX+=1;
                return 1;
            }

            ///Provjera za lijevo
            if(matrica[*patsovY*stupac + *patsovX - 1] == '.' || matrica[*patsovY*stupac + *patsovX - 1] == 'h')
            {
                *smjer = 3;
                matrica[*patsovY*stupac + *patsovX] = '+';
                patsov_location = &matrica[*patsovY*stupac + *patsovX];
                *patsovX-=1;
                return 1;
            }

            /// Ako ne moze nigdje - gotovo
            matrica[*patsovY*stupac + *patsovX] = '*';
            patsov_location = &matrica[*patsovY*stupac + *patsovX];
            return 0;
        }

        /// ----- Collision ----- ///
        if(matrica[(*patsovY-1)*stupac + *patsovX] == '-')
        {
            matrica[*patsovY*stupac + *patsovX] = '*';
            patsov_location = &matrica[*patsovY*stupac + *patsovX];
            return 0;
        }

        patsov_location = matrica[*patsovY * redak + *patsovX];
        *patsovY-=1;
        return 1;
    }

}



int main(){

int n, m;
int i, j;
int smj = 0;
char *paL = NULL;
int paX = 0;
int paY = 0;
char *labirint = NULL;



scanf("%i %i", &n, &m);
provjera(n ,m , 1, 50);

labirint = (char *) malloc(n*m*sizeof(char));
tockice(labirint,n,m);

while(pomak_patsova(labirint,n,m,&paX,&paY,paL,&smj));


ispis(labirint,n,m);


return 0;
}
