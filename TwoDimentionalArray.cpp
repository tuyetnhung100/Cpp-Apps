#include <iostream>
using namespace std;

//Multidimentional dynamic arrays and two-dimensional array.

int main() {
	int rows, cols;
	cout << "Rows, columns: ";
	cin >> rows >> cols;
	
	//allocate memory
	int **table = new int*[rows];

	for(int i = 0; i < rows; i++) {
		table[i] = new int[cols];
		for(int j = 0; j < cols; j++) {
			cout << " --- ";
			cout << "|";
		}
		cout << endl;
		//cout << " - ";
	}
	cout << endl;
	table[1][2] = 100;
	cout << "table[1][2] value: " << table [1][2] << endl;

	//deallocate memory
	for(int i = 0; i < rows; i++) {
		delete[] table[i];
	}
	delete[] table;
	table = NULL;
}
