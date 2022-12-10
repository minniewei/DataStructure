#include <iostream>
#include <vector>
using namespace std;
int main(){
    int totalNumber, start, end, tmpNumber;
    cin >> totalNumber >> start >> end;
    vector<vector<int>> path;
    for( int i = 0 ; i < totalNumber ; i ++){
        vector<int> tmpVector;
        for( int j = 0 ; j < totalNumber ; j ++){
            cin >> tmpNumber ;
            tmpVector.push_back(tmpNumber);
        }
        path.push_back(tmpVector);
    }

    for( int k = 0 ; k < totalNumber ; k ++){
        for(int i = 0 ; i < totalNumber ; i ++){
            for(int j = 0 ; j < totalNumber ; j ++){
                if( i == j )continue;
                if( (path[i][j] == 0 && path[i][k] != 0 && path[k][j] != 0) ||(path[i][j] != 0 && path[i][k] != 0 && path[k][j] != 0 && ( path[i][k] + path[k][j]  < path[i][j] ) ) ){
                    path[i][j] = path[i][k] + path[k][j] ;
                }
            }
        }
    }
  	cout << path[start][end] << endl;
    return 0; 
}
