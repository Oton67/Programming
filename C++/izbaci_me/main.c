#include <stdio.h>
#include <stdlib.h>

int main()
{
    int niz[1000];
    int N, K;
    int i, j;
    int min = 0, max = 0;
    int min_pos = 0;
    int max_pos = 0;

    int max_niz[1000];
    int min_niz[1000];

    int max_n, min_n;


    scanf("%i", &N);
    scanf("%i", &K);

    max_n = N;
    min_n = N;

    for(i = 0; i < N; i++) scanf("%i", &niz[i]);

    for(i = 0; i < N; i++) max_niz[i] = niz[i];
    for(i = 0; i < N; i++) min_niz[i] = niz[i];


    /// ----- Za max ----- ///
    for(i = 0; i < K; i++)
    {
        max = -2000000000;
        for(j = 0; j < max_n; j++) if(max < max_niz[j]) max = max_niz[j], max_pos = j;

        for(j = max_pos; j + 1 < max_n; j++) max_niz[j] = max_niz[j+1];
        max_n-=1;

    }

    for(i = 0; i < max_n; i++) printf("%i ", max_niz[i]);
    printf("\n");


    /// ----- Za min ----- ///
    for(i = 0; i < K; i++)
    {
        min = 2000000000;
        for(j = 0; j < min_n; j++) if(min > min_niz[j]) min = min_niz[j], min_pos = j;

        for(j = min_pos; j + 1 < min_n; j++) min_niz[j] = min_niz[j+1];
        min_n-=1;

    }

    for(i = 0; i < min_n; i++) printf("%i ", min_niz[i]);
    printf("\n");


    return 0;
}
