#include<bits/stdc++.h>
using namespace std;
int n, w, k;
vector<int> l, r;
int dp[200010][2]; //at pos i, billboard is left/right
int dp2[200010][55][2]; 

int cook1() {
    dp[0][0] = l[0]; //left
    dp[0][1] = r[0]; //right
    for(int i=1;i<n;i++) {
        int lastidx = i-w-1;
        if(lastidx < 0) { 
            dp[i][0] = max(l[i], dp[i-1][0]);
            dp[i][1] = max(r[i], dp[i-1][1]);
        } else {
            dp[i][0] = max(dp[lastidx][1] + l[i], dp[i-1][0]); //choose the last one or i-1 with be the same as i-1
            dp[i][1] = max(dp[lastidx][0] + r[i], dp[i-1][1]);
        }
    }
    return max(dp[n-1][0], dp[n-1][1]);
}

int cook2() {
    dp2[0][1][0] = l[0]; //left
    dp2[0][1][1] = r[0]; //right
    for(int i=1;i<n;i++) {
        for(int j=1;j<=k;j++) {
            int lastidx = i-w-1;
            if(lastidx < 0) { 
                dp2[i][1][0] = max(l[i], dp2[i-1][1][0]);
                dp2[i][1][1] = max(r[i], dp2[i-1][1][1]);
            } else {
                dp2[i][j][0] = max(dp2[lastidx][j-1][1] + l[i], dp2[i-1][j][0]);
                dp2[i][j][1] = max(dp2[lastidx][j-1][0] + r[i], dp2[i-1][j][1]);
            }
        }
    }
    int ans = -INT_MAX;
    for(int i=1;i<=k;i++) {
        ans = max(ans, dp2[n-1][i][0]);
        ans = max(ans, dp2[n-1][i][1]);
    }

    return ans;
}

int main() {
    cin >> n >> w >> k;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        l.push_back(a);
    }
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        r.push_back(a);
    }
    if(n == k) cout << cook1() << "\n";
    else cout << cook2() << "\n";
}