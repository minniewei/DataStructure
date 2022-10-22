#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<char> postfix(string NowDealString){
    map<char, int> mapOperand;
    mapOperand['+'] = 12;
    mapOperand['-'] = 12;
    mapOperand['*'] = 13;
    mapOperand['/'] = 13;
    mapOperand[')'] = 19;
    mapOperand['('] = 0; 
    stack<char> enterOperand;
    vector<char> output;
    string nowResult = "";
    for(int i = 0 ; i < NowDealString.length() ; i++){
        //對於每一個獲取值我們要判斷是否為數字或操作符號
        //假設說為數字，我直接把他加進去新的string當中
        if((int)NowDealString[i] == 32){
            continue;
        }else if(NowDealString[i]!='+' && NowDealString[i] !='-' && NowDealString[i] !='*' && NowDealString[i] !='/' && NowDealString[i] !=')' && NowDealString[i] != '('){
            output.push_back(NowDealString[i]);
            output.push_back(' ');
        }else{
            //先從stack當中取出上一個數字(stack當中不為空)
            
                //我們要先從stack當中取出上一個數字並進行比較
                //假如說為右括號 ----> 到左括號之間的內容都要取出來而又括號跟左括號不用印出來
                //假如說為左括號 ----> 無條件放進stack當中(略過下面的if)
                //其他的都要先進行比較
                if((int)NowDealString[i] == 41){
                    while(enterOperand.top() != '('){
                        output.push_back(enterOperand.top());
                        output.push_back(' ');
                        enterOperand.pop();
                    }
                    enterOperand.pop();
                    continue;
                }else {
                    while(!enterOperand.empty() && mapOperand[enterOperand.top()] >= mapOperand[NowDealString[i]] && (int)NowDealString[i] != 40){
                        //將上一個取出並放到nowresult
                        output.push_back(enterOperand.top());
                        output.push_back(' ');
                        enterOperand.pop();
                    }
                }

            //將輸入的符號存進去
            enterOperand.push(NowDealString[i]);
        }
    }
    //將stack剩下的東西都拿出來
    while(!enterOperand.empty()){
        output.push_back(enterOperand.top());
        output.push_back(' ');
        enterOperand.pop();
    }
    return output;
}

int main(){
    vector<char> output;
    int totalnumber;
    string tmp;
    cin >> totalnumber;
    //cin轉getline的必備條件
    cin.ignore();
    for(int i = 0 ; i < totalnumber ; i++){
        getline(cin,tmp);
        output = postfix(tmp) ;
        for(int j = 0;j <output.size();j++){
            cout<<output[j];
        }
        cout << endl;
    }
    return 0;
}