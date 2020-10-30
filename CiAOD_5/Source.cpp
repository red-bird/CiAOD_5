#include <iostream>

using namespace std;

int main() {
	int n, tmp;
	int** array;
	bool* choosen;
	int edgeNum = 0;

	cout << "Prim algorythm\n" << "Enter amount of nodes\n";
	if (!(cin >> n)) {
		cout << "incorrect input\n";
		return -1;
	}
	cout << "Enter adjancy array\n";

	//initializes choosed to track selected vertex
	choosen = new bool[n];
	for (int i = 1; i < n; i++)
		choosen[i] = false;
	choosen[0] = true; // choose random vertex, for example first
	int x, y; // rows and cols num

	// create array
	array = new int* [n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];

	// enter values
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			array[i][j] = tmp;
		}

	cout << "Format - (Edge)Weight\n";
	while (edgeNum < n - 1) {
		x = 0;
		y = 0;
		int min = INT_MAX; // set the greatest num

		for (int i = 0; i < n; i++) {
			if (choosen[i]) {
				for (int j = 0; j < n; j++)
				{
					if (!choosen[j] && array[i][j]) {
						if (min > array[i][j]) {
							x = i;
							y = j;
							min = array[i][j];	
						}
					}
				}
			}
		}
		cout << '(' << x << " -> " << y << ") " << array[x][y] << " | ";
		choosen[y] = true;
		++edgeNum;
	}

	return 0;
}