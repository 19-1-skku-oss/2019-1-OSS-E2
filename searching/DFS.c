// DFS is Depth-First Search

#include <stdio.h>
 
int number = 9;
int visit[9];
int* a[][10];
 
void dfs(int start){
    if(visit[start]){
        return; // get out in case of visit
    }
    
    visit[start] = true; // visiting
    printf("%d ", start);
    
    for(int i=0; i< a[start].size(); i++){
        int x = a[start][i]; // Visit adjacent nodes
        dfs(x);
    }
}
 
int main(void){
    // connect the 1,2
    a[1].push_back(2);
    a[2].push_back(1);
    
    // connect the 1,3
    a[1].push_back(3);
    a[3].push_back(1);
    
    // connect the 2,3
    a[2].push_back(3);
    a[3].push_back(2);
    
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
    
    // run bfs searching from node 1 
    dfs(1);
    
    return 0;
} 
