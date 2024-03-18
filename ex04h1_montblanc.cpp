#include<bits/stdc++.h>
using namespace std;
int n, d;
vector<int> v;

int main() {
    cin >> n >> d;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int high = v[n-1];
    int low = 1;
    int mid = (high+low)/2;
    int ans = INT_MAX;
    int ansdays = -1;
    while(low <= high) {
        int y = 0;
        int days = 0;
        int idx=0;
        bool kTooSmall = false;
        while(1) {
            // y += mid;
            days++;
            while(idx<n && v[idx] <= y+mid) {
                idx++;
            }
            idx--;
            if(y == v[idx]) {
                kTooSmall = true;
                break;
            }
            y = v[idx];
            // cout << "day " << days << ", sleep at " << v[idx] << "\n";
            if(idx == n-1) break;
        }
        // cout << "k = " << mid << ", takes days=" << days << "\n";

        if(days > d || kTooSmall) { //too slow
            low = mid+1;
            mid = (high+low)/2;
        } else if(days <= d) { //too fast
            if(ans > mid) {
                ans = mid;
                ansdays = days;
            }
            high = mid-1;
            mid = (high+low)/2;
        }
    }
    cout << ans << " " << ansdays << "\n";
}