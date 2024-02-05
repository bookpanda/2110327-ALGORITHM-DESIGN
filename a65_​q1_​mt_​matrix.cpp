#include<bits/stdc++.h>
using namespace std;

int find_val(vector<vector<int> > &mtx, vector<long long> half, int n, long long r, long long c) {
    // cout << "half = " << half[n] << ", r=" << r << ", c=" << c << "\n";
    if(n==1) {
        return mtx[r-1][c-1];
    }

    if(r > half[n]) {
        if(c > half[n]) return -1 * find_val(mtx, half, n-1, c-half[n], r-half[n]);
        return -1 * find_val(mtx, half, n-1, r-half[n], c);
    }
    if(c > half[n]) return find_val(mtx, half, n-1, c-half[n], r);
    return find_val(mtx, half, n-1, r, c);
}

int main() {
    int n, m, u, v, w, p;
    vector<vector<int> > mtx;

    cin >> n >> m;
    cin >> u >> v >> w >> p;
    mtx = {{u, v}, {w, p}};
    vector<long long> half;
    half.push_back(-1);
    half.push_back(1);
    for(int i=2;i<=n;i++) {
        half.push_back(half[i-1] * 2);
    }
    while(m--) {
        long long r, c;

        cin >> r >> c;
        cout << find_val(mtx, half, n, r, c) << "\n";
    }

}