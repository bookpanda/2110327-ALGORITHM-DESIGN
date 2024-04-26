#include<bits/stdc++.h>
using namespace std;
int n, m, k, totalval=0;
vector<int> val, fire, al[5010];

int main() {
    cin >> n >> m >> k;
    val.resize(n);
    fire.resize(k);
    for(int i=0;i<n;i++) {
        cin >> val[i];
        totalval += val[i];
    }
    for(int i=0;i<k;i++) cin >> fire[i];
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
    }

    vector<int> visited(n, 0);
    for(int day=0;day<k;day++) {
        queue<int> q;
        q.push(fire[day]);
        visited[fire[day]] = 1;
        while(!q.empty()) {
            int node = q.front();
            totalval -= val[node];
            val[node] = 0;
            q.pop();
            for(auto nn: al[node]) {
                if(visited[nn]) continue;
                q.push(nn);
                visited[nn] = 1;
            }
        }

        cout << totalval << " ";
    }
}