#include<bits/stdc++.h>
using namespace std;
int u, v, w, p;

int mt(long long size, long long r, long long c) {
    // cout << "size=" << size << ", r=" << r << ", c=" << c << "\n";
    if(size == 2) {
        if(r==1 && c==1) return u;
        if(r==1 && c==2) return v;
        if(r==2 && c==1) return w;
        if(r==2 && c==2) return p;
    }
    long long mid = size / 2;
    long long nr = r - mid;
    long long nc = c - mid;
    if(r > mid) {
        if(c > mid) return -1 * mt(mid, nc, nr);
        return -1 * mt(mid, nr, c);
    }
    if(c > mid) return mt(mid, nc, r);
    return mt(mid, r, c);
}

int main() {
    int n, m;
    cin >> n >> m;
    cin >> u >> v >> w >> p;
    while(m--) {
        long long r, c;
        cin >> r >> c;
        long long size = 1LL << n;
        // cout << "size = " << size << "\n";
        int ans = mt(size, r, c);
        cout << ans << "\n";
    }

}