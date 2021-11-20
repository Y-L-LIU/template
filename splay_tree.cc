#include <cstdio>
#define k 10000
template<typename T>
class Node{
public:
    T data;
    int children[2];
    int parent;
    int cnt;
    int size;
    Node(T x):data(x){};
};

Node<int> t[k];//suppose it should be int may be modified.
int root=0;//Actual root where 0 is a supposed father of root
int total=0;
void rotate(int x){
    int y=t[x].parent;
    int z=t[y].parent;
    int pos_x=(t[y].children[0]==x)?0:1;//x's position with regard to y
    int pos_y=(t[z].children[0]==x)?0:1;//y's position with regard to z
    //exchange x and y
    t[z].children[pos_y]=x;
    t[x].parent=z;
    t[y].parent=x;
    //give out child
    t[y].children[pos_x]=t[x].children[pos_x^1];
    t[x].children[pos_x^1]=y;
    //consider the transformation of size
    int m=t[x].children[pos_x^1];// changed x's child
    t[y].size=t[y].size-(t[x].size)+(t[m].size);
    t[x].size=t[x].size-(t[m].size)+(t[y].size);
}

void splay(int x, int goal){
    while(t[x].parent!=goal){
        int y=t[x].parent;
        int z=t[z].parent;
        if(z!=goal){
            (t[z].children[0]==y)^(t[y].children[0]==x)?rotate(x):rotate(y);
        }
        rotate(x);
    }
    if(goal==0)root=x;
}

template <typename T>
void insert(T x){
    int cur=root;
    int ff=0;
    while(cur&&t[cur].data!=x){
        ff=cur;
        t[cur].size++;//find downward, each time increase the ancestor by 1
        cur=t[cur].children[x>t[cur].data];
    }
    if(cur){t[cur].cnt++;t[cur].size++;}//increase the duplicated element
    else{
        cur=  ++total;
        if(ff){t[ff].children[x>t[ff].data]=u;}
        t[cur].children[0]=t[cur].children[1]=0;
        t[cur].parent=ff;
        t[cur].data=x;
        t[cur].cnt=1;
        t[cur].size=1;
    }
    splay(cur,0);
}

template <typename T>
void find(T x){
    int u=root;
    if(!u)return;
    while(x!=t[u].data && t[u].children[x>t[u].data]){
        u=t[u].children[x>t[u].val];
    }
    splay(u,0);
}

template <typename T>
int next(T x, int f){//prevoius f=0 next f=1
    find(x);
    int u=root;
    if(f && t[u].data>x)return u;//If we cannot find the item x
    if(!f && t[u].data<x)return u;
    u=t[u].children[f];
    while(t[u].children[f^1]){
        u=t[u].children[f^1];
    }
    return u;
}

template <typename T>
void Delete(T x){
    int last=next(x,0);
    int next=next(x,1);
    splay(last,0);
    splay(next,last);
    //pre comes to root node
    //next is the right child of pre
    //x is the left child of next, where x is alse a leaf node
    int del=t[next].children[0];
    if(t[del].cnt>1){
        t[del].cnt--;splay(del, 0);
    }else{t[next].children[0]=0;}
}

template <typename T>
int kth(int m){
    int u=root;
    if(t[u].size<m)return 0;
    while(1){
        int y=t[u].children[0];
        if(x>t[y].size+t[u].size){
            x-=t[y].size+t[u].size;
            u=t[u].children[1];
        }else{
            if(t[y].size>=x){
                u=y;
            }else{return t[u].data;}
        }
    }
}










