#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num;
    int idx_1, idx_2;
    int sum;
    int min = 2000000001;
    int left, right;

    cin >> num;

    int value[num];

    for(int i = 0; i < num; i++) {
        cin >> value[i];
    }

    left = 0;
    right = num - 1;
    idx_1 = 0;
    idx_2 = num - 1;

    while(left != right) {
        sum = value[left] + value[right];

        if(abs(sum) < min) {
            min = abs(sum);
            idx_1 = left;
            idx_2 = right;
        }

        if(sum == 0) {
            break;
        }

        if(sum < 0) {
            left += 1;
        }

        if(sum > 0) {
            right -= 1;
        }
    }
    
    cout << value[idx_1] << " " << value[idx_2] << "\n";    

    return 0;
}