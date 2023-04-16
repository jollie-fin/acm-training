#include <stdio.h>

int main(int argc, char **argv)
{
    char tab[32768];
    while (fgets(tab,32767,stdin))
    {
        fputs(tab,stdout);
    }
    return 0;
}
