#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    vector<int> count(N + 1, 0);
    vector<int> prefix_sum(N + 1, 0);

    // Calculate prefix sum of matches
    for (int i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + (a[i] == b[i]);
    }

    for (int l = 1; l <= N; l++) {
        for (int r = l; r <= N; r++) {
            int checked = prefix_sum[r] - prefix_sum[l - 1]; 
            // Count matches before l
            checked += prefix_sum[l - 1]; 
            // Count matches after r
            checked += prefix_sum[N] - prefix_sum[r]; 
            // Count matches within the reversed subarray (handle carefully)
            for (int i = l - 1, j = r - 1; i < r; i++, j--) {
                if (a[j] == b[i]) {
                    checked++;
                }
            }
            count[checked]++;
        }
    }

    for (int i = 0; i <= N; i++) {
        cout << count[i] << endl;
    }

    return 0;
}
