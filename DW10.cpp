#include <iostream>
#include <vector>
using namespace std;
int main(){
    int totalNumber, start, end;
    int tmpNumber;
    cin >> totalNumber >> start >> end;
    //　處理所有輸入的相關問題
    vector<vector<int>> path;
    for( int i = 0 ; i < totalNumber ; i ++){
        vector<int> tmpvector;
        for( int j = 0 ; j < totalNumber ; j ++){
            cin >> tmpNumber;
            tmpvector.push_back(tmpNumber);
        }
        path.push_back(tmpvector);
    }
    // 進行一連串的運算
    // 今天假設必定通過k這個點，我想知道各個陣列的值會變成多少
    for( int k = 0 ; k < totalNumber ; k ++){
        for( int i = 0 ; i < totalNumber ; i ++){
            for( int j = 0 ; j < totalNumber ; j++){
                if(path[i][j] == 0 && i == j)  continue;
                if((path[i][j] == 0 && path[i][k] != 0 && path[k][j] != 0 ) || (path[i][j] != 0 && path[i][k] != 0 && path[k][j] != 0 && (path[i][k]  + path[k][j]  < path[i][j]))){
                    path[i][j] = path[i][k] + path[k][j] ;
                }
            }
        }
        // 進行test
        //cout << "我現在在進行test喔喔喔!!" << endl;
        //for( int i = 0 ; i < totalNumber ; i ++){
        //    for( int j = 0 ; j < totalNumber ; j++){
        //        cout << path[i][j] << " ";
        //    }
        //    cout << endl;
        //}
    }
    // 最後找到0-3的最小cost(0,3)
    cout << path[start][end] << endl;

    return 0 ;
}