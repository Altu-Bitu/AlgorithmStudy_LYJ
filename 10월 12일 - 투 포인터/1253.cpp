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


        int left = 0, right = n - 1; // right = i-1가 안되는 이유 : 음수고려하지 않았음
        int sum = number[left] + number[right];
        while (left < right) {


            //본인은 제외되어야 함
            if (right == i) {
                right--;
                sum -= number[right + 1];
                sum += number[right];
                continue;
            }
            if (left == i) {
                left++;
                sum -= number[left - 1];
                sum += number[left];
                continue;
            }


            if (sum == target) {
                ans++;
                break;
            } else if (sum > target) {
                right--;
                sum -= number[right + 1];
                sum += number[right];
            } else if (sum < target) {
                left++;
                sum -= number[left - 1];
                sum += number[left];
            }


        }


    }

    cout << ans;

}