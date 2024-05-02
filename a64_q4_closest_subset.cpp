#include<bits/stdc++.h>
using namespace std;
int n, m, k, ans = INT_MAX;
vector<int> v, qs;

int hrt(int idx, int sum, int sel) {
    int need = m - sel;
    int maxSum = idx > 0 ? qs[idx-1 + need] - qs[idx-1] + sum : qs[idx-1 + need] + sum;
    // int maxSum = qs[need-1] + sum;
    int minSum = n-1-need >= 0 ? qs[n-1] - qs[n-1-need] + sum : qs[n-1] + sum;
    if(k < minSum) return minSum - k;
    if(k > maxSum) return k - maxSum;
    return 0;
}

void cook(int idx, int sum, int sel) {
    if(sel == m) {
        ans = min(ans, abs(sum - k));
        return;
    }
    if(hrt(idx, sum, sel) > ans) return;
    if(idx == n) return;

    cook(idx+1, sum, sel);
    cook(idx+1, sum+v[idx], sel+1);
}

int main() {
    cin >> n >> m >> k;
    v.resize(n);
    qs.resize(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    qs[0] = v[0];
    for(int i=1;i<n;i++) {
        qs[i] = qs[i-1] + v[i];
    }
    // cout << "qs : ";
    // for(auto x: qs) {
    //     cout << x << " ";
    // } cout << "\n";

    cook(0, 0, 0);
    cout << ans << "\n";
}