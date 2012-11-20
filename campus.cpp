#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

bool gr[750][750];
int mere[750];
int classe[750];
int lg[750];
int x[750];
int y[750];
bool traite[750];
int nbclasse;
int N;
int M;

void tasse_rec(int i, int cl)
{
  if (classe[i] > 0)
    return;
  classe[i] = cl;
  for (int j = 0; j < lg[i]; j++)
    tasse_rec(gr[i][j], cl);
}

void tasse()
{
  nbclasse = 1;
  for (int i = 0; i < N; i++)
  {
    if (classe[i] == 0)
      tasse_rec(i,nbclasse++);
  }
}


bool acquisition()
{
  if (!(cin >> N))
    return false;
  for (int i = 0; i < N; i++)
  {
    lg[i] = 0;
    classe[i] = 0;
    mere[i] = i;
  }

  for (int i = 0; i < N; i++)
    cin >> x[i] >> y[i];
  cin >> M;
  for (int i = 0; i < M; i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    gr[a][lg[a]++] = b;
    gr[b][lg[b]++] = a;
  }
  tasse();
  return true;
}

double d(int mi, int mj)
{
  double min = 400000000.;
  for (int i = 0; i < N; i++)
  {
    if (mere[i] != mi)
      continue;
    for (int j = 0; j < N; j++)
      {
        if (mere[j] != mj)
          continue;
        double d2 = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        if (d2 <= min)
          min = d2;
      }
  }
  return sqrt(min);
}

void affiche_mere()
{
  for (int i = 0; i < N; i++)
    cout << mere[i] << " ";
  cout << endl;
}

double fusionne_proche(int i)
{
  double min = 20000.;
  int opti = i;
  for (int j = 0; j < nbclasse; j++)
  {
    if (j != mere[i])
    {
      double dis = d(mere[i],j);
      if (dis < min)
      {
        min = dis;
        opti = j;
      }
    }
  }
  for (int j = 0; j < nbclasse; j++)
  {
    if (mere[j] == opti)
      mere[j] = mere[i];
  }
  affiche_mere();
  cout << "choix " << opti<< " distance " << min << endl;
  if (min == 20000.)
    return 0.;
  return min;
}

double calcule()
{
  double retour = 0.;
  for (int i = 0; i < N; i++)
  {
    retour += fusionne_proche(i);
  }
  return retour;
}

int main()
{
  while (acquisition())
    printf("%.2f\n", calcule());
}

