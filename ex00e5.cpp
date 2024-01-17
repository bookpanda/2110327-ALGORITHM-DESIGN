#include<bits/stdc++.h>
using namespace std;

int n,k;
void dfs(int lvl, vector<int> &v, int streak, bool hit) {
    // cout << "lvl " << lvl << " streak " << streak << "\n";
    if(lvl == n) {
        if(hit) {
            for(int i=0;i<n;i++) cout << v[i];
            cout << "\n";
        }
        return;
    } 
    v[lvl] = 0;
    dfs(lvl+1, v, 0, hit);
    v[lvl] = 1;
    if(streak+1 == k) dfs(lvl+1, v, streak+1, true);
    else dfs(lvl+1, v, streak+1, hit);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    vector<int> v;
    v.resize(n);
    dfs(0, v, 0, false);
}