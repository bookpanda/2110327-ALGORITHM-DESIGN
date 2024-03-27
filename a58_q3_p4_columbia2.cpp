#include<bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m)), ans(n, vector<int>(m));
    vector<vector<vector<int> > > visited(n, vector<vector<int> >(m, vector<int>(3)));
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++)
            for(int k=0;k<3;k++) visited[i][j][k] = INT_MAX;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v[i][j];
        }
    }

    priority_queue<pair<pair<int,int>, pair<int,int> > > pq;
    pq.push({{-0, -0}, {0, 0}});
    visited[0][0][0] = 0;
    int dx[] = {1, -1, 0, 0, 0};
    int dy[] = {0, 0, 1, -1, 0};
    while(!pq.empty()) {
        int dist = -pq.top().first.first;
        int tear = -pq.top().first.second;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        // cout << r << ", " << c << "   cost=" << dist << ", tear=" << tear << "\n";
        if(tear < 2)
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                int nr = r + dx[i] + dx[j];
                int nc = c + dy[i] + dy[j];
                if(0<=nr && nr<n && 0<=nc && nc<m && visited[nr][nc][tear+1] > dist) {
                    visited[nr][nc][tear+1] = dist;
                    pq.push({{-dist, -(tear+1)}, {nr, nc}});
                }
            }
        }
        // for(int i=0;i<4;i++) {
        //     int nr = r + dx[i];
        //     int nc = c + dy[i];
        //     if(0<=nr && nr<n && 0<=nc && nc<m && visited[nr][nc][tear+1] > dist) {
        //         visited[nr][nc][tear+1] = dist;
        //         pq.push({{-(dist), -(tear+1)}, {nr, nc}});
        //     }
        // }

        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr && nr<n && 0<=nc && nc<m && visited[nr][nc][tear] > dist + v[nr][nc]) {
                visited[nr][nc][tear] = dist + v[nr][nc];
                pq.push({{-(dist + v[nr][nc]), -(tear)}, {nr, nc}});
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ans[i][j] = min(visited[i][j][0], min(visited[i][j][1], visited[i][j][2]));
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) 
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}