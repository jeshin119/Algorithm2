#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int n,m,a[1004][1004],v[1004][1004];
int ret;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
queue<pair<int,int> > q;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if (a[i][j]==1){
				v[i][j]=1;
				q.push(pair<int,int>(i,j));
			}
		}
	}
	while(q.size()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if (ny<0||ny>=n||nx<0||nx>=m)
				continue;
			if (a[ny][nx]==-1 || v[ny][nx])
				continue;
			q.push(pair<int,int>(ny,nx));
			v[ny][nx]=v[y][x]+1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (a[i][j]== 0 && v[i][j]==0){
				cout<<-1;
				return 0;
			}
			ret=max(ret,v[i][j]);
		}
	}
	cout<<ret-1;
}