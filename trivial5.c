#include <stdio.h>

int main()
{
    int j;

    for (;;)
    {
        scanf("%d",&j);
        if (j==0)
            return 0;
        printf("%d\n", j*(j+1)*(2*j+1) / 6);
    }
    return 0;
}
