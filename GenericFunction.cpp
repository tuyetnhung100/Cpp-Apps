#include <iostream>
using namespace std;
//Generics are implemented using templates

template <typename T> //generic data type, typename or class works e.g. <class T> 
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 5, b = 7;
	cout << a << " - " << b << endl;
	Swap<int>(a, b); //generic function, you don't need to specify type, Swap(a, b) still works
	cout << a << " - " << b << endl;

	char c = 'c', d = 'd';
	cout << c << " - " << d << endl;
	Swap<char>(c, d); //generic function
	cout << c << " - " << d << endl;

}
