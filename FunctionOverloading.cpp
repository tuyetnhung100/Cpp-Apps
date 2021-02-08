#include <iostream>
using namespace std;
//Function Overloading are functions w/ the same name but different parameters 
//It is useful because we don't need to create multiple functions w/ different 
//names when they are doing almost the same thing.

int sum(int a, int b);
double sum(double a, double b);
float sum(float a, float b, float c);

int main() {
	cout << sum(4, 3) << endl;
	cout << sum(4.2, 3.2) << endl;
	cout << sum(4.2, 3.2, 2.2) << endl;
}
int sum(int a, int b) {
	return a + b;
}
double sum(double a, double b) {
	return a + b;
}
float sum(float a, float b, float c) {
	return a + b + c;
}


