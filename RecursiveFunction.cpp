#include <iostream>
using namespace std;

int recursive_sum(int m, int n) {	//Step 2. m=2, n=4; First recursion passing m=3, n=4; Second passing m=4, n=4.
	if(m == n)	//Step 3. Check if 2==4   ;   3==4   ;   4==4.		 
		return m; //can return m or n here bc they are the same

			  //this if statement will break out of the recursion 
			  //by returning a value when m is equal to n.
			  //until m=n, the recursion will keep running and
			  //return nothing bc it cannot enter the if statement
			  //as the condition (m==n) is not true.
			  //the if statement acts as a base case in this situation
			  //**Must have a base case when using recursion to avoid 
			  //the recursion from happening infinite # of time.
			  //(m == n) like i<=n in For loop below, condition used to stop loop from running.

	return m + recursive_sum(m + 1, n); //2+(3+(4)) //Step 4. 2 is not = 4 so did not enter if statement
       							//   moves to this return
							//  First recursion 2+1 != 4   [return m + passing 3 to m, 4 to n into Step 2]
							//  * 2 + (3 + ())  
							//  * return m + (return m + recursive_sum(m + 1, n));
							//  Second recursion 3+1 == 4 -> enter if statement & break
							//  * 2 + (3+(4))
							//  * return m +(return m + (return m));
							//   (m + 1) because like i++ in the for loop, used
							//   to move from m # to n #.
}

//Sum numbers between m-n
int main() {
	int m = 2, n = 4;

	cout << "Sum:" << recursive_sum(m, n) << endl;  //Step 1. passing 2 to m, and 4 to n.
	//int sum = 0;
	//for (int i = m; i <= n; i++) {
	//	sum += i;
	//}
	//cout << "Sum:" << sum << endl;
}
