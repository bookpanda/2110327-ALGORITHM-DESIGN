#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> sum;
    sum.push_back(3);
    int cou = 4;
    for(int i=1;i<29;i++) {
        sum.push_back(2*sum[i-1] + cou++);
    }
    // sum[1] has 4

    int n;
    cin >> n;
    // for(int n=1;n<=200;n++) {
        // cout << "N = " << n << " -------\n";
    for(int i=0;i<29;i++) {
        if(sum[i] > n) {
            int totalsum = 0;
            // cout << "init sum = " << totalsum << "\n";
            for(int j=i-1;j>=0;j--) {
                // more than half or less than half
                int half = sum[j];
                if(totalsum + half > n) { //less than half
                    if(totalsum+1 == n) {
                        cout << "g";
                        totalsum = n;
                        break;
                    } else continue;
                }
                totalsum += half;
                // cout << "+half=" << half << ", total=" << totalsum << "\n";
                if(totalsum == n) {
                    cout << "a";
                    break;
                }
                if(totalsum + j+4 > n) {
                    if(totalsum+1 == n) cout << "g";
                    else cout << "a";
                    totalsum = n;
                    break;
                }
                totalsum += j+4; //middle point
                if(totalsum == n) {
                    cout << "a";
                    break;
                }
                // cout << "+middle=" << j+4 << ", total=" << totalsum << "\n";
            }
            if(totalsum + 1 == n) {
                cout << "g";
            } else if(totalsum + 1 < n) {
                cout << "a";
            }
            break;
        } else if(sum[i] == n) {
            cout << "a";
            break;
        }
    }
    // cout << "\n";
    // }
}