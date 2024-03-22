#include<bits/stdc++.h>
using namespace std;
int n, a, b;
int m[1010][1010], visited[1010][1010];
queue<pair<int,pair<int,int> > > q;

int main() {
    cin >> n >> a >> b;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        m[x][y] = 1;
    }

    q.push({1, {a, b}});
    visited[a][b] = 1;

    int dx[] = {1, -1, 0, 0};   
    int dy[] = {0, 0, 1, -1};
    while(!q.empty()) {
        int d = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        // cout << "dig " << d << ", r=" << r << ", c=" << c << "\n";

        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(1<=nr && nr<=1000 && 1<=nc && nc<=1000 && !visited[nr][nc]) {
                if(m[nr][nc]) {
                    // cout << "(" << nr << ", " << nc << ") = " << d+1 << "\n";
                    visited[nr][nc] = d+1;
                    q.push({d+1, {nr, nc}});
                } else {
                    visited[nr][nc] = d;
                    q.push({d, {nr, nc}});
                }
            }
        }
    }

    int ans = INT_MAX;
    for(int i=1;i<=1000;i++) {
        ans = min(ans, visited[i][1]);
        ans = min(ans, visited[i][1000]);
        ans = min(ans, visited[1][i]);
        ans = min(ans, visited[1000][i]);
    }

    // for(int i=1;i<=10;i++) {
    //     for(int j=1;j<=10;j++) {
    //         cout << visited[i][j] << " ";
    //     } cout << "\n";
    // }
    cout << ans-1 << "\n";
}