#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v, qs;
map<pair<int,int>, pair<int, pair<int,int> > > dp;

int getSum(int st, int ed) {
    if(st-1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

pair<int, pair<int,int> > cook(int st, int ed) {
    if(st > ed) return {-INT_MAX, {-1, -1}};
    if(st == ed) return {v[st], {st, st}};
    if(dp.find({st, ed}) != dp.end()) return dp[{st, ed}];

    // cout << "st=" << st << ", ed= " << ed << "\n";

    int mid = (st + ed) / 2;
    pair<int, pair<int,int> > maxhalf = max(cook(st, mid), cook(mid+1, ed));

    int left = v[mid];
    int lidx = mid;
    for(int i=mid-1;i>=st;i--) {
        int sum = getSum(i, mid);
        if(sum > left) {
            left = sum;
            lidx = i;
        }
    }

    int right = v[mid+1];
    int ridx = mid+1;
    for(int i=mid+2;i<=ed;i++) {
        int sum = getSum(mid+1, i);
        if(sum > right) {
            right = sum;
            ridx = i;
        }
    }
    pair<int, pair<int,int> > maxcenter = {left + right, {lidx, ridx}};
    pair<int, pair<int,int> > ans = max(maxhalf, maxcenter);
    dp[{st, ed}] = ans;
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
    for(int i=1;i<n;i++) qs.push_back(qs[i-1] + v[i]);

    pair<int, pair<int,int> > mcs1 = cook(0, n-1);
    pair<int, pair<int,int> > left = cook(0, mcs1.second.first-1);
    pair<int, pair<int,int> > right = cook(mcs1.second.second+1, n-1);
    int ans = mcs1.first + max(0, max(left.first, right.first));
    // cout << mcs1.first << ", " << max(0, max(left.first, right.first)) << ", " << ans << "\n";
    cout << ans << "\n";
}