#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

#define LEFT_FIRST 0
#define RIGHT_FIRST 1

struct Node;
typedef Node* TreeNode;
struct QueueRecord;
typedef QueueRecord* Queue;
struct Node{
    int val;
    int m_layer;
    TreeNode left;
    TreeNode right;
}

struct QueueRecord{
    int Front;
    int Rear;
    int* array;
}

TreeNode BuildTree(int* inorder,int*postorder,int* postend,int instart,int inend){
    //exit,recursion form
    TreeNode root,left_node,right_node;
    int i;

    if(instart>inend) return NULL;
    int tmp_val=postorder[*postend];
    *postend-=1;
    for(i=instart;i<inend;i++){
        if(inorder[i] == val ) break;
    }
    //core,recursion,notice that right is prior to the left
    right_node =BuildTree(inorder,postorder,postend,i+1,inend);
    left_node =BuildTree(inorder,postorder,postend,instart,i-1);
    
    root= (TreeNode)malloc(sizeof(struct Node));
    root->val=tmp_val;
    root->right=right_node;
    root->left= left_node;
    return root;
}

void zigzagPrint(TreeNode T){
    

}

int main(){
    int n;
    // scanf("%d",&n);
    int *inorder = (int*) malloc (sizeof(int)*n);
    int* postorder = (int*) malloc (sizeof(int)*n);
    int i=0;
//test
    n=8;
    inorder=[12 ,11 ,20 ,17, 1 ,15 ,8 ,5];
    postorder=[12, 20, 17, 11 ,15, 8 ,5 ,1]
    // for(i=0;i<n;i++)  scanf("%d",inorder+i);
    // for(i=0;i<n;i++)  scanf("%d",postorder+i);
    TreeNode root = BuildTree(inorder,postorder,n-1,0,n-1);

}