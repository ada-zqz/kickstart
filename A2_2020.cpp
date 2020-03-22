#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findmaxb(int & maxb, int pre, int P, vector<vector<int>> B, int N, int K, vector<bool> & visited) {
    if(P == 0) {
        if(maxb < pre) maxb = pre;
        return;
    }
    if(P < 0) {
        return;
    }
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            for(int j = 0; j < K; j++) {
                if(P - 1 - j < 0) continue;
                cout << i << j << " " << B[i][j] << endl;
                findmaxb(maxb, pre + B[i][j], P - 1 - j, B, N, K, visited);
            }
            visited[i] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;
    int N, K, P;
    for(int t = 0; t < T; t++) {
        cin >> N >> K >> P;
        vector<vector<int>> B(N, vector<int>(K, 0));
        vector<bool> visited(N, false);
        int above, b;
        for(int i = 0; i < N; i++) {
            above = 0;
            for(int j = 0; j < K; j++) {
                cin >> b;
                B[i][j] = b + above;
                above = B[i][j];
            }
        }
        int maxb = 0;
        findmaxb(maxb, 0, P, B, N, K, visited);
        cout << "Case #" << t + 1 << ": " << maxb << endl;
    }
}

