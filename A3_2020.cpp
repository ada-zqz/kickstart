#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    int N, K;
    for(int t = 0; t < T; t++) {
        cin >> N >> K;
        vector<int> M(N);
        vector<int> df(N);
        for(int i = 0; i < N; i++) {
            cin >> M[i];
            df[i] = i > 0 ? M[i] - M[i - 1] : 0;
        }
        sort(df.rbegin(), df.rend());
        int dmin;
        dmin = max(max(df[0] - df[0] / 2, df[0] / 2), df[1]);
        cout << "Case #" << t + 1 << ": " << dmin << endl;
    }
}

