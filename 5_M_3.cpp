#include <bits/stdc++.h>
int n,ret;
struct borad{
	int a[24][24];
	int rotate(){
		int tmp[24][24];
		int p=a.size();
		int q=a[0].size();
		for(int i=0;i<q;i++){
			for(int j=0;j<p;j++){
				tmp[i][j]=a[n-j-1][i];
			}
		}
		memcpy(tmp,a,sizeof(a));
	}

	int go(){
		int n=a.size();
		int m=a[0].size();
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
		}
		memcpy(tmp,a,sizeof(a));
	}

	int get_max(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ret=max(ret,a[i][j]);
			}
		}
	}
}

int ggo(borad b,int start){
	if(start==5){
		ret=b.get_max();
		return ;
	}
	for(int i=0;i<4;i++){
		borad c=b;
		b.go();
		ggo(c,start+1);
		c.rotate();
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