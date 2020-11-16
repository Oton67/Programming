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

struct osoba
{
    char oznaka[10+1];
    char ime_prezime[100];
    char grad[100];

};


struct kripto UcitajKripto(FILE* creepto)
{
    struct kripto rez;
    fread(&rez, sizeof(struct kripto),1,creepto);

    return rez;
};

struct osoba UcitajOsobe(FILE* stranke)
{
    struct osoba rez;
    fscanf(stranke, " %[^#]#%[^#]#%[^\n]*[\n]", rez.oznaka, rez.ime_prezime, rez.grad);//Eew88hC3Fn#Anita Vukorepa#Diklo
    return rez;
};


char *zadnjih_deset(char *niz)
{
    static char vrati[10+1];

    int i = 0;
    int j = 10;

    for(i = 0; i < 10; i++)
    {
        vrati[i] = niz[j];
        j++;
    }

    //printf("%s\n", vrati);
    return vrati;
}


char *prvih_deset(char *niz)
{
    static char vrati[10+1];

    int i;

    for(i = 0; i < 10; i++)
    {
        vrati[i] = niz[i];
    }

    //printf("%s\n", vrati);
    return vrati;
}


char *spoji(char *ljudi, char *tran)
{
    char *spojeno[20+1];
    strcpy(spojeno, ljudi);

    strcpy(&spojeno[10], tran);

    return spojeno;
}





int main()
{
    int i;
    int counter_creepto = 0;
    int counter_osoba = 0;

    struct kripto tran[1000];
    struct osoba ljudi[100];
    char naziv_stranke[100];

    FILE* stranke = NULL;
    FILE* creepto = NULL;

    stranke = fopen("stranke.txt", "r");
    creepto = fopen("creepto.val", "rb");



    /// ---------- Ucitavanje u strukture --------- ///
    while(1)
    {
        tran[counter_creepto] = UcitajKripto(creepto);
        if(feof(creepto)) break;
        counter_creepto++;
    }

    while(1)
    {
        ljudi[counter_osoba] = UcitajOsobe(stranke);
        if(feof(stranke)) break;
        counter_osoba++;
    }



    for(i = 0; i < counter_osoba; i++)
    {
        printf("Oznaka: %s\n", ljudi[i].oznaka);
        printf("Ime i prezime: %s\n", ljudi[i].ime_prezime);
        printf("Grad: %s\n", ljudi[i].grad);


        printf("------------------\n");
    }


/*

    for(i = 0; i < 3; i++)
    {
        printf("Kod: %s\n", tran[i].kod);
        printf("Iznos: %i\n", tran[i].iznos);
        printf("Dan: %i\n", tran[i].dan);
        printf("Mjesec: %i\n", tran[i].mjesec);
        printf("Godina: %i\n", tran[i].godina);
        printf("Sat: %i\n", tran[i].sat);
        printf("Minuta: %i\n", tran[i].minuta);
        printf("Sekunda: %i\n", tran[i].sekunda);

        printf("------------------\n");

    }*/

/*
    char *prvihDeset[10+1];
    char *zadnjihDeset[10+1];

    char *prvihDesetSljedece[10+1];


    *prvihDeset = prvih_deset(tran[0].kod);
    *zadnjihDeset = zadnjih_deset(tran[0].kod);

    *prvihDesetSljedece = zadnjih_deset(tran[1].kod);


    int lol = spoji(*prvihDeset,*zadnjihDeset);
    for(i = 0; i < counter_osoba; i++)*/
    {










    }




    fclose(creepto);
    fclose(stranke);

    return 0;
}
