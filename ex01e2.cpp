#include<bits/stdc++.h>
using namespace std;

int get_sum(vector<int> &qs, int st, int ed) {
    if(st-1<0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int max_sum(vector<int> &v, vector<int> &qs, int st, int ed) {
    if(st==ed) return v[st];

    int mid = (st+ed)/2;
    int left = max_sum(v, qs, st, mid);
    int right = max_sum(v, qs, mid+1, ed);
    int maxdiv = max(left, right);

    int leftmax = v[mid];
    for(int i=st;i<=mid;i++) {
        leftmax = max(leftmax, get_sum(qs, i, mid));
    }

    int rightmax = v[mid+1];
    for(int i=mid+1;i<=ed;i++) {
        rightmax = max(rightmax, get_sum(qs, mid+1, i));
    }
    // cout << "st " << st << ", ed " << ed << ", mid " << mid << ", left=" << left << ", right=" << right << " ,  leftmax=" << leftmax << " , rightmax=" << rightmax << "\n";
    return max(maxdiv, leftmax+rightmax);
}

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<int> qs;
    qs.resize(n);
    qs[0] = v[0];
    for(int i=1;i<n;i++) qs[i] = qs[i-1] + v[i];
   
    // for(int i=0;i<n;i++) {
    //     cout << qs[i] << " ";
    // }
    // cout << "\n";

    cout << max_sum(v, qs, 0, n-1) << "\n";
}