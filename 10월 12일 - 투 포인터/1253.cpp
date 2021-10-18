//
// 1253번 - 좋다
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
    for (int i = 2; i < n; i++) {
        int target = number[i];

//        cout << "target number : " << target << "\n";


        int left = 0, right = i - 1;
        int sum = number[left] + number[right];
        while (left < right) {

//            cout << "left : " << left << " right: " << right << "\n";
//            cout << "left number : " << number[left] << " right: " << number[right] << "\n";
//            cout << "sum : " << sum << "\n";


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