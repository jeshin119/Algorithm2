//ranked풀이. 1을 빼는 것보다 /3, /2를 이용해서 숫자를 먼저 줄이는게 최소값을 구하는 길이므로 
//일단 /3 또는 /2를 때리고 그것을 위한 -1연산을 %연산으로 대체한다.
//기가막히다 어떻게생각하냐 이런거.
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000004],n;
int f(int k){
    if (k<=1){
        return 0;
    }
    int q=f(k/3)+k%3+1;
    int w=f(k/2)+k%2+1;
    return (min(q,w));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    cout<<f(n)<<"\n";
}