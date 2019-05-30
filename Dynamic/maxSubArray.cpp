#include <iostream>
#include <vector>


using namespace std;

struct A{

	int a;
	int b;
};



/* 动态规划 */
int maxSubArray(vector<int> &nums){
	int lenth = nums.size();
	int max = 0;
	int sum = 0;

	for(int i=0;i<lenth;i++){
		if(sum<=0){
			sum = nums[i];	 	//前i个和<=0，就等于下一个
		}
		else if(sum > 0){
			sum += nums[i];
		}
		if(sum > max){
			max = sum;
		}
	}
	return max;
}

int main(int argc, char *argv[]){


	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
//	vector<int> nums = {1};
	int max = maxSubArray(nums);
	cout << max << endl;
//	vector<int> nums = {-2,1};
/*
	int lenth = nums.size();
	int sum = 0;
	int max = 0;

// 暴力求解 
	for(int i=0;i<lenth;i++){
		for(int j=i;j<lenth;j++){
			sum += nums[j];
			if(sum > max)
				max = sum;
		}
		sum = 0 ;
	}
	cout << max << endl;
	*/

	

	return 0;
}
