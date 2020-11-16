#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,flag,br1,br2;
    char c[100], operacija;

    scanf("%s",&c[0]);

    br1 = 0;
    br2 = 0;
    flag = 0;

    for(i = 0; c[i] != 0; i++)
    {
        if(c[i]>='0' && c[i] <= '9')
        {
            if(flag == 0) br1 = (br1*10) + (c[i]-'0');
            if(flag == 1) br2 = (br2*10) + (c[i]-'0');

        }

        if(c[i] == 'K') operacija = 'K', flag=1;
        if(c[i] == '+') operacija = '+', flag=1;
        if(c[i] == '-') operacija = '-', flag=1;
        if(c[i] == '/') operacija = '/', flag=1;
        if(c[i] == '*') operacija = '*', flag=1;
    }


    if(operacija == 'K') printf("%i", br1*br1);
    if(operacija == '+') printf("%i", br1+br2);
    if(operacija == '-') printf("%i", br1-br2);
    if(operacija == '*') printf("%i", br1*br2);
    if(operacija == '/') printf("%i", br1/br2);

    //for(i = 0; c[i] != 0; i++) printf("%c",c[i]);
    return 0;
}
