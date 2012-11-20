#include <iostream>

#define GAUCHE 1
#define DROITE 2
#define HAUT 4
#define BAS 8

int w,h;
int maze[20][20];
bool deja_passe[20][20];
char chemin[600];

using namespace std;
struct couple
{
    int x,y;
    couple(int px, int py)
    {
        x = px;
        y = py;
    }
};

bool calcule_solution(int indice,int x, int y)
{
    if (x == -1 || x==w || y==-1 || y==h)
        return false;
    if (deja_passe[y][x])
        return false;
    if (x == w-1 && y == h-1)
    {
        chemin[indice] = '\0';
        return true;
    }
    int m = maze[y][x];
    deja_passe[y][x] = true;
    if ((indice+10) % 80 == 0)
        chemin[indice++] = '\n';
    if (m&DROITE && calcule_solution(indice+1,x+1,y))
    {
        chemin[indice] = 'R';
        return true;
    }
    if (m&GAUCHE && calcule_solution(indice+1,x-1,y))
    {
        chemin[indice] = 'L';
        return true;
    }
    if (m&HAUT && calcule_solution(indice+1,x,y-1))
    {
        chemin[indice] = 'U';
        return true;
    }
    if (m&BAS && calcule_solution(indice+1,x,y+1))
    {
        chemin[indice] = 'D';
        return true;
    }
    return false;
}

bool acquisition()
{
    cin >> h >> w;
    if (w==0 && h==0)
        return false;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
        {
            deja_passe[y][x] = false;
            int e;
            int ouv = 0;
            cin >> e;
            if (e >= 2) ouv|=BAS;
            if (e % 2 == 1) ouv|=DROITE;
            if (x > 0 && (maze[y][x-1]&DROITE)) ouv|=GAUCHE;
            if (y > 0 && (maze[y-1][x]&BAS)) ouv|=HAUT;
            maze[y][x] = ouv;
        }
    return true;
}

void affiche()
{
    cout << '+';
    for (int i = 0; i < w; i++)
        cout << "---+";
    cout << endl;
    for (int y = 0; y < h; y++)
    {
        cout << '|';
        for (int x = 0; x < w; x++)
        {
            cout << "   ";
            if (maze[y][x] & DROITE)
                cout << ' ';
            else
                cout << '|';
        }
        cout << endl;
        cout << '+';
        for (int x = 0; x < w; x++)
        {
            if (maze[y][x] & BAS)
                cout << "   +";
            else
                cout << "---+";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    int no_probleme = 1;
    while (acquisition())
    {
        cout << "Super-maze " << no_probleme++ << ":\n";
        affiche();
        calcule_solution(0,0,0);
        cout << "Solution: " << chemin << endl;
        cout << endl;
    }
}
            

