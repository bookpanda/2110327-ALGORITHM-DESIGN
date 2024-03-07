#include<bits/stdc++.h>
using namespace std;
string a, b;
int dp[505][505];

int lcs(int ia, int ib) {
    if(ia < 0 || ib < 0) return 0;
    if(dp[ia][ib] != -1) return dp[ia][ib];

    int ans;
    if(a[ia] == b[ib]) {
        ans = lcs(ia-1, ib-1) + 1;
    } else {
        int f1 = lcs(ia-1, ib);
        int f2 = lcs(ia, ib-1);
        ans = max(f1, f2);
    }
    dp[ia][ib] = ans;

    return ans;
}

int main() {
    cin >> a >> b;
    int lena = a.size();
    int lenb = b.size();
    for(int i=0;i<=lena;i++)
    for(int j=0;j<=lenb;j++)
    dp[i][j] = -1;

    int ans = lcs(lena-1, lenb-1);
    cout << ans << "\n";
}