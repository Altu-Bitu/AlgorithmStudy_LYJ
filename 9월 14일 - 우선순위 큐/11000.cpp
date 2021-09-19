//
// Created by 이유정 on 2021/09/19.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> v;

int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, s, t;
    cin >> N;

    while (N--) {

        cin >> s >> t;

        pq.push({s, t});

    }


    v.push_back(0); //0


    while (!pq.empty()) {
        int start = pq.top().first; //수업 시작 시간
        int end = pq.top().second;
        int flag = false;
        pq.pop();

        for (int i = 0; i < v.size(); i++) { //여기 시간초관데

            if (v[i] <= start) {
                v[i] = end;
                flag = true;
                break;
            }


        }

        if (flag == false) {
            v.push_back(end);
        }

    }

    cout << v.size();

}