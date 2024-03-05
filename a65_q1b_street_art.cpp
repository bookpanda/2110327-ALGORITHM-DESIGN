#include<bits/stdc++.h>
using namespace std;
long long w;
// vector<long long> y;
map<long long, long long> y;
// map<pair<long long, long long>, long long> dp; no need bc it never hit
int n;

long long calScore(long long st, long long ed) {
    // auto it1 = lower_bound(y.begin(), y.end(), st);
    // auto it2 = upper_bound(y.begin(), y.end(), ed);
    auto it1 = y.lower_bound(st);
    auto it2 = y.upper_bound(ed);
    long long total = 0;
    while(it1 != it2) {
        total += it1->second;
        it1++;
    }
    return total;
}

long long cook(long long st, long long ed) {
    if(st > ed) return 0;
    if(ed-st < 2) {
        return calScore(st, ed);
    }
    if(calScore(st, ed) == 0) return 0;

    long long u = (ed-st+1)/3;
    long long v = (ed-st+2)/3;
    long long nst[3] = {st,     st+u,     st+u+v};
    long long ned[3] = {st+u-1, st+u+v-1, ed};
    long long a = cook(nst[0], ned[0]);
    long long b = cook(nst[1], ned[1]);
    long long c = cook(nst[2], ned[2]);
    long long minmeth = min(min(a, b), c);
    
    long long ans = calScore(st, ed) + a + b + c - minmeth;
    // cout << "st = " << st << ", ed=" << ed << ", ans=" << ans << "\n";

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> w >> n;
    y[1] = 0;
    y[w] = 0;
    for(int i=0;i<n;i++) {
        long long a;
        cin >> a;
        y[a]++;
        // y.push_back(a);
    }
    // sort(y.begin(), y.end());

    long long ans = cook(1, w);
    cout << ans << "\n";
}