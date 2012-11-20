#include <iostream>
bool h[1000001] = {false};
bool sm[1000001] = {false};

using namespace std;

bool est_semi_prime(int p)
{
  int i;
  for (i = 5; i*i <= p; i+=4)
  {
    if (p%i == 0 && (p/i)%4 == 1)
    {
      if (h[i] && h[p/i])
        return true;
    }
  }
  return false;
}

bool est_h_prime(int p)
{
  int i;
  for (i = 5; i*i <= p; i+=4)
  {
    if (p%i == 0 && (p/i)%4 == 1)
    {
      return false;
    }
  }
  return true;
}

void calcule_h_prime()
{
  h[5] = true;
  for (int i = 9; i < 1000001; i+=4)
  {
    if (est_h_prime(i))
      h[i] = true;
    else
      h[i] = false;
  }
}

void calcule_sm_prime()
{
  for (int i = 9; i < 1000001; i+=4)
  {
    if (est_semi_prime(i))
      sm[i] = true;
    else
      sm[i] = false;
  }
}

int nb(int p)
{
  int ret = 0;
  int i;
  for (i = 5; i <= p; i+=4)
  {
    if (sm[i])
      ret++;
  }
  return ret;
}

int main()
{
  calcule_h_prime();
  calcule_sm_prime();
  int n;
  while (1)
  {
    cin >> n;
    if (n == 0)
      return 0;
    cout << nb(n) << endl;
  }
}
