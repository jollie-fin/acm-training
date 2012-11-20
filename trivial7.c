#include <stdio.h>

int main()
{
    int c,i,x,y;
    scanf("%d",&c);
    for (i = 0; i < c; i++)
    {
        scanf("%d %d",&x,&y);
        if (y == x || y == x-2)
            printf("%d\n", x+y-(x%2));
        else
            printf("No Number\n");
    }
    return 0;
}
