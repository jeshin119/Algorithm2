#include <bits/stdc++.h>
using namespace std;
#define time t
int n,k,l,a[104][104],time,di,y,x,visited[104][104],idx;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
vector<pair<int,int>>_time;
deque<pair<int,int>>snake;
int main(){
	cin>>n>>k;
	for(int i=0;i<k;i++){
		cin>>y>>x;
		a[--y][--x]++;
	}
	cin>>l;
	for(int i=0;i<l;i++){
		int tmp1;char tmp2;
		cin>>tmp1>>tmp2;
		if(tmp2=='D')
			_time.push_back({tmp1,1});
		else
			_time.push_back({tmp1,3});
	}
	snake.push_back({0,0});
	while(snake.size()){
		time++;
		tie(y,x)=snake.front();
		int ny=y+dy[di];
		int nx=x+dx[di];
		if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx])break;
		if(!a[ny][nx]){
			visited[snake.back().first][snake.back().second]=0;
			snake.pop_back();
		}
		else
			a[ny][nx]=0;
		visited[ny][nx]=1;
		snake.push_front({ny,nx});
		if(time==_time[idx].first){
			di=(di+_time[idx].second)%4;
			idx++;
		}
	
	}
	cout<<time<<"\n";
}