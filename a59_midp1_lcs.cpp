#include<bits/stdc++.h>
using namespace std;
int la, lb;
string a, b;
pair<int, string> dp[1010][1010];

pair<int, string> lcs(int ia, int ib) {
    if(ia < 0 || ib < 0) return {0, ""};
    if(dp[ia][ib].first != 0) return dp[ia][ib];

    pair<int, string> ans;
    if(a[ia] == b[ib]) {
        ans = lcs(ia-1, ib-1);
        ans.first++;
        ans.second += a[ia];
    } else {
        pair<int, string> fa = lcs(ia-1, ib);
        pair<int, string> fb = lcs(ia, ib-1);
        ans = max(fa, fb);
    }

    dp[ia][ib] = ans;
    return ans;
}

int main() {
    cin >> la >> lb;
    cin >> a >> b;
    for(int i=0;i<=la;i++) {
        for(int j=0;j<=lb;j++) {
            int x;
            cin >> x;
        }
    }

    pair<int, string> ans = lcs(la-1, lb-1);
    // cout << ans.first << "\n";
    cout << ans.second << "\n";
}