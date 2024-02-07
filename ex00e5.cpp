#include<bits/stdc++.h>
using namespace std;

void cook(int lvl, int n, int k, vector<int> &v, int streak, bool mou) {
    if(lvl == n) {
        if(!mou) return;
        for(int i=0;i<v.size();i++) {
            cout << v[i];
        }
        cout << "\n";
        return;
    }
    v.push_back(0);
    cook(lvl+1, n, k, v, 0, mou);
    v.pop_back();

    v.push_back(1);
    if(streak+1 == k) cook(lvl+1, n, k, v, streak+1, true);
    else cook(lvl+1, n, k, v, streak+1, mou);
    v.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v;
    if(k == 0) cook(0, n, k, v, 0, true);
    else cook(0, n, k, v, 0, false);
}