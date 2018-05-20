//============================================================================
// Name        : SortingLab.cpp
// Author      : Shawn, Justin Schnee
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include "SortingClass.hpp"
using namespace std;


int main() {
	srand(time(NULL));
	SortingClass newSrtCls = SortingClass(10, 0, 9);
	 newSrtCls.compareSorts();


	// test for quick Sort

	int * arry = newSrtCls.copyArr("rand");
	newSrtCls.quickSort(0, 9, arry);
	for(int i = 0; i < 10; i++){
		cout << arry[i] <<  ", ";
	}
}
