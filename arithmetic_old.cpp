#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int nb[3][10];
#define max(a,b)(((a)>(b))?(a):(b))

void affiche(int no)
{
  for (int i = 0; i < 10; i++)
    cout << nb[no][i];
}

  int lg[3];

void tasse(int no)
{
  int i;
  for (i = lg[no]-1; i >= 0; i--)
    nb[no][i+10-lg[no]] = nb[no][i];
  for (i = 0; i < 10-lg[no]; i++)
    nb[no][i] = 0;
}

bool acquisition()
{
  int c;
  int no = 0;
  lg[0] = lg[1] = lg[2] = 0;
  while (1)
  {
    if (no >= 3)
      *((int *) 0) = 1;
    c=getchar();
    switch (c)
    {
      case EOF:
      case '\n':
        if (no == 2)
        {
          if(lg[0] >= 10 || lg[1] >= 10 || lg[2] >= 10)
            *((int *) 0) = 0;
          if(lg[0] == 0 || lg[1] == 0 || lg[2] == 0)
            *((int *) 0) = 0;
          tasse(0);
          tasse(1);
          tasse(2);
          return true;
        }
        break;

      case '+':
      case '=':
        no++;
        break;
      
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        nb[no][lg[no]++] = c-'0';
        break;



      default:
        break;
    }
  }
}

bool calcule(int base)
{
  int retenue = 0;
  for (int i = 9; i >= 0; i--)
  {
    if (nb[0][i] >= base || nb[1][i] >= base || nb[2][i] >= base)
      return false;

    if (nb[0][i]+nb[1][i]+retenue==nb[2][i])
    {
      retenue = 0;
    }
    else if (nb[0][i]+nb[1][i]+retenue==nb[2][i]+base)
    {
      retenue = 1;
    }
    else
      return false;
  }
  if (retenue == 0)
    return true;
  return false;
}

bool calcule1()
{
  int a=0,b=0,c=0;
  bool un;
  un = true;
  for (int i = 9; i >= 0; i--)
  {
    if ((nb[0][i] <= 1 && un == true))
    {
      if (nb[0][i] == 0)
        un = false;
      else
        a++;
    }
    else if (nb[0][i] == 0 && un == false)
    {
      ;
    }
    else
      return false;
  }

  un = true;
  for (int i = 9; i >= 0; i--)
  {
    if ((nb[1][i] <= 1 && un == true))
    {
      if (nb[1][i] == 0)
        un = false;
      else
        b++;
    }
    else if (nb[1][i] == 0 && un == false)
    {
      ;
    }
    else
      return false;
  }


  un = true;
  for (int i = 9; i >= 0; i--)
  {
    if ((nb[2][i] <= 1 && un == true))
    {
      if (nb[2][i] == 0)
        un = false;
      else
        c++;
    }
    else if (nb[2][i] == 0 && un == false)
    {
      ;
    }
    else
      return false;
  }
  return a+b==c;
}
  


int calcule()
{
  if (calcule1()) return 1;
  for (int i = 2; i <= 24; i++)
  {
    if (calcule(i))
      return i;
  }
  return 0;
}

int main()
{
  int n = 0;
  int c;

  while ((c = getchar()) != '\n')
  {
    switch (c)
    {
      case '\n':
        break;
          
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        n = n*10 + c-'0';
      default:
        break;
    }
  }

  for (int i = 0; i < n; i++)
  {
    acquisition();
    cout << calcule() << endl;
  }
}
