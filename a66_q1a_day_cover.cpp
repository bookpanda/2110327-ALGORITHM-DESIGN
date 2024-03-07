#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > v;
vector<int> days;
int cou = 0, mincou=INT_MAX;

void recur(int lvl) {
    if(lvl == m) {
        for(int i=1;i<=n;i++) if(days[i] < 1) return;
        mincou = min(mincou, cou);
        return;
    }

    recur(lvl+1);

    for(int i=0;i<v[lvl].size();i++) {
        days[v[lvl][i]]++;
    }
    cou++;
    recur(lvl+1);
    for(int i=0;i<v[lvl].size();i++) {
        days[v[lvl][i]]--;
    }
    cou--;

}

int main() {
    cin >> n >> m;
    days.resize(n+1);
    for(int i=0;i<m;i++) {
        vector<int> tmp;
        int s;
        cin >> s;
        for(int j=0;j<s;j++) {
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        v.push_back(tmp);
    }
    recur(0);
    cout << mincou << "\n";
}