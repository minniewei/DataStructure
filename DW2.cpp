#include <vector>
#include <iostream>
#include <stack>
using namespace std;
typedef struct {
    int vert;
    int horiz;
}offset;
offset direction[4];
void setElement(){
    //北邊
    direction[0].vert = -1;
    direction[0].horiz = 0;
    //東邊
    direction[1].vert = 0;
    direction[1].horiz = 1;
    //南邊
    direction[2].vert = 1;
    direction[2].horiz = 0;
    //西邊
    direction[3].vert = 0;
    direction[3].horiz = -1;
}
struct point{
    int col;
    int row;
    int dir;
    point(int col, int row):col(col), row(row), dir(0){};
    point():col(-1),row(-1),dir(0){};
};
void maze(){
    int EXIST_COL,EXIST_ROW,row,col,dir;
    int tmpnumber,next_row,next_col;
    //假如說找到了我會把found改成1，未找到則found維持0
    int found = 0;
    stack<point> nowPoint;
    vector<point> output;
    //暫時存放我的節點
    point tmp;
    cin >> EXIST_ROW >> EXIST_COL;
    vector<vector<int>> maze;
    vector<vector<int>> mark(EXIST_ROW + 2, vector<int>(EXIST_COL + 2 ,0));
    //設定maze
    for(int i = 0 ; i <EXIST_ROW +2 ; i ++){
        vector<int> tmp;
        for(int j = 0 ; j < EXIST_COL +2 ; j++ ){
            if(i == 0 || i == EXIST_ROW + 1 || j == 0 || j == EXIST_COL + 1){
                tmp.push_back(1);
            }else{
                cin >> tmpnumber;
                tmp.push_back(tmpnumber);
            }
        }
        maze.push_back(tmp);
    }
    //正式處理問題 ---> 先設置最初始的點
    nowPoint.push(point(1,1));
    //問題1
    mark[1][1] = 1;
    while(!nowPoint.empty() && !found){
        //把stack最上層的節點取出來並放到tmp當中
        tmp = nowPoint.top();
        nowPoint.pop();
        //情況1:找到了
        while(tmp.dir < 4 && ! found){
            //設定下一步的位置
            //問題點2
            next_row = tmp.row + direction[tmp.dir].vert;
            next_col = tmp.col + direction[tmp.dir].horiz;
            if(next_row == EXIST_ROW&& next_col == EXIST_COL){
                //由於我的stack要包含完整的路徑
                nowPoint.push(tmp);
                nowPoint.push(point(next_col,next_row));
                found = 1;
            }else if( !maze[next_row][next_col] && !mark[next_row][next_col]){
                //情況2:不是這個點，但下面有路可以走
                nowPoint.push(tmp);
                nowPoint.push(point(next_col,next_row));
                //問題1
                mark[next_row][next_col] = 1;
                break;
            }else{
                //情況3:不是這個點且下面沒路可以走
                tmp.dir++;
            }
        }
    }
    if(!found){
        //假使沒有找到
        cout << "Can't reach the exit!" ;
    }else{
        //假使找到了
        //題目要求要用stack為了方便，我只能轉成vector
        int size =nowPoint.size();
        for(int i = 0 ; i < size ; i++){
            output.push_back(nowPoint.top());
            nowPoint.pop();
        }
        for(int i = 1 ; i <= output.size() ; i++){
            cout << "(" << output[output.size()-i].row - 1 <<"," << output[output.size()-i].col - 1 << ")" << " ";
        }
    }
}
int main(){
    setElement();
    maze();
    return 0;
}