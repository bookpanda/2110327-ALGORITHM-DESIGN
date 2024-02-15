#include<bits/stdc++.h>
using namespace std;
int n, m;
int dp[505][505];

int cook(int r, int c, vector<vector<int> > &v) {
    if(r < 0 || c < 0) return -INT_MAX;
    if(dp[r][c] != 0) return dp[r][c];
    if(r == 0 && c == 0) return v[0][0];

    int down = cook(r-1, c, v) + v[r][c];
    int right = cook(r, c-1, v) + v[r][c];
    int dr = cook(r-1, c-1, v) + 2*v[r][c];

    int ans = max(max(down, right), dr);
    // cout << "r=" << r << ", c=" << c << ", ans=" << ans << "\n";
    dp[r][c] = ans;
    return ans;
}

int main() {
    cin >> n >> m;
    vector<vector<int> > v;
    for(int i=0;i<n;i++) {
        vector<int> tmp;
        for(int j=0;j<m;j++) {
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        v.push_back(tmp);
    }

    int ans = cook(n-1, m-1, v);
    cout << ans << "\n";
}