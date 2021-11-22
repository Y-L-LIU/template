using namespace std;
#define N 10000
int parent[N];
int size_[N];

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


void make_set(int v) {
    parent[v] = v;
    size_[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        if(size_[a]<size_[b]) parent[a]=b;
        else parent[b] = a;

        if(size_[a]==size_[b]) size_[a]++;
}

class edge
{
public:
    int u,v;
    int weight;
}p[N];
int n;
int cost;
int main(){
    quicksort(p, 0, N-1, [](edge x){return x.weight;});
    for(int i=0;i<n;++i){
        make_set(i);
    }
    for(int i=0; i<N;++i){
        if(parent[p[i].u]!=parent[p[i].v]){
            cost+=p[i].weight;
            union_sets(p[i].u,p[i].v);
        }
    }
}








