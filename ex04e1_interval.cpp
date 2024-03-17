#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> st, ed;
vector<pair<int, int > > v;


int main() {
    cin >> n;
    st.resize(n);
    ed.resize(n);
    for(int i=0;i<n;i++) {
        cin >> st[i];
    }
    for(int i=0;i<n;i++) {
        cin >> ed[i];
        v.push_back({ed[i], st[i]});
    }
    sort(v.begin(), v.end());

    int last=-1, ans=0;
    for(int i=0;i<n;i++) {
        if(v[i].second >= last) {
            last = v[i].first;
            ans++;
        }
    }
    cout << ans << "\n";
}