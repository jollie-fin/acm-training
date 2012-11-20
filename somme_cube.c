#include <iostream>
#include <algorithm>

long long cube[50001] = {0};
int combien = 0;

int main()
{
	long long x;

	while (std::cin >> x)
	{
		for (long long i=combien+1; i <= x; i++)
		{
			cube[i] = cube[i-1] + i*i*i;
		}
		combien = std::max ((int) x,combien);
		std::cout << cube[x] << std::endl;
	}
}
