/* Pack_binary.cpp
 *
 * 0-1背包问题：动态规划求解
 *
 * F[i][j] = F[i-1][j]; if w[i] > j;
 * F[i][j] = max{ F[i-1][j-w[i]]+p[i], F[i-1][j] }; else;
 *
 * Author: xblin
 */

#include <iostream>
#include<algorithm>

using namespace std;

const int W[] = {0,3,4,5}; //物品重量，起始加0，处理数组下标
const int P[] = {0,4,5,6}; //物品价值，起始加0，处理数组下标

const int N = 3+1;  //物品个数为3
const int C = 10+1; //背包容量为10

class PackBinary{

public:
	PackBinary(const int *W, const int *P) : w(W), p(P) {}
	int solution();


private:
	const int *w;
	const int *p;
	int F[N][C] = {{0}};
};

int PackBinary::solution(){
	
	int MaxVal;

	for(int i=1; i<N; i++){
		for(int j=0; j<C; j++){
			if(w[i] > j)
				MaxVal = F[i-1][j];
			else{
				F[i][j] = std::max(F[i-1][j-w[i]]+p[i], F[i-1][j]);
				MaxVal = F[i][j];
			}
		}
	}
	return MaxVal;
}


int main(int argc, char *argv[]){

	PackBinary pack(W, P);
	int maxval = pack.solution();
	cout << maxval << endl;

	return 0;
}
