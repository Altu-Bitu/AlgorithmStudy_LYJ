#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int ans; //정답: 최대 이익

//얻을 수 있는 최대 이익 리턴하는 함수, cnt: 상담 시작 가능한 날, sum: 지금까지의 이익
// n : 퇴사 전까지 할 수 있는 일의 수
void maxConsul(int n, vector<ci> &consulting, int start, int sum) {
    if (start > n) //상담 끝나는 날이 퇴사일을 넘는다면 -> 상담할 수 없는 경우
        return;

    ans = max(ans, sum); //답을 계속 최댓값으로 갱신

    for (int i = start; i < n; i++) { //i번째 날을 상담하는 경우
        // i 번째 날 + i번째 날 상담을 시작하면, 걸리는 상담일 수 (다음 함수의 시작날) , 상담하면 얻을 수 있는 이익
        maxConsul(n, consulting, i + consulting[i].first, sum + consulting[i].second);
    }
}

/**
 * [퇴사]
 * 상담을 적절히 했을 때, 얻을 수 있는 최대 수익을 구하는 프로그램
 *
 * [풀이]
 * 1일 부터 상담받는 경우에서 시작해서 할 수 있는 모든 경우의 수를 다 해보자
 * n = 15 이므로, 상담을 하는데 필요한 기간이 모두 1일이라 가정하면 최대 연산 횟수는
 * -> C(15,1) + C(15,2) + ... + C(15,15) <= C(15,7) * 15 = 96,525 이므로 충분히 브루트 포스 접근 가능!
 */

int main() {
    int n; //퇴사까지 남은 날

    //입력
    cin >> n;
    vector<ci> consulting(n);

    for (int i = 0; i < n; i++)
        cin >> consulting[i].first >> consulting[i].second; //first: 상담 시간, second: 이익

    //연산
    maxConsul(n, consulting, 0, 0); //최초 시작은 0일, 0원

    //출력
    cout << ans << '\n';

    return 0;
}