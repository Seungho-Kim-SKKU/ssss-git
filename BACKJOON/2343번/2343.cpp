#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int num[100001];

int main() {
    cin >> N >> M;

    int max_length = 0;
    int min_length = 0;
    

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        max_length += num[i];
        min_length = max(min_length, num[i]);
    }

    while (min_length <= max_length) {
        int cnt = 0;
        int mid = (min_length + max_length) / 2;
        int sum = 0;

        for (int i = 0; i < N; i++) {
            if (sum + num[i] > mid) {
                cnt++;
                sum = 0;
            }
            sum += num[i];
        }
        if (sum != 0)
            cnt++;

        if (cnt <= M)
            max_length = mid - 1;
        else 
            min_length = mid + 1;
    }

    cout << min_length << endl;

    return 0;
}