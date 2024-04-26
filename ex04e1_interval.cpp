#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> stv, edv;
vector<pair<int, int> > v;

int main() {
    cin >> n;
    stv.resize(n);
    edv.resize(n);
    for(int i=0;i<n;i++) cin >> stv[i];
    for(int i=0;i<n;i++) cin >> edv[i];
    for(int i=0;i<n;i++) v.push_back({edv[i], stv[i]});
    sort(v.begin(), v.end());
    int cou=0, edt=-1;
    for(int i=0;i<n;i++) {
        int st = v[i].second;
        int ed = v[i].first;
        if(edt <= st) {
            edt = ed;
            cou++;
        }
    }
    cout << cou << "\n";
}