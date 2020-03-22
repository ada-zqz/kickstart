#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    int N, B;
    for(int t = 0; t < T; t++) {
        cin >> N >> B;
        vector<int> A(N);
        for(int i = 0; i < N; i++) cin >> A[i];
        sort(A.begin(), A.end());

        int left = B;
        int nhouse = 0;
        for(int v: A) {
            if(v <= left) {
                nhouse++;
                left = left - v;
            }
        }
        cout << "Case #" << t + 1 << ": " << nhouse << endl;
    }
}

