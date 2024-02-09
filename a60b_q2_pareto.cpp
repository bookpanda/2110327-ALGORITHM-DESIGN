#include<bits/stdc++.h>
using namespace std;

vector<int> pareto(vector<pair<int,int> > &v, int l,int r) {
    // cout << "l=" << l << ", r=" << r << "\n";
    if(l > r) return {};
    if(l == r) return {l};
    
    int mid = (l+r)/2;
    vector<int> prtl = pareto(v, l, mid);
    vector<int> prtr = pareto(v, mid+1, r);
    vector<pair<pair<int,int>, int> > tmp;
    for(auto x: prtl) tmp.push_back({v[x], x});
    for(auto x: prtr) tmp.push_back({v[x], x});
    sort(tmp.begin(), tmp.end());

    vector<int> ans;
    int maxy = -1;
    for(int i=tmp.size()-1;i>=0;i--) {
        maxy = max(maxy, tmp[i].first.second);
        if(tmp[i].first.second >= maxy) ans.push_back(tmp[i].second);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    vector<int> ans = pareto(v, 0, n-1);
    cout << ans.size() << "\n";
}