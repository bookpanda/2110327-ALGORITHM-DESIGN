#include<bits/stdc++.h>
using namespace std;
int n, t[5];
vector<int> al[250010], visited[3];

int main() {
    cin >> n;
    for(int i=0;i<3;i++) {
        cin >> t[i];
        visited[i].resize(n+1);
    }
    for(int i=1;i<=n;i++) {
        int a;
        cin >> a;
        for(int j=0;j<a;j++) {
            int b;
            cin >> b;
            al[i].push_back(b);
        }
    }

    for(int person=0;person<3;person++) {
        int st = t[person];
        queue<pair<int, int> > q;
        q.push({0, st});
        visited[person][st] = 1;
        // cout << "st = " << st << "\n";

        while(!q.empty()) {
            int dist = q.front().first;
            int node = q.front().second;
            q.pop();
            // cout << "node = " << node << "\n";

            for(int i=0;i<al[node].size();i++) {
                int nn = al[node][i];
                if(!visited[person][nn]) {
                    visited[person][nn] = dist+1;
                    q.push({dist+1, nn});
                }
            }
        }
    }

    int ans = INT_MAX;
    for(int i=1;i<=n;i++) {
        int v1 = visited[0][i];
        int v2 = visited[1][i];
        int v3 = visited[2][i];
        // cout << "v1 " << v1 << ", v2 " << v2 << ", v3 " << v3 << "\n";
        if(v1 && v2 && v3) {
            ans = min(ans, max(v1, max(v2, v3)));
        }
    }
    cout << ans << "\n";
}