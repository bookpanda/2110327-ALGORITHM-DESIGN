#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<long long> aux; //aux[i] = how many times i will appear in a[]
    aux.push_back(0);
    aux.push_back(1);
    aux.push_back(2);
    aux.push_back(2);
    int c = 3;
    while(aux.size() < 5000) {
        for(int i=0;i<aux[c];i++) {
            aux.push_back(c);
            // cout << c << " ";
        }
        c++;
    }
    cin >> n;
    while(n--) {
        long long idx;
        cin >> idx;
        long long sum=0;
        long long ans=0;
        for(int i=1;i<5000;i++) {
            // cout << "sum = " << sum << ", aux[" << i << "] = " << aux[i] << ", ans=" << ans << "\n";
            if(sum + aux[i]*i > idx) {
                ans += ceil((long double)(idx-sum) / i+1);
                // cout << "ceil = " << ceil((long double)(idx-sum) / aux[i+1]) << "\n";
                break;
            }
            sum += aux[i]*i;
            ans += aux[i];
        }
        cout << ans-1 << "\n";
        // for(int i=0;i<)
    }
}