#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v, vs;
int dp[1005][1005];

int lis(int iv, int ivs) {
    if(iv < 0 || ivs < 0) return 0;
    if(dp[iv][ivs] != -1) return dp[iv][ivs];

    int ans;
    if(v[iv] == vs[ivs]) {
        ans = lis(iv-1, ivs-1) + 1;
    } else {
        int f1 = lis(iv-1, ivs);
        int f2 = lis(iv, ivs-1);
        ans = max(f1, f2);
    }
    dp[iv][ivs] = ans;

    return ans;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    dp[i][j] = -1;
    vs = v;
    sort(vs.begin(), vs.end());
    int ans = lis(n-1, n-1);
    cout << ans << "\n";
}