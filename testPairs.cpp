#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	int factors;
	int levels;

	cout << "Input number of factors:" << endl;
	cin >> factors;
	cout << "Input number of levels:" << endl;
	cin >> levels;

	for(int i = 0; i < factors; i++)
	{
		for(int j = 0; j < levels; j++)
		{
			for(int k = levels*(i+1); k < factors*levels; k++)
			{
				cout << j+(levels*i) << " " << k << endl;
			}
		}
	}

	return 0;
}
