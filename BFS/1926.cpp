#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int n,m,a[504][504],cnt,v[504][504],_max;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
queue<pair<int,int> > q;
int bfs(int sy,int sx)
{
	int ret=1;
	while(q.size())
	{
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if (ny<0 || nx<0|| ny>=n|| nx>=m)
				continue;
			if (v[ny][nx] || a[ny][nx]==0)
				continue;
			v[ny][nx]=1;
			q.push(pair<int,int>(ny,nx));
			ret+=bfs(ny,nx);
		}
	}
	return (ret);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (v[i][j] || a[i][j]==0)
				continue;
			cnt++;
			v[i][j]=1;
			q.push(pair<int,int>(i,j));
			_max= max(_max,bfs(i,j));
		}
	}
	cout<<cnt<<"\n";
	cout<<_max;
}