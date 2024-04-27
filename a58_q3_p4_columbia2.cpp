#include<bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    vector<vector<vector<int> > > sp(n, vector<vector<int> >(m, vector<int>(3)));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v[i][j];
            for(int k=0;k<3;k++) sp[i][j][k] = 9999999;
        }
    }

    int dx[] = {0, 0, 1, -1, 0};
    int dy[] = {1, -1, 0, 0, 0};
    priority_queue<pair<pair<int, int>, pair<int, int> > > pq;
    pq.push({{0, 0}, {0, 0}});
    sp[0][0][0] = 0;
    while(!pq.empty()) {
        int w = -pq.top().first.first;
        int t = pq.top().first.second;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr && nr<n && 0<=nc && nc<m && sp[nr][nc][t] > w + v[nr][nc]) {
                pq.push({{-(w + v[nr][nc]), t}, {nr, nc}});
                sp[nr][nc][t] = w + v[nr][nc];
            }
        }

        if(t<2)
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                int nr = r + dx[i] + dx[j];
                int nc = c + dy[i] + dy[j];
                if(0<=nr && nr<n && 0<=nc && nc<m && sp[nr][nc][t+1] > w) {
                    pq.push({{-(w), t+1}, {nr, nc}});
                    sp[nr][nc][t+1] = w;
                }
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << min(sp[i][j][0], min(sp[i][j][1], sp[i][j][2])) << " ";
        }
        cout << "\n";
    }
}