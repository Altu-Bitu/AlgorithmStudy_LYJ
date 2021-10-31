//
// 2143번 - 두 배열의 합
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
//        cout << "=================================================================\n";
//        cout << "STEP : " << cnt << "\n";
//        cnt++;

        int num;

        if (flag) {//left가 움직인 경우 ->백스탭
            num = v[left - 1];
            m[num]--;
            size--;

//            cout << "move LEFT now num : " << num << "\n";
//            cout << "m[num] : " << m[num] << "\n";
//            cout << "size : " << size << "\n";


        } else {//right가 움직인 경우 -> 전진
            num = v[right];
            m[num]++;
            size++;

//            cout << "move RIGHT now num : " << num << "\n";
//            cout << "m[nums] : " << m[num] << "\n";
//            cout << "size : " << size << "\n";

            if (m[num] > k) {
//                cout << "k를 초과함\n";
                max_cnt = num;
            }


        }

//        cout << "max cnt : " << max_cnt << "\n";
//        cout << "m[max cnt] : " << m[max_cnt] << "\n";

        if (m[max_cnt] > k) { //한계도달 ( right쪽  그만 탐색)
//            cout << "now moving to LEFT\n";
            flag = true;
            if (size > max) {
                max = size - 1;
//                cout << "답 변경 : " << max << "\n";
            }
            left++;

        } else {//한계 미도달 (right쪽으로 계속 탐색)
//            cout << "now moving to RIGHT\n";
            flag = false;
            right++;
        }


    }

    if (size > max) {
        max = size;
//        cout << "답 변경 : " << max << "\n";
    }

    cout << max;


}