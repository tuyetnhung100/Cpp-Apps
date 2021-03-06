#include <iostream>
// this is a recommended practice, bc "using namespace std;" include so many members that we might not need.
using std::cout;
using std::endl;
using std::string;

namespace namespace1 {
	int age = 26;
	string name = "Nina";
}

namespace namespace2 {
	int age = 27;
}

int main() {
	std::cout << namespace2::age << endl;
	cout << namespace1::name << endl;
	return 0;	
}


