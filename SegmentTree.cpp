#include <iostream>
#include <vector>

using namespace std;
/*
This Template is for a Template for SegTree
Change the Merge Function As needed
Give the Arr And Default Value for Template you need
*/

template <typename T>class SegTree{
    private:
        vector<T>Tree;
        int n; // Renamed 'default' to 'defaultValue' as 'default' is a C++ keyword.
        T defaultValue;
        
        T merge(T a,T b){
            return max(a,b);
        }

        void build(int l,int r,int node,vector<T>& arr){
            if(l==r){
                Tree[node]=arr[l];
                return;
            }
            int mid=(l+r)/2;
            build(l,mid,2*node+1,arr);
            build(mid+1,r,2*node+2,arr);
            Tree[node]=merge(Tree[2*node+1],Tree[2*node+2]);  
        }
        T query(int l,int r,int node,int ql,int qr){
            if(l>qr || r<ql){
                return defaultValue;
            }
            if(l>=ql && r<=qr){
                return Tree[node];
            }
            int mid=(l+(r-l)/2);
            return merge(query(l,mid,2*node+1,ql,qr),query(mid+1,r,2*node+2,ql,qr));
        }
        void update(int l,int r,int node,int pos,T val){
            if(l==r){
                Tree[node]=val;
                return val;
            }
            int mid=(l+(r-l)/2);
            if(mid<pos){
                update(mid+1,r,2*node+2,pos,val);
            }
            else{
                update(l,mid,2*node+1,pos,val);
            }
            Tree[node]=merge(Tree[2*node+1],Tree[2*node+2]);
            return ;  
        }
    public:
        SegTree(vector<T> arr,T d){
            n=arr.size();
            defaultValue=d;
            Tree.resize(4*n);
            build(0,n-1,0,arr);
        }
        T query(int l,int r){
            return query(0,n-1,0,l,r);
        }
        void update(int pos,T val){
            update(0,n-1,0,pos,val);
        }
};

int main(){
    vector<int> arr={1,2,3,4,5};
    int d=INT_MIN;
    SegTree<int> s(arr,d);
    cout<<s.query(0,4)<<endl;
}