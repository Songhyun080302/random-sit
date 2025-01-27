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
    for (int l = 1; l <= N; l++) {
        for (int r = l; r <= N; r++) {
            int checked = 0;

            // 부분 배열 l부터 r까지를 역순으로 정렬했을 때 일치하는 요소의 개수를 세는 부분
            for (int i = 0; i < l - 1; i++) {
                if (a[i] == b[i]) {
                    checked++;
                }
            }
            for (int i = l - 1, j = r - 1; i < r; i++, j--) { // i < r 조건으로 변경
                if (a[j] == b[i]) {
                    checked++;
                }
            }
            for (int i = r; i < N; i++) {
                if (a[i] == b[i]) {
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
