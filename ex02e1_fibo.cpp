#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;

int fibo(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    if(mp.find(n) != mp.end()) return mp[n];

    mp[n] = fibo(n-1) + fibo(n-2);
    return mp[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n) << "\n";
}