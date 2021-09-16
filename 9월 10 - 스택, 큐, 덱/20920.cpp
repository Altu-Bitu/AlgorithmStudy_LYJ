//
// Created by 이유정 on 2021/09/15.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


map<string, int> m;


bool compare(const pair<string, int> &a, pair<string, int> &b) {

    if (a.second != b.second)//언급 횟수 순
        return a.second >= b.second;//내림차순
    if (a.first.length() != b.first.length()) //길이 순
        return a.first.length() >= b.first.length();//내림차순
    return a.first < b.first;// 오름차순(알파벳순 )
}

int main() {

    int N, M;
    cin >> N >> M;

    string word;
    while (N--) {
        cin >> word;

        if (word.length() >= M) {
            m[word]++; //중복제거 + 언급횟수 기록을 위해 map사용
        }

    }

    //map을 vector로 이동 (정렬용도 )
    vector<pair<string, int>> w_list(m.begin(), m.end());

    sort(w_list.begin(), w_list.end(), compare);

    for (int i = 0; i < w_list.size(); i++) {
        cout << w_list[i].first << "\n";
    }
}