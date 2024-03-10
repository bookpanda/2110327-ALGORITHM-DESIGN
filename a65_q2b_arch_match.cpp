#include<bits/stdc++.h>
using namespace std;
int n, dp[505][505];
vector<int> v;

int cook(int st, int ed) {
    if(st >= ed) return 0;
    if(st+1 == ed) return max(v[st] * v[ed], 0);
    if(dp[st][ed] != -1) return dp[st][ed];

    int ans = 0;
    for(int i=st+1;i<=ed;i++) {
        int musubi = max(v[st] * v[i], 0);
        ans = max(ans, musubi + cook(st+1, i-1) + cook(i+1, ed));
        ans = max(ans, cook(st+1, i) + cook(i+1, ed));
    }

    dp[st][ed] = ans;
    // cout << "dp[" << st << "][" << ed << "] = " << dp[st][ed] << "\n";
    return ans;
}

int main() {
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) 
    for(int j=0;j<n;j++)
        dp[i][j] = -1;

    int ans = cook(0, n-1);
    cout << max(ans, 0) << "\n";
}