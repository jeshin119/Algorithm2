#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1004],n,prev_arr[1004],cnt[1004],max_idx;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	fill(cnt,cnt+1004,1);
	for(int i=0;i<n;i++){
		int prev_flg=-1;
		for(int j=0;j<i;j++){
			if (a[j]<a[i] && cnt[j]>=cnt[i]){
				cnt[i]=cnt[j]+1;
				if (cnt[max_idx]<cnt[i])
					max_idx=i;
				prev_flg=j;
			}
		}
		prev_arr[i]=prev_flg;
	}
	cout<<cnt[max_idx]<<"\n";
	int here = max_idx;
	vector<int>v;
	while(here >= 0 && a[here]){
		v.push_back(a[here]);
		here=prev_arr[here];
	}
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i]<<" ";
	}
}