#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    vector<int> v;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    while(m--) {
        long long no;
        cin >> no;
        
        no -= n;
        if(no <= 0) {
            cout << 0 << "\n";
            continue;
        }
        long long ans = LLONG_MAX;
        long long high = LLONG_MAX;
        long long low = 0;
        long long mid = (high+low)/2;
        while(low <= high) {
            // cout << "mid = " << mid << "\n";
            long long sum = 0;
            for(int i=0;i<n;i++) {
                sum += mid / v[i];
            }
            if(sum >= no || sum < 0) {
                // cout << "sum >= no\n";
                ans = min(ans, mid);
                high = mid-1;
                mid = (high+low)/2;
            } else {
                // cout << "sum < no\n";
                low = mid+1;
                mid = (high+low)/2;
            }
        }
        cout << ans << "\n";
    }
}