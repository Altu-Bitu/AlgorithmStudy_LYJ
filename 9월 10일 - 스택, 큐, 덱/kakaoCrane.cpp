//
// 카카오 크레인 인형뽑기 게임
// https://programmers.co.kr/learn/courses/30/lessons/64061
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>


using namespace std;

vector<stack<int>> dolls; // 스택으로 만든 각 라인 저장

//각 라인을 스택으로 만들기
// index : 해당 라인
stack<int> dollStack(vector<vector<int>> &board, int index) {

    stack<int> s;
    for (int i = board.size() - 1; i >= 0; i--) { //해당 라인 밑바닥 부터 검사
        int doll = board[i][index]; // 들어있는 인형
        if (doll == 0) break; // 0인 칸부터 인형없음
        s.push(doll);

    }

    return s;

}


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> bucket;

    for (int i = 0; i < board.size(); i++) //각 열의 인형들을 스택에 넣기
        dolls.push_back(dollStack(board, i)); //그걸 다시 벡터배열로 만들기

    for (int i = 0; i < moves.size(); i++) {

        int pos = moves[i] - 1; // 이번 회차에 뽑을 라인 인덱스

        if (dolls[pos].empty()) // 뽑을 라인이 비어있으면, 밑에 꺼 실행 ㄴㄴ
            continue;
        int pick = dolls[pos].top(); // 뽑힌 인형
        dolls[pos].pop(); //인형 뽑음

        if (!bucket.empty() && bucket.top() == pick) {//인형 칸이 안비었음 + 버켓에 담긴거랑 똑같음
            answer += 2;
            bucket.pop();//똑같으니까 제거
        } else {
            bucket.push(pick);//안똑같으면 그냥 버켓에 넣기
        }
    }
    return answer;
}



//int solution(vector<vector<int>> board, vector<int> moves) {
//    int answer = 0;
//    int past = -1;
//    int now = -1;
//    //인형을 뽑아서 bucket에 담는다
//    //board에서는 그자리 0으로 바꿔야함
//    for(int i=0; i<moves.size();i++){ //뽑기 기계 움직이기
//
//        int loc = moves[i]-1; //세로줄
//        //인형 뽑기
//        for(int j=0;j<board.size();j++ ){
//
//            int doll = board[j][loc];
//            if(doll != 0){ //뽑을 수 있음
//                now = doll;
//                board[j][loc] = 0;
//                break;
//            }
//
//            if(j==board.size()-1){
//                now = -2; //끝까지 탐색했는데 못뽑음
//            }
//
//        }
//
//        //이전에 뽑앗던 인형을 저장해두고 같은지 비교
//        if(now != -2){
//            if(past == now){    //같으면
//                answer+=2;
//                bucket.pop(); //이전꺼 없애기
//
//                if(bucket.empty()) past=-1;
//                else past = bucket.top(); //past를 새로운걸로 교체
//            }else{
//                bucket.push(now);
//                past = now;
//            }
//        }
//
//
//
//    }
//
//    //이전에 뽑앗던 인형을 저장해두고 같은지 비교
//
//    //같으면
//    //1.answer +=2
//    //2.stack에서 꺼내서 젤위에있는거를 이전 인형으로 갈아치기
//
//    //다르면
//    //1.방금 뽑은 인형을 이전에 뽑은 인형으로 만들기
//
//
//    return answer;
//}

int main() {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 3},
                                 {0, 2, 5, 0, 1},
                                 {4, 2, 4, 4, 2},
                                 {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    cout << solution(board, moves);
}