//
// 민겸수
//
// 피드백 : 반례
// MKMMM max - 50111 not 50100
//
//


#include <iostream>

using namespace std;

string maxNum(string s) {
    string ans = "";//최댓값
    string temp = "";//변환시 사용할 string
    for (int i = 0; i < s.length(); i++) {
        temp += '0';//K가 나오기 전까지 0을 붙이기
        if (s[i] == 'K') { //K가 마지막으로 끝나는 십진수 변환
            temp[0] = '5';
            ans += temp;
            temp = "";
        }
    }
    if (temp.length() >= 1) { //K로 끝나지 않았다면 마지막 M모두 1로 변환(반례!)
        for (int i = 0; i < temp.length(); i++)
            temp[i] = '1';
        ans += temp;
    }
    return ans;
}

string minNum(string s) {
    string ans = "";
    string temp = "";
    char first = '1';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'M') {
            temp += first;
            first = '0';
        } else { //'K' -> 그 전까지 M묶음 변환 더하고, K는 따로 변환
            ans += temp + '5';
            temp = "";
            first = '1';
        }
    }
    if (temp.length() >= 1)
        ans += temp;
    return ans;
}

/**
 * [가장 큰 값]
 * 민겸수에서 마지막이 K일 때, K까지 포함하여 십진수로 변환한다
 * K로 끝나지 않는다면 각 M을 모두 하나로 처리한다 (ex. MMM -> 111)
 *
 * [가장 작은 값]
 * K는 무조건 단독으로 변환한다
 * 나머지 M묶음들은 같이 변환한다
 * ex. MMKMM -> 10510
 */

int main() {
    string s;

    //입력
    cin >> s;

    //출력
    cout << maxNum(s) << '\n' << minNum(s) << '\n';

    return 0;
}




//
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//queue<char> q;
//string max_str;
//string min_str;
//
//int main() {
//
//    string mk;
//
//    cin >> mk;
//
//    for (int i = 0; i < mk.length(); i++) {
//        q.push(mk[i]); -> 굳이 q를 사용할 필요가 없음
//    }
//
//    //find max
//    //K가 나올 때 마다 변환
//    char c;
//    int num = 0;
//    while (!q.empty()) {
//
//        c = q.front();
//        q.pop();
//        if (c == 'K') {
//
//            max_str += '5';
//            if (num > 0) { //쌓인 M의 수 만큼 0붙이기
//                for (int i = 0; i < num; i++) {
//                    max_str += '0';
//                }
//            }
//            num = 0;
//            continue;
//        }
//
//        num++;//m의 수
//    }
//
//
//
//    //남은 것 출력
//    //주의! 최댓값이므로 남은 M은 전부 1인것이 크다!
//    if (num > 0) {
//
//        for (int i = 0; i < num; i++) { //1이 맨 앞에 붙어서 1개 적은 0의 수
//            max_str += '1';
//        }
//    }
//
//
//    //find min
//    for (int i = 0; i < mk.length(); i++) {
//        q.push(mk[i]);
//    }
//
//    num = 0;
//    while (!q.empty()) {
//
//        c = q.front();
//        q.pop();
//        if (c == 'K') {
//
//            //모아둔 M출력
//            if (num == 1) {
//                min_str += '1';
//            } else if (num > 0) {
//                min_str += '1';
//                for (int i = 0; i < num - 1; i++) {
//                    min_str += '0';
//                }
//            }
//            num = 0;
//
//            //K붙이기
//            min_str += '5';
//            continue;
//        }
//
//        num++;//m의 수
//
//
//    }
//
//    //남은 M출력
//    if (num == 1) {
//        min_str += '1';
//    } else if (num > 0) {
//        min_str += '1';
//        for (int i = 0; i < num - 1; i++) {
//            min_str += '0';
//        }
//    }
//
//
//    cout << max_str << "\n" << min_str;
//}
//
