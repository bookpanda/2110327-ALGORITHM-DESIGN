#include<bits/stdc++.h>
using namespace std;
int n, m, k;
priority_queue<pair<int, pair<int, int> > > event;

int main() {
    cin >> n >> m >> k;
    queue<int> fac, store;
    for(int kp=0;kp<k;kp++) {
        int d, e, l;
        cin >> d >> e >> l;
        event.push({-d, {e, l}});
    }
    while(!event.empty()) {
        int e = event.top().second.first;
        int l = event.top().second.second;
        event.pop();
        if(e == 0) {
            fac.push(l);
            if(!store.empty()) {
                cout << store.front() << "\n";
                store.pop();
                fac.pop();
            } else cout << "0\n";
        } else {
            store.push(l);
            if(!fac.empty()) {
                cout << fac.front() << "\n";
                fac.pop();
                store.pop();
            } else cout << "0\n";
        }

    }
}