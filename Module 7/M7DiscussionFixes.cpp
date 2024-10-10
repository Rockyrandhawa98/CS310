// Displays the current available shirt stock.

#include <iostream>
#include <string>

using namespace std;

enum Colors{Blue, Red, Yellow};
enum ShirtSizes{XS, S, M};

int main()
{
	cout << "Welcome to Made-Up Mart!\n" << endl;

	cout << "We're currently having shirt sale. Here's what we have in stock: \n" << endl;

	const int Color_Numbers = 3;
	const int Available_Sizes = 3;

	int ShirtRacks[Color_Numbers][Available_Sizes] = {0};

	ShirtRacks[Blue][XS] = 0;
	ShirtRacks[Blue][S] = 3;
	ShirtRacks[Blue][M] = 8;
	ShirtRacks[Red][XS] = 7;
	ShirtRacks[Red][S] = 1;
	ShirtRacks[Red][M] = 0;
	ShirtRacks[Yellow][XS] = 5;
	ShirtRacks[Yellow][S] = 0;
	ShirtRacks[Yellow][M] = 11;

	string Shirts[Color_Numbers] = {"Blue", "Red", "Yellow"};
	string Size[Available_Sizes] = { "XS", "S", "M" };

	for (int i = 0; i < Color_Numbers; i++)
	{
		for (int x = 0; x < Available_Sizes; x++)
			cout << "Color: " << Shirts[i] << " , Size: " << Size[x] << " Count: " << ShirtRacks[i][x] << endl;
	}
	
	cout << "\nThank you for shopping with us, see you soon!" << endl;

	return 0;
}