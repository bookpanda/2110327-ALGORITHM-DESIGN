#include<bits/stdc++.h>
using namespace std;
int l, r; 
int cou = 0;
map<int, pair<int,int> > mp;

int cook(int n, int idx) {
    if(n <= 1) {
        if(idx>=l && idx<=r && n==1) {
            cout << "n = " << n << " cou++ at idx=" << idx << "\n";
            cou++;
        }
        return idx;
    }
    if(mp.find(n) != mp.end()) {
        cou += mp[n].second;
        cout << "cou+=" << mp[n].second << " = " << cou << "\n";
        return idx+mp[n].first;
    }

    int coubef = cou;
    int newidx = idx+1;
    newidx = cook(n/2, newidx-1);
    newidx = cook(n%2, newidx+1);
    newidx = cook(n/2, newidx+1);

    // cout << "n = " << n << ", last idx = " << newidx << "\n";
    mp[n] = {newidx-idx, cou-coubef};
    return newidx; //return last idx of seq
}

int main() {
    int n;
    cin >> n;
    cin >> l >> r;
    cook(n, 1);
    cout << cou << "\n";
}