/* rmMulti.cpp
 *
 * Author:xblin
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
	int rmMulti(vector<int> &nums){
		int lenth = nums.size();
		if(lenth==0)
			return 0;
		int new_ptr = 0;
		for(int i=1;i<lenth;i++){
			if(nums[i] != nums[new_ptr]){
				new_ptr++;
				nums[new_ptr] = nums[i];
			}
		}
		return new_ptr+1;
	}
};

int main(int argc, char *argv[]){

	Solution solve;
	
	vector<int> nums{1,1,2,2,3,3,4};

	cout << solve.rmMulti(nums) << endl;
	return 0;
}
