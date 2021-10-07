//
// 큰 수 만들기
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> m;

//
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void makeMap(string s) {
    for (int i = 1; i <= s.size(); i++) {
        int a = s.at(i - 1) - '0';
        m.insert(make_pair(i, a));
    }

//    for (auto it = m.begin(); it != m.end(); it++) {
//        cout << it->first << " " << it->second << "\n";
//    }
}


string solution(string number, int k) {
    string answer = "";

    makeMap(number);
    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), compare);

    for (int i = 0; i < k; i++) {
        m.erase(vec[i].first);
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        string s = to_string(it->second);
        answer.append(s);
    }

//    cout << answer;

    return answer;
}

int main() {

    string number;
    cin >> number;

    int k;
    cin >> k;


    solution(number, k);
}