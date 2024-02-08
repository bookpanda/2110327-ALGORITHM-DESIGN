#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    vector<int> v;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    while(m--) {
        int lim;

        cin >> lim;
        int high = n-1;
        int low = 0;
        int mid = (high+low)/2;
        int ans = -1;
        while(low <= high) {
            if(v[mid] > lim) {
                high = mid-1;
            } else if(v[mid] <= lim) {
                ans = max(ans, mid);
                low = mid+1;
            }
            mid = (high+low)/2;
        }
        cout << ans << "\n";
    }

}