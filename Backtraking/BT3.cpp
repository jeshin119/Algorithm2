//BOJ 15650 N과M(2)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int>v;
void p(int start){
	v.push_back(start);
	if (v.size()==m)
	{
		for(auto i:v){
			cout<<i<<" ";
		}
		cout<<"\n";
		return ;
	}
	for(int i=start+1;i<=n;i++){
		p(i);
		v.pop_back();
	}

}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n-m+1;i++){
		v.clear();
		p(i);
	}
}

