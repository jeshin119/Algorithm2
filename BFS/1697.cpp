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
	if (n>k){
		cout<<n-k;
		return 0;
	}
	q.push(n);
	v[n]=1;
	while(q.size()){
		int here=q.front();
		q.pop();
		for(int i=0;i<3;i++){
			int there;
			if (i==0)
				there=here+1;
			if (i==1)
				there=here-1;
			if (i==2)
				there=here*2;
			if (there<0 || there>2*k)
				continue;
			if (v[there])
				continue;
			v[there]=v[here]+1;
			q.push(there);
		}
	}
	cout<<v[k]-1;
}