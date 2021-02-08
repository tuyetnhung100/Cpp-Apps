#include <iostream>
using namespace std;

int main() 
{
	//count digits of a number
	int number; 		//bc int can only hold a max value of 2147483647 which is a 10 digits number, 
	cout << "Number: ";	//this program cannot return more than 10 digits.
	cin >> number;

	if (number == 0)
		cout << "You have entered 0.\n";
	else 
	{
		if (number < 0) //if entered number is negative, we turn it into positive.
			number = -1 * number;

		int counter = 0;
		while (number > 0) 
		{
			//number = number / 10; //if input 123, => 12.3, takes away one digit from number
			number /= 10;		//each time the loop runs. Until var number is equal to zero
			counter++;		//we exit this loop. With that, increments counter by 1 digit,
					        //each time so we can return the digits of entered number. 
		}
		cout << "Number contains " << counter << " digits\n";		
	}	
}
