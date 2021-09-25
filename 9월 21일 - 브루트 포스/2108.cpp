

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;


bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second != b.second) return a.second > b.second; //내림차순
    return a.first < b.first; //오름차순
}


int main() {

    int N, num;
    vector<int> v;
    map<int, int> m;
    cin >> N;
    v.assign(N, 0);


    int median, mode, range;

    double mean;
    double sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> num;
        v[i] = num;
        m[num]++;
        sum += num;
    }

    sort(v.begin(), v.end());


    mean = sum / N;
    median = v[N / 2];
    range = v[N - 1] - v[0]; //v.end()-v.begin()은 안됨..

//    for (int i = 0; i < N; i++) {
//        cout << v[i] << " ";
//    }

    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

//    for (int i = 0; i < vec.size(); i++) {
//        cout << vec[i].first << " " << vec[i].second << "\n";
//    }

    if (vec[0].second != vec[1].second) mode = vec[0].first;
    else mode = vec[1].first;

    cout << fixed;
    cout.precision(0);
    cout << mean << "\n" << median << "\n" << mode << "\n" << range;


}