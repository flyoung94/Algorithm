/* BSearch.cpp
 *
 * Author: xblin
 */

#include <iostream>

using namespace std;

int bsearch(int *arr, int left, int right, int target) {


	while(left <= right){ // <=
	
		int mid = (left + right)/2;
	
		if(arr[mid] > target)
			right = mid - 1;   // mid -1
		else if(arr[mid] < target) 
			left = mid + 1;   // mid + 1
		else
			return mid;
	}
	
	return -1;
}

int main(int argc, char *argv[]) {
	
	int targe;
	cin >> targe;

	int arr[] = {1,3,5,6,7,8,9};

	int res = bsearch(arr,0, 6, targe);

	cout << res << endl;
	
	return 0;
}
