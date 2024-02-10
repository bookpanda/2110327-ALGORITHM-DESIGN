#include<bits/stdc++.h>
using namespace std;

int max_sum(vector<int> &v, int st, int ed, int w) {
    if(st > ed) return 0;
    if(st==ed) return v[st];

    int mid = (st+ed)/2;
    int lefthalf = max_sum(v, st, mid, w);
    int righthalf = max_sum(v, mid+1, ed, w);
    int maxhalf = max(lefthalf, righthalf);

    vector<int> bqs;
    bqs.push_back(v[mid+1]);
    for(int i=mid+2;i<=ed;i++) bqs.push_back(bqs[i-mid-2] + v[i]);
    for(int i=mid+2;i<=ed;i++) bqs[i-mid-1] = max(bqs[i-mid-2], bqs[i-mid-1]);
    // cout << st << ", " << ed << "\n";
    // cout << "left=" << lefthalf << ", right=" << righthalf << "\n";
    // cout << "bqs:";
    // for(auto x: bqs) {
    //     cout << x << " ";
    // } cout << "\n";

    int maxsum = -INT_MAX;
    int leftsum = 0;
    for(int i=mid;i>=st;i--) {
        leftsum += v[i];
        int edidx = min(i+w-1, ed);
        if(edidx < mid+1 || edidx - mid - 2 < 0) break;
        int sum = leftsum + bqs[edidx - mid - 2];
        // cout << "leftest=" << i << ", edidx=" << edidx << ", leftsum=" << leftsum << ", bqs=" << bqs[edidx - mid - 2] << "\n";
        maxsum = max(maxsum, sum);
    }
    
    return max(maxsum, maxhalf);
}

int main() {
    int n, w;
    vector<int> v;

    cin >> n >> w;
    if(w<1) return 0;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int ans = max_sum(v, 0, n-1, w);
    cout << ans << "\n";
}