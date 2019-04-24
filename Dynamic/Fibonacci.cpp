/* Fibonacci.cpp
 *
 * Author: xblin
 */

#include <iostream>

using namespace std;

//递归求解
int Fibonacci_1(int n){

	if(n==0) 
		return 0;
	else if(n==1) 
		return 1;
	else
		return Fibonacci_1(n-1) + Fibonacci_1(n-2);
}

//自顶向下的动态规划
int Fibonacci_2(int n) {

	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	
	int Fmin = 0;
	int Fmax = 1;
	int Fn;

	for(int i=2; i<=n; i++){
		Fn = Fmin + Fmax;
		Fmin = Fmax;
		Fmax = Fn;
	}
	return Fn;
}


int main(int argc, char *argv[]){

	int n;
	cin >> n;

	int res1 = Fibonacci_1(n);
	int res2 = Fibonacci_2(n);
	cout << res1 << endl << res2 << endl;;

	return 0;
}



