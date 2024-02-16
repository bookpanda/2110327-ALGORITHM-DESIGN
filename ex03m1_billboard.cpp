#include<bits/stdc++.h>
using namespace std;
int dp[10010][2];

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    dp[0][0] = 0;
    dp[0][1] = v[0];
    for(int i=1;i<n;i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + v[i];
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << "\n";
}