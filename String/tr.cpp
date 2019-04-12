/* tr.cpp
 *
 * tr space to %20
 * 原址，O(n)
 *
 * Author: xblin
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]){


	char str[] = "lab string str2.";

//	char *str1 = "lab string str1.";
//	cout << sizeof(str) << endl;

	char *p = str;
	int empty = 0;
	int lenth = 0;
	while(*p != '\0'){
		if(*p == ' ')
			empty++;

		lenth++;
		p++;
	}

	lenth++;

	char *p1 = p;
	char *p2 = (p+empty*2);

	for(int i=0; i<lenth-1; i++){
	
		if(*p1 != ' '){
			*(p2--) = *(p1--);
		}
		else{
			*(p2--) = '0';
			*(p2--) = '2';
			*(p2--) = '%';
			p1--;
		}
	}

	cout << str << endl;

//	cout << empty << endl;
//	cout << lenth<< endl;

//	char *p = str2;
//	cout << *p << *(p+1) << endl;

	return 0;
}


