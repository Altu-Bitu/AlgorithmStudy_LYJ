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

#include <iostream>
#include <stack>
#include <vector>


using namespace std;

vector<char> ans;
stack<char> s;
bool flag = true;

bool compOperator(char cur, char past) {

    //true : push
    //false : pop

    // ) > * / > + - > (

    if (cur == '*' || cur == '/') {
        if (past == '+' || past == '-') return true;
//        return false;
    }
//    if (cur == '+' || cur == '-') {
//        if (past == '*' || past == '/') return false;
//        return true;
//    }
    return false;


}


int main() {

    string str;

    cin >> str;

    for (int i = 0; i < str.length(); i++) {

        char c = str[i];

        if (isalpha(c)) {
            ans.push_back(c);
        } else {
            if (s.empty()) s.push(c);
            else {
                if (c == ')') {
                    while (s.top() != '(') {
                        //계속 pop
                        ans.push_back(s.top());
                        s.pop();
                    }
                    s.pop();
                } else {


                    flag = compOperator(c, s.top());
                    while (!flag) {
                        if (s.empty())break;
                        ans.push_back(s.top());
                        s.pop();
                        flag = compOperator(c, s.top());
                    }
                    s.push(c);
//                    if (flag) s.push(c);
//                    else {
//                        ans.push_back(s.top());
//                        s.pop();
//                    }

                }
            }

        }



//        1. operand? or operator?
//            operand : ans에 직행
//            operator : stack으로 직행
//
//            2. operator 라면?
//                우선순위 고려
//                지금꺼 <= 스택에 있는거 -> 스택에서 뺴기
//
//                지금꺼 > 스택에 있는거 -> 스택에 넣기



    }
    while (!(s.empty())) { //남은거 다 빼기
        ans.push_back(s.top());
        s.pop();
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }


}