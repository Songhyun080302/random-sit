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

    vector<int> count(N + 1, 0);  // To store the number of operations resulting in exactly c cows checked

    // Step 1: Try all possible subarrays [l, r]
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            int checked = 0;

            // Step 2: Reversal of a[l:r], then count the number of cows that match
            // Before reversal, the checked cows are counted.
            vector<int> temp_a = a;  // Copy of array a to perform the reversal
            reverse(temp_a.begin() + l, temp_a.begin() + r + 1);  // Reverse the subarray a[l:r]

            // Count the number of checked cows
            for (int i = 0; i < N; i++) {
                if (temp_a[i] == b[i]) {
                    checked++;
                }
            }

            // Increment the corresponding count of checked cows
            count[checked]++;
        }
    }

    // Step 3: Output the result
    for (int i = 0; i <= N; i++) {
        cout << count[i] << endl;
    }

    return 0;
}
