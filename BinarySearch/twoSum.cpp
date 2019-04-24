/* twoSum.cpp
 *
 * leetcode-167
 *
 * Author: xblin
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
	vector<int> twoSum(vector<int> &numbers, int target){
		//int left = 1;
		//int right = numbers.size(); 
		vector<int> res;

		int l = 0;
		int r = numbers.size()-1;
		while(l != r) {
			if((numbers[l]+numbers[r]) < target) 
				l++;

			else if((numbers[l]+numbers[r]) > target) 
				r--;
			else{
				res.push_back(l+1);
				res.push_back(r+1);
				break;
			}	
		}

		return res;

/*
		vector<int>::iterator it_start = numbers.begin();
		vector<int>::iterator it_end = numbers.end()-1;
	//	it_end--;
		while(it_start != it_end){
			if((*it_start+*it_end) < target)
				it_start++;
			else if((*it_start+*it_end) > target)
				it_end--;
			
			else{
				res.push_back(*it_start);
				res.push_back(*it_end);
				break;
			}
		}
		return res;
		*/
	}
};

int main(int argc, char *argv[]){

	vector<int> nums = {2,7,11,16};
	Solution slv;
	vector<int> res = slv.twoSum(nums, 9);
	
	for(auto elem : res){
//		cout << "elem size" << endl;
		cout << elem << endl;
	}
	
	return 0;
}
