#include <stdio.h>

int main()
{
    int c,i,j;
    scanf("%d",&c);
    for (i = 0; i < c; i++)
    {
        scanf("%d",&j);
        if (j % 2 == 0)
            printf("%d\n", j/2*(j/2 - 1));
        else
            printf("%d\n", (j-1)/2*(j-1)/2);
    }
    return 0;
}
