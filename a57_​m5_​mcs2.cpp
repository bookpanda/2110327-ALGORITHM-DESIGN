#include<bits/stdc++.h>
using namespace std;

int getSum(int st, int ed, vector<int> &qs) {
    if(st-1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int mcs(int st, int ed, vector<int> &v, vector<int> &qs, int mode) {
    if(st == ed) return v[st];
    if(st > ed) return mode == 1 ? -INT_MAX : INT_MAX;

    int mid = (st+ed) / 2;
    int lefthalf = mcs(st, mid, v, qs, mode);
    int righthalf = mcs(mid+1, ed, v, qs, mode);
    int maxhalf = mode == 1 ? max(lefthalf, righthalf) : min(lefthalf, righthalf);

    int left = v[mid];
    for(int i=st;i<=mid;i++) {
        left = mode == 1 ? max(left, getSum(i, mid, qs)) : min(left, getSum(i, mid, qs));
    }
    int right = v[mid+1];
    for(int i=mid+1;i<=ed;i++) {
        right = mode == 1 ? max(right, getSum(mid+1, i, qs)) : min(right, getSum(mid+1, i, qs));
    }
    int maxmiddle = left + right;
    
    int ans = mode == 1 ? max(maxhalf, maxmiddle) : min(maxhalf, maxmiddle);
    // cout << st << ", " << ed << "    mode=" << mode << ", ans=" << ans << "\n";
    return ans;
}

int main() {
    int n;
    vector<int> v, qs;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    qs.push_back(v[0]);
    for(int i=1;i<n;i++) qs.push_back(v[i] + qs[i-1]);
    int sum1 = mcs(0, n-1, v, qs, 1);
    int minsum = mcs(0, n-1, v, qs, -1);
    int sum2 = qs[n-1] - minsum;
    // cout << "sum1=" << sum1 << ", minsum=" << minsum << ", sum2=" << sum2 << "\n";
    if(qs[n-1] == minsum) {
        cout << sum1 << "\n";
    } else cout << max(sum1, sum2) << "\n";
}