// BFS is Breadth-First Search

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int number = 9;
int visit[9];
vector<int> a[10];
 
void bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()){
        // Repeat if there is a value in the queue
        // If there is a value in the queue, it means there are nodes that have not yet been visited.
        
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for(int i=0; i< a[x].size(); i++){
            int y = a[x][i];
            if(!visit[y]){
                q.push(y);
                visit[y] = true; 
            }
        }
    }
}
 
int main(void){
    
    // connect the 1,2
    a[1].push_back(2);
    a[2].push_back(1);
    
    // connect the 1,3
    a[1].push_back(3);
    a[3].push_back(1);
    
    // connect the 2,4
    a[2].push_back(4);
    a[4].push_back(2);
 
    // connect the 2,5
    a[2].push_back(5);
    a[5].push_back(2);
    
    // connect the 4,8
    a[4].push_back(8);
    a[8].push_back(4);
    
    // connect the 5,9
    a[5].push_back(9);
    a[9].push_back(5);
    
    // connect the 3,6
    a[3].push_back(6);
    a[6].push_back(3);
    
    // connect the 3,7
    a[3].push_back(7);
    a[7].push_back(3);
    
    // Run bfs searching from node 1
    bfs(1);
    
    return 0;
} 
