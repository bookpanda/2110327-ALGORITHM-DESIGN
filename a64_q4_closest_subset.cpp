#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> num, qs;
int ans = INT_MAX;

int maxSum(int step, int sel) {
    int quota = m - sel;
    return qs[quota];
}

int minSum(int step, int sel) {
    int quota = m - sel;
    return qs[n-1] - qs[n-1-quota];
}

int heuristic(int step, int sel, int sum) {
    int saitei = sum + minSum(step, sel);
    int saikou = sum + maxSum(step, sel);
    if(k < saitei) return saitei - k;
    if(k > saikou) return k - saikou;
    return 0;
}

void cook(int step, int sel, int sum) {
    // cout << "step " << step << ", sel " << sel << ", sum " << sum << "\n";
    // if(sum + tail[step] > ans) return;
    if(sel == m) {
        // cout << "sum = " << sum << "\n";
        ans = min(ans, abs(k - sum));
        return;
    }
    if(step == n) return;
    if(heuristic(step, sel, sum) > ans) return;

    int newsum = sum + num[step];
    if(sel < m)
    cook(step+1, sel+1, newsum);

    cook(step+1, sel, sum);
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
    reverse(num.begin(), num.end());
    qs[0] = num[0];
    for(int i=1;i<n;i++) qs[i] = qs[i-1] + num[i];

    cook(0, 0, 0);

    cout << ans << "\n";
}