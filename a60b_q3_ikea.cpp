#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> al[1010];
vector<int> dep, dep2;

int main() {
    cin >> n >> m;
    dep.resize(n+1);
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        dep[b]++;
    }
    // for(int i=1;i<=n;i++) {
    //     cout << "dep[" << i << "] = " << dep[i] << "\n";
    // }
    for(int turn=0;turn<5;turn++) {
        vector<int> v(n);
        dep2 = dep;
        bool muri = false;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            // cout << "node " << v[i] << " dep=" << dep[v[i]] << "\n";
            if(dep2[v[i]] > 0) muri = true;
            for(int j=0;j<al[v[i]].size();j++) {
                int nn = al[v[i]][j];
                dep2[nn]--;
            }
        }
        if(muri) {
            cout << "FAIL\n";
        } else {
            cout << "SUCCESS\n";
        }
    }
}