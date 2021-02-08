#include <iostream>
using namespace std;

//Prime number is a number that is only divisible by: 1 and itself
//1 is not a prime number

bool isPrimeNumber(int number) {	
	for (int i = 2; i < number; i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}

int main() {
	int count = 0;
	int i;
	for (i = 1; i <= 100; i++) {
		bool isPrime = isPrimeNumber(i);
		if (isPrime && i != 1) {  
			cout << i << " is prime number\n";
			count++;
		}
	}
	cout << "There are " << count << " prime numbers from 1 to " << i-1 << endl; 
}
