#include <iostream>
#include <vector>
using namespace std;

class BITREE
{
    public:
    vector<int>arr;
    vector<int>tree;

    BITREE(vector<int> &arr)
    {
        this->arr=arr;
        tree.resize(arr.size()+1);
        tree[0]=0;
        buildTree(arr);
    }

    void buildTree(vector<int>&arr)
    {
        for(int i=1;i<arr.size();i++){
            update(arr[i-1],i);
        }
    }

    void update(int val,int pos)
    {
        while(pos<=arr.size()){
            cout<<"update"<<(pos&(-pos))<<endl;
            tree[pos]+=val;
            pos+=(pos)&(-(pos));
        }
        return ;
    }

    int query(int j)
    {
        int ans=0;
        while(j>0){
            cout<<"query"<<j<<endl;
            ans+=tree[j];
            j-=j&(-j);
        }
        return ans;
    }
};

int main(){
    cout<<"started"<<endl;
    vector<int> arr={1,2,3,4};
    BITREE obj (arr);
    cout<<obj.query(4)<<endl;
}