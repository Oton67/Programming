#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct kripto
{
    char kod[20+1];
    int iznos;
    int dan;
    int mjesec;
    int godina;
    int sat;
    int minuta;
    int sekunda;
};


struct kripto UcitajKripto(FILE* creepto)
{
    struct kripto rez;
    fread(&rez, sizeof(struct kripto),1,creepto);

    return rez;
};


int provjeriZnakove(char *niz, char *kod)
{
    int i, j;
    int flag;

    for(i = 0; i < strlen(niz); i++)
    {
        flag = 0;
        for(j = 0; j < strlen(kod); j++)
        {
            if(niz[i] == kod[j]) flag = 1;
        }
        if(flag == 0) return 0;
    }

    return 1;
}


void ubaci(char **niz_2d, int n, char *kod, int h, int min, int sec)
{
    niz_2d[n] = (char *)malloc(30*sizeof(char));
    sprintf(niz_2d[n], "%s@%02d:%02d:%02d", kod, h, min, sec);
}


static int myCompare (const void * a, const void * b)
{
    return strcmp (*(const char **) a, *(const char **) b);
}


void sort(char **niz_2d, int n)
{

    char kod[n][20];
    char tmp[30];
    int h[n];
    int min[n];
    int sec[n];
    int i,j,k;
    int tmpint;

    for(i = 0; i < n; i++)
    {
        sscanf(niz_2d[i], "%[a-z-A-Z-0-9]@%02d:%02d:%02d", kod[i], &h[i], &min[i], &sec[i]);
        //printf("%s %d %d %d\n", kod[i], h[i], min[i], sec[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            if(j == i) j++;
            if(j >= n) break;
            if(h[i] > h[j])
            {
                tmpint = h[i];
                h[i] = h[j];
                h[j] = tmpint;

                tmpint = min[i];
                min[i] = min[j];
                min[j] = tmpint;

                tmpint = sec[i];
                sec[i] = sec[j];
                sec[j] = tmpint;

                strcpy(tmp, niz_2d[i]);
                strcpy(niz_2d[i], niz_2d[j]);
                strcpy(niz_2d[j], tmp);
            }
            else if(h[i] == h[j])
            {
                if(min[i] > min[j])
                {
                    tmpint = h[i];
                    h[i] = h[j];
                    h[j] = tmpint;

                    tmpint = min[i];
                    min[i] = min[j];
                    min[j] = tmpint;

                    tmpint = sec[i];
                    sec[i] = sec[j];
                    sec[j] = tmpint;

                    strcpy(tmp, niz_2d[i]);
                    strcpy(niz_2d[i], niz_2d[j]);
                    strcpy(niz_2d[j], tmp);
                }
                else if(min[i] == min[j])
                {
                    if(sec[i] > sec[j])
                    {
                        tmpint = h[i];
                        h[i] = h[j];
                        h[j] = tmpint;

                        tmpint = min[i];
                        min[i] = min[j];
                        min[j] = tmpint;

                        tmpint = sec[i];
                        sec[i] = sec[j];
                        sec[j] = tmpint;

                        strcpy(tmp, niz_2d[i]);
                        strcpy(niz_2d[i], niz_2d[j]);
                        strcpy(niz_2d[j], tmp);
                    }

                    else if(sec[i] == sec[j])
                    {
                        ///abecedno

                        char niz_za_sort[2][30];

                        strcpy(niz_za_sort[0], niz_2d[i]);
                        strcpy(niz_za_sort[1], niz_2d[j]);
                        qsort(niz_za_sort, 2, sizeof(const char *), myCompare);

                        strcpy(niz_2d[i], niz_za_sort[0]);



                    }
                }
            }

        }
    }


    //for(i = 0; i < n; i++) printf("%i\n", h[i]);



}


int main()
{
    int i;
    int counter_creepto = 0;

    struct kripto tran[1000];

    FILE* stranke = NULL;
    FILE* creepto = NULL;

    creepto = fopen("creepto.val", "rb");




    /// ---------- Ucitavanje u strukturu --------- ///
    while(1)
    {
        tran[counter_creepto] = UcitajKripto(creepto);
        if(feof(creepto)) break;
        counter_creepto++;
    }


    int n = 0;
    char *niz = (char*)malloc(sizeof(char)* (20+1));
    scanf("%s", niz);

    char **za_sort = NULL;
    for(i = 0; i < counter_creepto; i++) if(provjeriZnakove(niz, tran[i].kod)) n++;
    za_sort = (char**)malloc(sizeof(char*) * n);

    n = 0;

    for(i = 0; i < counter_creepto; i++)
    {
        if(provjeriZnakove(niz,tran[i].kod))
        {
            ubaci(za_sort, n, tran[i].kod, tran[i].sat, tran[i].minuta, tran[i].sekunda);
            n++;
        }
    }


    sort(za_sort, n);

    for(i = 0; i < n; i++) printf("%s\n", za_sort[i]);
    //printf("%i\n", n);






//    for(i = 0; i < counter_creepto; i++)
//    {
//        printf("Kod: %s\n", tran[i].kod);
//        printf("Iznos: %i\n", tran[i].iznos);
//        printf("Dan: %i\n", tran[i].dan);
//        printf("Mjesec: %i\n", tran[i].mjesec);
//        printf("Godina: %i\n", tran[i].godina);
//        printf("Sat: %i\n", tran[i].sat);
//        printf("Minuta: %i\n", tran[i].minuta);
//        printf("Sekunda: %i\n", tran[i].sekunda);
//
//        printf("------------------\n");
//
//    }

    fclose(creepto);

    return 0;
}
