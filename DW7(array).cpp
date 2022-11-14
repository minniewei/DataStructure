#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct ToDoThing{
    int priority;
    string thing;
    ToDoThing(int pri, string thi):priority(pri),thing(thi){};
    ToDoThing():priority(0),thing(""){};
};
int main(){
    vector<ToDoThing> ListThing;
    ListThing.push_back(ToDoThing());
    int totalThingToDo;
    string tmpThing;
    int tmpPriority;
    cin >> totalThingToDo;
    // 這裡為建立節點
    for(int i = 1 ; i <= totalThingToDo ; i ++){
        cin >> tmpThing;
        cin >> tmpPriority;
        //代表為第一個插入的數值
        if(i == 1){
            ListThing.push_back(ToDoThing(tmpPriority, tmpThing));
        }else{
            ToDoThing item = ToDoThing(tmpPriority,tmpThing);
            ListThing.push_back(item);
            int nowKey = i ;
            while((nowKey != 1) && (tmpPriority > ListThing[nowKey/2].priority)){
                ListThing[nowKey] = ListThing[nowKey/2];
                nowKey = nowKey/2;
            }
            ListThing[nowKey] = item;
        }
    }
    cout << "First three things to do:" << endl;
    // 這裡為找到最大的節點並刪除
    for(int i = 0 ; i < 3 ; i ++){
        if(ListThing.size() == 0 )break;
        // 先將第一個節點存放到root
        ToDoThing root = ListThing[1];
        // 把最後一個節點存放到tmp當中
        ToDoThing tmp = ListThing[ListThing.size()-1];
        int parent = 1;
        int child = 2;
        while(child < ListThing.size()){
            // 要設定我的東西不能超出size的範圍 / 進行同一階層的比較，找出比較大者
            if(child < ListThing.size() && ListThing[child].priority < ListThing[child +1].priority) child += 1;
            if(tmp.priority >= ListThing[child].priority) break;
            ListThing[parent] = ListThing[child];
            parent = child;
            child *= 2;
        }
        //最大的那個會被移動到最後面，現在
        ListThing[parent] = tmp;
        cout << root.thing << endl;
        ListThing.pop_back();
    }
    return 0 ;
}