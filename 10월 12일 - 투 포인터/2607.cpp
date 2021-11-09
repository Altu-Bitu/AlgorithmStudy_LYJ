//
// 2607번 - 비슷한 단어
//

/*
 * 같은 구성
 * GOD / DOG
 * 1. 같은 종류의 문자로 이루어짐
 * 2. 같은 개수만큼 존재
 *
 * 비슷한 단어
 * 1. 같은 구성을 가질 때 -> map is totally same
 *
 * 2. 한 문자를 더하거나, : 글자수가 -1개 이며, 종류
 * 빼거나, : 글자수가 +1개 이며, 모든 종류의 문자가 존재함
 * 다른 문자로 변경했을 때 : 글자수가 같으며,
 * 같은 구성을 가지게 될 때
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> checkAlpha(string word) { // 해당 string의 구성을 알아내는 함수
    vector<int> alphabet(26, 0);

    for (int i = 0; i < word.length(); i++) {
        alphabet[word[i] - 'A']++;
    }

    return alphabet;
}

int main() {
    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리

    int n; //주어지는 총 단어의 수
    cin >> n;

    //기준이 되는 단어

    string word; // 기준이 되는 단어 입력받기
    cin >> word;

    n--;// 총 단어의 수 하나 감소

    vector<int> word_list = checkAlpha(word); // 단어의 구성
    int size = word.size();//단어의 길이

    int ans = n; //정답의 수(일단 전부 정답이라고 가정 )
    while (n--) {
        string cmp_word;
        cin >> cmp_word;//비교 글자

        vector<int> cmp_word_list = checkAlpha(cmp_word); //단어의 구성
        int cmp_size = cmp_word.size();// 단어의 길이


        if (abs(cmp_size - size) == 1) {//단어의 길이 차이가 1인 경우 ( 단어 추가 , 제거 경우)
            int wrong = 0; //다른 글자의 수

            for (int i = 0; i < 26; i++) {
                if (wrong >= 2) { //2개 이상인 경우 답이 될 수 없음
                    ans--;
                    break;
                }
                if (word_list[i] != cmp_word_list[i]) { //원래 string의 글자수가 더 많은 상황
                    wrong += abs(word_list[i] - cmp_word_list[i]);// 글자 수 차이만큼
                }
            }

        } else if (cmp_size == size) { //글자수가 같은 경우 (비슷한 단어인 경우, 한글자 변경하는 경우)
            int loss = 0; // 비교 대상보다 적을 때
            int add = 0; // 비교 대상보다 많을 떄

            for (int i = 0; i < 26; i++) { //26자를 검사

                if (word_list[i] > cmp_word_list[i]) { //원래 string의 글자수가 더 많은 상황
                    loss += word_list[i] - cmp_word_list[i];// 글자 수 차이만큼
                } else if (word_list[i] < cmp_word_list[i]) {
                    add += cmp_word_list[i] - word_list[i]; //글자수 차이 만큼
                }

            }

            if (add == 1 && loss == 1) continue; // 한글자 변경하는 경우
            else if (add == 0 && loss == 0) continue; // 비슷한 단어인 경우
            else {//나머지 경우는 답이 될 수 없음
//                cout << cmp_word << "is not answer FOR 2 \n";
                ans--;
            }

        } else {//글자수 차이가 2 이상인 경우 답이 될 수 없음
//            cout << cmp_word << "is not answer FOR 3 \n";
            ans--; //글자수 차이가 2이상
        }


    }
    cout << ans;

}




//#include <iostream>
//#include <vector>
//
//using namespace std;
//const int SIZE = 26;
//
////알파벳별 등장횟수 저장
//vector<int> alphaMap(string str) {
//    vector<int> result(SIZE, 0);
//    for (int i = 0; i < str.size(); i++)
//        result[str[i] - 'A']++;
//    return result;
//}
//
///**
// * 단어가 같은 구성일 조건
// * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
// * 2. 같은 문자는 같은 개수만큼 있음
// *
// * 비슷한 단어의 조건
// * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
// *    -> 두 단어에서 다른 문자의 개수가 총 1개
// * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
// *    -> 두 단어에서 다른 문자의 개수가 총 2개
// *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
// */
//int main() {
//    int n, ans = 0;
//    string source, target;
//
//    //입력
//    cin >> n >> source;
//
//    //연산
//    vector<int> source_alpha = alphaMap(source);
//    while (--n) {
//        cin >> target;
//
//        int diff = 0;
//        vector<int> target_alpha = alphaMap(target);
//        for (int i = 0; i < SIZE; i++) //두 단어의 차이
//            diff += abs(source_alpha[i] - target_alpha[i]);
//        if (diff <= 1 || (diff == 2 && source.size() == target.size())) //문자를 더하거나, 빼거나, 바꾸거나
//            ans++;
//    }
//
//    //출력
//    cout << ans;
//}