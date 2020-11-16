#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *ucitajPoruku()
{
    static char niz[100] = {};
    char **vrati;
    scanf("%s", niz);

    vrati = malloc(sizeof(char) * strlen(niz) + 1);
    strcpy(vrati,niz);


    free(niz);
    return vrati;
}

void prebroji(char **lista, int i)
{
    int sok = 0;
    int voda = 0;
    int pivo = 0;
    char rijec[10];


    int brojac;
    for(brojac = 0; brojac < i; brojac++)
    {

        int broj = 0;
        char slovo[10] = {};
        int brojac_slovo = 0;
        int j = 0;

        int k;

        while(j <= strlen(lista[brojac]))
        {
            if(lista[brojac][j] >= '0' && lista[brojac][j] <='9')
            {
                broj = broj * 10 + (lista[brojac][j] - '0');

                //printf("%i \n", broj);
            }

            if(lista[brojac][j] >= 'a' && lista[brojac][j] <= 'z')
            {
                slovo[brojac_slovo] = lista[brojac][j];
                brojac_slovo++;
            }

            if(lista[brojac][j] == ',' || lista[brojac][j] == 0)
            {
                //printf("%s\n", slovo);

                if(strcmp(slovo, "voda") == 0) voda = voda + broj;
                if(strcmp(slovo, "sok") == 0) sok = sok + broj;
                if(strcmp(slovo, "pivo") == 0) pivo = pivo + broj;

                broj = 0;
                brojac_slovo = 0;
                for(k = 0; k < sizeof(slovo) / sizeof(char); k++) slovo[k] = 0;
            }
            j++;
        }


    }

    printf("Sok -> %i\n", sok);
    printf("Voda -> %i\n", voda);
    printf("Pivo -> %i\n",pivo);

}


int main()
{

    int i;
    char **lista = malloc(sizeof(char*));




    /// ---------- Ucitavanje i dinamicka alokacija ---------- ///
    int brojac = 0;
    while(1)
    {
        char **tmp;
        tmp = ucitajPoruku();

        lista[brojac] = malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(lista[brojac], tmp);

        /// ----- Provjera za OK ----- ///
        if(strcmp(lista[brojac],"OK") == 0) break;;

        //printf("String: %s Duljina: %i\n", lista[brojac], strlen(lista[brojac]));

        free(tmp);

        brojac++;
        lista = (char **) realloc(lista, (brojac+1) * sizeof(*lista));
    }


    prebroji(lista,brojac);
    return 0;
}
