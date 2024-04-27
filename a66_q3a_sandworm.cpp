#include<bits/stdc++.h>
using namespace std;
int n, m, k, N[710][710], S[710][710], hasWorm[710][710];
int visitN[710][710], visitS[710][710];
vector<pair<int, int> > wormst;

int main() {
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin >> N[i][j];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin >> S[i][j];
    }
    for(int i=0;i<k;i++) {
        int a, b;
        cin >> a >> b;
        hasWorm[a-1][b-1] = 1;
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    queue<pair<int, int> > q;
    q.push({0, 0});
    visitN[0][0] = 1;
    int cou = 1;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(hasWorm[r][c] && S[r][c]!=1) wormst.push_back({r, c});

        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr && nr<n && 0<=nc && nc<m && N[nr][nc]!=1 && !visitN[nr][nc]) {
                visitN[nr][nc] = 1;
                cou++;
                q.push({nr, nc});
            }
        }
    }
    // cout << "cou = " << cou << "\n";

    int ans = cou;
    for(int w=0;w<wormst.size();w++) {
        if(visitS[wormst[w].first][wormst[w].second]) continue;
        queue<pair<int, int> > q;
        q.push(wormst[w]);
        visitS[wormst[w].first][wormst[w].second] = 1;
        int cou2 = 1;
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(0<=nr && nr<n && 0<=nc && nc<m && S[nr][nc]!=1 && !visitS[nr][nc]) {
                    visitS[nr][nc] = 1;
                    cou2++;
                    q.push({nr, nc});
                }
            }
        }
        // cout << "st = " << wormst[w].first << ", " << wormst[w].second << "  cou2 = " << cou2 << "\n";
        ans = max(ans, cou+cou2);
    }

    cout << ans << "\n";
}