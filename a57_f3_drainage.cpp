#include<bits/stdc++.h>
using namespace std;
int n, l;
vector<int> v;

int main() {
    cin >> n >> l;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());

    int maxcover = -1;
    int cou = 0;
    for(int i=0;i<n;i++) {
        if(maxcover < v[i]) {
            cou++;
            maxcover = v[i] + l - 1;
        }
    }
    cout << cou << "\n";
}