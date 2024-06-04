#include <iostream>
#include <algorithm>
using namespace std;
int n,r,c,th;
int z(int here,int row,int col){
	if (here==0){
		return 0;
	}
	int half =1<<(here-1);
	if (row<half && col <half)
		return z(here-1,row,col);
	else if (row<half && col>=half)
		return (half*half+z(here-1,row,col-half));
	else if (row>=half && col<half)
		return (half*half*2 +z(here-1,row-half,col));
	return (half*half*3 +z(here-1,row-half,col-half));
}
int main(){
	cin>>n>>r>>c;
	cout <<z(n,r,c);
}