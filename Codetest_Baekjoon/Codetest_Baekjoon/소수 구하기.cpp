#include<iostream>

using namespace std;
int N, M;
int arr[1000001];

int main()
{
	cin >> N >> M;
	for (int i = 2; i <= M; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i * i <= M; i++)
	{
		if (arr[i] !=0 )
		{
			for (int j = i * i; j <= M; j += i)
				arr[j] = 0;
		}
	}

	for (int i = N; i <= M; i++)
	{
		if (arr[i] != 0)
		{
			cout << arr[i] <<"\n";
		}
	}

}