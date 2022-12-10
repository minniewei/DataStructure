//我希望使用Kruskal方法來找到最小生成樹
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Edge{
    public :
    int x ;
    int y ;
    int w ;
};
vector<int> p;
vector<int> num;
int findParent(int a){
    //假設說他的parent不是他自己(代表這個邊已經被選過)
    //重點-----> 錯誤的地方
    while( a != p[a]) a = p[a];
    return a;
}
bool cmp(Edge a, Edge b){
    // 初始化說要進行升續排列
    return a.w < b.w;
}
int main(){
    int n, m ;
    int tmpx, tmpy, tmpw;
    int totalWeight = 0;
    int totalUseEdge = 0 ;
    vector<Edge> edge;
    cin >> n >> m;
    // 將所有的邊儲存起來
    for(int i = 0 ; i < m ; i ++){
        Edge tmpEdge;
        cin >> tmpx >> tmpy >> tmpw;
        tmpEdge.x = tmpx ;
        tmpEdge.y = tmpy ;
        tmpEdge.w = tmpw ;
        edge.push_back(tmpEdge);
    }
    // 我要對p跟num進行初始化
    for(int i = 0 ; i < n ; i ++){
        p.push_back(i);
        num.push_back(1);
    }
    // 依照權重大小將邊進行排序
    sort(edge.begin(), edge.end(), cmp);
    for( int i = 0 ; i < m && totalUseEdge < n; i ++){
        // 將每個邊取出來並看其兩個點是否在同一個集合當中 ， 不在同一個集合才要進行相對應的計算
        if(findParent(edge[i].x) != findParent(edge[i].y)){
            totalWeight += edge[i].w;
            totalUseEdge ++;
            //假設說x所在的集合大小比較大
            //重點 ----> 錯誤的地方
            if(num[findParent(edge[i].x)] > num[findParent(edge[i].y)]){
                num[findParent(edge[i].x)] += num[findParent(edge[i].y)];
                p[findParent(edge[i].y)] = p[findParent(edge[i].x)];
            }else{
                num[findParent(edge[i].y)] += num[findParent(edge[i].x)];
                p[findParent(edge[i].x)] = p[findParent(edge[i].y)];                
            }
            //假設說y所在的集合大於或等於x
        }
    }
    if(totalUseEdge == n-1) cout << totalWeight << endl;
    return 0 ;
}
//常見錯誤
// 1. 要記得初始化為0