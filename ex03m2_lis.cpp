#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1010][1010];
vector<int> v, v2;

int lis(int ia, int ib) {
    if(ia < 0 || ib < 0) return 0;
    if(dp[ia][ib] != -1) return dp[ia][ib];

    int ans = 0;
    if(v[ia] == v2[ib]) {
        ans = 1 + lis(ia-1, ib-1);
    } else {
        ans = max(lis(ia-1, ib), lis(ia, ib-1));
    }

    dp[ia][ib] = ans;
    return ans;
}

int main() {
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
        dp[i][j] = -1;
    v2 = v;
    sort(v2.begin(), v2.end());
    int ans = lis(n-1, n-1);
    cout << ans << "\n";
}