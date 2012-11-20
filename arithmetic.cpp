#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int nb[3][5];
int lg[3];

#define max(a,b)(((a)>(b))?(a):(b))

void transforme(int no, int val)
{
  cout << no << val;
  int log = 0;
  int val_bis = val;
  while (val_bis >= 0)
  {
    log ++;
    val_bis /= 10;
  }

  lg[no] = log;
  for (int i = log-1; i <= 0; i++)
  {
    nb[no][i] = val%10;
    val/=10;
  }
}
    
void acquisition()
{
  string t,u;
  int a,b,c;
  cin >> a;
  cout << a << ";";
  cin >> t;
  cout << t << ";";
  cin >> b;
  cout << b << ";";
  cin >> u;
  cout << u << ";";
  cin >> c;
  cout << c << ";";/*
  cin >> a >> t >> b >> u >> c;
  cout << a << t << b << u << c;*/
  transforme(0,a);
  transforme(1,b);
  transforme(2,c);
}
/*
void affiche()
{
  for (int i = 0; i < 
*/
bool calcule(int base)
{
  int a = 0,b = 0,c = 0;
  for (int i = 0; i < lg[0]; i++)
  {
    if ((nb[0][i] >= base && base > 1) || (nb[0][i] > base))
      return false;
    a=base*a+nb[0][i];
  }
  for (int i = 0; i < lg[1]; i++)
  {
    if ((nb[1][i] >= base && base > 1) || (nb[1][i] > base))
      return false;
    b=base*b+nb[1][i];
  }
  for (int i = 0; i < lg[2]; i++)
  {
    if ((nb[2][i] >= base && base > 1) || (nb[2][i] > base))
      return false;
    c=base*c+nb[2][i];
  }
//  cout << "a,b,c,base" << a << "," << b << "," << c << "," << base << endl;
  return a+b-c == 0;
}

int calcule()
{
  for (int i = 1; i <= 30; i++)
  {
    if (calcule(i))
      return i;
  }
  return 0;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    acquisition();
    cout << calcule() << endl;
  }
}
