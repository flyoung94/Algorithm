
#include <iostream>

using namespace std;

class Quicksort{

public:
	Quicksort(int *arr) : _array(arr) {}
	int part(const int left, const int right);
	void sort(int left, int right);



private:
	int *_array;

};

int Quicksort::part(const int left, const int right){
	
	int base = _array[right];

	int ptr = left;
	
	for(int i=left; i<right; i++){
		if( _array[i] < base){
			std::swap(_array[i], _array[ptr++]);
		}
	}

	std::swap(_array[ptr], _array[right]);

	return ptr;
}


void Quicksort::sort(int left, int right){

	if(left < right){
		int base = part(left, right);
		sort(left, base-1);
		sort(base+1, right);
	}
}

void
