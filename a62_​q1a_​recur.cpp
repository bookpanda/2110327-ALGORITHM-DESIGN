#include<bits/stdc++.h>
using namespace std;

void cook(int r1, int r2, int c1, int c2, vector<vector<int> > &v, int a, int b) {
    if(r1 > r2 || c1 > c2) return;
    // cout << r1 << ", " << c1 << " to " << r2 << ", " << c2 << ", len=" << r2-r1+1 << ", a=" << a << ", b=" << b <<  "\n";
    if(a == 0) {
        v[r1][c1] = b;
        return;
    }

    int midr = (r1+r2) / 2;
    int midc = (c1+c2) / 2;
    cook(r1,    midr,    c1,     midc,    v, a-1, b);
    cook(r1,    midr,    midc+1,  c2,     v, a-1, b-1);
    cook(midr+1, r2,     c1,     midc,    v, a-1, b+1);
    cook(midr+1, r2,     midc+1,  c2,     v, a-1, b);
}

int main() {
    int a,b;
    cin >> a >> b;
    int n = 1 << a;
    vector<vector<int> > v;
    v.resize(n);
    for(int i=0;i<n;i++) v[i].resize(n);
    // cout << "n = " << n << "\n";
    cook(0, n-1, 0, n-1, v, a, b);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << v[i][j] << " ";
        } cout << "\n";
    }
}