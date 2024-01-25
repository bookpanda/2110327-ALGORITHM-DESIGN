#include<bits/stdc++.h>
using namespace std;

int n,k;
int cou = 1;
void mess(vector<int> &v, int st, int ed) {
    if(ed-st == 1) return;
    if(cou == k) {
        for(int i=0;i<n;i++)
            cout << v[i] << " ";
        exit(0);
    } else if(cou > k) return;

    int mid = (st+ed)/2;
    for (int i=0;i<mid-st;i++) {
        // tmp = a[f+i];
        // a[f+i] = a[m+i];
        // a[m+i] = tmp;
        swap(v[st+i], v[mid+i]);
    }
    // int sz = ed-st;
    // int l=st, r=ed-1;
    // for(int i=0;i<sz/2;i++) {
    //     swap(v[l++], v[r--]);
    // }

    cou+=2;
    if(cou == k) {
        for(int i=0;i<n;i++)
            cout << v[i] << " ";
        exit(0);
    } else if(cou > k) return;

    mess(v, st, mid);
    mess(v, mid, ed);
}

int main() {
    vector<int> v;

    cin >> n >> k;
    
    for(int i=1;i<=n;i++) {
        v.push_back(i);
    }

    mess(v, 0, n);
    if(cou == k) {
        for(int i=0;i<n;i++)
            cout << v[i] << " ";
        exit(0);
    }
    
    cout << -1;    
}