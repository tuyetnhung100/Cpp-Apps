#include <iostream>
using namespace std;

int main() {
	//Reversing number
	
	int number, reversedNumber = 0;
	cout << "Number: ";
       	cin >> number;	//123
	
	while (number != 0) {
		reversedNumber *= 10;	//0, 30, 320, 321
		//int lastDigit = number % 10; //123 % 10 = (123 - 120) = 3(the remaining of division)
		reversedNumber += number % 10; //add the last digit of number, 0 + 3, 30 + 2, 320 + 1
		number /= 10;	//take out last digit of number, to break out of loop, 123 -> 12 -> 1 -> 0
	}	
	cout << "Reversed: " << reversedNumber << endl; 
}
