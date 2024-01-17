#include<bits/stdc++.h>
using namespace std;

bool canShoot(int xCannon, int xMonster, int range) {
    return xCannon+range >= xMonster && xCannon-range <= xMonster;
}


int main() {
    int n,m,k,w;
    vector<int> p,h,t;
    vector<pair<int,int> > mon;

    cin >> n >> m >> k >> w;
    p.resize(m);
    h.resize(m);
    t.resize(k);
    for(int i=0;i<m;i++) cin >> p[i]; // coords of monster
    for(int i=0;i<m;i++) cin >> h[i]; // hp
    for(int i=0;i<k;i++) cin >> t[i]; // coords of cannon
    sort(t.begin(), t.end());
    for(int i=0;i<m;i++) {
        mon.push_back({p[i],h[i]});
    }
    sort(mon.begin(), mon.end());

    int midx=0;
    for(int i=0;i<k;i++) {
        // cout << "cannon " << i << " is at tile " << t[i] << "\n";
        while(midx<k && (mon[midx].second<=0 || !canShoot(t[i], mon[midx].first, w))) {
            if(mon[midx].first - t[i] > w) break;
            midx++;
            // cout << "now mon at " << mon[midx].first << "\n";
        }
        if(midx<k && mon[midx].second>0 && canShoot(t[i], mon[midx].first, w)) {
            // cout << "cannon " << i << " shoot monster " << midx << "\n";
            mon[midx].second--;
        }
    }

    int total = 0;
    for(int i=0;i<m;i++){
        // cout << "moster " << i << " has health " << mon[i].second << "\n";
        total += mon[i].second;
    }

    cout << total << "\n";
}