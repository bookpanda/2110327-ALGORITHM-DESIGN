#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> b, f;
vector<int> al[5005];
vector<bool> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    b.resize(n);
    visited.resize(n);
    for(int i=0;i<n;i++) visited[i] = false;
    f.resize(k);

    int totalsum = 0;
    for(int i=0;i<n;i++) {
        cin >> b[i];
        totalsum += b[i];
    }
    for(int i=0;i<k;i++) {
        cin >> f[i];
    }
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
    }

    for(int day=0;day<k;day++) {
        int st = f[day];
        queue<int> s;
        s.push(st);
        // for(int i=0;i<al[st].size();i++) {
        //     s.push(al[st][i]);
        // }
        while(!s.empty()) {
            int node = s.front();
            s.pop();
            if(visited[node]) continue;

            visited[node] = true;
            totalsum -= b[node];
            b[node] = 0;
            for(int i=0;i<al[node].size();i++) {
                s.push(al[node][i]);
            }
        }
        cout << totalsum << " ";
    }
}