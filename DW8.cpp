#include <iostream>
#include <queue>
using namespace std;
struct node{
    int num;
    node * right;
    node * left;
    node(int num, node * left, node * right):num(num), right(right), left(left){};
    node():num(0), right(nullptr), left(nullptr){};
    node(int num):num(num), right(nullptr), left(nullptr){};
};
void insert(node *&root, int num){
    if( root == nullptr) root = new node(num);
    else if( root -> num > num ) insert( root -> left , num );
    else if (root -> num < num ) insert( root -> right, num );
    else return ;
}
// 重點:取名delete的時候要小心 ---> delete是保留字
void deleteNode(node *&root, int num){
    if( root == nullptr){
        cout << "cannot delete" << endl;
        return;
    }else if(root -> num != num && root -> left == nullptr && root -> right == nullptr) {
        cout << "cannot delete" << endl;
        return ;
    }else if(root -> num == num){
        if( root -> left == nullptr && root -> right == nullptr) {
            root = nullptr;
            return;
        }else if( root -> left == nullptr ){
            root  = root -> right;
            return;
        }else if( root -> right == nullptr ){
            root = root -> left;
            return;
        }else{
            node * temp = root -> left;
            while( temp -> right != nullptr ) temp = temp -> right;
            root -> num = temp -> num ;
            deleteNode(root -> left, temp -> num);
            return ;
        } 
    }else if(root -> num > num) {
        deleteNode(root -> left, num);
    }else if(root -> num < num){
        deleteNode(root -> right, num);
    }
}
int searched = 0;
int found = 0;
void search(node * root, int num){
    if( root == nullptr ) return;
    search(root -> left, num);
    // 假設說左邊全部找完會取得最小值
    searched ++;
    if(searched == num){
        cout << root -> num << endl;
        return ;
    }
    search(root -> right, num);
}
void traversal(node * root){
    if(root == nullptr) return;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node * temp = q.front();
        q.pop();
        cout << temp -> num << " ";
        if( temp -> left != nullptr ) q.push( temp -> left );
        if( temp -> right != nullptr ) q.push( temp -> right );
    }
}
void height( node * root ){
    // 重點: 要記得return 回去啊啊啊
    if( root == nullptr ) {
        cout << "0" << endl;
        return;
    }
    queue<node*> q;
    q.push( root );
    int height = 0 ;
    while(true){
        int qsize = q.size();
        if(qsize == 0 ) {
            cout << height << endl;
            return ;
        }
        height ++;
        // 這層子節點的所有截點都儲存起來
        while( qsize > 0 ){
            node * temp =  q.front();
            q.pop();
            if(temp -> left != nullptr) q.push(temp -> left);
            // 不要用else if 
            if(temp -> right != nullptr ) q.push(temp -> right);
            qsize --;
        }
    }
}
int main(){
    string thing;
    node *root = nullptr ;
    while(cin >> thing){
       if( thing == "insert" ){
            int num;
            cin >> num;
            insert(root, num);
       }else if (thing == "delete"){
            int num;
            cin >> num;
            deleteNode(root, num);
       }else if (thing == "search"){
            int num;
            cin >> num;
            found = 0 ;
            searched = 0 ;
            search(root, num);
       }else if (thing == "height"){
            height(root);
       }else if (thing == "traversal"){
            traversal(root);
            break;
       }
    }
    return 0;
}