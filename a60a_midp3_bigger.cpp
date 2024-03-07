#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int dp[10010][2];

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    dp[0][0] = 0;
    dp[0][1] = v[0];
    for(int i=1;i<n;i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if(i-3 >= 0) {
            dp[i][1] = max(dp[i-2][0] + v[i], dp[i-3][1] + v[i]);
        } else {
            dp[i][1] = v[i];
        }
    }
    // for(int i=0;i<n;i++) {
    //     cout << dp[i][0] << ", " << dp[i][1] << "\n";
    // }

    cout << max(dp[n-1][0], dp[n-1][1]) << "\n";
}