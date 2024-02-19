#include<bits/stdc++.h>
using namespace std;
int k, dp[3000003];
vector<int> v;

int cook(int n) {
    if(n == 0) return 1;
    if(dp[n] != 0) return dp[n];

    int ans = 0;
    for(int i=0;i<k;i++) {
        if(n - v[i] < 0) continue;
        ans += cook(n-v[i]);
        ans %= 1000003;
    }
    dp[n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n >> k;
    for(int i=0;i<k;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    dp[0] = 1;

    int ans = cook(n);
    cout << ans << "\n";

}