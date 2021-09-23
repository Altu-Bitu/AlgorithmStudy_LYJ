//
// Created by 이유정 on 2021/09/19.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 샘플코드
// 1. 답의 높이를 저장하는 벡터 / 탑의 인덱스는 따로 stack
vector<int> transTop1(int n, vector<int> &num) {
    stack<int> st;
    vector<int> ans(n + 1, 0); //정답 배열은 이미 전부 0으로 초기화 (송신하는 탑이 전부 없다고 가정됨)

    for (int i = 1; i <= n; i++) {//모든 탑에 대해 고려
        while (!st.empty() && num[st.top()] <= num[i]) { //현재 탑 높이보다 st.top() 인덱스의 탑 높이가 같거나 낮다면(송신탑이 될 수 없음) pop
            st.pop();
        }
        if (!st.empty()) ans[i] = st.top(); //스택이 비어있지 않다면(현재 탑보다 큰 탑이 존재함) 스택의 top에 저장된 인덱스가 현재 탑의 신호 수신탑
        st.push(i); //현재 탑의 인덱스 스택에 push
    }

    return ans;
}


int main() {
    int n;

    //입력
    cin >> n;

    vector<int> num(n + 1, 0); //탑의 인덱스가 1부터 시작하므로 n+1 할당
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    //연산
    //vector<int> ans = transTop1(n, num);
    vector<int> ans = transTop2(n, num);

    //출력
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}


//2. 탑의 높이, 탑의 인덱스를 동시에 저장하는 pair stack사용

//stack<pair<int, int>> s; // 탑의 높이, 몇번째 탑인지
//vector<int> ans;
//
//int main() {
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//
//    int N, num;
//
//    cin >> N;
//
//    for (int i = 0; i < N; i++) {
//        cin >> num;
//
//        while (!s.empty()) {
//
//            if (s.top().first >= num) {
//                ans.push_back(s.top().second);
//                break;
//            }
//
//            s.pop(); // 나보다 큰거는 pop해버리면안됨 , 작은건 앞으로 고려 x라서 pop
//
//
//        }
//
//        if (s.empty()) { //스택 끝까지 다찾아봤는데 더큰 탑이 없엇음 - > 0개
//            ans.push_back(0);
//        }
//        s.push({num, i + 1}); // 지금 받은거 스택에 넣기
//    }
//
//
//    for (int i = 0; i < N; i++) {
//        cout << ans[i] << " ";
//    }
//
//}