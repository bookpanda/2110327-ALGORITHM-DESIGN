#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<string> v;
int dp[1010][1010];
int b = 0;

int cook(int r, int c) {
    if(r<0 || c<0) return 0;
    if(dp[r][c] != -1) return dp[r][c];

    int tl = cook(r-1, c-1);
    int l = cook(r, c-1);
    int t = cook(r-1, c);
    int minprev = min(min(l,t), tl);

    // cout << r << ", " << c << ": l=" << l << ", t=" << t << ", tl=" << tl << "\n";
    if(v[r][c] == '0') {
        dp[r][c] = 0;
        return 0;
    }  
    dp[r][c] = minprev + 1;
    b = max(b, minprev+1);
    return minprev+1;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
    dp[i][j] = -1;

    int ans = cook(n-1, m-1);
    cout << b << "\n";

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << dp[i][j] << " ";
    //     } cout << "\n";
    // }
}