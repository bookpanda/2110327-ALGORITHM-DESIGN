#include<bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    vector<vector<int> > visited(n, vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        visited[i][j] = INT_MAX;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v[i][j];
        }
    }

    priority_queue<pair<int, pair<int,int> > > pq;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    pq.push({0, {0, 0}});
    visited[0][0] = 0;
    while(!pq.empty()) {
        int val = -pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr && nr<n && 0<=nc && nc<m && visited[nr][nc] > val + v[nr][nc]) {
                visited[nr][nc] = val + v[nr][nc];
                pq.push({-(val + v[nr][nc]), {nr, nc}});
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << visited[i][j] << " ";
        } cout << "\n";
    }
}