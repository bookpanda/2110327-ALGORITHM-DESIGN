#include<bits/stdc++.h>
using namespace std;

int n;
int cou = 0;
vector<int> v;

void merge(vector<int> &arr, int st, int mid, int ed) {
    // cout << "merge " << st << ", " << mid << " , " << ed << "\n";
    vector<int> l, r;
    for(int i=st;i<=mid;i++) {
        l.push_back(arr[i]);
    }
    for(int i=mid+1;i<=ed;i++) {
        r.push_back(arr[i]);
    }

    int li=0, ri=0;
    int idx=st;
    while(li<l.size() && ri<r.size()) {
        if(l[li] <= r[ri]) {
            arr[idx++] = l[li++];
        }
        else {
            // cout << r[ri] << " comes bef " << l[li] << "\n";
            cou+=l.size()-li;
            arr[idx++] = r[ri++];
        }
    }
    while(li<l.size()) {
        arr[idx++] = l[li++];
    }
    while(ri<r.size()) {
        arr[idx++] = r[ri++];
    }
}

void mergeSort(vector<int> &arr, int st, int ed) {
    // cout << "mergeSort " << st << ", " << ed << "\n";
    if(st >= ed) return;
    int mid = (st+ed-1) / 2;

    mergeSort(arr, st, mid);
    mergeSort(arr, mid+1, ed);
    merge(arr, st, mid, ed);   
}


int main() {
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    mergeSort(v, 0, n-1);
    cout << cou << "\n";

}