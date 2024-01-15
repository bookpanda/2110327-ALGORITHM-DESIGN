#include<bits/stdc++.h>
using namespace std;

vector<int> before;
bool used[20];
int n;

void recur(int lvl, vector<int> &v) {
    if(lvl == n) {
        for(int i=0;i<n;i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0;i<n;i++) {
        if(used[i]) continue;

        if(before[i] != -1 && !used[before[i]]) {
            // cout << "before (" << before[i] << ") of " << i << " is not used\n";
            continue;
        }

        used[i] = true;
        v[lvl] = i;
        recur(lvl+1, v);
        used[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;

    cin >> n >> m;
    before.resize(n);
    for(int i=0;i<n;i++) before[i] = -1;

    while(m--) {
        int ai,bi;
        cin >> ai >> bi;
        before[bi] = ai;
    }
    vector<int> v(n);
    recur(0, v);

}