

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


/**
 * 1. 입력으로 주어진 변수가 C++ 형식에도 맞고, JAVA 형식에도 맞을 수 있음 (ex. name)
 * 2. "Error!"인 경우 (C++)
 *    2-1. 언더바('_')로 시작하거나, 끝나는 변수
 *    2-2. 언더바('_')가 연속해서 등장하는 변수
 *    2-3. 대문자가 등장하는 변수
 * 3. "Error!"인 경우 (Java)
 *    3-1. 대문자로 시작하는 변수
 *    3-2. 언더바('_')가 등장하는 변수
 */


#include <iostream>
#include <queue>


using namespace std;


bool isCpp(String str) {

    if (!islower(str[0])) return -1;//error

    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) return false;
        if (str[i] == '_' && (i == 0 || i == str.size() - 1 || str[i - 1] == '_')) //첫 or 마지막 글자가 '_' 또는 '_'가 연속 등장
            return false;
    }
}

bool isJava(string str) { //java 형식인가?
    return !isupper(str[0]) && str.find('_') == string::npos; //첫 글자가 대문자거나, '_'가 있으면 안됨
}


string toCpp(string str) { //java 형식을 c++로
    string result;
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) //대문자라면 앞에 '_' 삽입
            result += '_';
        result += tolower(str[i]); //소문자로 바꿔서 넣기
    }
    return result;
}

string toJava(string str) { //c++ 형식을 java로
    string result;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '_') { //'_' 라면 그 다음 글자를 대문자로 바꿔서 삽입
            result += toupper(str[i + 1]);
            i++;
            continue;
        }
        result += str[i]; //나머지 글자는 그냥 삽입
    }
    return result;
}


int main() {

    string str;

    cin >> str;
    bool is_cpp = isCpp(str);
    bool is_java = isJava(str);

    if (is_cpp && is_java) //두 형식에 모두 부합하면 그냥 출력
        cout << str;
    else if (is_cpp) //c++ 형식이라면 java로 바꿔서 출력
        cout << toJava(str);
    else if (is_java) //java 형식이라면 c++로 바꿔서 출력
        cout << toCpp(str);
    else //둘 다 아니라면 에러
        cout << "Error!";

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