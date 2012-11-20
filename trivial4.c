#include <stdio.h>

int main(int argc, char **argv)
{
    int tab[500];
    int i,j,tmp,al,d;
        int b;
    for(;;)
    {
        scanf("%d %d",&al,&d);
        if (al == 0 && d == 0)
            return 0;
       b=0;
       for (j = 0; j < al; j++)
            tab[j] = 0;
       for (i = 0; i < d; i++)
        {
            for (j = 0; j < al; j++)
            {

                if (i==0)
                    tab[j] = 0;
                scanf("%d",&tmp);
                tab[j] += tmp;
                if (tab[j] == d)
                    b=1;
            }
        }

        if (b)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}


