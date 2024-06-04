#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int n,k,from,to;
void hanoi(int n,int from, int to){
	if (n==1){
		cout<<from<<" "<<to<<'\n';
		return ;
	}
	hanoi(n-1,from,6-from-to);
	cout<<from<<" "<<to<<'\n';
	hanoi(n-1,6-from-to,to);
}
int main(){
	cin>>n;
	cout<<(1<<n)-1<<"\n";
	hanoi(n,1,3);
}