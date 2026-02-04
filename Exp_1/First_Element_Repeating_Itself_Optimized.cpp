#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    //Optimized approach
    unordered_set<int>seen;
    int number;
    for(int num:nums){
        if(seen.find(num)!=seen.end()){
            number=num;
            cout<<number;
            return 0;
        }
        seen.insert(num);
    }
    
    return 0;
}