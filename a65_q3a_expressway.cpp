#include<bits/stdc++.h>
using namespace std;
int n, c[710][710];

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            c[i][j] = 1000000000;
        }
    }
    cin >> c[1][2];
    for(int i=3;i<=n;i++) {
        int m;
        cin >> m;
        for(int j=0;j<m;j++) {
            int a, b;
            cin >> a >> b;
            c[i][a] = b;
            c[a][i] = b;
        }
    }

    for(int k=3;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }

        // cout << "c: \n";
        // for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=n;j++) {
        //         if(c[i][j] < 10) cout << c[i][j] << "  ";
        //         else cout << c[i][j] << " ";
        //     } cout << "\n";
        // }

        cout << c[1][2] << " ";
    }

}