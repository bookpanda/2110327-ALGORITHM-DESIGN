#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> al[1010], req;

int main() {
    cin >> n >> m;
    req.resize(n+1);
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        req[b]++;
    }
    // for(int i=1;i<=n;i++) {
    //     cout << "req " << i << " = " << req[i] << "\n";
    // }
    for(int a=0;a<5;a++) {
        vector<int> in(n);
        for(int i=0;i<n;i++) {
            cin >> in[i];
        }
        vector<int> tr = req;
        bool isSuccess=true;
        // cout << "\nitera " << a << "\n";
        for(int i=0;i<n;i++) {
            int node = in[i];
            // cout << "node = " << node << ", tr=" << tr[node] << "\n";
            if(tr[node] > 0) {
                isSuccess = false;
                break;
            }
            for(int j=0;j<al[node].size();j++) {
                int nn = al[node][j];
                tr[nn]--;
            }
        }

        if(isSuccess) cout << "SUCCESS\n";
        else cout << "FAIL\n";
    }
}