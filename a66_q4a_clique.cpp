#include<bits/stdc++.h>
using namespace std;
int n, f[55][55], ans = -INT_MAX;
vector<int> b, tail;
bool used[55];

void cook(int idx, int sum) {
    if(idx == n) {
        ans = max(ans, sum);
        return;
    }
    if(sum + tail[idx] < ans) return;

    bool canJoin = true;
    for(int i=0;i<idx;i++) {
        if(used[i] && !f[i][idx]) {
            canJoin = false;
            break;
        }
    }
    if(canJoin) {
        used[idx] = true;
        cook(idx+1, sum+b[idx]);
        used[idx] = false;
    }

    cook(idx+1, sum);
}

int main() {
    cin >> n;
    b.resize(n);
    tail.resize(n);
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cin >> f[i][j];
    }
    tail[n-1] = b[n-1];
    for(int i=n-2;i>=0;i--) {
        tail[i] = tail[i+1] + b[i];
    }

    cook(0, 0);
    cout << ans << "\n";
}