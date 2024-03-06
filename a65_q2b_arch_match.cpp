#include<bits/stdc++.h>
using namespace std;
int n, dp[505][505];
vector<int> v;

int cook(int st, int ed) {
    if(st >= ed) return 0;
    if(ed - st == 1) return max(0, v[st]*v[ed]);
    if(dp[st][ed] != -INT_MAX) return dp[st][ed];
    // cout << "st = " << st << ", ed=" << ed << "\n";

    int ans = max(cook(st+1, ed), cook(st, ed-1));
    for(int i=st+1;i<=ed;i++) {
        ans = max(ans, v[st]*v[i] + cook(st+1, i-1) + cook(i+1, ed));
    }
    dp[st][ed] = ans;
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
    dp[i][j] = -INT_MAX;
    int ans = cook(0, n-1);
    cout << ans << "\n";
}