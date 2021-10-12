//
// 에너지 모으기
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> balls;
vector<bool> check;
vector<int> num_list;
queue<int> q;
long long max_num;


int main() {

    int n;
    cin >> n;

    balls.assign(n, 0);
    num_list.assign(n - 2, 0);
    check.assign(n, false);

    int k = 0;
    for (int i = 1; i < n - 1; i++) {
        num_list[k++] = i;
    }


    for (int i = 0; i < n; i++) {
        cin >> balls[i];
    }


    do {
        check[0] = true;
        check[n - 1] = true;

        for (int i = 0; i < num_list.size(); i++) {
            q.push(num_list[i]);
        }

        long long sum = 0;
        while (!q.empty()) {

            int idx = q.front();
            q.pop();

            //사용한 것 체크
            check[idx] = true;


            //안사용한 부분찾기
            int left = idx - 1;
            int right = idx + 1;

            while (left != 0) {
                if (check[left]) {
                    left--;
                } else {
                    break;
                }
            }

            while (right != n - 1) {
                if (!check[right]) {
                    break;
                } else {
                    right++;
                }
            }
            sum += balls[left] * balls[right];

        }

        //최대값 갱신 + 초기화
        if (max_num < sum) max_num = sum;
        sum = 0;
        fill(check.begin(), check.end(), false);


    } while (next_permutation(num_list.begin(), num_list.end())); //모든 순열을 구함


    cout << max_num;

}

