#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int> > v, vin;

    for(int i=0;i<n;i++) {
        int x, c;
        cin >> x >> c;
        vin.push_back({x, c});
    }
    sort(vin.begin(), vin.end());
    v.push_back(vin[0]);
    for(int i=1;i<n;i++) {
        v.push_back({vin[i].first, v[i-1].second + vin[i].second});
    }
    sort(v.begin(), v.end());
    // cout << "\n";
    // for(auto x: v) {
    //     cout << x.first << ", " << x.second << "\n";
    // }

    while(q--) {
        int idx;
        int ans;
        cin >> idx;
        int high = n - 1;
        int low = 0;
        int mid = (high+low) / 2;
        while(low <= high) {
            // cout << "mid = " << mid << "\n";
            if(v[mid].second >= idx) {
                ans = v[mid].first;
                high = mid - 1;
                mid = (high + low) / 2;
            } else if(v[mid].second < idx) {
                low = mid + 1;
                mid = (high + low) / 2;
            }
        }
        cout << ans << "\n";
    }
}