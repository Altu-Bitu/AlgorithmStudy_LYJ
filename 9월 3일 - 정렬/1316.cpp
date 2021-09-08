/*
 * 알튜비튜 - 0903
 * 1316번
 *
 * 그룹 단어 체커
 * 그룹 단어란 단어에 존재하는 모든 문자에 대해서,
 * 각 문자가 연속해서 나타나는 경우만을 말한다.
 * 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고,
 * kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만,
 * aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
 * 단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> arr;


bool isGroup(string str) {

    vector<int> check;
    check.assign(26, 0);

    int past = 0;
    int c;

    for (int i = 0; i < str.length(); i++) {
        c = str.at(i);

        if (past != c) {
            if (check[c - 97] != 0)
                return false;
            check[c - 97] = 1;
        }

        past = c;

    }
    return true;

}

int main() {

    //ASCII code
    //a=97, b=98 ....

    int N;
    cin >> N;
    int ans = N;

    arr.assign(N, {});

    string str;
//    int abc = 'a';

//    cout << abc;

    for (int i = 0; i < N; i++) {
        cin >> str;
        arr[i] = str;
    }

    for (int j = 0; j < N; j++) {
        if (isGroup(arr[j]) == false)
            ans--;
    }

    cout << ans;

}

//vector<string> arr;
//vector<char> wordList;
//
//int countChar(int N, int ans) {
//
//    char past = '\0';
//    char curr;
//
//    for (int i = 0; i < N; i++) {
//        string str = arr[i];
//        for (int j = 0; j < str.length(); j++) {
//            curr = str[j];
//            if (curr != past) {
//                auto it = find(wordList.begin(), wordList.end(), curr);
//                if (it == wordList.end()) {
//                    wordList.push_back(curr);
//                } else {
//                    ans--;
//                    wordList.clear();
//                    past = '\0';
//                    break;
//                }
//            }
//            past = curr;
//        }
//        past = '\0';
//        wordList.clear();
//
//    }
//    return ans;
//
//}
//
//
//int main() {
//
//    int N;
//    cin >> N;
//
//    int ans = N;
//
//    string str;
//    arr.assign(N, "");
//
//    for (int i = 0; i < N; i++) {
//        cin >> str;
//        arr[i] = str;
//    }
//
//    cout << countChar(N, ans);
//
//}