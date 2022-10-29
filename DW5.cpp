#include <iostream>
#include <vector>
using namespace std;
class operaterNode{
    //我打算使用vector來創建tree
    public:
        vector<int> node;
        void addNewNode(int);
        void preOrder(int);
        void inOrder(int);
        void postOrder(int);
};
void operaterNode::addNewNode(int num){
    node.push_back(num);
}
void operaterNode::inOrder(int index){
    //先檢測是否有這個節點存在
    if(index <= node.size()){
        inOrder(2*index);
        cout << node[index-1] << " ";
        inOrder(2*index + 1);
    }
}
void operaterNode::preOrder(int index){
    //先檢測是否有這個節點存在
    if(index <= node.size()){
        cout << node[index-1] << " ";
        preOrder(2*index);
        preOrder(2*index + 1);
    }
}
void operaterNode::postOrder(int index){
    //先檢測是否有這個節點存在
    if(index <= node.size()){
        postOrder(2*index);
        postOrder(2*index + 1);
        cout << node[index-1] << " ";
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
        //記得我的tree是從index為1開始，但存放在vector當中是從index為0開始
        newTree -> preOrder(1);
        cout << endl;
        newTree -> inOrder(1);
        cout << endl;
        newTree -> postOrder(1);
        cout << endl;
    } 
}