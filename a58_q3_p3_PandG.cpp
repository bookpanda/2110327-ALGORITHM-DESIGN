#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int R, C, n, T, pr, pc;
        vector<int> tg, rg, cg;
        vector<string> mp;
        cin >> R >> C >> n >> T >> pr >> pc;
        tg.resize(n);
        rg.resize(n);
        cg.resize(n);
        mp.resize(R);
        priority_queue<pair<int, pair<int,int> > > gl;
        for(int i=0;i<n;i++) {
            cin >> tg[i] >> rg[i] >> cg[i];
            gl.push({-tg[i], {rg[i], cg[i]}});
        }
        for(int i=0;i<R;i++) {
            cin >> mp[i];
        }
        priority_queue<pair<int,int> > pq, pq2;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int turn=0;turn<=T;turn++) {
            pq = pq2;
            while(!pq2.empty()) pq2.pop();
            while(!pq.empty()) {
                int cr = pq.top().first;
                int cc = pq.top().second;
                pq.pop();

                for(int i=0;i<4;i++) {
                    int nr = cr + dx[i];
                    int nc = cc + dy[i];
                    if(nr<0 || nr>=R || nc<0 || nc>=C || mp[nr][nc] != '.') continue;
                    mp[nr][nc] = 'g';
                    pq2.push({nr, nc});
                }
            }
            while(!gl.empty() && -gl.top().first == turn) {
                int cr = gl.top().second.first;
                int cc = gl.top().second.second;
                gl.pop();
                mp[cr][cc] = 'g';
                pq2.push({cr, cc});
            }
            cout << "\nmap turn " << turn << "\n";
            for(int i=0;i<R;i++) {
                cout << mp[i] << "\n";
            }
        }

        priority_queue<pair<int,int> > pq3, pq4;
        bool ans = false;
        pq4.push({pr, pc});
        for(int turn=0;turn<T;turn++) {
            pq3 = pq4;
            while(!pq4.empty()) pq4.pop();
            while(!pq3.empty()) {
                int cr = pq3.top().first;
                int cc = pq3.top().second;
                pq3.pop();

                mp[cr][cc] = '0' + turn;
                if(mp[cr][cc] == '.') {
                    ans = true;
                    break;
                }

                for(int i=0;i<4;i++) {
                    int nr = cr + dx[i];
                    int nc = cc + dy[i];
                    if(nr<0 || nr>=R || nc<0 || nc>=C || mp[nr][nc] == '#' || mp[nr][nc] <= '0' + turn) continue;
                    pq4.push({nr, nc});
                }
            }
            cout << "\nmap turn " << turn << "\n";
            for(int i=0;i<R;i++) {
                cout << mp[i] << "\n";
            }
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}