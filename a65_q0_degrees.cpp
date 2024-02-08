#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    int maxdeg = 0;
    vector<vector<int> > v;
    for(int i=0;i<n;i++) {
        vector<int> tmp;
        for(int j=0;j<n;j++) {
            int a;
            cin >> a;
            tmp.push_back(a);
            if(a == 1) {
                mp[i]++;
                mp[j]++;
                maxdeg = max(maxdeg, max(mp[i]/2, mp[j]/2));
            }
        }
        v.push_back(tmp);
    }
    map<int, int> s;
    for(int i=0;i<=maxdeg;i++) s[i] = 0;
    for(auto &x: mp) {
        // cout << "node " << x.first << " have deg=" << x.second << "\n";
        int deg = x.second / 2;
        s[deg]++;
    }
    for(auto &x: s) {
        cout << x.second << " ";
    }
}