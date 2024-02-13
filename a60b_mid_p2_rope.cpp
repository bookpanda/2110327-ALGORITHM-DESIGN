#include<bits/stdc++.h>
using namespace std;
int n, a, b, c;
map<int,int> mp;

int cook(int l) {
    if(l<0) return -INT_MAX;
    if(l==0) return 0;
    if(mp.find(l) != mp.end()) return mp[l];

    int la = cook(l-a);
    int lb = cook(l-b);
    int lc = cook(l-c);
    int lm = max(max(la, lb), lc);

    mp[l] = lm + 1;
    return mp[l];
}

int main() {
    cin >> n >> a >> b >> c;
    int ans = cook(n);
    cout << ans << "\n";
}