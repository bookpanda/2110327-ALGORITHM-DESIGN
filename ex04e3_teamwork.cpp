#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;

int main() {
    cin >> n >> m;
    v.resize(m);
    for(int i=0;i<m;i++) cin >> v[i];
    sort(v.begin(), v.end());
    queue<int> q;
    int ct = 0;
    double totaltime = 0;
    for(int i=0;i<m;i++) {
        // int time = v[i] + offset;
        while(!q.empty() && q.front() <= ct) q.pop();
        if(q.size() < n) {
            q.push(v[i] + ct);
            // cout << "push " << v[i]+ct << "\n";
            totaltime += v[i] + ct;
            continue;
        }
        //q is full
        ct = q.front();
        q.pop();
        q.push(v[i] + ct);
        // cout << "push " << v[i]+ct << "\n";
        totaltime += v[i] + ct;
    }

    double avgtime = totaltime / m;
    printf("%.3lf\n", avgtime);
}