#include<bits/stdc++.h>
using namespace std;
int n, m;
int order[1010], edge[1010], qs[1010]; 

int calDist(int st, int ed) {
    if(st > ed) swap(st, ed);
    if(st == 0) {
        return min(qs[ed], qs[m] - qs[ed]);
    } else {
        return min(qs[ed] - qs[st], qs[m] - (qs[ed] - qs[st]));
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++) cin >> order[i];
    order[m] = order[0];
    for(int i=1;i<=m;i++) cin >> edge[i];
    qs[0] = 0;
    for(int i=1;i<=m;i++) {
        qs[i] = qs[i-1] + edge[i];
    }//qs[m] = from 0 to 0
    
    for(int day=0;day<n;day++) {
        int pa, pb;
        cin >> pa >> pb;
        int pos1 = order[0];
        int totalsum = 0;
        for(int i=1;i<=m;i++) {
            int pos2 = order[i];
            // cout << "from " << pos1 << " to " << pos2 << "\n";
            //1 no portal
            int dist = calDist(pos1, pos2);
            //2 use portal a
            int dist2 = calDist(pos1, pa) + calDist(pb, pos2);
            //3 use portal b
            int dist3 = calDist(pos1, pb) + calDist(pa, pos2);

            // cout << "no portal dist = " << dist << ", use a = " << dist2 << ", use b = " << dist3 << "\n";
            dist = min(dist, min(dist2, dist3));
            pos1 = pos2;
            totalsum += dist;
        }
        cout << totalsum << "\n";
    }
}