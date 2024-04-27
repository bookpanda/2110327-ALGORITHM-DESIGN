#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> req, al[1010];

int main() {
    cin >> n >> m;
    req.resize(n+1);
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        req[b]++;
        al[a].push_back(b);
    }
    for(int t=0;t<5;t++) {
        vector<int> tmp(n);
        for(int i=0;i<n;i++) cin >> tmp[i];
        bool success = true;
        vector<int> req2(req);
        for(auto step: tmp) {
            if(req2[step] > 0) {
                success = false;
                break;
            }
            for(auto nn: al[step]) {
                req2[nn]--;
            }
        }

        if(success) cout << "SUCCESS\n";
        else cout << "FAIL\n";
    }
}