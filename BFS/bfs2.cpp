#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
using namespace std;
string s;
int n,m,ret,a[104][104],v[104][104];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
queue<pair<int,int> > q;
void bfs(int sy,int sx)
{
	while(q.size()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if (ny<0||nx<0||ny>=n||nx>=m)
				continue;
			if (v[ny][nx] || a[ny][nx]==0)
				continue;
			q.push(pair<int,int>(ny,nx));
			v[ny][nx]=v[y][x]+1;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<m;j++){
			a[i][j]=s[j]-'0';
		}
	}
	q.push(pair<int,int>(0,0));
	v[0][0]=1;
	bfs(0,0);
	cout<<v[n-1][m-1];
}