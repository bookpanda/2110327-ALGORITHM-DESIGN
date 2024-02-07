#include<bits/stdc++.h>
using namespace std;

void cook(int lvl, int cou, int a, int b, vector<int> &v) {
    if(lvl == b) {
        if(cou != a) return;
        for(int i=0;i<v.size();i++) {
            cout << v[i];
        } cout << "\n";
        return;
    }
    v[lvl] = 0;
    cook(lvl+1, cou, a, b, v);
    v[lvl] = 1;
    cook(lvl+1, cou+1, a, b, v);
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> v;
    v.resize(b);
    cook(0, 0, a, b, v);
}