//
// 20922번 - 겹치는 건 싫어
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> v;

int main() {

    int n, k;

    cin >> n >> k;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int max_value = 0;//변수명으로 max는 사용하지 x!

    map<int, int> m; //등장 수, 등장 횟수

    int left = 0, right = 0;


    while (left <= right && right < n) {

        // right를 증가시키고 종료했으므로 =이 붙어야함
        if (m[v[right]] >= k) { //한계도달 ( right쪽  그만 탐색하고 왼쪽으로 줄여나가기 )
            m[v[left]]--;
            left++;
        } else {//한계 미도달 (right쪽으로 계속 탐색)
            m[v[right]]++;
            if (right - left + 1 > max_value) {
                max_value = right - left + 1; //길이가 더 긴 경우 답 갱신
            }
            right++; //right를 증가시키고 종료
        }
    }


    cout << max_value;


}