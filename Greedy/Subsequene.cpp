/* Subsequeue.cpp
 *
 * Leetcode-376	
 * 贪心算法+状态机思想
 *
 * Author: xblin
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
		const int Begin = 00;
		const int Up = 01;
		const int Down = 10;
		int lenth = 1;
		int Status = Begin;  
		if(nums.empty())
			return 0;
		for(int i=0; i<nums.size()-1;i++){
			switch(Status){
				case Begin: {
					if(nums[i+1] > nums[i]){
						lenth++;
						Status = Up;
					}
					else if(nums[i+1] < nums[i]){
						lenth++;
						Status = Down;
					}
					else
						Status = Begin;
				
				} break;

				case Up: { 
					if(nums[i+1] < nums[i]) {
						lenth++;
						Status = Down;
					}
					else
						Status = Up;
				
				} break;
				case Down: {
					if(nums[i+1] > nums[i]){
						lenth++;
						Status = Up;
					}
					else
						Status = Down;
				} break;
			}
		}

		return lenth;
	}
};


int main(int argc, char *argv[]){

	std::vector<int> nums = {1,17,6,5,7,1};
	Solution solve;
	cout << solve.wiggleMaxLength(nums) << endl;

	return 0;
}
