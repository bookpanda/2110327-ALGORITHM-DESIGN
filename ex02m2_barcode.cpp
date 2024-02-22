#include<bits/stdc++.h>
using namespace std;
int dp[35][35]; //nth, color changing
int n, m, k;

int main() {
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
        dp[i][0] = 1; //0, 00, 000, 0000, 00000...

    for(int i=2;i<=n;i++) { //nth
        for(int j=1;j<=k;j++) { //color changing
            for(int p=1;p<=m;p++) { //streak
                if(i-p < 1) break;
                dp[i][j] += dp[i-p][j-1];
            }
        }
    }
    cout << dp[n][k] << "\n";
}