

#include <iostream>
#include <vector>

using namespace std;


vector<pair<int, int>> v;

int main() {

    int N;
    cin >> N;
    v.assign(N + 1, {0, 0});

    for (int i = 1; i < N + 1; i++) {

        cin >> v[i].first >> v[i].second;

    }

    int day = 1;
    int sum = 0;//금액의 총합
    int next_day = 0;
    int max = 1;

    while (day <= N) {


//        max = day;
//        for (int i = day; i < N + 1; i++) {
//
//            if (i + v[i].first > N)continue;
//            if (v[i].second > v[max].second) { max = i; }
//
//        }
//
//        next_day = day + v[max].first;
        next_day = day + v[day].first;

        if (next_day > 7) {
            break;
        }

        sum += v[day].second;


        day = next_day;

    }

    cout << sum;


}
