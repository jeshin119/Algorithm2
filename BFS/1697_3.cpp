//개쉬움
#include <bits/stdc++.h>
using namespace std;
int n,k,visited[100004];
queue<int> q;
int main(){
    cin>>n>>k;
    q.push(n);
    visited[n]=1;
    while (q.size()){
        int here=q.front();
        q.pop();
        if (here == k){
            cout<<visited[here]-1;
            return 0;
        }
        for(int i=0;i<3;i++){
            int there;
            if (i==0)
                there=here+1;
            else if (i==1)
                there = here-1;
            else
                there=here*2;
            if (there<0 ||there>100000)
                continue;
            if (visited[there])
                continue;
            q.push(there);
            visited[there]=visited[here]+1;
        }
    }
}