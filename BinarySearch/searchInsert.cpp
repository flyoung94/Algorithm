/* searchInsert.cpp
 *
 * Author: xblin
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
	int searchInsert(vector<int> &nums, int target){
		int lenth = nums.size();
		int left = 0;
		int right = lenth-1;
		int mid;

		while(left<=right){
			mid = (left+right)/2;
			if(target > nums[mid])
				left = mid+1;
			else if(target < nums[mid])
				right = mid-1;
			else
				return mid;
		}
		return left;
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
