#include<bits/stdc++.h>
using namespace std;
# define N 26
int minmax(int d,int ind,bool ismax,int arr[],int h){
    if(d==h){
        return arr[ind];
    }
    if(ismax){
        return max(minmax(d+1,ind*2,false,arr,h),minmax(d+1,ind*2+1,false,arr,h));
    }
    else{
        return min(minmax(d+1,ind*2,true,arr,h),minmax(d+1,ind*2+1,true,arr,h));
    }
}
int main(){
    int arr[] = {2,3,5,9,0,1,7,5};
    int h = 4;
    int depth = 0;
    int res = minmax(1,0,true,arr,h);
    cout<<res<<endl;
    return 0;
}