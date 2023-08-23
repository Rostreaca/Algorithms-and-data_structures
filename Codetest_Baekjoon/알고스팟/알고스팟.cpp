#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dist[101][101];
int maze[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
queue<pair<int, int>> que;

int n, m;

int main()
{
	cin >> n >> m;

	char num;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			maze[i][j] = num - '0';
			dist[i][j] = 100000;
		}
	}

	dist[0][0] = 0;
	que.push(make_pair(0, 0));

	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

			if (maze[nx][ny] == 1)
			{
				if (dist[nx][ny] > dist[x][y] + 1)
				{
					dist[nx][ny] = dist[x][y] + 1;
					que.push(make_pair(nx, ny));
				}
			}
			else
			{
				if (dist[nx][ny] > dist[x][y])
				{
					dist[nx][ny] = dist[x][y];
					que.push(make_pair(nx, ny));
				}
			}
		}

	}

	cout << dist[m - 1][n - 1];

}