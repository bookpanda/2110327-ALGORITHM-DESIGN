#include<bits/stdc++.h>
using namespace std;
int n, m, seq[1010], t[1010], qs[1010];

int getSum(int st, int ed) {
    if(st > ed) swap(st, ed);
    if(st == 0) {
        return min(qs[ed-1], qs[m-1]-qs[ed-1]);
    }
    return min(qs[ed-1]-qs[st-1], qs[m-1]-(qs[ed-1]-qs[st-1]));
}

int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++) cin >> seq[i];
    for(int i=0;i<m;i++) cin >> t[i];
    qs[0] = t[0];
    for(int i=1;i<m;i++) {
        qs[i] = t[i] + qs[i-1]; //qs[m-1] = full circle
    }
    // cout << "qs\n";
    // for(int i=0;i<=m;i++) {
    //     cout << qs[i] << " ";
    // }cout << "\n";
    while(n--) {
        int a, b;
        cin >> a >> b;
        int prev = seq[0];
        int totalsum = 0;
        for(int i=1;i<m;i++) {
            int dest = seq[i];
            int straight = getSum(prev, dest);
            int portala = getSum(prev, a) + getSum(b, dest);
            int portalb = getSum(prev, b) + getSum(a, dest);
            // cout << "straight " << straight << ", a " << portala << ", b " << portalb << "\n";
            totalsum += min(straight, min(portala, portalb));
            prev = dest;
        }
        int dest = seq[0];
        int straight = getSum(prev, dest);
        int portala = getSum(prev, a) + getSum(b, dest);
        int portalb = getSum(prev, b) + getSum(a, dest);
        totalsum += min(straight, min(portala, portalb));
        cout << totalsum << "\n";
    }
}