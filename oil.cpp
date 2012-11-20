#include <iostream>
#include <cstdlib>

using namespace std;

bool oil[100][100];
int n,m;

bool acquisition()
{
  cin >> m;
  if (m == 0)
    return false;
  cin >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      char b;
      cin >> b;
      oil[i][j] = (b == '@');
    }
  return true;
}

void propage(int i, int j)
{
  if (i == -1 || j==-1 || i>=m || j>=n)
    return;
  if (!oil[i][j])
    return;
  oil[i][j] = false;
  propage(i-1, j);
  propage(i+1, j);
  propage(i, j-1);
  propage(i, j+1);
  propage(i-1, j-1);
  propage(i+1, j-1);
  propage(i-1, j+1);
  propage(i+1, j+1);

}

int calcule()
{
  int resultat = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (oil[i][j])
      {
        resultat++;
        propage(i,j);
      }
  return resultat;
}

int main()
{
  while (acquisition())
  {
    int c = calcule();
    cout << c << endl;
  }
  return 0;
}

