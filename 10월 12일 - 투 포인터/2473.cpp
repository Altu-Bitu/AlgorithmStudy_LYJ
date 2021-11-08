//
// 2473번 - 세 용액
//
//참고 : https://www.acmicpc.net/board/view/59873

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> liquid;
vector<int> answer(3, -1);
long long ans = 3 * 1e9 + 1;

void findLiquid(int mid, int left, int right) {

    long long sum;

    while (left < right) {

        sum = (long long) liquid[left] + (long long) liquid[right] + (long long) liquid[mid]; // 단위 주의

        if (abs(sum) < ans) {

            ans = abs(sum);
            answer[0] = mid;
            answer[1] = left;
            answer[2] = right;
        }

        if (sum == 0) {
            answer[0] = mid;
            answer[1] = left;
            answer[2] = right;
            return;

        } else if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        }

    }

}

int main() {

    int n;
    cin >> n;

    liquid.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }


    sort(liquid.begin(), liquid.end());
    /*
     * 하나는 고정하고 투포인터 방식
     */


    for (int i = 0; i < n - 2; i++) {

        findLiquid(i, i + 1, n - 1);

    }

    cout << liquid[answer[0]] << " " << liquid[answer[1]] << " " << liquid[answer[2]];


}