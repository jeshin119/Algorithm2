#include <bits/stdc++.h>
using namespace std;
int main(){
	//one dimentional
	//1.using rotate
	int arr1[5] = {1,2,3,4,5};
	rotate(arr1,arr1+1,arr1+5);
	for(int i=0;i<5;i++){
		printf("%d\t",arr1[i]);
	}
	cout<<"\n";

	//2.implement
	int arr2[5] = {1,2,3,4,5};
	int tmp[5];
	for(int i=0;i<5;i++){
		tmp[i]=arr2[i];
	}
	for(int i=0;i<4;i++){
		arr2[i+1]=tmp[i];
	}
	arr2[0]=tmp[4];
	
	// for(int i=0;i<3;i++){
	// 	arr2[i+1] = arr2[i];
	// }//this has near memory overlap problem.
	for(int i:arr2){
		cout<<i<<"\t";
	}
	cout<<"\n";

	//two dimentional
	//1.left ninety degree
	vector<vector<int>> v1={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int n1=v1.size();
	int m1=v1[0].size();
	vector<vector<int>> ret1(m1,vector<int>(n1,0));
	for(int i=0;i<m1;i++){
		for(int j=0;j<n1;j++){
			ret1[i][j]=v1[j][m1-1-i];
		}
	}
	for(int i=0;i<m1;i++){
		for(int j=0;j<n1;j++){
			cout<<" "<<ret1[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";
	//2.right ninety degree
	vector<vector<int>> v2={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int n2=v2.size();
	int m2=v2[0].size();
	vector<vector<int>> ret2(n2,vector<int>(m2,0));
	for(int i=0;i<m2;i++){
		for(int j=0;j<n2;j++){
			ret1[i][j]=v1[n2-1-j][i];
		}
	}
	for(int i=0;i<m2;i++){
		for(int j=0;j<n2;j++){
			cout<<" "<<ret1[i][j];
		}
		cout<<"\n";
	}
}