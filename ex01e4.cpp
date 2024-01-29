#include<bits/stdc++.h>
using namespace std;

long long modex(int x, int n, int k) {
    if(n==1) return x % k;
    long long res = modex(x, n/2, k);
    if(n % 2 == 0) {
        return (res * res) % k;
    } else {
        return ((res * res) % k) * x % k;
    }
}

int main() {
    int x, n, k;

    cin >> x >> n >> k;
    long long ans = modex(x, n, k);
    cout << ans << "\n";
}