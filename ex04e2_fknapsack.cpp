#include<bits/stdc++.h>
using namespace std;
double W;
int n;
vector<double> v, w;
vector<pair<double, pair<double, double> > > val;

int main() {
    cin >> W >> n;
    v.resize(n);
    w.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> w[i];

    val.resize(n);
    for(int i=0;i<n;i++) {
        val[i] = {v[i] / w[i], {w[i], v[i]}};
    }
    sort(val.begin(), val.end());
    reverse(val.begin(), val.end());

    int idx = 0;
    double totalw = 0, totalv = 0;
    while(idx < n && totalw < W) {
        double vpw = val[idx].first;
        double aw = val[idx].second.first;
        double wholeval = val[idx].second.second;
        if(vpw <= 0) break;
        double space = min(W - totalw, aw);
        if(space >= aw) totalv += wholeval;
        else totalv += space * vpw;
        totalw += space;
        // cout << "item vpw = " << vpw << ", add w=" << space << "\n";
        idx++;
    }

    printf("%.4lf\n", totalv);
}