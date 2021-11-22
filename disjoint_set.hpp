#define N 10000
int parent[N];
int size[N];

void make_set(int v) {
    parent[v] = v;
    size[v] = 0;
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
        if(size[a]<size[b]) parent[a]=b;
        else parent[b] = a;

        if(size[a]==size[b]) size[a]++;
}


