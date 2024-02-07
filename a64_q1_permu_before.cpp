#include<bits/stdc++.h>
using namespace std;

void permu(int lvl, int n, vector<int> &v, vector<bool> &used, map<int,int> &prereq) {
    if(lvl == n) {
        for(int i=0;i<v.size();i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0;i<n;i++) {
        if(prereq.find(i) != prereq.end() && !used[prereq[i]]) { //have condition
            continue;
        }
        if(!used[i]) {
            used[i] = true;
            v.push_back(i);
            permu(lvl+1, n, v, used, prereq);
            used[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    vector<int> v;
    vector<bool> used;
    map<int,int> prereq;
    cin >> n >> m;
    used.resize(n);
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        prereq[b] = a;
    }

    permu(0, n, v, used, prereq);
}