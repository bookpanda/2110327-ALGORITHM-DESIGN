#include<bits/stdc++.h>
using namespace std;
int n;
long long w;
map<long long, long long> y;

long long getSum(long long st, long long ed) {
    auto it1 = y.lower_bound(st);
    auto it2 = y.upper_bound(ed);
    long long cou=0;
    while(it1 != it2) {
        cou += it1->second;
        it1++;
    }
    return cou;
}

long long cook(long long st, long long ed) {
    if(st > ed) return 0;
    if(st+1 >= ed) return getSum(st, ed);
    if(getSum(st, ed) == 0) return 0;

    // cout << st << ", " << ed << "\n";

    long long u = (ed-st+1) / 3;
    long long v2 = (ed-st+2) / 3;
    long long f1 = cook(st, st+u-1);
    long long f2 = cook(st+u, st+u+v2-1);
    long long f3 = cook(st+u+v2, ed);
    long long worst = min(f1, min(f2, f3));
    long long ans = f1+f2+f3 - worst + getSum(st, ed);
   
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> w >> n;
    for(int i=0;i<n;i++) {
        long long a;
        cin >> a;
        y[a]++;
    }

    long long ans = cook(1, w);
    cout << ans << "\n";
}