#include <iostream>
#include <iomanip> //iomanip library contains function setw()
using namespace std;

int main() {
	int height, width;
	cout << "Height: ";
	cin >> height;
	cout << "Width: ";
	cin >> width;
	char symbol;
	cout << "Symbol: ";
	cin >> symbol;

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			cout << setw(3) << symbol; //set width of symbol field to 3 fields(spaces)		
		}
		cout << endl;
	}
}
