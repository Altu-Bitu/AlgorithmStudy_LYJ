//
// 2473번 - 세 용액
//
//참고 : https://www.acmicpc.net/board/view/59873

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> liquid;


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

    int mid;
    long long ans = 3 * 1e9 + 1;
    int ans1, ans2, ans3;
    for (int i = 0; i < n - 2; i++) {
        mid = i;

        int left = i + 1;
        int right = n - 1;
        long long sum;
        while (left < right) {

            sum = liquid[left] + liquid[right] + liquid[mid];

            if (abs(sum) < ans) {

                ans = abs(sum);
                ans1 = mid;
                ans2 = left;
                ans3 = right;
            }

            if (sum == 0) {
                cout << liquid[mid] << " " << liquid[left] << " " << liquid[right];
                return 0;
            } else if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            }

        }


    }

    cout << liquid[ans1] << " " << liquid[ans2] << " " << liquid[ans3];


}