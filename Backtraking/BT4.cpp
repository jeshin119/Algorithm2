//BOJ 15651 N과M(3)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int>v;
void g(int start){
	v.push_back(start);
	if(v.size()==m){
		for(auto i:v){
			cout<<i<<" ";
		}
		cout<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		g(i);
		v.pop_back();
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		v.clear();
		g(i);
	}
}