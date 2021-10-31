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

    int max = 1;

    map<int, int> m;

    int left = 0, right = 1;
    m[v[left]]++;
    int size = 1; //지금까지의 길이
    int flag = false; // false : right로 움직이기 / true:left로 움직이기
    int max_cnt = 100001;//절대 나올일 없는 숫자

    while (left <= right && right < v.size()) {

        int num;

        if (flag) {//left가 움직인 경우 ->백스탭
            num = v[left - 1]; //주의 : 이전 수를 없앤 것임
            m[num]--;
            size--;

        } else {//right가 움직인 경우 -> 전진
            num = v[right];
            m[num]++;
            size++;

            if (m[num] > k) {
                max_cnt = num; // 가장 등장 횟수가 많은 수를 저장해둠
            }


        }


        if (m[max_cnt] > k) { //한계도달 ( right쪽  그만 탐색하고 왼쪽으로 줄여나가기 )
            flag = true;
            if (size > max) {
                max = size - 1; //길이가 더 긴 경우 답 갱신
            }
            left++;

        } else {//한계 미도달 (right쪽으로 계속 탐색)
            flag = false;
            right++;
        }


    }

    if (size > max) { //마지막 체크
        max = size;
    }

    cout << max;


}