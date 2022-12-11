#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

//  使用stack進行一連串的運算
stack < long long int > s ;
vector< string > node;

void insertNode(string x){
    node.push_back(x);
}
void count(string x){
    if(x == "+"){
        long long int a = s.top();
        s.pop();
        long long int b = s.top();
        s.pop();
        s.push( a + b );
    }else if ( x == "-"){
        long long int a = s.top();
        s.pop();
        long long int b = s.top();
        s.pop();
        s.push( b - a );        
    }else if ( x == "*"){
        long long int a = s.top();
        s.pop();
        long long int b = s.top();
        s.pop();
        s.push( b * a );           
    }else if( x == "/"){
        long long int a = s.top();
        s.pop();
        long long int b = s.top();
        s.pop();
        s.push( b / a );          
    }else if( x != "-1"){
        //重點 ---> 轉換成數字
        s.push( x[0]- '0');
    }
}
void postOrder(int x){
    if(x < node.size()){
        postOrder(2*x) ;
        postOrder(2*x + 1) ;
        count(node[x]);
    }
}
int main(){
    int height ;
    string tmpString;
    cin >> height ;
    // 先將第一個空格填滿
    node.push_back("");
    // 先將東西輸入處裡完成
    for( int i = 1 ; i <= pow(2, height)-1 ; i ++){
        cin >> tmpString ;
        node.push_back(tmpString);
    }   
    postOrder(1);
    cout << s.top();
    return 0 ; 
}
