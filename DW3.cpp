#include <iostream>
using namespace std;
//定義每個節點
struct ListNode{
public:
    int cof,exp;
    ListNode *next;
    ListNode() : cof(0),exp(0),next(nullptr) {}
    ListNode(int cofout,int expout) : cof(cofout),exp(expout),next(nullptr) {}
    ListNode(int cofout,int expout,ListNode *next) : cof(cofout),exp(expout),next(next) {}
};
int main(){
    /*總共要建立三個鏈結串列
    串列1:第一個多項式
    串列2:第二個多項式
    串列3:第三個多項式(一跟二多項式的相加)
    */
    //建立儲存大小的變數
    int ListSize[2];
    ListNode *head[3];
    ListNode *tmp[3];
    //暫時存放輸入變數
    int cof,exp;
    //確認是否為第一個數字
    //假設說為1，代表為第一個數字;假設說為0，代表非為第一個數字
    int firstNumber = 1;
    //處理第一個和第二個鏈結串列
    for(int j =0 ; j < 2 ; j++){
        cin >> ListSize[j];
        for(int i = 0 ; i < ListSize[j] ; i++){
            if(i == 0){
                cin >> cof >> exp;
                tmp[j] = head[j] = new ListNode(cof,exp);
            }else{
                cin >> cof >> exp;
                tmp[j] -> next = new ListNode(cof,exp);
                tmp[j] = tmp[j] -> next;
            }
        } 
    }
    tmp[0] = head[0];
    tmp[1] = head[1];
    while(tmp[0] != NULL || tmp[1]  != NULL){
        if(tmp[0] != NULL && tmp[1] != NULL){
            if(tmp[0] -> exp < tmp[1] -> exp){
                if(firstNumber == 1){
                    tmp[2] = head[2] = new ListNode(tmp[1] -> cof,tmp[1] -> exp);
                    firstNumber = 0;
                }else{
                    tmp[2] -> next = new ListNode(tmp[1] -> cof,tmp[1] -> exp);
                    tmp[2] = tmp[2] -> next;
                }
                tmp[1] = tmp[1] -> next;
            }else if(tmp[0] -> exp > tmp[1] -> exp){
                if(firstNumber == 1){
                    tmp[2] = head[2] = new ListNode(tmp[0] -> cof,tmp[0] -> exp);
                    firstNumber = 0;
                }else{
                    tmp[2] -> next = new ListNode(tmp[0] -> cof,tmp[0] -> exp);
                    tmp[2] = tmp[2] -> next;
                }
                tmp[0] = tmp[0] -> next;
            }else{
                if(firstNumber == 1){
                    tmp[2] = head[2] = new ListNode(tmp[0] -> cof + tmp[1] -> cof ,tmp[0] -> exp);
                    firstNumber = 0;
                }else{
                    tmp[2] -> next = new ListNode(tmp[0] -> cof + tmp[1] -> cof ,tmp[0] -> exp);
                    tmp[2] = tmp[2] -> next;
                }
                tmp[0] = tmp[0] -> next;
                tmp[1] = tmp[1] -> next;
            }
        }else if(tmp[0] != NULL){
            if(firstNumber == 1){
                tmp[2] = head[2] = new ListNode(tmp[0] -> cof,tmp[0] -> exp);
                firstNumber = 0;
            }else{
                tmp[2] -> next = new ListNode(tmp[0] -> cof,tmp[0] -> exp);
                tmp[2] = tmp[2] -> next;
            }
            tmp[0] = tmp[0] -> next;
        }else{
            if(firstNumber == 1){
                tmp[2] = head[2] = new ListNode(tmp[1] -> cof,tmp[1] -> exp);
                firstNumber = 0;
            }else{
                tmp[2] -> next = new ListNode(tmp[1] -> cof,tmp[1] -> exp);
                tmp[2] = tmp[2] -> next;
            }
            tmp[1] = tmp[1] -> next;
        }
        
    }
    //印出第三個鏈結串列
    tmp[2] = head[2];
    while(tmp[2] != NULL ){
        if(tmp[2] ->cof !=0 ){
            cout << tmp[2] -> cof << " " << tmp[2] -> exp << " " ;
        }
        tmp[2]  = tmp[2] -> next;
    }

    return 0;
}
