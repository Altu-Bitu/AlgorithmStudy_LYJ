//
// 외판원 문제
//


#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;
int N;
int min_cost = 1e9;
vector<vector<int>> v;
bool check[SIZE]; //모든 도시를 방문해야함


void backtracking(int cur, int cost, int cnt, int first) { //마지막으로 방문한 도시, 지금까지의 금액, 지금 까지 계산한 것 중 최소, 최초 시작마을


    if (cnt == N) { //기저조건 -> 4개의 마을을 다 탐색했다.
        //처음 마을로 돌아가기
        if (v[cur][first] != 0) { //최초마을로 가는 길이 있을때만
            cost += v[cur][first];

//            cout << "first : " << first << "\n";
//            cout << "last : " << cur << "\n";
//            cout << "cost : " << cost << "\n";
            if (min_cost > cost) min_cost = cost; //구한 값이 최소면 갱신
        }

        return;

    }


    for (int i = 0; i < N; i++) {


        if (v[cur][i] != 0 && !check[i]) {//해당도시 방문 가능 or 45행 안넣을거면 &&min_cost>=cost 추가해야함
            check[i] = true;//방문했다고 체크
            cost += v[cur][i];//지금도시 -> i도시로의 가격

            if (min_cost >= cost) { //최소가격(?) 보다 큰경우 더이상 해당 가지 탐색 x -> 이렇게 했더니 틀렸고 위에있는 if문에 추가하니 맞음...
//                cout << "next(i) : " << i << "\n";
                backtracking(i, cost, cnt + 1, first);
            } // 여기로 해야 정답이고 시간도 훨 줄었다
            //원래 상태로 되돌리기
            check[i] = false;// 방문기록x
            cost -= v[cur][i];// 금액 제외시킴
//            } -> 이부분 피드백 : 원래대로 돌리는 부분을 if문 내에 넣어버렸기 때문에 ! 42행에서 도시가 체크되고 원복이 안되어서 에러였다!! 원복부분을 뺴야함
        }
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    v.assign(N, vector<int>(N, 0));
//    vector<int> vec(N, 0);


    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            cin >> v[j][i];
        }
//        v.push_back(vec);
//        vec.assign(N, 0);
    }


//    둘중 하나로 해야 오류 안남
//    for (int j = 0; j < N; j++) {
//        for (int i = 0; i < N; i++) {
//            cin >> num;
//            vec.push_back(num);
//        }
//        v.push_back(vec);
//        vec.clear(); //-> 이거로 하면 (N,0)으로 안되가지고 오류남
//    }

    for (int i = 0; i < N; i++) {
        check[i] = true; //최초마을은 이미 방문상태
        backtracking(i, 0, 1, i);//최초마을은 이미 방문해있으니까 cnt =1
        check[i] = false;//최초 마을 방문 해제
    }


    cout << min_cost;


}