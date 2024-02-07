#include<bits/stdc++.h>
using namespace std;

bool canShoot(int xMon, int xCannon, int r) {
    return abs(xCannon - xMon) <= r;
}

int main() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> mpos, mhp, tpos;
    vector<pair<int,int > > mon;
    mpos.resize(m);
    mhp.resize(m);
    tpos.resize(k);
    mon.resize(m);
    for(int i=0;i<m;i++) cin >> mpos[i];
    for(int i=0;i<m;i++) cin >> mhp[i];
    for(int i=0;i<k;i++) cin >> tpos[i];
    for(int i=0;i<m;i++) mon.push_back({mpos[i], mhp[i]});
    sort(tpos.begin(), tpos.end());
    sort(mon.begin(), mon.end());

    int mid=0;
    for(int i=0;i<k;i++) {
        while(mid < mon.size() && (!canShoot(tpos[i], mon[mid].first, w) || mon[mid].second == 0)) {
            if(mon[mid].first - tpos[i] > w) break;
            mid++;
        }
        if(mid < mon.size() && canShoot(tpos[i], mon[mid].first, w) && mon[mid].second > 0) {
            mon[mid].second--;
        }
    }
    int totalhp = 0;
    for(auto x: mon) { 
        totalhp += x.second;
    }
    
    cout << totalhp << "\n";
}