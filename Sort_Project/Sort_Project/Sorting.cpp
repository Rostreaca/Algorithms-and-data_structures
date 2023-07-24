#include<iostream>

using namespace std;

int Unsorted_array[8] = {7,5,4,2,3,1,6,8};
int arrayLength = sizeof(Unsorted_array) / sizeof(Unsorted_array[0]);

void BubbleSort(int a[])
{
	for (int i=0 ; i < arrayLength-1; i++)
	{
		int temp = 0;
		for (int j = 0; j < arrayLength-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void SelectionSort(int a[])
{
	for (int i = 0; i < arrayLength; i++)
	{
		int temp = 0;
		int min_num = a[i];
		int index = i;
		for (int j = i; j < arrayLength; j++)
		{
			if (min_num > a[j])
			{
				min_num = a[j];
				index = j;
			}
		}
		
		temp = a[i];
		a[i] = min_num;
		a[index] = temp;

	}
}

void insertionSort(int a[]) {
	int i, j, remember;

	for (i = 1; i < arrayLength; i++)
	{
		remember = a[i];
		for (j= i - 1; j>=0 && a[j]>remember ;j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = remember;
	}
}

void QuickSort(int a[],int _Left, int _Right)
{
	int Left = _Left;
	int Right = _Right;
	int pivot = a[(Left+Right)/2];
	int temp;
	
	while ( Left <= Right) // 오른쪽 값이 왼쪽 값보다 크면
	{
		while (a[Left] < pivot) Left++; //왼쪽에서부터 pivot 보다 큰 값 찾기
		while (a[Right] > pivot) Right--; // 오른쪽에서부터 pivot 보다 작은 값 찾기
		if (Left <= Right) //왼쪽에서 찾은 pivot보다 큰 값이 오른쪽에서 찾은 pivot보다 작은 값보다 왼쪽에 있다면
		{
			temp = a[Left];
			a[Left] = a[Right];
			a[Right] = temp;
			//SWAP

			Left++;
			Right--;
		}
	}

	if (_Left < Right) QuickSort(a, _Left, Right); //왼쪽 배열 재귀
	if (Left < _Right) QuickSort(a, Left, _Right); //오른쪽 배열 재귀

}

int main()
{
	for (int i = 0; i < arrayLength; i++)//before sorting
	{
		cout << Unsorted_array[i];
	}
	cout<<endl;

	cout << "정렬 방법을 선택해주세요" << endl;
	cout << "버블정렬 : 1, 선택정렬 : 2, 삽입정렬 : 3 퀵 정렬 : 4"<<endl;
	int input;
	cin >> input;
	if (input == 1) BubbleSort(Unsorted_array); //sorting
	else if (input == 2) SelectionSort(Unsorted_array); //sorting
	else if (input == 3) insertionSort(Unsorted_array); //sorting
	else if (input == 4) QuickSort(Unsorted_array, 0, arrayLength - 1); //sorting
   
	

	for (int i = 0; i < arrayLength; i++) //after sorting
	{
		cout << Unsorted_array[i];
	}
}