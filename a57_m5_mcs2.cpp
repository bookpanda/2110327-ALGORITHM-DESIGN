#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v, qs;

int getSum(int st, int ed) {
    if(st - 1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int cook(int st, int ed, int mode) {
    if(st > ed) return mode == 1 ? -INT_MAX : INT_MAX;
    if(st == ed) return v[st];

    int mid = (st + ed) / 2;
    int lefthalf = cook(st, mid, mode);
    int righthalf = cook(mid+1, ed, mode);
    int half = mode == 1 ? max(lefthalf, righthalf) : min(lefthalf, righthalf);

    int left = v[mid];
    for(int i=mid-1;i>=st;i--) {
        int sum = getSum(i, mid);
        left = mode == 1 ? max(left, sum) : min(left, sum);
    }
    int right = v[mid+1];
    for(int i=mid+2;i<=ed;i++) {
        int sum = getSum(mid+1, i);
        right = mode == 1 ? max(right, sum) : min(right, sum);
    }
    int ans = mode == 1 ? max(half, left+right) : min(half, left+right);

    // cout << "st= " << st << ", ed= " << ed << ", ans = " << ans << "\n";

    return ans;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    qs.push_back(v[0]);
    for(int i=1;i<n;i++) qs.push_back(v[i] + qs[i-1]);

    int mcs1 = cook(0, n-1, 1);
    int minmcs = cook(0, n-1, -1);
    if(minmcs == qs[n-1]) {
        cout << mcs1 << "\n";
    } else {
        int mcs2 = qs[n-1] - minmcs;
        // cout << mcs1 << ", " << minmcs << ", mcs2 = " << mcs2 << "\n";
        cout << max(mcs1, mcs2) << "\n";
    }
}