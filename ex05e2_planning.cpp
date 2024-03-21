#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> al[1010], deg, visited, ans;

int main() {
    cin >> n;
    deg.resize(n);
    visited.resize(n);
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        deg[i] = a;
        while(a--) {
            int b;
            cin >> b;
            al[b].push_back(i);
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++) {
        if(deg[i] == 0) {
            q.push(i);
            visited[i] = 1;
            ans.push_back(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i=0;i<al[node].size();i++) {
            int dest = al[node][i];
            // al[node].erase()
            deg[dest]--;
            if(deg[dest] == 0 && !visited[dest]) {
                visited[dest] = 1;
                q.push(dest);
                ans.push_back(dest);
            }
        }
    }
    // cout << "ans\n";
    for(auto x: ans) {
        cout << x << " ";
    }
}