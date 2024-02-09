#include<bits/stdc++.h>
using namespace std;
int n, r, c;
vector<pair<int, pair<int,int> > > v;

void cook(int r1, int r2, int c1, int c2, int hr, int hc) {
    if(r2 - r1 == 1) {
             if(hr == r1 && hc == c1) v.push_back({0, {r1, c1}});
        else if(hr == r1 && hc == c2) v.push_back({1, {r1, c1}});
        else if(hr == r2 && hc == c1) v.push_back({2, {r1, c1}});
        else if(hr == r2 && hc == c2) v.push_back({3, {r1, c1}});
        return;
    }

    int midr = (r2+r1)/2;
    int midc = (c2+c1)/2;
    if(hr <= midr && hc <= midc) { // top left
        v.push_back({0, {midr, midc}});
        cook(r1,    midr,    c1,     midc,    hr,     hc);
        cook(r1,    midr,    midc+1,  c2,     midr,    midc+1);
        cook(midr+1, r2,     c1,     midc,    midr+1,  midc);
        cook(midr+1, r2,     midc+1,  c2,     midr+1,  midc+1);
    } else if(hr <= midr && hc > midc) { // top right
        v.push_back({1, {midr, midc}});
        cook(r1,    midr,    c1,     midc,    midr,    midc);
        cook(r1,    midr,    midc+1,  c2,     hr,     hc);
        cook(midr+1, r2,     c1,     midc,    midr+1,  midc);
        cook(midr+1, r2,     midc+1,  c2,     midr+1,  midc+1);
    } else if(hr > midr && hc <= midc) { // bottom left
        v.push_back({2, {midr, midc}});
        cook(r1,    midr,    c1,     midc,    midr,    midc);
        cook(r1,    midr,    midc+1,  c2,     midr,    midc+1);
        cook(midr+1, r2,     c1,     midc,    hr,     hc);
        cook(midr+1, r2,     midc+1,  c2,     midr+1,  midc+1);
    } else if(hr > midr && hc > midc) { // bottom right
        v.push_back({3, {midr, midc}});
        cook(r1,    midr,    c1,     midc,    midr,    midc);
        cook(r1,    midr,    midc+1,  c2,     midr,    midc+1);
        cook(midr+1, r2,     c1,     midc,    midr+1,  midc);
        cook(midr+1, r2,     midc+1,  c2,     hr,     hc);
    }
    return;
}

int main() {
    cin >> n >> c >> r;

    cook(0, n-1, 0, n-1, r, c);
    cout << v.size() << "\n";
    for(auto x: v) {
        cout << x.first << " " << x.second.second << " " << x.second.first << "\n";
    }
}