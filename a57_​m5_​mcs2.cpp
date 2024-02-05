#include<bits/stdc++.h>
using namespace std;

int get_sum(vector<int> &qs, int st, int ed) {
    if(st-1<0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int max_sum(vector<int> &v, vector<int> &qs, int st, int ed, int flip) {
    if(st==ed) return v[st];

    int mid = (st+ed)/2;
    int lefthalf = max_sum(v, qs, st, mid, flip);
    int righthalf = max_sum(v, qs, mid+1, ed, flip);
    int maxhalf;
    if(flip == 1) maxhalf = max(lefthalf, righthalf);
    else if(flip == -1) maxhalf = min(lefthalf, righthalf);

    int leftmax = v[mid];
    for(int i=st;i<=mid;i++) {
        int sum = get_sum(qs, i, mid);
        if(flip == 1) leftmax = max(leftmax, sum);
        else if(flip == -1) leftmax = min(leftmax, sum);
    }
    int rightmax = v[mid+1];
    for(int i=mid+1;i<=ed;i++) {
        int sum = get_sum(qs, mid+1, i);
        if(flip == 1) rightmax = max(rightmax, sum);
        else if(flip == -1) rightmax = min(rightmax, sum);
    }
    int midmax = leftmax + rightmax;

    if(flip == 1) return max(maxhalf, midmax);
    return min(maxhalf, midmax);
}

int main() {
    int n;
    vector<int> v, qs;

    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    qs.push_back(v[0]);
    for(int i=1;i<n;i++) {
        qs.push_back(qs[i-1] + v[i]);
    }

    int ms1 = max_sum(v, qs, 0, n-1, 1);
    int minsum = max_sum(v, qs, 0, n-1, -1);
    if(qs[n-1] == minsum) {
        cout << ms1 << "\n";
        return 0;
    }
    int ms2 = qs[n-1] - minsum;
    // cout << "ms1 " << ms1 << ", minsum " << minsum << ", ms2 " << ms2 << "\n";

    cout << max(ms1, ms2) << "\n";
}