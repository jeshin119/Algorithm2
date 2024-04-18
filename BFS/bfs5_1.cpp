#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <initializer_list>
using namespace std;
int n,k,v[200008];
queue<int> q;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	q.push(n);
	v[n]=1;
	while(!q.empty()){
		int here=q.front();q.pop();
		for(int nxt:{here-1, here+1, here*2}){
			if (nxt<0 || nxt>100000)
				continue;
			if (v[nxt])
				continue;
			v[nxt]=v[here]+1;
			q.push(nxt);
		}
	}
	cout<<v[k]-1;
}