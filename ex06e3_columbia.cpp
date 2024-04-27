#include<bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m)), sp(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v[i][j];
            sp[i][j] = INT_MAX;
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({0, {0, 0}});
    sp[0][0] = 0;
    while(!pq.empty()) {
        int val = -pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr && nr<n && 0<=nc && nc<m && sp[nr][nc] > val+v[nr][nc]) {
                pq.push({-(val+v[nr][nc]), {nr, nc}});
                sp[nr][nc] = val+v[nr][nc];
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << sp[i][j] << " ";
        }
        cout << "\n";
    }
}