//
// Created by 이유정 on 2021/09/25.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;


bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second != b.second) return a.first > b.first; //내림차순
    return a.second < b.second; //오름차순
}


int main() {

    int N, num;
    vector<int> v;
    map<int, int> m;
    cin >> N;
    v.assign(N, 0);


    int mean, median, mode, range;

    int sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> num;
        v[i] = num;
        m[num]++;
        sum += num;
    }

    sort(v.begin(), v.end());


    mean = sum / N;
    median = v[N / 2 + 1];
    range = v.end() - v.begin();


    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

    if (vec[0].second != vec[1].second) mode = vec[0].first;
    else mode = vec[1].first;


    cout << mean << "\n" << median << "\n" << mode << "\n" << range; 


}