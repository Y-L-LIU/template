#include<iostream>
using namespace std;
template<typename T>
void swap(T* a, T* b)
{
    T t = *a;
    *a = *b;
    *b = t;
}

template<typename T, typename T1>
int partition(T a[],int p,int r,T1 key){
    T x= a[r];
    int i=p-1;
    for(int j=p; j<r; ++j){
        if(key(a[j])<=key(x)){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[r]);
    return i+1;
}

template<typename T, typename T1>
void quicksort(T a[], int p, int r,T1 key){
    if(p<r){       
        int q = partition(a, p, r, key);
        quicksort(a, p, q-1, key);
        quicksort(a, q+1, r, key);
    }
}

// int main(){
//     struct  a{
//         int a,b;
//     }p[10];
//     for(int i=10;i>0;--i){
//         p[10-i].a=i;
//         p[10-i].b=i;
//     }
//     for(int i=0;i<10;++i){
//         cout<<p[i].b;
//     }
//     quicksort(p,0,9,[](a x){return x.b;});
//     for(int i=0;i<10;++i){
//         cout<<p[i].b;
//     }
// }
