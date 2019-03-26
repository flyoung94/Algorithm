/* candy.cpp
 *
 * Leetcode-455
 *
 * Author: xblin
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{

public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		::sort(g.begin(), g.end());
		::sort(s.begin(), s.end());

		int i=0;
		
		for(auto n : s){
			if(n>=g[i]){
				i++;
				if(i==g.size())
					break;
			}
		}
		return i;
	}
};


int main(int argc, char *argv[]){

	vector<int> g = {7,8,9,10};
	vector<int> s = {7,8,9,10};

	Solution solve;
	cout << solve.findContentChildren(g, s) << endl;
		
	return 0;
}

