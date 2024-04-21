#include<bits/stdc++.h>
using namespace std;
int n, m, k, ans=INT_MAX;
vector<int> num, qs;

int maxSum(int quota) {
    return qs[quota-1];
}
int minSum(int quota) {
    if(n-1-quota < 0) return qs[n-1];
    return qs[n-1] - qs[n-1-quota];
}
int hrt(int quota, int sum) {
    int minS = sum + minSum(quota);
    int maxS = sum + maxSum(quota);
    if(k < minS) return abs(k - minS);
    if(k > maxS) return abs(k - maxS);
    return 0;
}

void cook(int idx, int quota, int sum) {
    if(quota == 0) {
        ans = min(ans, abs(sum - k));
        return;
    }
    if(idx == n || quota > (n-idx+1)) return;
    int heu = hrt(quota, sum);
    // cout << "idx " << idx << ", q " << quota << ", sum " << sum << ", heu " << heu << ", ans " << ans << "\n";
    if(heu > ans) return;

    cook(idx+1, quota - 1, sum + num[idx]);
    cook(idx+1, quota, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    num.resize(n);
    qs.resize(n);
    for(int i=0;i<n;i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end()); //desc
    qs[0] = num[0];
    for(int i=1;i<n;i++) qs[i] = qs[i-1] + num[i];

    cook(0, m, 0);

    cout << ans << "\n";
}