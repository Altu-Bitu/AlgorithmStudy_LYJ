//
// 9019번 - DSLR
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, char> ci;
const int SIZE = 10000; //최대 9999까지 저장가능 -

//역추적
string back(int x, vector<ci> &path) { //x = B부터 역추적 시작
    string ans = "";//답을 반환할 string
    while (path[x].first != -1) {//path가 -1이면 끝
        ans += path[x].second;//명령어 부분을 ans에 저장
        x = path[x].first;//역추적
    }
    reverse(ans.begin(), ans.end());//역추적했으므로 순서를 역전함
    return ans;//저장한 string을 반환
}

//bfs
//연산을 적용해서 나온 계산값들을 자식노드로 하여 bfs탐색
void bfs(int a, int b, vector<ci> &path) {
    vector<bool> visited(SIZE, false); //방문 노드체크를 위한 배열
    queue<int> q; //bfs 탐색을 위한 큐

    q.push(a); //시작 노드 초기화
    visited[a] = true;//시작 노드를 방문했다고 표시
    while (!q.empty()) {
        int cur = q.front();//계산값을 저장함
        q.pop();

        if (cur == b) //B를 만들었다면 즉시 탐색 종료
            break;

        vector<ci> child = {{cur * 2 % SIZE,                   'D'}, //2배 후 나머지 (범위초과 고려)
                            {(cur - 1 + SIZE) % SIZE,          'S'}, //1 감소 후 나머지 (범위초과 고려)
                            {(cur * 10 % SIZE) + (cur / 1000), 'L'}, //앞으로 한칸씩 이동
                            {(cur % 10 * 1000) + (cur / 10),   'R'}};//뒤로 한칸씩 이동
        for (int i = 0; i < 4; i++) {//4가지 경우 수행
            int next = child[i].first;//계산 결과값
            if (!visited[next]) { //이전에 나온 계산값이 아니라면
                q.push(next);//큐에 넣음
                visited[next] = true;//이미 나온 계산값을 체크
                path[next] = ci(cur, child[i].second); //자식 노드에 부모 노드(경로/계산값)와 명령어 저장
            }
        }
    }
}

/**
 * path: 경로와 수행한 명령어(D, S, L, R)를 저장
 *
 * 각 명령어의 수행 결과를 사칙연산으로 나타낼 수 있음 (cur: 현재 수, SIZE = 10,000)
 * D: cur * 2 % SIZE
 * S: (cur - 1 + SIZE) % SIZE (cur이 0일 경우를 처리하기 위해)
 * L: (cur * 10 % SIZE) + (cur / 1000)
 * R: (cur % 10 * 1000) + (cur / 10)
 *
 * 따라서 위의 연산을 적용한 값들을 자식노드로 하여 bfs 탐색 진행
 * 앞서 구한 path값을 따라 B인덱스부터 역추적 시작
 */

int main() {
    int t, a, b; // t: test case의 수 , a : 최초의 수 , b : 변환된 수

    //입력 & 연산 & 출력
    cin >> t; //test case의 수를 입력받음
    while (t--) {//해당 수 만큼 반복
        cin >> a >> b;// 두개의 수를 입력받음
        vector<ci> path(SIZE, {-1, ' '}); //first: 경로, second: 명령어
        bfs(a, b, path);//bfs탐색
        cout << back(b, path) << '\n';//역추적한 값을 출력
    }
    return 0;//종료 
}

