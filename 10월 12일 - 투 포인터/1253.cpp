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


    sort(number.begin(), number.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int target = number[i];



        int left = 0, right = n - 1; // right = i-1가 안되는 이유 : 음수고려하지 않았음
        int sum = number[left] + number[right];
        while (left < right) {


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