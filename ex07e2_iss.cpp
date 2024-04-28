#include<bits/stdc++.h>
using namespace std;
int n, cou=0;

void cook(int sum, int last) {
    // cout << sum << ", " << last << "\n";
    if(sum == n) {
        cou++;
        return;
    }
    for(int i=last;i<=n-sum;i++) {
        cook(sum+i, i);
    }
}

int main() {
    cin >> n;
    cook(0, 1);
    cout << cou << "\n";
}