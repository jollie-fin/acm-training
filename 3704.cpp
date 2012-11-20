#include <iostream>
using namespace std;

long long puissance[500];
long long mat[500];
long long etat[500];
long long tmp[500];

long long N,M,k;

void identite(long long a[500])
{
    a[0] = 1LL;
    for (long long  i = 1; i < N; i++)
        a[i] = 0LL;
}

void affecte(long long d[500], long long s[500])
{
    for (long long i = 0LL; i < N; i++)
    {
        d[i] = s[i];
    }
}

void produit(long long d[500], long long a[500], long long b[500])
{
    for (long long i = 0LL; i < N; i++)
    {
        long long valeur=0;
        for (long long j = 0LL; j < N; j++)
        {
            if (i-j < 0)
                valeur+=a[i-j+N]*b[j];
            else
                valeur+=a[i-j]*b[j];
        }
        tmp[i] = valeur % M;
    }
    affecte(d,tmp);
}

void exponation_rapide()
{
    long long p=1;
    affecte(puissance,mat);
    while (p <= k)
    {
        if (k % (2LL*p))
        {
            produit(etat, puissance, etat);
        }
        k = k - (k%(2LL*p));
        p*=2LL;
        produit(puissance,puissance,puissance);
    }
}

bool acquisition()
{
    long long d;
    if (!(cin >> N >> M >> d >> k))
        return false;
    for (long long i = 0LL; i < N; i++)
    {
        cin >> etat[i];
        mat[i] = (i<=d) || (i>=N-d);
    }
    return true;
}

void affiche_mat(long long mat[500])
{
    cout << mat[0];
    for (long long i = 1LL; i < N; i++)
        cout << " " << mat[i];
    cout << endl;
}

int main()
{
    while (acquisition())
    {
        exponation_rapide();
        affiche_mat(etat);
    }
}

