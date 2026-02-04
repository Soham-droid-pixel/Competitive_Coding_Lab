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
    //Brute force approach
    int number=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]==nums[j]){
              number=nums[i];
              cout<<number;
              return 0;
            }
        }
    }
        cout<<"No number repeated"<<endl;

    return 0;
}