#include <iostream>
using namespace std;

int main() {
	//pointers and the variable that it is pointing to have to have the same data type. 
	int n = 5;
	cout << &n << endl;   //prints out the memory address of n.

	int* ptr = &n;	      //ptr is pointing to the address of n.	
	cout << ptr << endl;  //prints out the address of n.
	cout << *ptr << endl; //dereference by adding a star to ptr, 
			      //this will access & prints out the value that is stored in that address.
	*ptr = 10;            //sets value 10 into the memory address that ptr is pointing to.
	cout << *ptr << endl; //dereference ptr will prints out the value stored in that address which is 10.
	cout << n << endl;    //the value stored in the address of n that ptr is pointing to, 
			      //is now changed to 10 as well.

	//assigning value to variable using pointers.
	int v;
	int* ptr2 = &v;
	*ptr2 = 7;
	cout << "v=" << v << endl; //7
}
