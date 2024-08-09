#include <iostream>
#include <vector>
using namespace std;
int n,ret,cnt,a[15];
bool ok(int l){
	for(int i=0;i<l;i++){
		if (a[i] == a[l])
			return false;
		if (abs(a[l]-a[i])==l-i)
			return false;
	}
	return true;
}
void q(int y){
	if(y==n)
		ret++;
	for(int i=0;i<n;i++){
		a[y]=i;
		if (ok(y))
			q(y+1);
	}
}
int main(){
	cin>>n;
	q(0);
	cout<<ret;
}