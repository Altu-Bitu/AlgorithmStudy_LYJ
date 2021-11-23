//
// 13422번 - 도둑
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> houses;

//슬라이딩 윈도우 방식
int robbery(int k, int m, int n) {//방범 장치가 작동하는 돈의 양, 연속된 집의 수 , 마을의 집 수

    //초기 값 setting
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < m; i++) { //m개
        sum += houses[i];
    }
    if (sum < k) ans++;

    if (n != m) { //예외 : 집의 수와 연속으로 털 집의 수가 같은 경우는 초기값으로 끝남

        //슬라이딩 윈도우 방식 n-2회 진행
        for (int i = 0; i < n - 1; i++) {
            sum -= houses[i % n];
            sum += houses[(i + m) % n];
            if (sum < k) ans++;

        }
    }

    return ans;
}


int main() {

    //테스트 케이스의 수(t) / 집의 수(n) / 연속으로 털 집(m) /방범장치(k)
    int t, n, m, k;

    cin >> t;


    while (t--) { //t 번 수행
        cin >> n >> m >> k;

        // 집
        houses.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> houses[i];
        }

        //슬라이딩 윈도우 방식

        int ans = robbery(k, m, n);

        cout << ans << "\n";
        ans = 0;


    }


}