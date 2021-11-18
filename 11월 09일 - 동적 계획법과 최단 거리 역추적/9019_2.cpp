//
// 9019번 - DSLR
// 역추적이 필요하지 않고 큐에 바로 적용하는 풀이

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, string> ci;
const int SIZE = 10000; //최대 9999까지 저장가능

string bfs(int a, int b) {
    vector<bool> visited(SIZE, false);//방문 여부를 저장
    queue<ci> q;//bfs탐색을 위한 큐

    q.push(ci(a, "")); //시작 노드 초기화(최초 값, 명령어 없음)
    visited[a] = true;//방문 체크
    while (!q.empty()) {//큐가 비어있지 않은 동안 지속
        int cur = q.front().first; //현재 계산된 값
        string cur_path = q.front().second;//명령어 (경로를 이어서 계속 저장)
        q.pop();

        if (cur == b) //B를 만들었다면 탐색 종료
            return cur_path;//명령어 string 반환


        //명령어 "D"
        int next = cur * 2 % SIZE;//명령어 적용 값 계산
        if (!visited[next]) {//방문한 적 없는 경우에만
            q.push(ci(next, cur_path + "D"));//방문값 , 명령어에 D를 추가하여 반환
            visited[next] = true;//방문 체크
        }

        //명령어 "S"
        next = (cur - 1 + SIZE) % SIZE;//명령어 적용 값 계산
        if (!visited[next]) {//방문한 적 없는 경우에만
            q.push(ci(next, cur_path + "S"));//방문값 , 명령어에 S를 추가하여 반환
            visited[next] = true;//방문 체크
        }

        //명령어 "L"
        next = (cur * 10 % SIZE) + (cur / 1000);//명령어 적용 값 계산
        if (!visited[next]) {//방문한 적 없는 경우에만
            q.push(ci(next, cur_path + "L"));//방문값 , 명령어에 L를 추가하여 반환
            visited[next] = true;//방문 체크
        }

        //명령어 "R"
        next = (cur % 10 * 1000) + (cur / 10);//명령어 적용 값 계산
        if (!visited[next]) {//방문한 적 없는 경우에만
            q.push(ci(next, cur_path + "R"));//방문값 , 명령어에 L를 추가하여 반환
            visited[next] = true;//방문 체크
        }
    }
}

/**
 * 기본 풀이 설명은 9019.cpp 주석 참고
 *
 * 큐에 경로를 바로 저장하며 푸는 풀이
 * -> 따라서 역추적 과정이 필요 없음
 *
 * 배열 풀이와 다르게 자식 노드 탐색을 if문 4개로 분리하는 이유
 * -> 자식 노드를 저장하는 벡터 선언 시 소요되는 시간 때문에 벡터 + for 문을 해당 풀이에서 사용하면 시간초과
 */

int main() {
    int t, a, b; // t: test case의 수 , a : 최초의 수 , b : 변환된 수

    //입력 & 연산 & 출력
    cin >> t; //test case의 수를 입력받음
    while (t--) {//해당 수 만큼 반복
        cin >> a >> b;// 두개의 수를 입력받음
        cout << bfs(a, b) << '\n';//bfs탐색 수행
    }
    return 0;//종료
}