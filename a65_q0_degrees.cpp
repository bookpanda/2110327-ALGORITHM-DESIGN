#include<bits/stdc++.h>
using namespace std;
int n;
map<int, int> mp;

int main() {
    vector<vector<int> > am;

    cin >> n;
    for(int i=0;i<n;i++) {
        vector<int> v;
        for(int j=0;j<n;j++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        am.push_back(v);
    }

    int maxdeg=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(am[i][j] == 1) {
                // mp[i]++;
                mp[j]++;
                // maxdeg = max(maxdeg, mp[i]);
                maxdeg = max(maxdeg, mp[j]);
            }
        }
    }
    map<int,int> deg;
    for(auto x: mp) {
        // cout << x.first << ", " << x.second << "\n";
        deg[x.second]++;
    }
    for(int i=0;i<=maxdeg;i++) {
        cout << deg[i] << " ";
    }
}