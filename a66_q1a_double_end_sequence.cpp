#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v, qs;

int getSum(int st, int ed) {
    if(st-1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int cook(int st, int ed) {
    if(st > ed) return -INT_MAX;
    if(st == ed) return v[st];

    int mid = (st + ed) / 2;
    int maxhalf = max(cook(st, mid), cook(mid+1, ed));

    map<int, int> mp;
    int left = 0;
    for(int i=mid;i>=st;i--) {
        left += v[i];
        if(mp.find(v[i]) == mp.end()) mp[v[i]] = -INT_MAX;
        mp[v[i]] = max(mp[v[i]], left);
    }
    int maxsum = -INT_MAX;
    for(int i=mid+1;i<=ed;i++) {
        if(mp.find(v[i]) == mp.end()) continue;

        int sum = getSum(mid+1, i);
        maxsum = max(maxsum, mp[v[i]] + sum);
    }

    return max(maxsum, maxhalf);
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    qs.push_back(v[0]);
    for(int i=1;i<n;i++) qs.push_back(qs[i-1] + v[i]);
    int ans = cook(0, n-1);
    cout << ans << "\n";
}