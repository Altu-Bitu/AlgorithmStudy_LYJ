#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 1000;
const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;

int cost[SIZE + 1][3] = {0};//0:R 1:G 2:B
int dp[SIZE + 1][3] = {0};

int main() {

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i][RED] >> cost[i][GREEN] >> cost[i][BLUE];
    }

    int ans = 999999999;


    for (int j = 0; j < 3; j++) {//각각 색으로 시작하는경우 따로

        dp[1][RED] = 999999999;
        dp[1][GREEN] = 999999999;
        dp[1][BLUE] = 999999999;

        dp[1][j] = cost[1][j]; //첫번쨰 꺼 j색으로 칠함


        for (int i = 2; i < n + 1; i++) { //첫번째 건너 뛰고
            dp[i][RED] = min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + cost[i][RED];
            dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + cost[i][GREEN];
            dp[i][BLUE] = min(dp[i - 1][GREEN], dp[i - 1][RED]) + cost[i][BLUE];
        }

        for (int k = 0; k < 3; k++) {
            if (j != k) ans = min(ans, dp[n][k]);
        }

    }

    cout << ans;

}



