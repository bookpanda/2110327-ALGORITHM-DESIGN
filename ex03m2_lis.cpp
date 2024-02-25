#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1010][1010];
vector<int> a, b;

int lis(int ia, int ib) {
    if(ia < 0 || ib < 0) return 0;
    if(dp[ia][ib] != 0) return dp[ia][ib];

    int ans = 0;
    if(a[ia] == b[ib]) {
        ans = lis(ia-1, ib-1) + 1;
    } else {
        int la = lis(ia-1, ib);
        int lb = lis(ia, ib-1);
        ans = max(la, lb);
    }
    dp[ia][ib] = ans;

    return ans;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int in;
        cin >> in;
        a.push_back(in);
    }
    b = a;
    sort(b.begin(), b.end());

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // int ans = lis(n-1, n-1);
    cout << dp[n][n] << "\n";
}