#include<bits/stdc++.h>
using namespace std;
int n;
int cou[5];
vector<int> v;

int main() {
    int ans = 0;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        cou[v[i]]++;
    }
    int idx=cou[1];
    for(int i=0;i<cou[1];i++) {
        if(v[i] == 2) {
            while(idx < n && v[idx] != 1) {
                idx++;
            }
            swap(v[idx], v[i]);
            ans++;
        }
    }
    for(int i=0;i<cou[1];i++) {
        if(v[i] == 3) {
            while(idx < n && v[idx] != 1) {
                idx++;
            }
            swap(v[idx], v[i]);
            ans++;
        }
    }
    for(int i=cou[1];i<cou[1]+cou[2];i++) {
        if(v[i] == 3) {
            // while(idx < n && v[idx] != 2) {
            //     idx++;
            // }
            // swap(v[idx], v[i]);
            ans++;
        }
    }
    // for(int i=0;i<n;i++) {
    //     cout << v[i] << " ";
    // } cout << "\n";

    cout << ans << "\n";
}