// program prompts user for side lengths (a, b, c) of a triangle and 
// writes out if that triangle is equilateral, isosceles, or scalene

#include <iostream>
using namespace std;

int main() 
{
	float a, b, c;
	cout << "a, b, c: ";
	cin >> a >> b >> c;

	if (a == b && b == c) 
		cout << "Equilateral triangle" << endl;
	else 
		if (a != b && a != c && b != c)
			cout << "Scalene triangle" << endl;
		else 
			cout << "Isosceles triangle" << endl;
}

