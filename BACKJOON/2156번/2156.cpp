#include <iostream>

int max_num = 0;
int num;
int wine[10001];

using namespace std;

void max_sum(int sum, int idx, int a) {
    if(idx == num) {
        if(max_num < sum) {
            max_num = sum;
        }
        return;
    }
    if(a == 2) {
        max_sum(sum, idx + 1, 0);
    }    
    else if(a == -2) {
        max_sum(sum + wine[idx], idx + 1, 1);
    }
    else {
        max_sum(sum, idx + 1, a - 1);
        max_sum(sum + wine[idx], idx + 1, a + 1);
    }
}

int main() {
    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> wine[i];
    }

    max_sum(0, 0, 0);

    cout << max_num << "\n";

    return 0;
}