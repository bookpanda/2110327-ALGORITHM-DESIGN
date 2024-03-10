#include<bits/stdc++.h>
using namespace std;
int n, k, r=1000003;
vector<int> v, dp;

int main() {
    cin >> n >> k;
    v.resize(k);
    dp.resize(n+1);
    for(int i=0;i<k;i++) {
        cin >> v[i];
    }
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        dp[i] = 0; 
        for(int j=0;j<k;j++) {
            if(i-v[j] < 0) continue;
            dp[i] += dp[i-v[j]];
            dp[i] %= r;
        }
    }
    cout << dp[n] << "\n";
}