#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;
#define MAX 1000

void Merge(int a[] ,int front ,int end ,int mid);

void ExChangeSort(int a[] ,int sz){
	if(sz < 2)
		return;
	for(int i = 0; i < sz-1; i++){
		for (int j = i+1; j < sz; j++)
		{
			if(a[i] < a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
void swap(int *a ,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr ,int front ,int end){
	if(front < end){
		int pivot = Partition(arr ,front ,end);
		QuickSort(arr ,front ,pivot -1);
		QuickSort(arr ,pivot +1 ,end);
	}
}
void MergeSort(int a[] ,int front ,int end){
	if(front < end){
		int mid = (front +end)/2;
		MergeSort(a ,front ,end);
		MergeSort(a ,mid+1 ,end);
		Merge(a ,front ,end ,mid);
	}
}
void Merge(int a[] ,int front ,int end ,int mid){
	int n1 = mid -front +1;
	int n2 = end - mid;
	int* Left = new int[n1];
	int* Right = new int[n2];

	for(int i = 0; i < n1; i++){
		Left[i] = a[front +i];
	}
	for(int i = 0; i < n2; i++){
		Right[i] = a[i + mid +1];
	}
	Left[n1] = 2147483647;
	Right[n2] = 2147483647;
	int i = 0, j = 0;
	for(int k = front; k <= end; k++){
		if(Left[i] <= Right[j]){
			a[k] = Left[i];
			i++;
		}else{
			a[k] = Right[j];
			j++;
		}
	}
}
int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	//used time
	int start = clock();
	//input random num
	int num;
	int a[10000] = {0};
	cout<<"Input random num: ";
	cin>> num;
	cout<<"Output num: ";
	for(unsigned int i = 0; i < num; i++){
		a[i] = rand()%MAX;
		cout<< a[i] <<" ";
	}
	cout<<endl;
	//ExChangeSort
	cout<<"ExChangeSort:";
	ExChangeSort(a ,num);
	for(unsigned int i = 0; i < num; i++){
		cout<< a[i] <<" ";
	}
	cout<<endl;
	//QuickSort
	cout<<"QuickSort:";
	QuickSort(a  ,0 ,num -1);
	for(unsigned int i = 0; i < num; i++){
		cout<< a[i] <<" ";
	}
	cout<<endl;
	//MergeSort
	cout<<"MergeSort:";
	MergeSort(a ,0 ,num -1);
	for(unsigned int i = 0; i < num; i++){
		cout<< a[i] <<" ";
	}
	cout<<endl;
	//used time
	int end = clock();
	cout<<"used time: "<<(double)(end - start)/CLOCKS_PER_SEC;
	
	return 0;
}