#include<bits/stdc++.h>
using namespace std;

int cook(int x, int n, int k) {
    if(n == 0) return 1;
    int ans = cook(x, n/2, k);
    if(n % 2 == 1) return ((ans*ans)%k) * x % k;
    return (ans*ans)%k;
}

int main() {
    int x, n, k;
    cin >> x >> n >> k;
    cout << cook(x, n ,k) << "\n";
}