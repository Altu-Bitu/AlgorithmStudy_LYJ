//
// 16401 - 과자 나눠주기
//

/*
 * Parametric Search
 * 과자의 수 n개 (길이는 각각 다름 (최대1,000,000,000))
 * 조카의 수 m명 (모두 같은 길이의 과자를 얻어야함 )
 * 최대 과자의 길이는? (과자는 나누는 것만 가능 합치기 불가능)
 *
 * -> 과자의 크기가 k일 때, n명의 조카에게 모두 나누어 줄 수 있는가?
 *
 */



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sticks;
int m, n;

//주어진 과자 길이를 모두에게 나눠줄 수 있어야함
int divide(int k) { // k : 나눠줄 과자의 길이,


    int ans = 0;

    int i = 0;
    while (i < n) {
        int len = sticks[i];
//        cout << "[ " << i << " ]\n";
//        cout << "<<BEFORE>>\n";
//        cout << "ans : " << ans << " i지금과자 : " << i << "번  이 과자의 길이 : " << len << "\n";


        if (len < k) {
//            cout << "못쓰는 과자다\n";
            //버려
            i++;
        } else if (len > k) {
//            cout << "쓸 수 있는 과자다\n";
            //짤린조각도 나눠줄 수 잇을떄까지 잘라
            while (len >= k) {
//                cout << "과자 자른다~\n";
                len -= k;
                ans++;
            }
            i++;

        } else if (len == k) {
//            cout << "딱맞는 과자다 \n";
            ans++;
            i++;
        }

//        cout << "<<AFTER>>\n";
//        cout << "ans : " << ans << " i지금과자 : " << i << "번\n";
//
//        cout << "\n";
    }


    return ans; //그 과자길이로 나눠줄수있는 조카의 수
}

int upperSearch(int left, int right, int target) { //target = n(조카의 수)


    while (left <= right) {

        int mid = (left + right) / 2;


        int res = divide(mid);

        if (res < target) { //나눠 줄 수 있는 조카의 수가 적음 -> 과자길이를 짧게 해야
            right = mid - 1;

        } else if (res >= target) {// 나눠줄 수 있는 조카의 수가 큼 -> 과자의 길이를 길게 해야
            left = mid + 1;
        }

    }

    return left - 1;
}


int main() {


    cin >> m >> n;

    sticks.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    //과자의 길이 최소 : 1 (자를 수 있기 때문에)
    //과자의 길이 최대 : 과자 길이 중 최대 값
    cout << upperSearch(1, sticks[n - 1], m);

//    cout << divide(4);

}

