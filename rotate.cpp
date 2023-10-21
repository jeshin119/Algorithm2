#include <bits/stdc++.h>
using namespace std;
int main(){
	//one dimentional
	//1.using rotate
	int arr[5] = {1,2,3,4,5};
	rotate(arr,arr+1,arr+5);
	for(int i=0;i<5;i++){
		printf("%d\t",arr[i]);
	}
	//2.implement

}