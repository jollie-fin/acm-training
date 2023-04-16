#include <iostream>

using namespace std;

int adjacence[100][100];
int nb_de_qui[100];
int nb_a_qui[100];
bool traite[100];
int N,M;

void entree()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            adjacence[i][j] = -1;
    for (int i = 0; i < 100; i++)
    {
        traite[i] = false;
        nb_a_qui[i] = 0;
        nb_de_qui[i] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        int no_cas;
        int nb_regles;
        cin >> no_cas >> nb_regles;
        nb_de_qui[no_cas-1] = nb_regles;
        for (int j = 0; j < nb_regles; j++)
        {
            int dependance;
            cin >> dependance;
            adjacence[dependance-1][nb_a_qui[dependance-1]++] = no_cas-1;
        }
    }
}

inline bool estlibre(const int &tache)
{
    return nb_de_qui[tache] == 0;
}

inline void efface(const int &tache)
{
    for (int i = 0; i < N; i++)
    {
        if (adjacence[tache][i] == -1)
            break;
        nb_de_qui[adjacence[tache][i]]--;
    }
    traite[tache] = true;
}

void affiche_cas()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!traite[j] && estlibre(j))
            {
                efface(j);
                cout << j+1;
                if (i < N-1)
                    cout << " ";
                break;
            }
        }
    }
}

int main()
{
    int nb_cas;
    cin >> nb_cas;
    for (int i = 0; i < nb_cas; i++)
    {
        entree();
        affiche_cas();
        if (i<nb_cas-1)
            cout << endl;
        cout << endl;
    }
    return 0;
}
