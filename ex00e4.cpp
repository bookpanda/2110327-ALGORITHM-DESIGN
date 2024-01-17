#include<bits/stdc++.h>
using namespace std;

int a,b;

void dfs(int lvl, int cou, vector<int> &v) {
    if(lvl == b) {
        if(cou == a) {
            for(int i=0;i<b;i++) cout << v[i];
            cout << "\n";
        }
        return;
    }
    v[lvl] = 0;
    dfs(lvl+1, cou, v);
    if(cou < a) {
        v[lvl] = 1;
        dfs(lvl+1, cou+1, v);
    }
}

int main() {
    cin >> a >> b;
    vector<int> v;
    v.resize(b);
    dfs(0, 0, v);
}