#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int st[100010], t[100010];
vector<int> al[100010], sp;


int main() {
    cin >> n >> m >> k;
    sp.resize(n);
    for(int i=0;i<n;i++) sp[i] = INT_MAX;

    for(int i=0;i<k;i++) cin >> st[i];
    for(int i=0;i<n;i++) cin >> t[i];
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    priority_queue<pair<int, int> > pq;
    for(int i=0;i<k;i++) {
        pq.push({-t[st[i]], st[i]});
        sp[st[i]] = t[st[i]];
    }
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        // cout << "node " << node << ", cost= " << cost << "\n";

        for(int i=0;i<al[node].size();i++) {
            int nn = al[node][i];
            int newcost = cost + t[nn];
            if(sp[nn] > newcost) {
                sp[nn] = newcost;
                pq.push({-newcost, nn});
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans = max(ans, sp[i]);
        // cout << "sp[" << i << "] = " << sp[i] << "\n";
    }
    cout << ans << "\n";
    
}