/* find_arr.cpp
 *
 * 行列有序矩阵中寻找值 O(n)
 *
 * Author: xblin
 */

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

	int find;
	cin >> find;

	int arr[4][4] = {{1,2,8,9},
					 {2,4,9,12},
					 {4,7,10,13},
					 {6,8,11,15}
					};	
	
	int n = 0;
	int m = 3;
	string status = "false";
	

	while(n<=3 && m>=0){
		if(find < arr[n][m]){
			m--;
		}
		else if(find > arr[n][m]){
			n++;
		}
		else{
			status = "true";
			break;
		}
	}

	cout << status << endl;

	return 0;
}


