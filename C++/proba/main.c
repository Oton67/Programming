#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(){


    FILE* f = fopen("proba.txt", "r");


    char s[100];
    char s1[100];
    int broj;


    fscanf(f, "%s %s", s, s1);

    printf("%s\n", s);
    //printf("%s %i %s", s, broj, s1);

 return 0;
}




