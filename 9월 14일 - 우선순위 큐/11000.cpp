//
// 11000번
// 샘플코드참고
// https://iagreebut.tistory.com/196
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;
vector<pair<int, int>> v;


int main() {

    int N, s, t;
    cin >> N;

    v.assign(N, {0, 0});

    for (int i = 0; i < N; i++) {
        cin >> s >> t;
        v[i] = {s, t};
    }

    sort(v.begin(), v.end());

    int ans = 1; //최초는 넣어두기
    pq.push(v[0].second);

    for (int i = 1; i < N; i++) {

        if (pq.top() > v[i].first) {
            ans++;//새로운 교실이 필요
        } else {
            pq.pop();//새로운 교실 필요 x
        }
        pq.push(v[i].second);//배치완료이므로 배치 완료된 집단에 넣어줘야함

    }

    cout << ans;


}










//
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//vector<int> v;
//
//int main() {
//
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int N, s, t;
//    cin >> N;
//
//    while (N--) {
//
//        cin >> s >> t;
//
//        pq.push({s, t});
//
//    }
//
//
//    v.push_back(0); //0
//
//
//    while (!pq.empty()) {
//        int start = pq.top().first; //수업 시작 시간
//        int end = pq.top().second;
//        int flag = false;
//        pq.pop();
//
//        for (int i = 0; i < v.size(); i++) { //여기 시간초관데
//
//            if (v[i] <= start) {
//                v[i] = end;
//                flag = true;
//                break;
//            }
//
//
//        }
//
//        if (flag == false) {
//            v.push_back(end);
//        }
//
//    }
//
//    cout << v.size();
//
//}