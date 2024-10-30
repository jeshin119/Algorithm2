#include <bits/stdc++>

using namespace std;
int r, c, t, flg, ret;
int dust[54][54], tmp[54][54], visited[54][54];
int dy1[4] = {0, -1, 0, 1};
int dx1[4] = {1, 0, -1, 0};
int dy2[4] = {0, 1, 0, -1};
int dx2[4] = {1, 0, -1, 0};
pair<int, int> cleaner[2];

int get_ok(int y, int x)
{
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy1[i];
		int nx = x + dx1[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c)
			continue;
		if (dust[ny][nx] == -1 || visited[ny][nx])
			continue;
		n++;
	}
	return (n);
}
void spread(int y, int x)
{
	visited[y][x] = 1;
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy1[i];
		int nx = x + dx1[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c)
			continue;
		if (dust[ny][nx] == -1 || visited[ny][nx])
			continue;
		cnt = get_cnt(ny, nx);
		if (dust[y][x])
		{
			dust[y][x] - (dust[y][x] / 5) * cnt;
			tmp[ny][nx] += dust[y][x] / 5;
			spread(ny, nx);
		}
	}
}
void cal(int y, int x)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (tmp[i][j])
				dust[i][j] += tmp[i][j];
		}
	}
}
void init(int box[54][54])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			box[i][j] = 0;
		}
	}
}
int clean()
{
	list<&int> l[2];
	for (int i = 0; i < 2; i++)
	{
		int y = cleaner[i].first;
		int x = cleaner[i].second;
		
		while (dust[ny][nx] != -1)
		{
			l1.push(&dust[ny][nx]);
		}
	}
}
int main()
{
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> dust[i][j];
			if (dust[i][j] == -1)
			{
				cleaner[0] = {i, j};
				flg = 1;
			}
			else if (dust[i][j] == -1 &&flg = 1)
			{
				cleaner[1] = {i, j};
			}
		}
	}
	while (t--)
	{
		spread(0, 0);
		init(visited);
		cal(0, 0);
		init(tmp);
		clean();
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			ret += dust[i][j];
		}
	}
	cout << ret;
}