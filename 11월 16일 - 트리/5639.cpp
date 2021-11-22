//
// 5369번 - 이진 검색 트리
//
// 검색 : - c++ eof
//       - 자료구조 BST(이상호 교수님)
//       - 수업 PPT


#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int data;
};

void insert_node(Node *root, int data) {
    Node *p, *t;//부모노드, 자식노드
    Node *n;//현재 넣을 노드

    t = root;

    while (t != NULL) {//자식노드가 NULL이면 종료
        if (data == t->data) return;//이미 있으면 x
        p = t;//자식노드를 부모로 변경
        if (data < t->data) t = t->left; // 입력받은 값 < 노드값 -> left
        else t = t->right;
    }

    n = new Node();//새로삽입할 노드 초기화
    n->data = data;//데이터 넣기
    n->left = n->right = NULL;

    if (p != NULL) { //부모 노드가 NULL이면 종료
        if (data < p->data) p->left = n;//부모보다 작으면 left
        else p->right = n;
    }

}


void postorder(Node *v) {
    if (v != NULL) {
        postorder(v->left);
        postorder(v->right);
        cout << v->data << "\n";
    }
}

int main() {

    vector<int> v;
    int num;
    cin >> num;

    //첫번 째 입력으로 들어오는거 root(전위순회라)
    Node *root = new Node();
    root->data = num;
    root->left = root->right = NULL;


    while (true) {
        cin >> num;
        if (cin.eof()) break; //clion에서는 안되는군..

        insert_node(root, num);//root를 기준으로 이진트리 만들기
    }

    postorder(root);//후위 순회

}