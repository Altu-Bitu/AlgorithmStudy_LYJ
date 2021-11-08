//
// 1253번 - 좋다
//
// 참고 : https://www.acmicpc.net/board/view/68348
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> number;

//배열 내 서로 다른 두 수를 더했을 때, target이 되는 수가 존재하는가
bool findGoodNum(int target, int n, int i) {
    int left = 0, right = n - 1; // right = i-1가 안되는 이유 : 음수고려하지 않았음
    int sum;
    while (left < right) {

        sum = number[left] + number[right];

        //본인은 제외되어야 함
        if (right == i) {
            right--;
            continue;
        }
        if (left == i) {
            left++;
            continue;
        }


        if (sum == target) {
            return true;// 존재하므로 true 반환
        } else if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;

        }
    }

    return false;//검사가 종료되었는데 발견되지 않음 -> false
}

int main() {

    int n;
    cin >> n;

    number.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }

    //투포인터를 사용하기 위해 정렬 필요
    sort(number.begin(), number.end());

    int ans = 0;//GOOD 한 수의 갯수
    for (int i = 0; i < n; i++) { // 0부터 시작해야하는 반례 3개 0 0 0
        int target = number[i];

        bool res = findGoodNum(target, n, i);
        if (res) ans++; //true가 return된 경우 정답의 수를 증가

    }

    cout << ans;

}