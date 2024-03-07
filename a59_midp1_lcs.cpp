#include<bits/stdc++.h>
using namespace std;
string a, b;
pair<int, string> dp[1005][1005];

pair<int, string> lcs(int ia, int ib) {
    if(ia < 0 || ib < 0) return {0, ""};
    if(dp[ia][ib].first != -1) return dp[ia][ib];

    pair<int, string> ans;
    if(a[ia] == b[ib]) {
        ans = lcs(ia-1, ib-1);
        ans.first += 1;
        ans.second += a[ia];
    } else {
        pair<int, string> f1 = lcs(ia-1, ib);
        pair<int, string> f2 = lcs(ia, ib-1);
        ans = max(f1, f2);
    }
    dp[ia][ib] = ans;

    return ans;
}

int main() {
    int lena, lenb;
    cin >> lena >> lenb;
    cin >> a >> b;
    for(int i=0;i<=lena;i++)
    for(int j=0;j<=lenb;j++) {
        int a;
        cin >> a;
    }
    for(int i=0;i<=lena;i++)
    for(int j=0;j<=lenb;j++)
    dp[i][j].first = -1;

    pair<int, string> ans = lcs(lena-1, lenb-1);
    cout << ans.second << "\n";
}