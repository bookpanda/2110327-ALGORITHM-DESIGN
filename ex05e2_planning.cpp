#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> al[1010], visited, seq, prereq;

int main() {
    cin >> n;
    prereq.resize(n);
    visited.resize(n);
    for(int i=0;i<n;i++) {
        int a;
        cin >> prereq[i];
        for(int j=0;j<prereq[i];j++) {
            cin >> a;
            al[a].push_back(i);
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++) {
        if(prereq[i] > 0) continue;
        q.push(i);
        visited[i] = 1;
        for(auto nn: al[i]) prereq[nn]--;
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto nn: al[node]) {
            if(visited[nn] || prereq[nn] > 0) continue;
            q.push(nn);
            for(auto ne: al[nn]) prereq[ne]--;
            visited[nn] = 1;
        }
    }
}