#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    vector<int> num;

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        num.push_back(a);
    }
    for(int i=0;i<m;i++) {
        int sum;
        bool found=false;
        cin >> sum;
        for(int j=0;j<n-1;j++) {
            int l = j+1;
            int r = n-1;
            while(l<r) {
                if(sum == num[j]+num[l]+num[r]){
                    cout << "YES\n";
                    found = true;
                    break;
                }
                else if(sum > num[j]+num[l]+num[r]) l++;
                else r--;
            }
            if(found) break;
        }
        if(!found) cout << "NO\n";
    }
}