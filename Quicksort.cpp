/* quicksort.cpp
 *
 * Author: xblin
 */

#include <iostream>
#include <vector>
#include <typeinfo>


using namespace std;

class QuickSort{

public:
	QuickSort(const vector<int> &array) : _array(array) {}
	const int part(const int left, const int right);	
	void quicksort(const int left, const int right);
//	ostream &operator << (ostream &os);

private:
	vector<int>	_array;
	friend ostream &operator << (ostream &os, const QuickSort &q);
	

};

const int QuickSort::part(int left, int right){

	int base = _array[right];	
	int base_ptr(left);  //must left, not 0;

	for(int i=left; i<right+1; i++){
		if(_array[i] < base){
			std::swap(_array[i], _array[base_ptr++]);
		}
	}
	std::swap(_array[base_ptr], _array[right]);

	return base_ptr;
}

void QuickSort::quicksort(const int left, const int right){
	if(left < right){
	
		int base = part(left, right);
		quicksort(left, base-1);
		quicksort(base+1, right);
	}
}

ostream &operator << (ostream &os, const QuickSort &q){

	for(auto elem : q._array)
		os << elem;
	return os;
} 

int main(int argc, char *argv[]){ 
	vector<int> array = {2,8,7,1,3,5,6,4};

	QuickSort q(array);
	q.quicksort(0,7);
	cout << q << endl;

	return 0;
}
