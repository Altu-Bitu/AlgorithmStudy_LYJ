

/**
 *
 * Naming JAVA
 * 1. start with small letter
 * 2. Separate with Big letter
 *
 * Naming C++
 * 1. only small letter
 * 2. Separate with _
 *
 *
 */





#include <iostream>
#include <queue>


using namespace std;


int isCpp(String str) {

    if (!islower(str[0])) return -1;//error


    for (int i = 0; i < str.length(); i++) {

        if ()

    }


}

int isJava(String str) {

    if (!islower(str[0])) return -1;//error


}

int main() {


}


//priority_queue<char> pq;
//queue<char> q;
//
//// -1 : error
//int decideLan() {
//
//    int flag = 3; // 1: c++ 2:java 3:both -1:error
//
//    while (!pq.empty()) {
//
//        char c = pq.top();
//        pq.pop();
//
//        if (islower(c)) continue; //소문자면 무시
//
//        if (c == '_') {
//            flag = 1; // _가 등장하면 일단 c++임}
//        }
//
//        if (isupper(c)) {
//            //대문자가 나왔는데
//
//            //1. 이전이 _였음
//            if (flag == 1) {
//                return -1;
//            }
//            return 2; //2. _이 아닌경우 _나 소문자가 나올일이 없음 즉, java일 확률뿐
//
//        }
//
//    }
//
//    return flag; // 소문자만 나오다 끝났으면 3, _만났으면 1
//}
//
//string cvtToJava() { // c to J
//
//
//    string ans = "";
//    bool flag = false;
//
//    while (!q.empty()) {
//        char c = q.front();
//        q.pop();
//
//        if (flag == true && c == '_') return "Error!"; //_이 2개이상 반복
//
//        if (c == '_') {
//            flag = true;
//            continue;
//        }
//
//
//        if (flag == true) {
//            ans.push_back(toupper(c)); //대문자로 바꿔서 삽입
//            flag = false;
//        } else {
//            ans.push_back(c);
//        }
//
//
//    }
//
//
//    return ans;
//
//
//}
//
//string cvtToC() {
//
//
//    string ans = "";
//
//
//    while (!q.empty()) {
//        char c = q.front();
//        q.pop();
//
//
//        if (islower(c)) {
//            ans.push_back(c);
//            continue;
//        }
//
//
//        ans.push_back('_');
//        ans.push_back(tolower(c)); //대문자로 바꿔서 삽입
//
//
//
//    }
//
//    return ans;
//
//
//}
//
//int main() {
//
//    string var;
//
//    cin >> var;
//
//    for (int i = 0; i < var.length(); i++) {
////        pq.push(var[i]);
//        q.push(var[i]);
//    }
//
//    if (!islower(var[0])) { //소문자 시작이 아님
//        cout << "Error!" << "\n";
//    } else if (var[var.length() - 1] == '_') { // _로 끝남
//        cout << "Error!" << "\n";
//    } else {
//
//        int lan = decideLan();
//
//
//        switch (lan) {
//            case 1://c++임
//                cout << cvtToJava() << "\n";
//                break;
//            case 2://java임
//                cout << cvtToC() << "\n";
//                break;
//            case 3: //변경이 필요없음
//                cout << var << "\n";
//                break;
//            case -1:
//                cout << "Error!" << "\n";
//                break;
//            default:
//                break;
//
//        }
//    }
//
//
//}