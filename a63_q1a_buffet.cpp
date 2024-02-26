#include<bits/stdc++.h>
using namespace std;
int n, k, m;
vector<int> f, qs;

int getSum(int st, int ed) {
    if(st-1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        f.push_back(a - m);
    }
    qs.push_back(f[0]);
    for(int i=1;i<n;i++) qs.push_back(qs[i-1] + f[i]);

    for(int i=0;i<k;i++) {
        int st, want;
        cin >> st >> want;
        st--;

        int high = n-1;
        int low = st;
        int mid = (high+low)/2;
        int minId = INT_MAX;
        // cout << "want " << want << "\n";
        while(low <= high) {
            int sum = getSum(st, mid);
            // cout << "mid = " << mid << ", sum=" << sum << "\n";
            if(sum >= want) {
                minId = min(minId, mid);
                high = mid-1;
                mid = (high+low)/2;
            } else {
                low = mid+1;
                mid = (high+low)/2;
            }
        }

        cout << minId+1 << "\n";
    }
}