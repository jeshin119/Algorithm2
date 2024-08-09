#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int n,l,ret;
deque<int> dq;
deque<int> a;
int main(){
	cin>>n>>l;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
	}
	
	for(int i=0;i<l;i++){
		if (a[i+l] == *a.end())
			break;
		
	}

}