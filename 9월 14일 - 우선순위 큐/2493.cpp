//
// Created by 이유정 on 2021/09/19.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


stack<pair<int, int>> s; // 탑의 높이, 몇번째 탑인지
vector<int> ans;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N, num;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;

        while (!s.empty()) {

            if (s.top().first >= num) {
                ans.push_back(s.top().second);
                break;
            }

            s.pop(); // 나보다 큰거는 pop해버리면안됨 , 작은건 앞으로 고려 x라서 pop


        }

        if (s.empty()) { //스택 끝까지 다찾아봤는데 더큰 탑이 없엇음 - > 0개
            ans.push_back(0);
        }
        s.push({num, i + 1}); // 지금 받은거 스택에 넣기
    }


    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

}