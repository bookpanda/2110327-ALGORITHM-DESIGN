#include<bits/stdc++.h>
using namespace std;
int n, str, stc;
vector<int> al[50010];
int mp[1010][1010];

int main() {
    cin >> n >> str >> stc;
    for(int i=0;i<n;i++) {
        int r, c;
        cin >> r >> c;
        mp[r][c] = 2;
    }
    queue<pair<int,int> > q, q2;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    q.push({str, stc});
    mp[str][stc] = 1;
    int cou = 0;
    while(1) {
        bool escape = false;
        cout << "cou " << cou << "\n";
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(1<=nr && nr<=1000 && 1<=nc && nc<=1000) {
                    if(mp[nr][nc]==0) {
                        mp[nr][nc] = 1;
                        q.push({nr, nc});
                    } else if(mp[nr][nc] == 2) {
                        mp[nr][nc] = 1;
                        q2.push({nr, nc});
                    }
                } else {
                    escape = true;
                }
            }
        }

        // for(int i=1;i<=10;i++) {
        //     for(int j=1;j<=10;j++) {
        //         cout << mp[i][j] << " ";
        //     } cout << "\n";
        // }

        if(escape) break;
        q = q2;
        cou++;
        while(!q2.empty()) q2.pop();
    }
    cout << cou << "\n";
}