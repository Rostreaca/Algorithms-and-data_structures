#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

int n, m;
vector<int> user[101];
bool visited[101];
int bacon[101];

int bfs_kevin(int x)
{
	for (int i = 0; i < 101; i++)
	{
		bacon[i] = 1;
		visited[i] = false;
	}

	queue<int> q;

	q.push(x);
	visited[x] = true;

	bacon[x] = 0;

	int result = 0;
	while (!q.empty())
	{
		int human = q.front();
		int last_bacon = bacon[human];
		q.pop();
		for (int i = 0; i < user[human].size(); i++)
		{
			int y = user[human][i];
			if (!visited[y])
			{
				bacon[y] = last_bacon + 1;
				result += bacon[y];
				q.push(y);
				visited[y] = true;
			}
		}
	}

	return result;
}

int main()
{

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;
			user[a].push_back(b);
			user[b].push_back(a);
		}
		break;
	}

	int answer = 10000000;

	int answer_num = 101;

	for (int i = 1; i < n; i++)
	{
		if (bfs_kevin(i) < answer)
		{
			answer = bfs_kevin(i);
			answer_num = i;
		}
	}
	cout << answer_num;
}