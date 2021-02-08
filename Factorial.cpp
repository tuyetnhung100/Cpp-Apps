#include <iostream>
using namespace std;

int main() {
	//The Factorial of a number
	//6!=1*2*3*4*5*6=720

	int number;
	cout << "Number: ";
	cin >> number;
	
	int factorial = 1;

	if (number <= 0) 
		cout << "Cannot factorial negative numbers or zero.\n";
	else {
		/*for (int i = 1; i <= number; i++) {
			factorial = factorial * i;
		}*/

		//6!=6*5*4*3*2*1=720
		for (int i = number; i >= 1; i--) {
			factorial *= i;
		}
		cout << number << "!=" << factorial << endl;
	}
}
