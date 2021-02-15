#include <iostream>
using namespace std;

// void ClearScreen()
// {
// 	for (int i = 0; i < 20; i++) 
// 		cout << "\n\n\n\n\n";
// }

int main()
{
	int hostUserNum, guestUserNum;
	cout << "Host: ";
	cin >> hostUserNum;
	// ClearScreen(); 
	// system("cls") - for windows vs
	system("clear");

	cout << "Guest: ";
	cin >> guestUserNum;
	//A shorter form of if else statement
	(hostUserNum == guestUserNum)? cout << "Correct!": cout << "Failed!";
       	cout << endl;	

	/*if (hostUserNum == guestUserNum) 
		cout << "Correct!" << endl;
	else
		cout << "Failed!" << endl;*/
}

