//使用linklist，但使用c++ queue
#include <iostream>
#include <queue>
using namespace std;
struct Node{
    Node *leftNode, *rightNode;
    int val;
    Node(Node* left, int val, Node* right):leftNode(left), rightNode(right), val(val){};
    Node(int val):val(val), leftNode(nullptr), rightNode(nullptr){};
    Node():leftNode(nullptr), rightNode(nullptr), val(0){};
};
class operaterNode{
    //我打算使用vector來創建tree
    public:
        Node *root = nullptr;
        Node *tmp = nullptr;
        queue<Node*> putNode;
        void addNewNode(int);
        void preOrder(Node*);
        void inOrder(Node*);
        void postOrder(Node*);
};
void operaterNode::addNewNode(int num){
    Node *CreateNode = new Node(num);  
    putNode.push(CreateNode);
    tmp = putNode.front();
    if(root == nullptr){
        root = CreateNode;
        tmp = root;
    }else{
        if(tmp -> leftNode == nullptr){
            tmp -> leftNode = CreateNode;
        }else{
            tmp -> rightNode = CreateNode;
            putNode.pop();
        }
    }
}
void operaterNode::inOrder(Node *nowNode){
    //先檢測是否有這個節點存在
    if(nowNode!= nullptr){
        inOrder(nowNode -> leftNode);
        cout << nowNode -> val << " ";
        inOrder(nowNode -> rightNode);
    }
}
void operaterNode::preOrder(Node *nowNode){
    //先檢測是否有這個節點存在
    if(nowNode!= nullptr){
        cout << nowNode -> val << " ";
        preOrder(nowNode -> leftNode);
        preOrder(nowNode -> rightNode);
    }
}
void operaterNode::postOrder(Node *nowNode){
    //先檢測是否有這個節點存在
    if(nowNode!= nullptr){
        postOrder(nowNode -> leftNode);
        postOrder(nowNode -> rightNode);
        cout << nowNode -> val << " ";
    }
}
int main(){
    int totalTree;
    cin >> totalTree;
    //創建節點的階段
    for(int i = 0 ; i < totalTree ; i++){
        int thisTreeNodeNumber,thisTimeNumber;
        //建立一個新的class
        operaterNode *newTree = new operaterNode;
        cin >> thisTreeNodeNumber;
        //將節點的值一個一個讀入
        for (int j = 0 ; j < thisTreeNodeNumber ; j++){
            cin >> thisTimeNumber;
            newTree -> addNewNode(thisTimeNumber);
        }
        //記得我的tree是從index為1開始，但存放在vector當中是從ind8ex為0開始
        newTree -> preOrder(newTree -> root);
        cout << endl;
        newTree -> inOrder(newTree -> root);
        cout << endl;
        newTree -> postOrder(newTree -> root);
        cout << endl;
    } 
}