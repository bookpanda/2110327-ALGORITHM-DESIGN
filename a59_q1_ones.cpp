#include<bits/stdc++.h>
using namespace std;

int minone=10000;

int addend(int dig) {
    int sum=1;
    dig--;
    while(dig--) {
        sum *= 10;
        sum += 1;
    }
    return sum;
}

void cook(int n, int onecou, int dig) {
    // cout << "n=" << n << ", onecou=" << onecou << "\n";
    if(n < 11) {
        //11 -1-1-1-1 = 7 use 6, 8 use 5, 9 use 4, 10 use 3
        if(n >= 7) onecou += 11-n+2;
        else onecou += n;
        minone = min(minone, onecou);
        return;
    }
    int num = addend(dig);
    int k = n/num;
    // cout << "num=" << num << ", dig=" << dig << "\n";
    cook(n - k*num, onecou + k*dig, dig-1);
    cook((k+1)*num - n, onecou + (k+1)*dig, dig-1);
}

int main() {
    int n;
    cin >> n;
    // int num = addend(getDig(n)+1);
    int num = 11;
    int cou=2;
    while(num < n) {
        num *= 10;
        num++;
        cou++;
    }
    cook(num-n, cou, cou);
    cook(n, 0, cou-1);
    cout << minone << "\n";
}