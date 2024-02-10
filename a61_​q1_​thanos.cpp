#include<bits/stdc++.h>
using namespace std;
int p, k, a, b;

int findAvCou(int st, int ed, vector<int> &v) {
    return upper_bound(v.begin(), v.end(), ed) - lower_bound(v.begin(), v.end(), st);
}

long long cook(int st, int ed, vector<int> &v) {
    if(st > ed) return LLONG_MAX;

    int mid = (st+ed) / 2;
    int length = (ed-st)+1;
    int avCou = findAvCou(st, ed, v);
    long long whole = avCou == 0 ? a : (long long)b * avCou * length;
    if(st == ed || avCou == 0) return whole;
    // cout << st << ", " << ed << "\n";
    // cout << "half=" << half << ", whole=" << whole << "\n";
    long long half = cook(mid+1, ed, v) + cook(st, mid, v);

    return min(half, whole);
}

int main() {
    vector<int> v;
    cin >> p >> k >> a >> b;
    int length = 1 << p;
    for(int i=0;i<k;i++) {
        int power;
        cin >> power;
        v.push_back(power);
    }
    sort(v.begin(), v.end());
    long long ans = cook(1, length, v);
    cout << ans << "\n";
}