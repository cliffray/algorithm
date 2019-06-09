#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <algorithm> 
using namespace std;
#define MAX 100000
#define FREQ 5
#define ARRAY_LENGintHS {10, 100, 1000, 10000, 100000}

void Merge(int a[], int front, int end, int mid);

void ExChangeSort(int a[], int sz) {
	if (sz < 2)
		return;
	for (int i = 0; i < sz - 1; i++) {
		for (int j = i + 1; j < sz; j++)
		{
			if (a[i] < a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

/*void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int* arr, int front, int end) {
	int pivot = arr[end];
	int i = front - 1;
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
void QuickSort(int* arr, int front, int end) {
	if (front < end) {
		int pivot = Partition(arr, front, end);
		QuickSort(arr, front, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
}*/


void quick_sort_recursive(int arr[], int start, int end) {
	if (start >= end)
		return;
	int mid = arr[end];
	int left = start, right = end - 1;
	while (left < right) { 
		while (arr[left] < mid && left < right)
			left++;
		while (arr[right] >= mid && left < right)
			right--;
		std::swap(arr[left], arr[right]);
	}
	if (arr[left] >= arr[end])
		std::swap(arr[left], arr[end]);
	else
		left++;
	quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}
void QuickSort(int arr[], int len) {
	quick_sort_recursive(arr, 0, len - 1);
}

void InsertionSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		int key = arr[i];
		int j = i - 1;
		while ((j >= 0) && (key < arr[j])) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void CountSort(int arr[], int len)
{
	int* output = new int[len];
	int count[MAX] = {0};
	memset(count, 0, sizeof(count));

	for (int i = 0; i < len; ++i)
		++count[arr[i]];
	for (int i = 1; i < MAX; ++i)
		count[i] += count[i - 1];
	for (int i = 0; i < len; ++i)
	{
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}
	for (int i = 0;  i < len; ++i)
		arr[i] = output[i];
	delete[] output;
}

/*void MergeSort(int a[], int front, int end) {
	if (front < end) {
		int mid = (front + end) / 2;
		MergeSort(a, front, mid);
		MergeSort(a, mid + 1, end);
		Merge(a, front, end, mid);
	}
}
void Merge(int a[], int front, int end, int mid) {
	int n1 = mid - front + 1;
	int n2 = end - mid;
	int* Left = new int[n1];
	int* Right = new int[n2];


	for (int i = 0; i < n1; i++) {
		Left[i] = a[front + i];
	}
	for (int i = 0; i < n2; i++) {
		Right[i] = a[i + mid + 1];
	}
	Left[n1] = 2147483647;
	Right[n2] = 2147483647;
	int i = 0, j = 0;
	for (int k = front; k <= end; k++) {
		if (Left[i] <= Right[j]) {
			a[k] = Left[i];
			i++;
		}
		else {
			a[k] = Right[j];
			j++;
		}
	}
}*/

void MergeSort(int arr[], int len) {
	int* a = arr;
	int* b = new int[len];
	for (int seg = 1; seg < len; seg += seg) {
		for (int start = 0; start < len; start += seg + seg) {
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		int* temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
}

void fullArray(int a[], int num) {
	for (int i = 0; i < num; i++) {
		a[i] = rand() % MAX;
		// cout<< a[i] <<" ";
	}
}

int main(int argc, char const* argv[])
{
	srand((unsigned)time(NULL));
	//used time
	double start, end, average = 0;
	//input random num

	int a[MAX] = { 0 };

	//ExChangeSort
	cout << "ExChangeSort:" << endl;
	for (int num : ARRAY_LENGintHS) {
		fullArray(a, num);
		start = clock();
		ExChangeSort(a, num);
		end = clock();
		printf("執行時間: %lf\n", (end - start) / CLOCKS_PER_SEC);
		average += end - start;
	}
	printf("平均時間: %lf\n", average / CLOCKS_PER_SEC / FREQ);
	cout << endl;

	//QuickSort
	average = 0;
	cout << "QuickSort:" << endl;
	for (int num : ARRAY_LENGintHS) {
		fullArray(a, num);
		start = clock();
		QuickSort(a, num);
		end = clock();
		printf("執行時間: %lf\n", (end - start) / CLOCKS_PER_SEC);
		average += end - start;
	}
	printf("平均時間: %lf\n", average / CLOCKS_PER_SEC / FREQ);
	cout << endl;

	//MergeSort
	average = 0;
	cout << "MergeSort:" << endl;
	for (int num : ARRAY_LENGintHS) {
		fullArray(a, num);
		start = clock();
		MergeSort(a,num);
		end = clock();
		printf("執行時間: %lf\n", (end - start) / CLOCKS_PER_SEC);
		average += end - start;
	}
	printf("平均時間: %lf\n", average / CLOCKS_PER_SEC / FREQ);
	cout << endl;


	//InsertionSort
	average = 0;
	cout << "InsertionSort:" << endl;
	for (int num : ARRAY_LENGintHS) {
		fullArray(a, num);
		start = clock();
		InsertionSort(a, num);
		end = clock();
		printf("執行時間: %lf\n", (end - start) / CLOCKS_PER_SEC);
		average += end - start;
	}
	printf("平均時間: %lf\n", average / CLOCKS_PER_SEC / FREQ);
	cout << endl;


	//CountSort
	average = 0;
	cout << "CountSort:" << endl;
	for (int num : ARRAY_LENGintHS) {
		fullArray(a, num);
		start = clock();
		CountSort(a, num);
		end = clock();
		printf("執行時間: %lf\n", (end - start) / CLOCKS_PER_SEC);
		average += end - start;
	}
	printf("平均時間: %lf\n", average / CLOCKS_PER_SEC / FREQ);
	cout << endl;


	return 0;
}