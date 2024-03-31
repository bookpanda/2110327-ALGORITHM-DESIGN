#include<bits/stdc++.h>
using namespace std;
int n, m, s, dp[110];
vector<pair<int, pair<int,int> > > edges;

int main() {
    cin >> n >> m >> s;
    for(int i=0;i<m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    for(int i=0;i<n;i++) {
            dp[i]= 1000000000;
    }
    dp[s] = 0;

    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int w = edges[j].first;
            int a = edges[j].second.first;
            int b = edges[j].second.second;
            dp[b] = min(dp[b], dp[a] + w);
        }
    }

    for(int i=0;i<m;i++) {
        int w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(dp[b] > dp[a] + w) {
            cout << "-1\n";
            return 0;
        }
    }

    for(int i=0;i<n;i++) {
        cout << dp[i] << " ";
    }
}