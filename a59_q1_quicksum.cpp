#include<bits/stdc++.h>
using namespace std;

int getSum(int r, int c, vector<vector<int> > &qs) {
    if(r < 0 || c < 0) return 0;
    return qs[r][c];
}

int main() {
    int n, m, k;
    vector<vector<int> > v, qs;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        vector<int> tmp;
        for(int j=0;j<m;j++) {
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        v.push_back(tmp);
    }

    qs.resize(n);
    for(int i=0;i<n;i++) qs[i].resize(m);

    qs[0][0] = v[0][0];
    for(int i=1;i<n;i++) qs[i][0] = qs[i-1][0] + v[i][0];
    for(int i=1;i<m;i++) qs[0][i] = qs[0][i-1] + v[0][i];
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            qs[i][j] = qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1] + v[i][j];
        }
    } 

    // cout << "--------\n";
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << qs[i][j] << " ";
    //     } cout << "\n";
    // }

    while(k--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        // int ans = qs[r2][c2] - qs[r2][c1-1] - qs[r1-1][c2] + qs[r1-1][c1-1];
        int ans = getSum(r2, c2, qs) - getSum(r2, c1-1, qs) - getSum(r1-1, c2, qs) + getSum(r1-1, c1-1, qs);
        cout << ans << "\n";
    }
}