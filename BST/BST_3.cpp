#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ret;
int n,k;
int main(){
    cin>>n>>k;
    vector<pair<int,int>>jul(n);
    for(int i=0;i<n;i++){
        cin>>jul[i].first>>jul[i].second;
    }
    sort(jul.begin(),jul.end());
    vector<int>bag(k);
    for(int i=0;i<k;i++){
        cin>>bag[i];
    }
    sort(bag.begin(),bag.end());
    priority_queue<int>pq;
    int j=0;
    for(int i=0;i<k;i++){
        while(j<n && jul[j].first<=bag[i])
            pq.push(jul[j++].second);
        if (pq.size()){
            ret+=pq.top();pq.pop();
        }
    }
    cout<<ret;
}