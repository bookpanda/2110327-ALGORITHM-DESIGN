#include<bits/stdc++.h>
using namespace std;
string a, b;
int dp[510][510];

int lcs(int ia, int ib) {
    if(ia < 0 || ib < 0) return 0;
    if(dp[ia][ib] != 0) return dp[ia][ib];

    int ans;
    if(a[ia] == b[ib]) {
        ans = lcs(ia-1, ib-1) + 1;
    } else {
        int sa = lcs(ia, ib-1);
        int sb = lcs(ia-1, ib);
        ans = max(sa, sb);
    }

    dp[ia][ib] = ans;
    return ans;
}

int main() {
    cin >> a >> b;
    int la = a.size();
    int lb = b.size();
    int ans = lcs(la-1, lb-1);
    cout << ans << "\n";
}