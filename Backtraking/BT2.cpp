#include <iostream>
#include <vector>
using namespace std;
int a[15][15],n,ret;
int dy[4]={1,0,-1,0};
int dx[4]={0,-1,0,1};
int	q(int y,int x){
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
			continue;
		if (ny == y || nx == x)
			continue;
		if (ny == nx || ny == -nx)
			continue;
		q(ny,nx);
	}
	return 1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			q(i,j);
		}
	}
}