#include <bits/stdc++.h>
using namespace std;
int n,ret;

struct board{
	int a[24][24];

	void rotate(){
		int tmp[24][24];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				tmp[i][j]=a[n-j-1][i];
			}
		}
		memcpy(a,tmp,sizeof(a));
	}

	void go(){
		int tmp[24][24];
		for(int i=0;i<n;i++){
			int d=0,c=-1;
			for(int j=0;j<n;j++){
				if(a[i][j]==0)continue;
				if(d&&a[i][j]==tmp[i][c]){
					tmp[i][c]*=2;d=0;
				}
				else{
					tmp[i][++c]=a[i][j];d=1;
				}
			}
			for(c++;c<n;c++)tmp[i][c]=0;
		}
		memcpy(a,tmp,sizeof(a));
	};

	void get_max(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ret=max(ret,a[i][j]);
			}
		}
	};
};

void ggo(board b,int start){
	if(start==5){
		b.get_max();
		return ;
	}
	for(int i=0;i<4;i++){
		board c=b;
		c.go();
		ggo(c,start+1);
		b.rotate();
	}
}

int main(){
	cin>>n;
	board b;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>b.a[i][j];
		}
	}
	ggo(b,0);
	cout<<ret<<"\n";	
}