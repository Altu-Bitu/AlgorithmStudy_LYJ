/*
 * 알튜비튜 - 0903
 * 1431번
 *
 * 시리얼 번호
 * 모든 시리얼 번호는 알파벳 대문자 (A-Z)와 숫자 (0-9)로 이루어져 있다.
 * 시리얼번호 A가 시리얼번호 B의 앞에 오는 경우는 다음과 같다.
 * A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
 * 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
 * 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
 * 시리얼이 주어졌을 때, 정렬해서 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


vector<string> arr;

int calSum(string str) {

    char c;
    int sum = 0;

    for (int i = 0; i < str.length(); i++) {
        c = str.at(i);
        if (isdigit(c)) {
            sum += (int) (c - '0');
        }
    }

    return sum;

}

bool compare(const string &a, const string &b) {

    if (a.length() != b.length())
        return a.length() < b.length();
    if (calSum(a) != calSum(b))
        return calSum(a) < calSum(b);
    return a < b;

}

int main() {

    int N;
    cin >> N;
    arr.assign(N, "");

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\n";

    }


}

// pair로 length를 저장 -> 불필요한 메모리 사용
// vector<pair<string, int>> arr;
//bool compare(const pair<string, int> &a, const pair<string, int> &b) {
//
//    if (a.second != b.second)
//        return a.second < b.second;
//    if (calSum(a.first) != calSum(b.first))
//        return calSum(a.first) < calSum(b.first);
//    return a.first < b.first;
//
//}
//
//
//int main() {
//    int N;
//    string str;
//    cin >> N;
//    arr.assign(N, {});
//
//    for (int i = 0; i < N; i++) {
//        cin >> str;
//        arr[i].first = str;
//        arr[i].second = str.length();
//    }
//
//    sort(arr.begin(), arr.end(), compare);
//
//    for (int i = 0; i < N; i++) {
//        cout << arr[i].first << "\n";
//
//    }
//
//}



// 구조체 사용 -> 굳이 필요없는 메모리 사용!
//struct info {
//    string str;
//    int len, sum;
//};
//
//
//void setStr(info &in) {
//
//
//    char c;
//
//    int sum = 0;
//    for (int i = 0; i < in.len; i++) {
//        c = in.str.at(i);
//        if (isdigit(c)) {
//            sum += (int) (c - '0');
//        }
//    }
//    in.sum = sum;
//
//
//}
//
//bool compare(const info &i1, const info &i2) {
//
//    if (i1.len != i2.len)
//        return i1.len < i2.len;
//    if (i1.sum != i2.sum)
//        return i1.sum < i2.sum;
//    return i1.str < i2.str;
//
//}
//
//
//int main() {
//
//    int N;
//    string str = "";
//    vector<info> arr;
//    cin >> N;
//
//    arr.assign(N, {});
//
//    for (int i = 0; i < N; i++) {
//        cin >> str;
//        arr[i].str = str;
//        arr[i].len = str.length();
//        setStr(arr[i]);
//    }
//
//    sort(arr.begin(), arr.end(), compare);
//
//    for (int i = 0; i < N; i++) {
//        cout << arr[i].str << "\n";
//
//    }
//}