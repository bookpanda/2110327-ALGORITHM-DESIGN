#include<bits/stdc++.h>
using namespace std;
int n, k, ans = -INT_MAX;
vector<int> v, pat, sel, tail;

bool isMatch(int idx) {
    if(idx < k-1) return false;

    bool match = true;
    for(int i=0;i<k;i++) {
        if(sel[idx-(k-1)+i] != pat[i]) {
            match = false;
            break;
        }
    }

    return match;
}

void cook(int idx, int sum, int last) {
    if(idx == n) {
        ans = max(ans, sum);
        return;
    }
    if(sum + tail[idx] < ans) return;

    if(last == 1) {
        if(isMatch(idx)) return;
        cook(idx+1, sum, 0);
        return;
    }

    if(!isMatch(idx)) cook(idx+1, sum, 0);

    sel[idx] = 1;
    if(!isMatch(idx)) cook(idx+1, sum+v[idx], 1);
    sel[idx] = 0;
}

int main() {
    cin >> n >> k;
    v.resize(n);
    sel.resize(n);
    pat.resize(k);
    tail.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<k;i++) cin >> pat[i];
    tail[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--) tail[i] = tail[i+1] + v[i]; 

    cook(0, 0, 0);
    cout << ans << "\n";
}