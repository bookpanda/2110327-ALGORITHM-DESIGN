#include<bits/stdc++.h>
using namespace std;
int n, am[705][705];

int main() {
    cin >> n >> am[1][2];
    am[2][1] = am[1][2];

    for(int y=3;y<=n;y++) {
        int m;
        cin >> m;
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            am[y][a] = b;
            am[a][y] = b;
        }

    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
            }
        }

        cout << "\n yr " << k << "\n";
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(am[i][j] >= 10) cout << am[i][j] << " ";
                else cout << am[i][j] << "  ";
            } cout << "\n";
        }
        if(k>=3)
        cout << am[1][2] << "\n";
    }
}