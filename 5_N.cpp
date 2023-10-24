// BOJ url ; https://www.acmicpc.net/problem/3190
#include <bits/stdc++.h>
using namespace std;
int n,k,l,ret,cnt;
pair<int,int>apples;
pair<int,int>turns;
int a[104][104];
int snake[104][104];
int	go(int y,int x){
	if(y<0||x<0||y>=n||x>=n)
		continue;
	for(int turn:turns){
		if(cnt ==turn){
			if(turn.second =='L')

			else if(turn.seconde =='D')
		}
	}
	for(int ap:apples){
		if(y==ap.first && x ==ap.second){
			
		}
	}
	cnt++;
}

int main()
{
	cin>>n;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>apples[i].fisrt>>apples[i].second;
	}
	cin>>l;
	for(int i=0;i<l,i++){
		cin>>turns[i].first>>turns[i].second;
	}
	while(true){
		int y=0;int x=0;
		
	}
	
}