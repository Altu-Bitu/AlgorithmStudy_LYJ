//
// 12852번 - 1로 만들기 2
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

int main() {

    int x;
    cin >> x;

    vector<ii> dp(x + 1, {x + 1, x + 1}); //dp[x].first : x가 되기 위한 최소 횟수, dp[x].second : 직전에 어디서 왔는지

    //x는 x에서 왔으며, 횟수는 0임
    dp[x].first = 0;
    dp[x].second = x;


    for (int i = x; i >= 1; i--) { //x부터 거꾸로 구해나감

        if (i % 3 == 0 && dp[i].first + 1 < dp[i / 3].first) { //3으로 나눌 수 있고, 더 적으면 갱신
            dp[i / 3].first = dp[i].first + 1;
            dp[i / 3].second = i;
        }

        if (i % 2 == 0 && dp[i].first + 1 < dp[i / 2].first) {
            dp[i / 2].first = dp[i].first + 1;
            dp[i / 2].second = i;
        }

        int tmp = i - 1;
        if (tmp >= 1 && dp[i].first + 1 < dp[tmp].first) {
            dp[tmp].first = dp[i].first + 1;
            dp[tmp].second = i;
        }


    }

    int ans = dp[1].first;
    cout << ans << "\n";


    //역추적
    int next = 1;
    vector<int> answer(ans + 1, 0);
    for (int i = ans; i >= 0; i--) {
        answer[i] = next;
        next = dp[next].second; //어디서 왔는지를 추적해나감
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}