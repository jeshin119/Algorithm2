//#BOJ 14889 url : 
#include <bits/stdc++.h>
using namespace std;
int INF=987654321;
int n,a[24][24],visited[24],ret=INF;

int cal(vector<int>stark,vecotr<int>link){
	int s=0,l=0;
	for(int i=0;i<stark.size();i++){
		for(int j=i+1;j<stark.size();j++){
			s+=a[stark[i]][stark[j]];
		}
	}
	for(int i=0;i<link.size();i++){
		for(int j=i+1;j<link.size();j++){
			l+=a[link[i]][link[j]];
		}
	}
	return(abs(s-l));
}

int	combi(int start,vector<int> v){
	if(v.size==n/2){
		vector<int>stark;
		vector<int>link;
		for(int i=0;i<n;i++){
			if(visited[[i]])
				stark.push_back(i);
			else
				link.push_back(i);
		}
		ret = min(ret,cal(stark,link));
		return (ret);
	}
	for(int i=start+1;i<n;i++){
		v.push_back(i);
		visited[i]=1;
		combi(i,v);
		visited[i]=0;
		v.pop_back(i);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	vector<int>v;
	ret = combi(-1,v);
	cout<<ret;
}