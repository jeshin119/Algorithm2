// BOJ url ; https://www.acmicpc.net/problem/3190
#include <bits/stdc++.h>
using namespace std;
int n,a[104][104],k,l,ret,nturns,napples;
vector<pair<int,char>> turns;
vector<pair<int,int>> apples;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int line[104][104];
int go(int y,int x,char &di){
	line[y][x]=1;
	
}

int main()
{
	cin>>n;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>apples[i].first>>apples[i].second;
		napples++;
	}
	cin>>l;
	for(int i=0;i<l;i++){
		cin>>turns[i].first>>turns[i].second;
		nturns++;
	}
	while(++ret){
		for(int i=0;i<nturns;i++){
			if(turns[nturns].first==y&&turns[nturns].second==x){
				
				turns[nturns].first=-1;turns[nturns].second=-1;
				
			}

		}
		go(0,0,'D');
		if(ret==turns[i].first){
			go(0,0,turns[i].second);
		}
	}
}