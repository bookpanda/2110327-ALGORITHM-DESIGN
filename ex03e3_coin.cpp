#include<bits/stdc++.h>
using namespace std;
int n, dp[100010];
vector<int> v;

int cook(int m) {
    if(dp[m] != 0) return dp[m];

    int ans = INT_MAX;
    for(int i=0;i<n;i++) {
        if(m-v[i] < 0) continue;
        ans = min(ans, cook(m-v[i])+1);
    }

    dp[m] = ans;
    return ans;
}

int main() {
    int m;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
        dp[a] = 1;
    }

    int ans = cook(m);
    cout << ans << "\n";
}