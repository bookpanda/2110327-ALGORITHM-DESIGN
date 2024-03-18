#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, pair<int,int> > > input;
queue<int> p, s;

int main() {
    cin >> n >> m >> k;
    input.resize(k);
    for(int i=0;i<k;i++) {
        cin >> input[i].first >> input[i].second.first >> input[i].second.second;
    }
    sort(input.begin(), input.end());

    for(int i=0;i<k;i++) {
        int day = input[i].first;
        int command = input[i].second.first;
        if(command == 0) {
            int plant = input[i].second.second;
            if(s.empty()) {
                p.push(plant);
                cout << "0\n";
            } else {
                cout << s.front() << "\n";
                s.pop();
            }

        } else if(command == 1) {
            int store = input[i].second.second;
            if(p.empty()) {
                s.push(store);
                cout << "0\n";
            } else {
                cout << p.front() << "\n";
                p.pop();
            }
        }
    }
}