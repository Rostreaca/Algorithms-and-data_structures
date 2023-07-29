#include<iostream>

using namespace std;

int Unsorted_array[8] = { 7,5,4,2,3,1,6,8 };
int arrayLength = sizeof(Unsorted_array) / sizeof(Unsorted_array[0]);
int Merged_array[8];

void BubbleSort(int a[])
{
	for (int i = 0; i < arrayLength - 1; i++)
	{
		int temp = 0;
		for (int j = 0; j < arrayLength - 1; j++)
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
		for (j = i - 1; j >= 0 && a[j] > remember; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = remember;
	}
}

void QuickSort(int a[], int _Left, int _Right)
{
	int Left = _Left;
	int Right = _Right;
	int pivot = a[(Left + Right) / 2];
	int temp;

	while (Left <= Right) // 오른쪽 값이 왼쪽 값보다 크면
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


void MergeSort(int a[], int start, int end)
{
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	MergeSort(a, start, mid);
	MergeSort(a, mid + 1, end);

	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end)
	{
		if (a[i] > a[j])
		{
			Merged_array[k++] = a[j++];
		}
		else
		{
			Merged_array[k++] = a[i++];
		}
	}

	if (i > mid)
	{
		while (j <= end)
		{
			Merged_array[k++] = a[j++];
		}
	}
	else
	{
		while (i <= mid)
		{
			Merged_array[k++] = a[i++];
		}
	}
	for (int n = start; n <= end; n++)
	{
		a[n] = Merged_array[n];
	}

}

void heapify(int a[], int n, int i)
{
	int root = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	//left 혹은 right 값이 배열의 범위를 벗어나지 않으면서 가장 큰 값 찾기
	if (left < n && a[left] > a[root]) root = left; //왼쪽 노드가 i값 보다 큰 값
	if (right <n && a[right] > a[root]) root = right; //오른쪽 노드가 i값 보다 큰 값

	int temp;
	if (root != i) //i가 가장 큰 값이 아니면
	{
		temp = a[i];
		a[i] = a[root];
		a[root] = temp; // 가장 큰 수와를 루트노드의 위치를 교체(swap(a[i],a[root]))
		heapify(a, n, root); //재귀를 반복하면서 최대 힙 트리가 생성됨
	}
}

void HeapSort(int a[], int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		heapify(a, n, i); //부모 노드가 자식 노드보다 큰 최대 힙 트리 생성
	}

	int temp;
	
	for (int i = n - 1; i >= 0; i--)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp; //배열의 마지막 인덱스 값과 0번째 인덱스 값을 교체해줌(swap(a[0],a[i]))

		heapify(a, i, 0); //마지막 인덱스를 제외하고 최댓값(루트 노드) 탐색 및 재설정
	}
}

int main()
{
	for (int i = 0; i < arrayLength; i++)//before sorting
	{
		cout << Unsorted_array[i];
	}
	cout << endl;

	cout << "정렬 방법을 선택해주세요" << endl;
	cout << "버블정렬 : 1, 선택정렬 : 2, 삽입정렬 : 3 퀵 정렬 : 4 병합 정렬 : 5 힙 정렬 : 6" << endl;
	int input;
	cin >> input;
	if (input == 1) BubbleSort(Unsorted_array); //sorting
	else if (input == 2) SelectionSort(Unsorted_array); //sorting
	else if (input == 3) insertionSort(Unsorted_array); //sorting
	else if (input == 4) QuickSort(Unsorted_array, 0, arrayLength - 1); //sorting
	else if (input == 5) MergeSort(Unsorted_array, 0, arrayLength - 1); //sorting
	else if (input == 6) HeapSort(Unsorted_array, arrayLength); //sorting


	for (int i = 0; i < arrayLength; i++) //after sorting
	{
		cout << Unsorted_array[i];
	}
}