#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int boule[100];
    int resultat[100];
    int n,b,i,j,r;
    for(;;)
    {
        scanf("%d %d",&n,&b);
        if (n == 0 && b == 0)
            return 0;
        for (i = 0; i < b; i++)
            scanf("%d",boule+i);
        for (i = 0; i <= n; i++)
            resultat[i] = 0;
        for (i = 0; i < b; i++)
            for (j = i; j < b; j++)
            {
                resultat[abs(boule[i]-boule[j])] = 1;
            }
        
        r=0;
        for (i = 0; i <= n; i++)
            r+=resultat[i];
        if (r==n+1)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}


