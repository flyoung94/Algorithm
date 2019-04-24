/* sqrt.cpp
 *
 * Author: xblin
 */

#include <iostream>

using namespace std;

class Solution{

public:
	int sqrt(int x){
		int right = x/2;
		int left = 1;
		while(left <= right){
			int mid = (left+right)/2;
			if(left)
		}
	}
};

int main(int argc, char *argv[]){
	
	int target;
	cin >> target;

	vector<int> nums = {1,3,5,6};

	Solution slt;
	int res = slt.searchInsert(nums, target);
	//int res = slt.searchInsert(nums, 6);
	cout << res << endl;

	return 0;
}
