#include<bits/stdc++.h>
using namespace std;
int n, m, k, ed, st[5010], sp[5010];
vector<pair<int, pair<int,int> > > edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    cin >> ed;
    for(int i=0;i<k;i++) cin >> st[i];
    for(int i=0;i<m;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }

    for(int i=0;i<n;i++) {
        sp[i] = 1000000000;
    }
   
    for(int i=0;i<k;i++)
        sp[st[i]] = 0;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<m;j++) {
            int w = edges[j].first;
            int a = edges[j].second.first;
            int b = edges[j].second.second;
            // cout << sp[b] << " " << sp[a] << "\n";
            if(sp[b] > sp[a] + w) {
                sp[b] = sp[a] + w;
                // cout << "sp[" << b << "] = from " << a << " with w=" << w << "\n";  
            }
        }
    }

    // for(int i=0;i<n;i++) {
    //     cout << "sp[" << i << "] = " << sp[i] << "\n";
    // }

    // int ans = INT_MAX;
    // for(int i=0;i<k;i++) {
        // ans = min(ans, sp[st[i]]);
    // }
    cout << sp[ed] << "\n";
}