#include<bits/stdc++.h>
using namespace std;
int n, m, mp[1010][1010], dp[1010][1010];

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> mp[i][j];
        }
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        dp[i][j] = INT_MAX;
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    queue<pair<int, int> > q;
    dp[0][0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr && nr<n && 0<=nc && nc<m && dp[nr][nc] > dp[r][c] + mp[nr][nc]) {
                dp[nr][nc] = dp[r][c] + mp[nr][nc];
                q.push({nr, nc});
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
}