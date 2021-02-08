#include <iostream>
using namespace std;

int main() {
	//Nesting do while loop and for loop.
	//program gets 3 grades from user
	//grade has to be between 1-5
	//calculate user's avg grade
	int grade;
	int sum = 0;
	for(int i = 0; i < 3; i++) {
		
		do {
			cout << "Enter grade " << i+1 << " : ";
			cin >> grade;
		} while (grade < 1 || grade > 5);
		sum += grade;
	}
	cout << "Sum: " << sum << endl;
	cout << "Avg grade: " << (float)sum / 3.0 << endl;
}
