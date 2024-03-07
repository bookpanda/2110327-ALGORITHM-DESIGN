#include<bits/stdc++.h>
using namespace std;
int n, w;
vector<int> v;
map<pair<int,int>, int> dp;

int cook(int st, int ed) {
    if(st > ed) return -INT_MAX;
    if(st == ed) return v[st];
    if(dp.find({st, ed}) != dp.end()) return dp[{st, ed}];

    int mid = (st + ed) / 2;
    int maxhalf = max(cook(st, mid), cook(mid+1, ed));

    vector<int> bqs;
    bqs.push_back(v[mid+1]);
    for(int i=mid+2;i<=ed;i++) bqs.push_back(bqs[i-mid-2] + v[i]);
    for(int i=mid+2;i<=ed;i++) bqs[i-mid-1] = max(bqs[i-mid-1], bqs[i-mid-2]);

    // cout << "st=" << st << ", ed=" << ed << "\n";
    // for(auto x: bqs) {
    //     cout << x << " ";
    // }
    // cout << "\n";

    int left = 0;
    int ans = -INT_MAX;
    for(int i=mid;i>=st;i--) {
        left += v[i];
        int leftlen = mid-i+1;
        int rightlen = w - leftlen;
        if(rightlen <= 0) break;
        int rightidx = min(int(bqs.size()-1), rightlen-1);
        ans = max(ans, bqs[rightidx] + left);
    }
    ans = max(ans, maxhalf);

    dp[{st, ed}] = ans;
    return ans;
}

int main() {
    cin >> n >> w;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int ans = cook(0, n-1);
    cout << ans << "\n";
}