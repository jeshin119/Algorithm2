#include <bits/stdc++.h>
using namespace std;
int ret,n;
struct board{
	int	a[24][24];

	void _rotate(){
		int tmp[24][24];
		int n=a.size();
		int m=a[0].size();
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				tmp[i][j]=a[n-j-1][i];
			}
		}
		memcpy(a,tmp,sizeof(a));
	}

	void _move(){
		int tmp[24][24];
		for(int i=0;i<n;i++){
			int c=-1,d=0;
			for(int j=0;j<n;j++){
				if(a[i][j]==0)continue;
				if(d && a[i][j]==tmp[i][c]){
					tmp[i][c] *=2;d=0;
				}
				else{
					tmp[i][++c]=a[i][j];d=1;
				}
			}
		}
	}

	int	get_max(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ret=max(ret,a[i][j]);
			}
		}
	}
}

void go(borad c,int hear){
	if(hear==5){
		c.get_max();
		return ;
	}
	for(int i=0;i<4;i++){
		borad d;
		d._move();
		go(d,hear+1);
		c._rotate();
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	borad c;
	go(c,0);
	cout<<ret<<"\n";
}