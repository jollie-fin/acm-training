#include <iostream>
#include <algorithm>

int t[101][100][100];
int foret[100][100];

int w,h;

int meilleur = 0;

bool acquisition()
{
	std::cin >> w;
	std::cin >> h;
	if (w == 0 && h == 0)
		return false;
	else
		for (int x = 0; x < w; x++)
			for (int y = 0; y < h; y++)
				std::cin >> foret[x][y];
}

void initialise()
{
	for (int k=0; k<=h; k++)
		for (int x=0; x<w; x++)
			for (int y=0; y<h; y++)
				t[k][x][y] = 0;
	for (int y=0; y<h; y++)
	{
		if (!foret[w-1][y])
		{
			meilleur = 1;
			t[1][w-1][y] = 1;
		}
	}
 }

void remplit1()
{
	for (int x=w-2; x>=0; --x)
		for (int y=h-1; y>=0; --y)
		{
			if (!foret[x][y])
				t[1][x][y] = 1+t[1][x+1][y];
				meilleur = std::max(meilleur, t[1][x][y]);
		}
}

void remplit(int k)
{
	for (int y=h-k; y>=0; --y)
	{
		if (!foret[w-1][y] && t[k-1][w-1][y+1] == 1)
		{
			t[k][w-1][y] = 1;
			meilleur = std::max(meilleur, t[k][w-1][y] * k);
		}
	}
		

	for (int x=w-2; x>=0; --x)
		for (int y=h-k; y>=0; --y)
		{
			if (!foret[x][y])
			{
				t[k][x][y] = std::min(1+t[k][x+1][y],t[k-1][x][y+1]);
				meilleur = std::max(meilleur, t[k][x][y] * k);
			}
		}
}

int main()
{
	while (acquisition())
	{
		meilleur = 0;
		initialise();
		remplit1();

		for (int k = 2; k <= h; k++)
			remplit(k);
		std::cout << meilleur << std::endl;
	}
}
