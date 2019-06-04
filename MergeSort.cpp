#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
const int Max = 1000;

void Merge(std::vector<int> &Array ,int front ,int mid ,int end){
	std::vector<int> LeftSub(Array.begin() + front ,Array.begin() + mid+1),
					 RightSub(Array.begin() + mid+1 ,Array.begin() + end+1);

	LeftSub.insert(LeftSub.end() ,Max);
	RightSub.insert(RightSub.end() ,Max);

	int idxLeft = 0 ,idxRight = 0;

	for(int i = front; i <= end; i++){
		if(LeftSub[idxLeft] <= RightSub[idxRight]){
			Array[i] = LeftSub[idxLeft];
			idxLeft ++;
		}
		else{
			Array[i] = RightSub[idxRight];
			idxRight ++;
		}
	}
}
void MergeSort(std::vector<int> &array ,int front ,int end){
	if(front < end){
		int mid = (front + end)/2;
		MergeSort(array ,front ,mid);
		MergeSort(array ,mid+1 ,end);
		Merge(array ,front ,mid ,end);
	}
}

void PrintArray(std::vector<int> &array){
	for(int i = 0; i <array.size(); i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	//time used
	int start = clock();
	int arr[] = {123 ,34 ,189 ,56 ,150 ,12 ,9 ,240};
	std::vector<int> array(arr ,arr + sizeof(arr)/sizeof(int));

	std::cout << "original:\n";
	PrintArray(array);

	MergeSort(array ,0 ,7);
	std::cout << "sorted:\n";
	PrintArray(array);
	//time used
	int end = clock();
	cout<<"used time: "<<(double)(end - start)/CLOCKS_PER_SEC;
	
	return 0;
}