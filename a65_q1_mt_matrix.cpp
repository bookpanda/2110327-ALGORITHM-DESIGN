#include<bits/stdc++.h>
using namespace std;
int n, m, u, v, w, p;

int cook(int lvl, long long r, long long c) {
    if(lvl <= 1) {
        if(r == 1 && c == 1) return u;
        if(r == 1 && c == 2) return v;
        if(r == 2 && c == 1) return w;
        if(r == 2 && c == 2) return p;
    }
    long long mid = 1LL << (lvl-1);
    // cout << "lvl = " << lvl << ", mid = " << mid << ", " << r << ", " << c << "\n";

    if(r <= mid) {
        if(c <= mid) return cook(lvl-1, r, c);
        else return cook(lvl-1, c-mid, r);
    } else {
        if(c <= mid) return -cook(lvl-1, r-mid, c);
        else return -cook(lvl-1, c-mid, r-mid);
    }
}

int main() {
    cin >> n >> m;
    cin >> u >> v >> w >> p;
    for(int i=0;i<m;i++) {
        long long r, c;
        cin >> r >> c;
        int ans = cook(n, r, c);
        cout << ans << "\n";
    }
}