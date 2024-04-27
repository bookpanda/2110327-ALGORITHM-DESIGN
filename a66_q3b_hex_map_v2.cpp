#include<bits/stdc++.h>
using namespace std;
int n, m;
int R[3], C[3], board[310][310], sp[310][310];

int main() {
    cin >> n >> m;
    cin >> R[1] >> C[1] >> R[2] >> C[2];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> board[i][j];
            sp[i][j] = INT_MAX;
        }
    }

    int dx[2][6] = {{0, 0, -1, -1, 1, 1}, {0, 0, -1, -1, 1, 1}};
    int dy[2][6] = {{1, -1, 0, 1, 0, 1}, {1, -1, -1, 0, -1, 0}};
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({-board[R[1]][C[1]], {R[1], C[1]}});
    sp[R[1]][C[1]] = board[R[1]][C[1]];

    while(!pq.empty()) {
        int w = -pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        int sel = r % 2 == 0 ? 1 : 0;

        for(int i=0;i<6;i++) {
            int nr = r + dx[sel][i];
            int nc = c + dy[sel][i];
            if(1<=nr && nr<=n && 1<=nc && nc<=m && sp[nr][nc] > w + board[nr][nc]) {
                sp[nr][nc] = w + board[nr][nc];
                pq.push({-(w + board[nr][nc]), {nr, nc}});
            }
        }
    }

    cout << sp[R[2]][C[2]] << "\n";

}