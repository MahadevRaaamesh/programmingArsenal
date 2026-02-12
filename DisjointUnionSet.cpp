#include <iostream>
#include <vector>

using namespace std;

class DSU{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DSU(int n){
            parent.resize(n);
            rank.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=0;
            }
        }
        int find(int u){
            if(u==parent[u]){
                return u;
            }else{
                return find(parent[u]);
            }
        }
        void join(int u,int v)
        {
            int pu=find(u);
            int pv=find(v);
            if(pv==pu){
                return;
            }
            if(rank[pu]<rank[pv]){
                parent[pu]=pv;
            }else if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }else{
                parent[pu]=pv;
                rank[pv]++;
            }

        }
};

int main(){
    DSU dsu(10);
    
    dsu.join(1,2);
    dsu.join(3,2);
    dsu.join(4,2);
    dsu.join(5,2);
    dsu.join(6,2);
    for(int i=1;i<=6;i++){
        cout<<dsu.find(i)<<endl;
    }
    return 0;
}