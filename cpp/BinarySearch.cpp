
#include <iostream>
#include <vector>
using namespace std;

bool bs(vector<int>& arr,int l,int r,int target)
{
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==target){
            return true;
        }
        else if(arr[mid]<target){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }

    return false;
}

bool isAnswerPossible(int val)
{    
    return val>10;
}

bool BsOnAnswerMin(int minv,int maxv,int target)
{
    int ans=-1;
    while(minv<=maxv)
    {
        int mid=minv+(maxv-minv)/2;
        if(isAnswerPossible(mid))
        {
            maxv=mid-1;
            ans=mid;
        }
        else
        {
            minv=mid-1;
        }
    }
    return ans;
}

bool BsOnAnswerMax(int minv,int maxv,int target)
{
    int ans=-1;
    while(minv<=maxv)
    {
        int mid=minv+(maxv-minv)/2;
        if(isAnswerPossible(mid))
        {
            minv=mid+1;
            ans=mid;
        }
        else
        {
            maxv=mid-1;
        }
    }
    return ans;
}




int main()
{
    
}