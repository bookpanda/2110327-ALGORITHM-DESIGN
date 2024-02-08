#include<bits/stdc++.h>
using namespace std;

int cook(vector<int> &v, int lim, int n) {
    int high = n-1;
    int low = 0;
    int mid = (high+low)/2;
    int ans = -1;
    while(low <= high) {
        if(v[mid] <= lim) {
            ans = max(ans, v[mid]);
            low = mid+1;
        } else {
            high = mid-1;
        }
        mid = (high+low)/2;
    }
    return ans;
}

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
        int ans = cook(v, lim, n);
        cout << ans << "\n";
    }

}