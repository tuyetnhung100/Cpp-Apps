#include <iostream>
using namespace std;

void showMenu() {
	cout << "**********MENU**********\n";
	cout << "1. Check balance\n";
	cout << "2. Deposit\n"; 
  	cout << "3. Withdraw\n";
	cout << "4. Exit\n";
       	cout << "************************\n";	
	}

int main() {
	//check balance, deposit, withdraw, menu
	int option;
	double balance = 500;
	do {
		showMenu();
		cout << "Option:";
		cin >> option;
		//system('cls') clear screen for windows vs
		system("clear");
		switch(option) {
			case 1: cout << "Balance is:" << balance << endl; break;
			case 2: 
				double depositAmount;
				cout << "Deposit amount:";
				cin >> depositAmount;
				balance += depositAmount;
				break;
			case 3:
				double withdrawAmount;
				cout << "Withdrawn Amount:";
				cin >> withdrawAmount;
				if (withdrawAmount <= balance)
					balance -= withdrawAmount;
				else 
					cout << "Not enough money\n";
				break;
			default: cout << "Invalid option!\n";
		}
	} while (option != 4);
}
