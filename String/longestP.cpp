/* 最长回文子串 (动态规划)
 *
 * Author: xblin
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string longestP(string s){

	size_t len = s.length();
	string res;

	if(len<=1){
		return s;
	}
	
	bool f[len][len];
	memset(f, 0, sizeof(f));

	int max_len = 1;

	for(int j=0;j<len;j++){
		f[j][j] = true;

		for(int i=0;i<j;i++){
			f[i][j] = (s[i]==s[j] && (j-i<=2 || f[i+1][j-1]));
			
			if(f[i][j]){
				if(j-i+1>=max_len){
					res = s.substr(i,j-i+1); //pos+len
					cout << i << "," << j << endl;
				}
				max_len = max(max_len, j-i+1);
			}
		}
		
	}
	cout << max_len << endl;
	if(max_len == 1) 
		return s.substr(0,1);

	return res;
	
}

int main(int argc, char *argv[]){

	string s;
	cin >> s;
	cout << s << endl;


	string res = longestP(s);
	cout << res << endl;
	
	return 0;
}
