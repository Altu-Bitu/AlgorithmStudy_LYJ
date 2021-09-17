//
// Created by 이유정 on 2021/09/15.
//



#include <iostream>
#include <deque>
#include <string>

using namespace std;


//입력받은 [1,2,3,4]를 1 2 3 4 deque으로
deque<int> refactoring(string str) {
    deque<int> result;//덱으로 만들어진 것

    string tmp; //숫자를 담을 임시 문자열
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) //숫자라면 문자열에 추가 (2자리 수 이상일때 대비)
            tmp += str[i];
        else if (!tmp.empty() && (str[i] == ',' || str[i] == ']')) { //문자열이 비어있지 않을 때, 쉼표 또는 닫는 괄호를 만나면 숫자로 바꿔주기
            result.push_back(stoi(tmp));
            tmp = ""; //문자열 초기화
        }

    }
    return result;
}

//입력받은 [1,2,3,4]를 1 2 3 4 deque으로
deque<int> refactoring(string str) {
    deque<int> result;//덱으로 만들어진 것

    string tmp; //숫자를 담을 임시 문자열
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) //숫자라면 문자열에 추가 (2자리 수 이상일때 대비)
            tmp += str[i];
        else if (!tmp.empty() && (str[i] == ',' || str[i] == ']')) { //문자열이 비어있지 않을 때, 쉼표 또는 닫는 괄호를 만나면 숫자로 바꿔주기
            result.push_back(stoi(tmp));
            tmp = ""; //문자열 초기화
        }

    }
    result[result.size() - 1] = ']'; //마지막 쉼표를 닫는 괄호로 바꿔주기
    return result;
}

/**
  * 함수 R에서 실제로 배열을 뒤집을 필요가 없다는게 핵심
  * 비어있는 배열을 리턴하는 경우를 주의
  */
int main() {
    int t, n;
    string p, str;

    cin >> t;
    while (t--) {
        //입력
        bool is_reversed = false, is_error = false;
        cin >> p >> n >> str;

        //연산
        deque<int> dq = refactoring(str); //문자열에서 숫자를 구해서 덱에 넣기
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') { //함수 R : is_reversed 변수만 반대로 바꿔주기
                is_reversed = !is_reversed;
                continue;
            }
            //함수 D
            if (dq.empty()) { //배열이 비어있으면 error
                is_error = true;
                break;
            }
            if (is_reversed) //뒤집힌 배열이면 맨 뒤 데이터 삭제
                dq.pop_back();
            else //올바른 순서의 배열이면 맨 앞 데이터 삭제
                dq.pop_front();
        }
        //출력
        if (is_error)
            cout << "error\n";
        else //숫자를 다시 문자열에 담아서 리턴하기
            cout << toStr(dq, is_reversed) << '\n';
    }
}


//
//#include <iostream>
//#include <deque>
//#include <string>
//#include <vector>
//
//// 다 안품!
//// 대체 출력형식 어캐하는거지..
////
//
//
//using namespace std;
//
//deque<string> dq;
//vector<string> ans;
//vector<string> res;
//bool flag = true; // true: front / false : back
//
//
//
//
//void insert_dq(string str) {
//    // index : 0 , length()-1은 제외  [ ] 임
//    // ,이 나올떄까지 범위만큼
//
//
//    int start = 1, cnt = 1;
//    string number;
//
//    for (int i = 1; i < str.length(); i++) {
//
//        char c = str[i];
//
////        cout << " c : " << c << "\n";
////        cout << "start : " << start << " end : " << cnt << "\n";
//
//
//        if (c == ',' || c == ']') {
////            cout << " c is ," << "\n";
//            //index start-end까지를 int로 dq에 push
//
//            number.append(str, start, cnt - 1);
//
////            cout << "number : " << number << "\n";
//
////            int num = atoi(number.c_str());
//            dq.push_back(number);
//            number = "";
//            //start,end index가 i+1
//            start = i + 1;
//            cnt = 1;
//        } else {
//            //end index ++
//            cnt++;
//
//        }
//
//    }
//
////    cout << "==========THIS IS DQ================ " << "\n";
////    while (!(dq.empty())) {
////        cout << dq.front() << " ";
////        dq.pop_front();
////
////    }
////    cout << "\n======================================\n";
//
//}
//
//int solution(string P) {
//
////    cout << " P : " << P << "\n";
//    for (int i = 0; i < P.length(); i++) {
//
//        char c = P[i];
//
//        if (dq.empty()) {
////            cout << "error" << "\n";
//            return -1;
//        }
//
//        if (c == 'R') {
////            cout << "flag : " << flag;
//            flag = !(flag);
////            cout << "flag : " << flag;
//        } else {
//            if (flag) dq.pop_front();
//            else dq.pop_back();
//        }
//
//    }
////    return 1;
//
////    cout << "==========NO ERROR=============== " << "\n";
////    while (!(dq.empty())) {
////        cout << dq.front() << " ";
////        dq.pop_front();
////
////    }
////    cout << "\n======================================\n";
//
//    return 1;
//
//}
//
//
//int main() {
//
//
//    int N, M;
//    cin >> N;
//    string P, str, answer; // P: 수행할 함수 str:리스트
//
//
//    for (int i = 0; i < N; i++) {
//        cin >> P >> M >> str;
//
//        //deque에 삽입하는 함수
////        cout << "INSERT DQ" << "\n";
//        insert_dq(str);
//        //결과 찾아내는 함수
//
////        cout << "SOLUTION" << "\n";
//        int result = solution(P);
//
////        cout << "[I] : " << i << " result :" << result << "\n";
//
//        //결과 string벡터 생성ㅇ
//        if (result == -1 || M == 0) res.push_back("error");
//        else {
//
//            answer.append("[");
//            if (flag) {
//                while (!(dq.empty())) {
//                    answer.append(dq.front());
//                    dq.pop_front();
//                    answer.append(",");
//                }
//            } else {
//                while (!(dq.empty())) {
//                    answer.append(dq.back());
//                    dq.pop_back();
//                    answer.append(",");
//                }
//            }
//            answer.pop_back();
//            answer.append("]");
//
//            res.push_back(answer);
//
//        }
//        dq.clear();
//        ans.clear();
//        answer = "";
//        flag = true;
//
//    }
//    for (int i = 0; i < res.size(); i++) {
//        cout << res[i] << "\n";
//    }
//
//
}