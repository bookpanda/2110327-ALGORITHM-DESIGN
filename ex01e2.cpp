#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v, qs;

int getSum(int st, int ed) {
    if(st-1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int mcs(int st, int ed) {
    if(st > ed) return -INT_MAX;
    if(st == ed) return v[st];
    // cout << "st=" << st << ", ed=" << ed << "\n";

    int mid = (st+ed) / 2;
    int maxhalf = max(mcs(st, mid), mcs(mid+1, ed));

    int left = v[mid];
    for(int i=st;i<mid;i++) {
        left = max(left, getSum(i, mid));
    }
    int right = v[mid+1];
    for(int i=mid+2;i<=ed;i++) {
        right = max(right, getSum(mid+1, i));
    }
    int midsum = left + right;

    return max(midsum, maxhalf);
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

    cout << mcs(0, n-1) << "\n";
}