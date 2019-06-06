// UnionFind algorithm is same as disjoint-set algorithm.

#include <stdio.h>

// finding parent node function
int getParent(int parent[], int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = getParent(parent, parent[x]);
}
 
// function that combines two parent nodes 
int unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    // select small value as parent node
    if(a<b){
        parent[b] = a;
        return a;
    }else{
        parent[a] = b;
        return b;
    }
}
 
// make sure you have the same parents
int findParent(int parent[], int a, int b){
    a=getParent(parent, a);
    b=getParent(parent, b);
    if(a == b){
        return 1;
    }
    return 0;
} 
 
int main(void){
    int parent[11];
    for(int i=1; i<=10; i++){
        parent[i] = i;
    }
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);
    unionParent(parent, 9, 10);
    
    // check the result
    for(int i=1; i<=10; i++){
        printf("node : %d / parent : %d\n", i, parent[i]);
    }
    
    printf("Are 1 and 5 connected? : %d\n", findParent(parent, 1, 5));
    printf("Are 1 and 3 connected? : %d\n", findParent(parent, 1, 3));
    printf("Are 5 and 10 connected? : %d\n", findParent(parent, 5, 10));
    
    return 0;
}
