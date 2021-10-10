//
// 퇴사2 - 동적계획법
//

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

vector<ii> v;
vector<int> dp;


int main() {

    int n;
    cin >> n;
    v.assign(n + 1, {0, 0});
    dp.assign(n + 2, 0);


    for (int j = 1; j <= n; j++) {
        cin >> v[j].first >> v[j].second;
    }


    for (int i = n; i > 0; i--) {
        if (i + v[i].first > n + 1) {//날짜 초과하면 상담못함
            dp[i] = dp[i + 1];
        } else {
            //i의 최댓값 = 선택x(그냥 다음 인덱스) or 선택o (상담금액 + 상담시 다음 상담 가능한 날짜의 dp)
            dp[i] = max(dp[i + 1], v[i].second + dp[i + v[i].first]);
        }
    }

    cout << dp[1];
}

