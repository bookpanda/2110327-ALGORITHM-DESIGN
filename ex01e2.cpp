#include<bits/stdc++.h>
using namespace std;

int getSum(int st, int ed, vector<int> &qs) {
    if(st-1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int mcs(int st, int ed, vector<int> &v, vector<int> &qs) {
    // cout << "st=" << st << ", ed=" << ed << "\n";
    if(st == ed) return v[st];

    int mid = (st+ed)/2;
    int lefthalf = mcs(st, mid, v, qs);
    int righthalf = mcs(mid+1, ed, v, qs);
    int maxhalf = max(lefthalf, righthalf);

    int left = v[mid];
    for(int i=st;i<mid;i++) {
        left = max(left, getSum(i, mid, qs));
    }
    int right = v[mid+1];
    for(int i=mid+1;i<=ed;i++) {
        right = max(right, getSum(mid+1, i, qs));
    }
    int middle = left + right;

    return max(middle, maxhalf);
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
    for(int i=1;i<n;i++) {
        qs.push_back(qs[i-1]+v[i]);
    }
    int ans = mcs(0, n-1, v, qs);
    cout << ans << "\n";
}