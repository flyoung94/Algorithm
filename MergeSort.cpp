/* MergeSort.cpp
 *
 * Author: xblin
 */

#include <iostream>

using namespace std;

const int INF = 10000; //定义一个伪无穷数

class MergeSort{

public:
	MergeSort(int *arr) : _array(arr) {}
	void merge_sort(int left, int right);

private:
	int *_array;
	void merge(int *arr, int left, int mid, int right); //合并
	void sort(int left, int right); //递归
};

void MergeSort::merge(int *arr, int left, int mid, int right){

	int length1 = mid-left+1;
	int length2 = right-mid;
	int *L = new int[length1+1]; //+1 为了存放结束标志
	int *R = new int[length2+1]; //+1 为了存放结束标志
	
	for(int i=0; i<length1; i++){
		L[i] = arr[left+i];
	}
	for(int j=0; j<length2; j++){
		R[j] = arr[mid+j+1];
	}

	L[length1] = INF;
	R[length2] = INF;

	for(int i=0,j=0,k=left; k<=right; k++){
		if(L[i] < R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
	}

	delete[] L;
	delete[] R;
}

void MergeSort::sort(int left, int right){
	if(left < right){
		int mid = (left+right) / 2;
		sort(left, mid);
		sort(mid+1, right);
		merge(_array, left, mid, right);
	}
}

void MergeSort::merge_sort(int left, int right){
	sort(left, right);
	for(int i=left; i<right; i++)
		cout << _array[i] << endl;
}

int main(int argc, char *argv[]){

	int array[] = {8,4,5,7,1,3,6,2};
	MergeSort M(array); 
	M.merge_sort(0,7);

	return 0;
}


