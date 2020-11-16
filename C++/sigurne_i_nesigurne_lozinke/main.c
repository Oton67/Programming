#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct login
{
    char input[100];
    char username[100];
    char password[100];
};


char *inputToUser(char *input)
{
    static char username[100];
    int i;
    for(i = 0; i < 100; i++) username[i] = 0;
    int brojac = 0;

    while(1)
    {
        if(input[brojac] == ':') break;
        username[brojac] = input[brojac];

        brojac++;
    }

    return username;
}


char *inputToPass(char *input)
{
    static char password[100];
    int i;
    for(i = 0; i < 100; i++) password[i] = 0;
    int brojac = 0;
    int pass_br = 0;

    while(1)
    {
        if(input[brojac] == ':') break;
        brojac++;
    }

    /// pomakni brojac da ne uzme ':'
    brojac++;
    while(1)
    {
        if(input[brojac] == 0) break;
        password[pass_br] = input[brojac];


        brojac++;
        pass_br++;

    }

    return password;
}

int FileToString(char **pass, FILE* f)
{
    int counter = 0;

    char linija[512+1];
    while (fscanf(f,"%512[^\n]%*[\n]", linija) >= 0)
    {

        pass[counter] = malloc(strlen(linija) * sizeof(char) + 1);
        strcpy(pass[counter], linija);
        //printf("%s\n", pass[counter]);

        counter++;
    }

    return counter;

}


int provjeriPass(char *niz, char **passwords, int pass_counter)
{
    int i;
    for(i = 0; i < pass_counter; i++)
    {
        if(strcmp(niz,passwords[i]) == 0) return 0;

    }
    return 1;

}

int provjeriSlicnost(char *user, char *pass)
{
    int i;
    int counter = 0;

    for(i = 0; i < strlen(user); i++)
    {
        if(user[i] == pass[i]) counter++;
    }

    if(counter >= 5) return 0;
    return 1;

}



int main()
{

    FILE* d = NULL;
    d = fopen("common_passwords.txt", "r");

    struct login osoba[100];
    int br = 0;
    int i;


    /// ----- Ucitavanje u strukturu ----- ///
    while(1)
    {
        scanf("%s", osoba[br].input);
        if(strcmp(osoba[br].input, ":") == 0) break;

        /// ----- Pretvara string u username i password - svako zasebno ----- ///
        strcpy(osoba[br].username, inputToUser(osoba[br].input));
        strcpy(osoba[br].password, inputToPass(osoba[br].input));

        free(osoba[br].input);
        br++;

    }

    /// ----- Pretvaranje datoteke u string ----- ///

    int pass_counter = 0;
    char **passwords[500];

    pass_counter = FileToString(passwords, d);

    //printf("%s", passwords[100]);


    /// --------------------------------------------///

    /// ----- Pisanje u datoteku ----- ///
    FILE* write = NULL;
    write = fopen("RezultatiAnalize.txt", "w");


    /// ----- Pisanje svih unesenih lozinka ----- ///

    for(i = 0; i < br; i++) fprintf(write, "%s\n", osoba[i].password);

    fprintf(write, "\nPopis sigurnih lozinki:\n");

    for(i = 0; i < br; i++)
    {
        if(provjeriPass(osoba[i].password, passwords, pass_counter) && provjeriSlicnost(osoba[i].username,osoba[i].password)) fprintf(write, "%s\n", osoba[i].password);
    }

    fclose(write);
    fclose(d);
    return 0;
}
