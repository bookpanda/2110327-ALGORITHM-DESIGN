#include<bits/stdc++.h>
using namespace std;
int hr, hc, length;

vector<vector<pair<int,int> > > pat = {{{1,0},{0,1},{1,1}}, {{0,0},{1,0},{1,1}}, {{0,0},{0,1},{1,1}}, {{0,0},{1,0},{0,1}}};
void print(vector<pair<int, pair<int,int> > > &hist) {
    vector<vector<int> > v;
    v.resize(length);
    for(int i=0;i<v.size();i++) v[i].resize(length);
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v[i].size();j++)
            v[i][j] = 0;
    for(auto t: hist) {
        int x = t.second.first;
        int y = t.second.second;
        int i = t.first;
        v[y + pat[i][0].first][x + pat[i][0].second] = i+1;
        v[y + pat[i][1].first][x + pat[i][1].second] = i+1;
        v[y + pat[i][2].first][x + pat[i][2].second] = i+1;
    }
    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[i].size();j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
}

void recur(int top, int bottom, int left, int right, int hr, int hc, vector<pair<int, pair<int,int> > > &hist) {
    int length = bottom - top + 1;
    if(length == 2) {
        // cout << "push " << left << ", " << top << "\n";
        if(hr == top && hc == left)             hist.push_back({0, {left, top}});
        else if(hr == top && hc == right)       hist.push_back({1, {left, top}});
        else if(hr == bottom && hc == left)     hist.push_back({2, {left, top}});
        else if(hr == bottom && hc == right)    hist.push_back({3, {left, top}});
        // cout << top << ", " << left << " to " << bottom << ", " << right << "  hole's r=" << hr << ", c=" << hc << "\n";
        // print(hist);
        return;
    }
    int midr = (bottom+top) / 2;
    int midc = (left+right) / 2;
    if(hr <= midr  && hc <= midc) { //hole in top left
        // cout << "top left\n";
        // cout << "push 0 " << midr << ", " << midc << "\n";
        hist.push_back({0, {midc, midr}});
        recur(top, midr, left, midc,          hr, hc, hist);
        recur(top, midr, midc+1, right,       midr, midc+1, hist);
        recur(midr+1, bottom, left, midc,     midr+1, midc, hist);
        recur(midr+1, bottom, midc+1, right,  midr+1, midc+1, hist);

    } else if(hr <= midr  && hc > midc) { //hole in top right
        // cout << "top right\n";
        // cout << "push 1 " << midr << ", " << midc << "\n";
        hist.push_back({1, {midc, midr}});
        recur(top, midr, left, midc,          midr, midc, hist);
        recur(top, midr, midc+1, right,       hr, hc, hist);
        recur(midr+1, bottom, left, midc,     midr+1, midc, hist);
        recur(midr+1, bottom, midc+1, right,  midr+1, midc+1, hist);

    } else if(hr > midr  && hc <= midc) { //hole in bottom left
        // cout << "btm left\n";
        // cout << "push 2 " << midr << ", " << midc << "\n";
        hist.push_back({2, {midc, midr}});
        recur(top, midr, left, midc,          midr, midc, hist);
        recur(top, midr, midc+1, right,       midr, midc+1, hist);
        recur(midr+1, bottom, left, midc,     hr, hc, hist);
        recur(midr+1, bottom, midc+1, right,  midr+1, midc+1, hist);

    } else if(hr > midr  && hc > midc) { //hole in bottom right
        // cout << "btm right\n";
        // cout << "push 3 " << midr << ", " << midc << "\n";
        hist.push_back({3, {midc, midr}});
        recur(top, midr, left, midc,          midr, midc, hist);
        recur(top, midr, midc+1, right,       midr, midc+1, hist);
        recur(midr+1, bottom, left, midc,     midr+1, midc, hist);
        recur(midr+1, bottom, midc+1, right,  hr, hc, hist);
    }
    // cout << top << ", " << left << " to " << bottom << ", " << right << "  hole's r=" << hr << ", c=" << hc << "\n";
    // print(hist);
}

int main() {
    cin >> length >> hc >> hr;

    vector<pair<int, pair<int,int> > > hist;
    recur(0, length-1, 0, length-1, hr, hc, hist);
    cout << hist.size() << "\n";
    for(auto x: hist) {
        cout << x.first << " " << x.second.first << " " << x.second.second << "\n";
    }
}