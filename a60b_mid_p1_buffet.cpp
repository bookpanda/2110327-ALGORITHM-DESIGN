#include<bits/stdc++.h>
using namespace std;
int f, w, n;
vector<int> v;

int main() {
    cin >> f >> w >> n;
    v.resize(f);
    for(int i=0;i<f;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int maxcover = -1;
    int cou = 0;
    for(int i=0;i<f;i++) {
        if(maxcover < v[i]) {
            maxcover = v[i] + 2*w;
            cou++;
        }
    }
    cout << cou << "\n";
}