/* K_Largest.cpp
 *
 * Leetcode-215
 * 方法：1.用维护最大堆(stl中的优先级队列),O(n)；2.快排思想 O(n)
 *
 * Author: xblin
 */

#include <iostream>
#include <vector>
#include <queue>

class Solution{
	
public:
	int findKthLargest(std::vector<int>& nums, int k) {
		std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
		for(int i=0; i<nums.size(); i++){
			if(Q.size() < k){
				Q.push(nums[i]);
			}
			else if(Q.top() < nums[i]){
				Q.pop();
				Q.push(nums[i]);
			}
		}

		return Q.top();
	}
};

class Solution1{

public:
	int findKthLargest(std::vector<int>& nums, int k) {
		

		int right = nums.size()-1;
		int left = 0;
		int ptr = partition(nums, left, right);
		while(ptr != nums.size()-k){
			if( ptr < nums.size()-k ){
				left = ptr+1;
				ptr = partition(nums, left, right);
			}
			else{
				right = ptr-1;
				ptr = partition(nums, left,right);
			}
		}
		return nums[ptr];
	}

	int partition(std::vector<int> &num, int left, int right){
		int base = num[right];
		int ptr=left;
		for(int i=left; i<right; i++){
			if(num[i] < base){
				std::swap(num[i], num[ptr]);
				ptr++;
			}
		}
		std::swap(num[ptr], num[right]);
		
		return ptr;
	}
};

int main(int argc, char *argv[]){

	std::vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(4);

	Solution1 solve;

	std::cout << solve.findKthLargest(nums, 2) << std::endl;

	return 0;
}
