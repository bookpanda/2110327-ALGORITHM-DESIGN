#include<bits/stdc++.h>
using namespace std;
int n, cou = 0, r2c[15], c2r[15];

bool check(int r, int c) {
    for(int i=1;i<r;i++) {
        int difr = abs(i - r);
        int difc = abs(r2c[i] - c);
        if(difr == difc) return false;
    }

    return true;
}

void cook(int r) {
    if(r == n+1) {
        cou++;
        return;
    }
    // cout << "r = " << r << "\n";
    // cout << "r2c : ";
    // for(int i=1;i<r;i++) {
    //     cout << r2c[i] << " ";
    // } cout << "\n";

    for(int c=1;c<=n;c++) {
        if(c2r[c] != 0 || !check(r, c)) continue;
        r2c[r] = c;
        c2r[c] = r;
        cook(r+1);
        r2c[r] = 0;
        c2r[c] = 0;
    }
}

int main() {
    cin >> n;
    cook(1);
    cout << cou << "\n";
}