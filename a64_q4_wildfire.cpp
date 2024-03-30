#include<bits/stdc++.h>
using namespace std;
int n, m, k, val[5010], st[5010];
vector<int> al[5010], visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    int totalsum = 0;
    for(int i=0;i<n;i++) {
        cin >> val[i];
        totalsum += val[i];
    }
    for(int i=0;i<k;i++) {
        cin >> st[i];
    }
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
    }
    visited.resize(n);
    for(int i=0;i<n;i++) visited[i] = 0;

    for(int day=0;day<k;day++) {
        if(visited[st[day]]) {
            cout << totalsum << " ";
            continue;
        }
        queue<int> q;
        q.push(st[day]);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = 1;
            totalsum -= val[node];
            val[node] = 0;
            for(int i=0;i<al[node].size();i++) {
                int nn = al[node][i];
                if(!visited[nn]) {
                    q.push(nn);
                }
            }
        }
        cout << totalsum << " ";
    }
}