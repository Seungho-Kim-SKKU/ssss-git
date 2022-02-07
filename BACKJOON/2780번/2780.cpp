#include <iostream>

using namespace std;

int main() {
    int tc;

    cin >> tc;    

    for (int i = 0; i < tc; i++) {
        int num;

        cin >> num;

        int dp[1001][11] = { 0, };

        for (int i = 0; i < 10; i++) 
            dp[1][i] = 1;

        for (int j = 2; j <= num; j++) {
            for (int k = 0; k < 10; k++) {
                switch (k) {
                    case 0:
                        dp[j][7] += dp[j - 1][0];
                        break;
                    case 1:
                        dp[j][2] += dp[j - 1][1];
                        dp[j][4] += dp[j - 1][1];
                        break;
                    case 2:
                        dp[j][1] += dp[j - 1][2];
                        dp[j][3] += dp[j - 1][2];
                        dp[j][5] += dp[j - 1][2];
                        break;
                    case 3:
                        dp[j][2] += dp[j - 1][3];
                        dp[j][6] += dp[j - 1][3];
                        break;
                    case 4:
                        dp[j][1] += dp[j - 1][4];
                        dp[j][5] += dp[j - 1][4];
                        dp[j][7] += dp[j - 1][4];
                        break;
                    case 5:
                        dp[j][2] += dp[j - 1][5];
                        dp[j][4] += dp[j - 1][5];
                        dp[j][6] += dp[j - 1][5];
                        dp[j][8] += dp[j - 1][5];
                        break;
                    case 6:
                        dp[j][3] += dp[j - 1][6];
                        dp[j][5] += dp[j - 1][6];
                        dp[j][9] += dp[j - 1][6];
                        break;
                    case 7:
                        dp[j][4] += dp[j - 1][7];
                        dp[j][8] += dp[j - 1][7];
                        dp[j][0] += dp[j - 1][7];
                        break;
                    case 8:
                        dp[j][5] += dp[j - 1][8];
                        dp[j][7] += dp[j - 1][8];
                        dp[j][9] += dp[j - 1][8];
                        break;
                    case 9:
                        dp[j][6] += dp[j - 1][9];
                        dp[j][8] += dp[j - 1][9];
                        break;
                }
                dp[j][k] %= 1234567;
            }
        }

        long long sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += dp[num][j];
            sum %= 1234567;
        }

        cout << sum << endl;
    }

    return 0;
}