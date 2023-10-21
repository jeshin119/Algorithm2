#include <bits/stdc++.h>
using namespace std;
int main(){
	//one dimentional
	//1.using rotate
<<<<<<< HEAD
	int arr1[5] = {1,2,3,4,5};
=======
	int arr[5] = {1,2,3,4,5};
>>>>>>> d820128bafa75fef9d74fd19b8a8b5a905dbd6e6
	rotate(arr,arr+1,arr+5);
	for(int i=0;i<5;i++){
		printf("%d\t",arr[i]);
	}
<<<<<<< HEAD
	cout<<"\n";
	//2.implement
	int arr2[5] = {1,2,3,4,5};
	int tmp=arr2[0];
	for(int i=0;i<3;i++){
		arr2[i+1] = arr2[i];
	}
	arr[4] = tmp;
	for(int i:arr2){
		cout<<i<<"\t";
	}
	cout<<"\n";
	//two dimentional
	//1.left ninety degree
	vector v1[][]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int n=v1.size();
	int m=v1[0].size();
	vector ret1[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			ret1[i][j]=v1[j][m-1-i];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<ret1[i][j];
		}
		cout<<"\n";
	}
	//2.right ninety degree
	vector v2[][]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int n=v2.size();
	int m=v2[0].size();
	vector ret2[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			ret1[i][j]=v1[n-1-j][i];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<ret1[i][j];
		}
		cout<<"\n";
	}
=======
	//2.implement

>>>>>>> d820128bafa75fef9d74fd19b8a8b5a905dbd6e6
}