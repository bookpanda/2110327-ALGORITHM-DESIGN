#include<bits/stdc++.h>
using namespace std;
int k, n;

int main() {
    cin >> k;
    while(k--) {
        cin >> n;
        double table[n][n], fw[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> table[i][j];
                fw[i][j] = table[i][j];
            }
        }

        for(int a=0;a<n;a++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(fw[i][j] < fw[i][a] * fw[a][j]) {
                        fw[i][j] = fw[i][a] * fw[a][j];
                    }
                }
            }
            // cout << a << " as middle:\n";
            // for(int i=0;i<n;i++) {
            //     for(int j=0;j<n;j++) {
            //         if(fw[i][j] < 10) cout << " ";
            //         cout << fw[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
        }

        bool profit = false;
        for(int i=0;i<n;i++) {
            if(fw[i][i] > 1) {
                profit = true;
                break;
            }
        }
        if(profit) cout << "YES\n";
        else cout << "NO\n";
    }
}