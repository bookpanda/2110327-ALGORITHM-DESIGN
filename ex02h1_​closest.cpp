#include<bits/stdc++.h>
using namespace std;

int dist(pair<int,int> p1, pair<int,int> p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return dx*dx + dy*dy;
}

int cp(vector<pair<int,int> > &vx) {
    if(vx.size() == 1) return INT_MAX;
    if(vx.size() == 2) return dist(vx[0], vx[1]);
    int mid = vx.size() / 2;

    vector<pair<int,int> > vxl, vxr;
    for(int i=0;i<mid;i++) {
        vxl.push_back(vx[i]);
    }
    for(int i=mid+1;i<vx.size();i++) {
        vxr.push_back(vx[i]);
    }

    int minl = cp(vxl);
    int minr = cp(vxr);
    int b = min(minl, minr);
    int midx = (vx[mid].first + vx[mid+1].first) / 2;

    vector<pair<int,int> > vyb;
    for(int i=0;i<vx.size();i++) {
        if(abs(vx[i].first - midx) < b) vyb.push_back({vx[i].second, vx[i].first});
    }
    sort(vyb.begin(), vyb.end());

    int mindist = b;
    for(int i=0;i<vyb.size();i++) {
        for(int j=i+1;j<vyb.size() && (vyb[j].first - vyb[i].first) < b; j++) {
            int dis = dist(vyb[i], vyb[j]);
            mindist = min(mindist, dis);
        }
    }
    return mindist;
}

int main() {
    int n;
    vector<pair<int,int> > vx;

    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        vx.push_back({x, y});
    }
    sort(vx.begin(), vx.end());
    cout << cp(vx);
}