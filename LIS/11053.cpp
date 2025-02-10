//BOJ 11053 가장긴수열.
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[1004],cnt[1004],max_value;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if (a[j]<a[i] && cnt[j]>=cnt[i]){
				cnt[i]=cnt[j]+1;
				max_value = max(cnt[i],max_value);
			}
		}
	}
	cout<<max_value+1;
}