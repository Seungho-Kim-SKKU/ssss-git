#include <iostream>

using namespace std;

int main() {
    int seat, vip;
    int dp[50];
    int vip_seat[50];

    cin >> seat >> vip;    

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= seat; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = 0; i < vip; i++) {
        cin >> vip_seat[i];
    }

    int sum = 1;
    int a = 0, b;

    for (int i = 0; i < vip; i++) {
        b = vip_seat[i];
        sum = sum * dp[b - a - 1];
        a = b;
    }
    sum = sum * dp[seat - a];

    cout << sum << endl;

    return 0;
}