#include<bits/stdc++.h>
using namespace std;
int t;

int main() {
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        double mp[510][510];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> mp[i][j];
            }
        }

        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(mp[i][j] < mp[i][k] * mp[k][j]) {
                        mp[i][j] = mp[i][k] * mp[k][j];
                    }
                }
            }

            // cout << "round " << k << "\n";
            // for(int i=0;i<n;i++) {
            //     for(int j=0;j<n;j++) cout << mp[i][j] << " ";
            //     cout << "\n";
            // }
        }

        bool isProfit = false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(mp[i][j] * mp[j][i] > 1) isProfit = true;
            }
        }
        if(isProfit) cout << "YES\n";
        else cout << "NO\n";
    }
}