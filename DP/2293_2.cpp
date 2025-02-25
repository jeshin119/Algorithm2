#include <stdio.h>
#include <cstring>
using namespace std;
int dp[101][10001];  
int coins[101];
int n, k;
int solve(int idx, int rem) {
    if(rem == 0) return 1; 
    if(idx == n || rem < 0) return 0; 
    if(dp[idx][rem] != -1) return dp[idx][rem]; 
    return dp[idx][rem] = solve(idx, rem - coins[idx]) + solve(idx + 1, rem);
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &coins[i]);
    } 
    memset(dp, -1, sizeof(dp)); 
    printf("%d\n", solve(0, k));
}