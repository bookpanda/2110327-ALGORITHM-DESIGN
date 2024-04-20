#include<bits/stdc++.h>
using namespace std;
int n, ans=0;
vector<int> row, col;

bool check(int r, int c) {
    for(int i=1;i<r;i++) {
        int difr = abs(r - i);
        int difc = abs(c - row[i]);
        if(difr == difc) return false;
    } 
    return true;
}

void cook(int r) {
    // cout << "r = " << r << "\n";
    if(r == n+1) {
        ans++;
        return;
    }

    for(int c=1;c<=n;c++) {
        if(col[c] != 0) continue;
        if(!check(r, c)) continue;
        row[r] = c;
        col[c] = r;
        cook(r+1);
        col[c] = 0;
        row[r] = 0;
    }
}

int main() {
    cin >> n;
    row.resize(n+1);
    col.resize(n+1);
    cook(1);
    cout << ans << "\n";
}