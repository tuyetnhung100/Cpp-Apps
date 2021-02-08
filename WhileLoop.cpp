#include <iostream> 
using namespace std;

int main()
{
	// Write out all the numbers between 100 - 500 that are
	// divisible by 3 and 5
	int counter = 100;
	while (counter <= 500)
	{
		if (counter % 3 == 0 && counter % 5 == 0)
			cout << counter << " is divisible by 3 and 5.\n";
		counter++; // To avoid infinite loop, we need to increment counter 
			   // each time the while loop runs, so eventually 100 
			   // will be added by 1 each time up until counter is 
			   // equal to 500 so we can exit this loop.
	}
}
