
#include "SortingClass.hpp"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

SortingClass::SortingClass(int si, int sm, int la){
	inOrderArr = new int[si];
	randArr = new int[si];
	revOrderArr = new int[si];
	size = si;
	smallest = sm;
	largest = la;

	int inOrdTracker = sm;
	int revOrdTracker = la;

	for(int i = 0; i < si; i++){
		inOrderArr[i] = inOrdTracker;
		inOrdTracker++;

		randArr[i] = rand()%(la - sm) + sm;

		revOrderArr[i] = revOrdTracker;
		revOrdTracker--;
	}
}

SortingClass::SortingClass(int si){
	inOrderArr = new int[si];
	randArr = new int[si];
	revOrderArr = new int[si];
	size = si;
	smallest = 10;
	largest = 5000;

	int inOrdTracker = 10;
	int revOrdTracker = 5000;

	for(int i = 0; i < si; i++){
		inOrderArr[i] = inOrdTracker;
		inOrdTracker++;

		randArr[i] = rand()%(4990) + 10;

		revOrderArr[i] = revOrdTracker;
		revOrdTracker--;
	}
}
SortingClass::SortingClass(){
	inOrderArr = new int[5000];
	randArr = new int[5000];
	revOrderArr = new int[5000];
	size = 5000;
	smallest = 10;
	largest = 5010;

	int inOrdTracker = 10;
	int revOrdTracker = 5010;

	for(int i = 0; i < 5000; i++){
		inOrderArr[i] = inOrdTracker;
		inOrdTracker++;

		randArr[i] = rand()%(5000) + 10;

		revOrderArr[i] = revOrdTracker;
		revOrdTracker--;
	}
}

int *SortingClass::copyArr(string s) {

    int *newArray = new int[size];
    int *srcArray = nullptr;

    if (s == "rand") {
        srcArray = randArr;
    } else if (s == "ord") {
        srcArray = inOrderArr;
    } else if (s == "rev") {
        srcArray = revOrderArr;
    }
    if (srcArray != nullptr)
    {
        for (int i = 0; i < size; i++)
        {
            newArray[i] = srcArray[i];
        }
    }
    return newArray;
}

void SortingClass::selectionSort(int arr[]) {
	for(int i = 0; i < size - 1; i++){
		int min_pos = i;
		for(int j = i + 1; j < size; j++){
			if(arr[j] < arr[min_pos]){
				min_pos = j;
			}
		}
		int tmp = arr[i];
		arr[i] = arr[min_pos];
		arr[min_pos] = tmp;
	}
}
void SortingClass::insertionSort(int arr[]){
	int i, comp, j;
	for(i = 1; i < size; i++){
		comp = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > comp){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = comp;
	}
}

//TODO : quickSort does not work
void SortingClass::quickSort(int first, int last, int arr[]){
	if(last - first > 1){
		int piv_index = partition(first, last, arr); // Partition the table.
		quickSort(first, piv_index - 1, arr);        // Sort the left half.
		quickSort(piv_index + 1, last, arr); 		 // Sort the right half.
	}
}

int SortingClass::partition(int first, int last, int arr[]){
     int x = first;
     int y = last;
     int tmp;
     int v = arr[x];
     x++;
     while (x <= y){
    	 while (arr[x]<v)
    		 x++;
    	 while (arr[y]> v)
    		 y--;
    	 if (x<=y){
    		 tmp = arr[x];
    		 arr[x]=arr[y];
    		 arr[y]=tmp;
    		 x++;
    		 y--;
    	 }
     }
    arr[first]=arr[y];
    arr[y] = v;

    return y;
}


void SortingClass::merge(int arr[], int f, int m, int l){
	int i, j, k;
	int n1 = m - f + 1;
	int n2 = l - m;
	int L[n1], R[n2];

	for(i = 0; i < n1; i++){
		L[i] = arr[f+i];
	}
	for(j = 0; j < n2; j++){
		R[j] = arr[m+1+j];
	}
	i = 0;
	j = 0;
	k = f;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}

}
void SortingClass::mergeSort(int arr[], int low, int hi) {
	if(low < hi){
		int m = low+(hi-low)/2;
		mergeSort(arr, low, m);
		mergeSort(arr, m+1, hi);
		merge(arr, low, m, hi);
	}
}

void SortingClass::compareSorts() {
	clock_t startTime = clock();
	double timePassed;

//SELECTION SORT
	int *arr = copyArr("rand");
	startTime = clock();
	selectionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Selection: rand "<<timePassed << endl;

	arr = copyArr("rev");
	startTime = clock();
	selectionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Selection: rev "<<timePassed << endl;

	arr = copyArr("ord");
	startTime = clock();
	selectionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Selection: ord "<<timePassed << endl;

//INSERTION
	arr = copyArr("rand");
	startTime = clock();
	insertionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Insertion: rand "<<timePassed << endl;

	arr = copyArr("rev");
	startTime = clock();
	insertionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Insertion: rev "<<timePassed << endl;

	arr = copyArr("ord");
	startTime = clock();
	insertionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Insertion: ord "<<timePassed << endl;

//QUICKSORT
	arr = copyArr("rand");
	startTime = clock();
	quickSort(0,size,arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Quick: rand "<<timePassed << endl;

	arr = copyArr("rev");
	startTime = clock();
	quickSort(0,size,arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Quick: rev "<<timePassed << endl;

	arr = copyArr("ord");
	startTime = clock();
	quickSort(0,size,arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Quick: ord "<<timePassed << endl;


//MERGE
	arr = copyArr("rand");

	startTime = clock();
	mergeSort(arr,0,size-1);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Merge: rand "<<timePassed << endl;

	arr = copyArr("rev");
	startTime = clock();
	mergeSort(arr,0,size-1);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Merge: rev "<<timePassed << endl;

	arr = copyArr("ord");
	startTime = clock();
	mergeSort(arr,0,size-1);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Merge: ord "<<timePassed << endl;




}
