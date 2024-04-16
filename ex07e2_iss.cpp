#include<bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;

    queue<pair<int, int> > q;
    q.push({0, 1});
    int cou = 0;
    while(!q.empty()) {
        int num = q.front().first;
        int last = q.front().second;
        q.pop();
        if(num == n) cou++;

        for(int i=last;i<=n;i++) {
            int nn = num + i;
            if(nn <= n) {
                q.push({nn, i});
            }
        }
    }
    cout << cou << "\n";
}