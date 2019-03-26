/* Subsequeue.cpp
 *
 * Leetcode-376	
 * 贪心算法+状态机思想
 *
 * Author: xblin
 */

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
				
				} break;

				case Up: {
				
				} break;
				case Down: {
				
				} break;
			}
		}

		return lenth;
	}
};
