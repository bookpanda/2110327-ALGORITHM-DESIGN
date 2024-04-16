#include<bits/stdc++.h>
using namespace std;
int n, row[15], col[15];
int cou = 0;

bool check(int depth) {
    for(int i=1;i<depth;i++) {
        int rd = depth - i;
        int cd = abs(row[depth] - row[i]);
        if(rd == cd) return false;
    }
    return true;
}

void dfs(int r) {
    if(r == n+1) {
        cou++;
        return;
    }
    for(int i=1;i<=n;i++) {
        if(col[i] != 0) continue;
        row[r] = i;
        col[i] = r;
        if(check(r)) dfs(r+1);
        row[r] = 0;
        col[i] = 0;
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << cou << "\n";
}