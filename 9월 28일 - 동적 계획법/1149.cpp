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


    for (int i = 1; i < n + 1; i++) {


        dp[i][RED] = min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + cost[i][RED];
        dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + cost[i][GREEN];
        dp[i][BLUE] = min(dp[i - 1][GREEN], dp[i - 1][RED]) + cost[i][BLUE];


    }

    cout << min(min(dp[n][RED], dp[n][GREEN]), dp[n][BLUE]);

}



