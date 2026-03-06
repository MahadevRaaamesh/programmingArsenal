#include <iostream>
#include <vector>

using namespace std;

bool condition(){

}

int SlidingWindow(vector<int>arr){
    int i=0;
    int answer=0;
    for(int j=0;j<arr.size();j++){
        //add new value
        while(i<j && !condition() ){
            //update params
            i++;
        }
        //check or count smthing
    }
    return answer;
}