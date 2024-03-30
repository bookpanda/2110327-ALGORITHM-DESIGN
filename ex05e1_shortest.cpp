#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<string> v;

int main() {
    cin >> n >> m;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int ans = -1;
    queue<pair<int, pair<int,int> > > q;
    q.push({0, {0, 0}});
    v[0][0] = 'X';
    while(!q.empty()) {
        int dist = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        if(r==n-1 && c==m-1) {
            ans = dist;
            break;
        }
        // cout << r << ", " << c << "\n";
        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr && nr<n && 0<=nc && nc<m && v[nr][nc] == '.') {
                v[nr][nc] = 'X';
                q.push({dist+1, {nr, nc}});
            }
        }
    }
    cout << ans << "\n";
}