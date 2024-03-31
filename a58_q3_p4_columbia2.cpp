#include<bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    vector<vector<vector<int> > > dp(n, vector<vector<int> >(m, vector<int>(3)));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
        for(int k=0;k<3;k++)
            dp[i][j][k] = INT_MAX;
    }

    int dx[] = {1, -1, 0, 0, 0};
    int dy[] = {0, 0, 1, -1, 0};
    queue<pair<int, pair<int, int> > > q;
    q.push({0, {0, 0}});
    dp[0][0][0] = 0;
    while(!q.empty()) {
        // int cost = q.front().first.first;
        int tear = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr && nr<n && 0<=nc && nc<m) {
                int newval = dp[r][c][tear] + v[nr][nc];
                if(dp[nr][nc][tear] > newval) {
                    dp[nr][nc][tear] = newval;
                    q.push({tear, {nr, nc}});
                }
            }
        }

        if(tear<2)
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                int nr = r + dx[i] + dx[j];
                int nc = c + dy[i] + dy[j];
                if(0<=nr && nr<n && 0<=nc && nc<m) {
                    int newval = dp[r][c][tear];
                    if(dp[nr][nc][tear+1] > newval) {
                        dp[nr][nc][tear+1] = newval;
                        q.push({tear+1, {nr, nc}});
                    }
                }
            }
        }
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << min(dp[i][j][0], min(dp[i][j][1], dp[i][j][2])) << " ";
        }
        cout << "\n";
    }

}