//
// 18111번 - 마인크래프트
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAX 7e7 //최대 500*256 + 6.4*10^7 개
using namespace std;

vector<vector<int>> mapp;
map<int, int> cnt;


//second기준 내림차순
bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}


//블럭 보유상황(?)
int isPossible(vector<pair<int, int>> &v, int b, int height) {

    int add = 0, sub = 0; //필요한 블럭의 수
//    int time = 0;
    int diff;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == height) continue;//높이가 같은 애들은 패스

        if (v[i].first > height) { //인벤토리에 추가될 블럭의 수
            diff = v[i].first - height;//높이 차이
            add += diff * v[i].second;
        }

        if (v[i].first < height) {//인벤토리에서 꺼내서 사용해야할 블럭의 수
            diff = height - v[i].first;//높이차이
            sub += diff * v[i].second;
        }

    }

    if (b + add < sub) { //블럭 수가 부족해서 불가능함
        return MAX;
    }


    return add * 2 + sub * 1;//블럭의 수가 충분하여 시간을 구하면됨

}


int main() {

    int min = MAX;
    int max = -1;

    int n, m;
    int b;
    cin >> n >> m >> b;

    mapp.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapp[i][j];
            cnt[mapp[i][j]]++;
            if (mapp[i][j] < min) min = mapp[i][j];
            else if (mapp[i][j] > max) max = mapp[i][j];
        }
    }


    //value 내림차순으로 정렬
    vector<pair<int, int>> vec(cnt.begin(), cnt.end());

    sort(vec.begin(), vec.end(), cmp);

//
//    for (int i = 0; i < vec.size(); i++) {
//        cout << vec[i].first << " " << vec[i].second << "\n";
//    }
//
//
//    cout << min << " " << max << "\n";

    pair<int, int> ans = {MAX, 0};
    for (int h = max; h >= min; h--) {

        int res = isPossible(vec, b, h);
        if (res < ans.first) {
            ans.first = res;
            ans.second = h;
        }
// max부터 값을 줄여가면서 진행 + <=이 아니므로 h에 더 높은값이 자동으로 저장될 수 있음
//        else if (res == ans.first && h > ans.second) {//길이가 같을떈 더 높은 것
//            ans.second = h;
//        }

    }

    cout << ans.first << " " << ans.second;


}

