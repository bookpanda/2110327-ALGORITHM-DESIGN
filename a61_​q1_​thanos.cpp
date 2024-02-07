#include<bits/stdc++.h>
using namespace std;
int p,k,a,b;
vector<int> apos;

int findAvCou(int st, int ed) {
    return upper_bound(apos.begin(), apos.end(), ed) - lower_bound(apos.begin(), apos.end(), st);
}

long long thanos(int st, int ed) {   
    int avCou = findAvCou(st, ed);    
    int length = ed-st+1;
    long long effort = (avCou > 0) ? (long long)avCou * length * b : a;

    if(avCou == 0) return effort;
    if(st == ed) return effort;
      
    int mid = (st+ed)/2;
    long long half = thanos(st, mid) + thanos(mid+1, ed);

    return min(half, effort);
}

int main() {
    cin >> p >> k >> a >> b;

    int length = (1 << p);
    while(k--) {
        int pos;
        cin >> pos;
        apos.push_back(pos);
    }
    sort(apos.begin(), apos.end());
    cout << thanos(1, length) << "\n";
}