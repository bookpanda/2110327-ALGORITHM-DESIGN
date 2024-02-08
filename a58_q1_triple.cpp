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
        int sum;
        cin >> sum;
        bool flag = false;
        for(int i=0;i<n-1;i++) {
            int l = i+1;
            int r = n-1;
            while(l < r) {
                int total = v[i] + v[l] + v[r];
                if(sum == total) {
                    cout << "YES\n";
                    flag = true;
                    break;
                } else if(sum > total) l++;
                else r--;
            }
            if(flag) break;
        }
        if(!flag) cout << "NO\n";
    }
}