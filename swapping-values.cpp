#include <iostream>
using namespace std;

void ClearScreen()
{
	int n;
	for (n = 0; n < 10; n++)                                                                                                                                                    printf( "\n\n\n\n\n\n\n\n\n\n" );                                                                                                                  
}

int main() 
{
	//Swapping values of two variable with a third var
	int a = 10;
	int b = 20;

	cout << "a = " << a << ", b= " << b << endl;

	int temp = a;
	a = b;
	b = temp;

	cout << "a = " << a << ", b= " << b << endl;
	ClearScreen();
	//Swapping values of two variable without a third var
	int x = 10;
	int y = 20;

	cout << "x = " << x << ", y = " << y << endl;
	
	x = x + y;//30
	y = x - y;//10
      	x = x - y;//20	

	cout << "x = " << x << ", y = " << y << endl;
}


