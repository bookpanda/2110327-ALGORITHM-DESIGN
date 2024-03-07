#include<bits/stdc++.h>
using namespace std;
int n;
int len[35];
int mid[35];
// 3
// 343
// 343 5 343
// 3435343 6 3435343

int main() {
    len[0] = 3;
    mid[0] = 3;
    for(int i=1;i<=27;i++) {
        len[i] = 2*len[i-1] + mid[i-1]+1;
        mid[i] = mid[i-1] + 1;
    }
    // for(int a=1;a<=100;a++) {
        cin >> n;
        // n = a;
        // cout << len[27];
        for(int i=27;i>=0;i--) {
            if(len[i] < n) {
                n -= len[i];
                if(mid[i]+1 < n) {
                    n -= mid[i]+1;
                } else { //n is in some mid
                    break;
                }
            }
        }
        if(n==1) cout << "g";
        else cout << "a";
    // }
}