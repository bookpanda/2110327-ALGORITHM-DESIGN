#include<bits/stdc++.h>
using namespace std;
int n, c[710][710];

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) c[i][j] = 9999999;
    cin >> c[1][2];
    c[2][1] = c[1][2];

    for(int i=3;i<=n;i++) {
        int m;
        cin >> m;
        for(int j=0;j<m;j++) {
            int b, w;
            cin >> b >> w;
            c[i][b] = w;
            c[b][i] = w;
        }
    }

    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
        if(k>=3) cout << c[1][2] << " ";
    }
}