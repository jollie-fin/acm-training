#include <iostream>
#include <cstdlib>

using namespace std;

int somme_cumulee[10001];
int N;

#define max(a,b)(((a)>(b))?(a):(b))

bool acquisition()
{
  cin >> N;
  if (N == 0)
    return false;
  else
  {
    somme_cumulee[0] = 0;
    for (int i=0; i < N; i++)
    {
      int p;
      cin >> p;
      somme_cumulee[i+1] = somme_cumulee[i] + p;
    }
  }
  return true;
}

int calcule()
{
  int resultat = 0;
  for (int i = 0; i <= N; i++)
  {
    for (int j = 0; j < i; j++)
    {
      resultat = max(resultat, somme_cumulee[i]-somme_cumulee[j]);
    }
  }
  return resultat;
}

int main()
{
  while (acquisition())
  {
    int resultat = calcule();
    if (resultat > 0)
      cout << "The maximum winning streak is "<<resultat<<"."<<endl;
    else
      cout << "Losing streak."<<endl;
  }
}
