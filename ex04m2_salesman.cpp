#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> seq, t, qs;

int calDist(int st, int ed) {
    if(st > ed) swap(st, ed);
    if(st == ed) return 0;
    if(st-1 < 0) return min(qs[ed-1], qs[m-1] - qs[ed-1]);
    return min(qs[ed-1] - qs[st-1], qs[m-1] - (qs[ed-1] - qs[st-1]));
}

int main() {
    cin >> n >> m;
    seq.resize(m);
    qs.resize(m);
    t.resize(m);
    for(int i=0;i<m;i++) {
        cin >> seq[i];
    }
    for(int i=0;i<m;i++) {
        cin >> t[i];
    }
    qs[0] = t[0];
    for(int i=1;i<m;i++) qs[i] = qs[i-1] + t[i]; //qs[n-1] = full loop
    for(int i=0;i<n;i++) {
        int a, b;
        int total = 0;
        cin >> a >> b;

        for(int j=0;j<m;j++) {
            int curr = seq[j];
            int dest = seq[(j+1)%m];

            int direct = calDist(curr, dest);
            int portala = calDist(curr, a) + calDist(b, dest);
            int portalb = calDist(curr, b) + calDist(a, dest);
            // cout << "direct: " << curr << "->" << dest << " = " << direct << "\n";
            // cout << "portala: " << curr << "->" << a << " = " << calDist(curr,a) << ",  " << b << "->" << dest << " = " << calDist(b,dest) << "\n";
            // cout << "portala: " << curr << "->" << b << " = " << calDist(curr,b) << ",  " << a << "->" << dest << " = " << calDist(a,dest) << "\n";
            total += min(direct, min(portala, portalb));
        }
        cout << total << "\n";
    }
}