#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
using namespace std;
int r,c,ret=1234567890;
int vf[1004][1004], vj[1004][1004];
char map[1004][1004];
string s;
queue<pair<int,int> > fire;
queue<pair<int,int> > jihun;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		cin>>s;
		for(int j=0;j<c;j++){
			map[i][j]=s[j];
			if (s[j]=='F'){
				fire.push(pair<int,int>(i,j));
				vf[i][j]=1;
			}
			if (s[j]=='J'){
				jihun.push(pair<int,int>(i,j));
				vj[i][j]=1;
			}
			if (s[j]=='#'){
				vj[i][j]=-1;
				vf[i][j]=-1;
			}
		}
	}
	while(fire.size()){
		int y=fire.front().first;
		int x=fire.front().second;
		fire.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if (ny<0||ny>=r||nx<0||nx>=c)
				continue;
			if (map[ny][nx]=='#' || vf[ny][nx])
				continue;
			vf[ny][nx]=vf[y][x]+1;
			fire.push(pair<int,int>(ny,nx));
		}
	}
	while(jihun.size()){
		int y=jihun.front().first;
		int x=jihun.front().second;
		jihun.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if (ny<0||ny>=r||nx<0||nx>=c){
				continue;
			}
			if (map[ny][nx]=='#' || vj[ny][nx])
				continue;
			vj[ny][nx]=vj[y][x]+1;
			jihun.push(pair<int,int>(ny,nx));
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if ((j!=0 && j!=c-1) && (i!=0 && i!=r-1))
				continue;
			if (vj[i][j]<1)
				continue;
			if (vf[i][j]==0 || (vj[i][j] < vf[i][j])){
				ret=min(ret,vj[i][j]);

			}
		}
	}
	if (ret==0 || ret == 1234567890)
		cout<<"IMPOSSIBLE";
	else
		cout<<ret;
}