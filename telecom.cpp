#include <iostream>

using namespace std;
int N,P,K;
int adjacence[1000][1000];
bool traite[1000];
int nb_voisins_dans_S[1000];
int nb_voisins[1000];
int file[2000];
int debut;
int fin;

bool entree()
{
    cin >> N;
    if (N == 0)
        return false;
    cin >> P >> K;

    for (int i = 0; i < N; i++)
    {
        traite[i] = false;
        nb_voisins[i] = 0;
    }


    for (int i = 0; i < P; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adjacence[a][nb_voisins[a]++]=b;
        adjacence[b][nb_voisins[b]++]=a;
    }

    debut = 0;
    fin = 0;

    for (int i = 0; i < N; i++)
    {
        nb_voisins_dans_S[i] = nb_voisins[i];
        if (nb_voisins_dans_S[i] < K)
            file[fin++] = i;        
    }


    while (debut != fin)
    {
        int candidat = file[debut++];
        if (nb_voisins_dans_S[candidat] < K && traite[candidat] == false)
        {
            traite[candidat] = true;
            for (int i = 0; i < nb_voisins[candidat]; i++)
            {
                nb_voisins_dans_S[adjacence[candidat][i]]--;
                if (nb_voisins_dans_S[adjacence[candidat][i]] == K-1)
                    file[fin++] = adjacence[candidat][i];
            }
        }
    }
    return true;
}

int taille_sous_graphe(int composante)
{
    traite[composante] = true;
    int retour = 1;
    for (int i = 0; i < nb_voisins[composante]; i++)
    {
        if (!traite[adjacence[composante][i]])
            retour += taille_sous_graphe(adjacence[composante][i]);
    }
    return retour;
}

int main()
{
    while (entree())
    {
        int max = 0;
        for (int i = 0; i < N; i++)
        {
            int t = 0;
            if (!traite[i])
                t=taille_sous_graphe(i);
            if (t > max)
            {
                max = t;
            }
        }
        cout << max << endl;
    }
    return 0;
}
