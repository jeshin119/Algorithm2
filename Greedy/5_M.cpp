//#BOJ 12100, url : https://www.acmicpc.net/problem/12100
#include <bits/stdc++.h>
int n, a[24][24];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void go(int &arr[][],int cnt){
}
int check(int &arr[][])
{
	int ret=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ret+=arr[i][j];
		}
	}
	return (ret);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int cnt = 5;
	while(cnt--){
		int tmp[24][24] = a;
		for(int i=0;i<4;i++){
			
		}
	}
}