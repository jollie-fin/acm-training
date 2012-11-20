#include <iostream>
using namespace std;
int nb_cas;
long long tab[100];

void initialise()
{
    cin >> nb_cas;
    
    for (int i = 0; i < nb_cas; i++)
        cin >> tab[i];  
}

bool ca_marche(int a, int b)
{
    for (int i = 0; i < nb_cas-1; i++)
    {
        if ((tab[i]*a*a+a*b+b) % 10001 != tab[i+1])
            return false;
    }
    return true;
}

void test()
{
    for (int b = 0; b <= 10000; b++)
        for (int a = 0; a <= 10000; a++)
        {
            if (ca_marche(a,b))
            {
                for (int i = 0; i < nb_cas; i++)
                {
                    cout << (tab[i]*a+b)%10001 << endl;
                }
                return;
            }
        }
}

int main()
{
    initialise();
    test();
}
