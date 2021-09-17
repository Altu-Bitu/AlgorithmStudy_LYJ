//
// Created by 이유정 on 2021/09/15.
//
//
//연산의 우선순서
//        () > * / > + -
//
// (이게 나오면 )이거 나올떄까지 push만해야함
//
//
//
//


// 아 외않되


/**
  * [중위 표기식 -> 후위 표기식]
  * 1. 피연산자는 스택에 넣지 않고 바로 답에 추가한다.
  * 2. '('는 무조건 스택에 넣는다.
  * 3. 항상 스택의 top 에 있는 연산자 우선순위가 제일 높아야 한다. (연산자 우선순위: *,/ > +,-)
  * 4. 따라서 스택의 top 에 있는 값이 현재 연산자의 우선순위와 같거나 더 높다면 스택에서 값을 꺼내 답에 추가한다.
  * 5. 4번 과정을 끝마치면, 스택에 현재 연산자를 넣는다.
  * 6. ')'가 들어오면 '('값이 스택의 top이 될 때까지 스택에서 값을 꺼내서 답에 추가한다.
  * 7. (!주의!) 주어진 문자열에 대한 검사가 모두 끝나면 스택에 남아있는 연산자를 모두 답에 추가한다.
  */

#include <iostream>
#include <stack>


//연산자 우선순위 리턴하는 함수
int priority(char ch) { // 해당 연산자의 우선순위를 숫자로 내보냄 (작을수록 우선순위 높음)
    switch (ch) {
        case '*':
        case '/': //우선순위 가장 높음
            return 1;
        case '+':
        case '-': //우선순위 낮음
            return 2;
        case '(':
        case ')': //우선순위 없음 -> 가장 낮게 처리
            return 3;
    }
}

//중위 표기식->후위표기식 함수
string infixToPostfix(string &s) {
    stack<char> st;
    string answer = ""; //후위표기식

    for (int i = 0; i < s.length(); i++) { //중위 표기식을 하나하나 받아냄
        switch (s[i]) {
            case '(': //'('일 경우 -> 무조건 push
                st.push(s[i]);
                break;
            case ')': //')'일 경우
                while (!st.empty() && st.top() != '(') { //스택의 top 값이 '(' 일때까지 꺼내 답에 연산자 추가
                    answer += st.top();
                    st.pop();
                }
                st.pop(); //'(' 제거
                break;
            case '*':
            case '/':
            case '+':
            case '-': //연산자일 경우
                //현재 연산자의 우선순위와 같거나 더 높다면 pop 스택에서 값을 꺼내 답에 추가
                while (!st.empty() && priority(st.top()) <= priority(s[i])) {
                    answer += st.top();
                    st.pop();
                }
                st.push(s[i]);
                break;
            default: //피연산자(숫자)라면 답에 무조건 추가
                answer += s[i];
                break;
        }
    }
    //스택에 연산자가 남아있다면 추가
    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }

    return answer;
}

int main() {
    string s; //입력(중위표기식)
    //입력
    cin >> s;
//출력
    cout << infixToPostfix(s) << '\n';

    return 0;
}



//#include <iostream>
//#include <stack>
//#include <vector>
//
//
//using namespace std;
//
//vector<char> ans;
//stack<char> s;
//bool flag = true;
//
//bool compOperator(char cur, char past) {
//
//    //true : push
//    //false : pop
//
//    // ) > * / > + - > (
//
//    if (cur == '*' || cur == '/') {
//        if (past == '+' || past == '-') return true;
////        return false;
//    }
////    if (cur == '+' || cur == '-') {
////        if (past == '*' || past == '/') return false;
////        return true;
////    }
//    return false;
//
//
//}
//
//
//int main() {
//
//    string str;
//
//    cin >> str;
//
//    for (int i = 0; i < str.length(); i++) {
//
//        char c = str[i];
//
//        if (isalpha(c)) {
//            ans.push_back(c);
//        } else {
//            if (s.empty()) s.push(c);
//            else {
//                if (c == ')') {
//                    while (s.top() != '(') {
//                        //계속 pop
//                        ans.push_back(s.top());
//                        s.pop();
//                    }
//                    s.pop();
//                } else {
//
//
//                    flag = compOperator(c, s.top());
//                    while (!flag) {
//                        if (s.empty())break;
//                        ans.push_back(s.top());
//                        s.pop();
//                        flag = compOperator(c, s.top());
//                    }
//                    s.push(c);
////                    if (flag) s.push(c);
////                    else {
////                        ans.push_back(s.top());
////                        s.pop();
////                    }
//
//                }
//            }
//
//        }
//
//
//
////        1. operand? or operator?
////            operand : ans에 직행
////            operator : stack으로 직행
////
////            2. operator 라면?
////                우선순위 고려
////                지금꺼 <= 스택에 있는거 -> 스택에서 뺴기
////
////                지금꺼 > 스택에 있는거 -> 스택에 넣기
//
//
//
//    }
//    while (!(s.empty())) { //남은거 다 빼기
//        ans.push_back(s.top());
//        s.pop();
//    }
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i];
//    }
//
//
//}