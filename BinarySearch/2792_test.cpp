#include <bits/stdc++.h>
using namespace std;
int n, m, a[300004], l = 1, r, ret;

bool check(int jelas) {
    int num = 0;
    for (int i = 0; i < m; i++) {
        num += a[i] / jelas;
        if (a[i] % jelas) num++;
    }
    return (num <= n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }

    while (l < r) {
        int jelas = (l + r) / 2;
        if (check(jelas)) {
            r = jelas;  // mid 포함 (탐색 범위 유지)
        } else {
            l = jelas + 1;
        }
    }

    cout << l << "\n";  // while 종료 후 l == r이므로 l 출력
}
