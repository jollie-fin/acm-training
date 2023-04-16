#include <iostream>

int p;

int pow(int a,int b)
{
    if (b==0) return 1;
    int c=pow(a,b/2);
    if (b%2==0)
        return (c*c)%p;
    else
        return (c*c*a)%p;
}

int polynome1[70];
int polynome2[70];

void affiche_polynome(int *polynome, int degree)
{
    for (int i = degree-1; i >= 0; i--)
    {
        std::cout << polynome[i] << "x^" << i;
        if (i != 0) std::cout << "+";
    }
    std::cout << std::endl;
}

void multiplication_par_constante(int *polynome, int degree, int b)
{
    for (int i = 0; i < degree; i++)
    {
        polynome[i] = (polynome[i] * b) % p;
    }
}

void multiplication_par_lineaire(int *polynome, int degree, int b)
{
    for (int i = degree-1; i >= 0; i--)
    {
        polynome[i+1]=polynome[i];
    }
    polynome[0] = 0;
    for (int i = 0; i < degree; i++)
    {
        polynome[i] = (b*polynome[i+1]+polynome[i]+p*p)%p;
    }
}

void division_polynome(int *resultat, const int *polynome, int degree, int b)
{
    static int tmp[70];
    int i;
    for (i = degree-1; i>=0; i--)
        tmp[i] = polynome[i];

    for (i = degree-2; i>=0; i--)
    {
        resultat[i] = tmp[i+1];
        tmp[i] = (tmp[i] - tmp[i+1]*b+p*p)%p;
    }
}

int inverse(int a)
{
    return pow(a,p-2);
}

void calcule_produit(int *polynome, int degree)
{
    for (int i=0; i < degree+1; i++)
        polynome[i] = 0;    
    polynome[0] = 1;
    for (int i=1; i <= degree; i++)
    {
        multiplication_par_lineaire(polynome, i, -i);
    }
}

int evalue(const int *polynome, const int x, int degree)
{
    int retour = 0,i;
    for (i=0; i<degree; i++)
    {
        retour = (retour + polynome[i]*pow(x, i))%p;


    }
    return retour;
}



void calcule_lagrange(int *polynome_orig, int *resultat, int degree, int no)
{
    division_polynome(resultat, polynome_orig, degree, -no);
    affiche_polynome(resultat,degree-1);
    int a = evalue(resultat, no, degree);

    multiplication_par_constante(resultat, degree-1, inverse(a));
}


int main()
{
    p = 43;
    calcule_produit(polynome1,8);
    affiche_polynome(polynome1,9);
    calcule_lagrange(polynome1,polynome2,9,1);
    affiche_polynome(polynome2,8);
    for (int i = 1; i < 8; i++)
        std::cout << evalue(polynome2,i,8) << std::endl;


    return 0;
}
