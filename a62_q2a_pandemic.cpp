#include<bits/stdc++.h>
using namespace std;
int n, m, t;
int v[505][505];

int main() {
    cin >> n >> m >> t;
    int infected=0;
    queue<pair<int, pair<int,int> > > q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v[i][j];
            if(v[i][j] == 1) {
                infected++;
                q.push({0, {i, j}});
            }
        }
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while(!q.empty()) {
        int d = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(d+1<=t && 0<=nr && nr<n && 0<=nc && nc<m && v[nr][nc] == 0) {
                v[nr][nc] = 1;
                infected++;
                q.push({d+1, {nr, nc}});
            }
        }
    }
    cout << infected << "\n";
}