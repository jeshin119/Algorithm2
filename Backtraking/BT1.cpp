#include <vector>
#include <iostream>
using namespace std;
int n,m,start;
vector<int>v;
bool b[10];
void BT(int start){
	if (v.size()==m){
		for(int a : v)
			cout <<a<<" ";
		cout<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		if (b[i]==0){
			v.push_back(i);
			b[i]=1;
			BT(i);
			b[i]=0;
			v.pop_back();
		}
	}
}
int main(){
	cin>>n>>m;
	BT(0);
}