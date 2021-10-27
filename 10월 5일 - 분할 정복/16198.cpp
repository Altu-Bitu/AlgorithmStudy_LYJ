//
// 에너지 모으기
//


//1. 순열

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


// 2. 백트래킹

#include <iostream>
#include <vector>

using namespace std;

vector<int> w;
int ans;

void backtracking(int sum) { //지금까지의 합
    if (w.size() == 2) { //에너지 구슬이 2개 -> 더 이상 고를 수 없음
        ans = max(ans, sum); //최댓값이 바뀌면 갱신
        return;
    }
    for (int i = 1; i < w.size() - 1; i++) { //처음과 마지막 선택 불가이므로 (0, ㅁㅏ지막 제외)
        int temp_w = w[i]; //x번째 구슬
        int sum_w = w[i - 1] * w[i + 1]; //모을 수 있는 에너지
        w.erase(w.begin() + i); //x번째 구슬 제거
        backtracking(sum + sum_w); // 새지지금 까지 합 + 로 얻은 에너
        w.insert(w.begin() + i, temp_w);//새로운 가지를 탐색하기 위해서 제거했던 구슬을 다시 넣어줌 (원상복귀)
    }
}

/**
 * 가능한 모든 경우를 구해서 계산하자
 * 이때, 사용한 에너지는 따로 저장해 둔 후에 배열에서 지우고, 다시 돌아왔을 때 저장한 값을 배열에 넣는다.
 */
int main() {
    int n;

    //입력
    cin >> n;
    w.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    //연산
    backtracking(0); // 매개변수 : 점수합

    //출력
    cout << ans << '\n';

    return 0;
}