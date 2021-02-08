#include <iostream>
using namespace std;

int main() {
	//Multiplication table
	//a)1*1=1   b)2*1=2   c)3*1=3
	//  1*2=2     2*2=4     3*2=6
	//  1*3=3     2*3=6     3*3=9
	//notice we have two operands in one function x*y, 
	//the pattern is similar (increasing by 1) 
	//so we will have 2 loops to run through each line
	//the first operand (x) will be 1 loop and the 2nd (y) will be an inner loop of it.
	//The program needs to run the inner loop (y) first and then the outer loop (x)
	//hence, we finish multiplications for table a and then move on to b and then c.
	
	for (int i = 1; i <= 10; i++) {	//outerloop, operand x
		for (int j = 1; j<= 10; j++) { //inner loop, operand y, program runs this part of code first
			cout << i << " * " << j << " = " << i*j << endl;
		}
		cout << endl;
	}
}
