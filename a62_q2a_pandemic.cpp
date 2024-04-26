#include<bits/stdc++.h>
using namespace std;
int n, m, T, area[510][510];

int main() {
    cin >> n >> m >> T;
    queue<pair<int, pair<int, int> > > q;
    int cou = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> area[i][j];
            if(area[i][j] == 1) {
                q.push({0, {i, j}});
                cou++;
            }
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while(!q.empty()) {
        int r = q.front().second.first;
        int c = q.front().second.second;
        int t = q.front().first;
        q.pop();

        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr && nr<n && 0<=nc && nc<m && area[nr][nc] == 0 && t+1<=T) {
                area[nr][nc] = 1;
                q.push({t+1, {nr, nc}});
                cou++;
            }
        }
    }

    cout << cou << "\n";
}