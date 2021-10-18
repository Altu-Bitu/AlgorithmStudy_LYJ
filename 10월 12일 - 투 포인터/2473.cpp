//
// 2473번 - 세 용액
//
//참고 : https://www.acmicpc.net/board/view/59873

/*
 * 하나는 고정하고 투포인터 방식을 쓰자
 */

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

    //정렬
    sort(liquid.begin(), liquid.end());


    int mid; //중앙 값 고정
    long long ans = 3 * 1e9 + 1; // 다 더하면 30억 ( + 1 하면 절대 넘을 일 없고 int범위는 넘어감 )
    int ans1, ans2, ans3; //답을 저장할 것
    for (int i = 0; i < n - 2; i++) {
        mid = i;// 고정할 중앙 값 인덱스

        int left = i + 1; // 고정한 값 이후를 투포인터로 탐색 ( 양끝 시작 )
        int right = n - 1;
        long long sum; // 합은 int범위를 벗어날 수 있음


        while (left < right) {

            sum = (long long) liquid[left] + (long long) liquid[right] +
                  (long long) liquid[mid]; // 단위 주의 (연산 도중에 int 범위를 벗어남)


            if (abs(sum) < ans) { //더 작아지면 갱신(절댓값 필수)

                ans = abs(sum);
                ans1 = mid;
                ans2 = left;
                ans3 = right;
            }

            if (sum == 0) {
                cout << liquid[mid] << " " << liquid[left] << " " << liquid[right];//0인경우 그냥 종료
                return 0;//이런식으로 멈추는게 안좋은 방법인가? (질문하기)
            } else if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            }

        }


    }

    cout << liquid[ans1] << " " << liquid[ans2] << " " << liquid[ans3];


}