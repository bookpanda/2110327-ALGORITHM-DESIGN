#include<bits/stdc++.h>
using namespace std;
int g[505][505]; 

int main() {
    int r, c;
    cin >> r >> c;
    for(int i=0;i<r;i++) {
        string s;
        cin >> s;
        for(int j=0;j<c;j++) {
            if(s[j] == '.') g[i][j] = -1;
            else g[i][j] = -2;
        }
    }
    queue<pair<int, int> > q;
    q.push({0, 0});
    g[0][0] = 0;
    int mx[] = {0, 0, 1, -1};
    int my[] = {1, -1, 0, 0};
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        int val = g[cr][cc];
        q.pop();
        for(int i=0;i<4;i++) {
            int nr = cr + mx[i];
            int nc = cc + my[i];
            if(0<=nr && nr<r && 0<=nc && nc < c && g[nr][nc] == -1) {
                g[nr][nc] = val + 1;
                q.push({nr, nc});
            }
        }
    }

    // for(int i=0;i<r;i++) {
    //     for(int j=0;j<c;j++) cout << g[i][j] << "\t";
    //     cout << "\n";
    // }

    if(g[r-1][c-1] > -1) cout << g[r-1][c-1] << "\n";
    else cout << "-1\n";
}