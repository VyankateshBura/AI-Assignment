#include<bits/stdc++.h>
using namespace std;
#define N 100

int BB(vector<vector<int>> g,int st,int goal,int arr[][N],bool visited[N]){
    int i = st;
    visited[st] = true;
    int count = 0;
    cout<<st<<" "<<goal<<endl;
    int ans = 0;
    while(i!=goal && count<11){
        count++;
        // cout<<"Inside loop"<<endl;
        int minimum=0;
        cout<<g[i].size()<<endl;
        if(g[i].size()==1){
            i = g[i][0];
            
            minimum = arr[i][g[i][0]];
        }
        else{
            minimum = INT_MAX;
            int min_index = i;
            cout<<"Edges are : ";
            for(int j=0;j<g[i].size();j++){
                cout<<(char)(g[i][j]+'A')<<" ";
                if(!visited[g[i][j]]&&minimum>arr[i][g[i][j]]){
                    minimum = arr[i][g[i][j]];
                    min_index = g[i][j];
                    
                }
            }
            if(min_index==i){

            }
            i=min_index;
            cout<<endl;
            cout<<"i value is :"<<(char)(i+'A')<<endl;
            
            visited[i]=true;
            
        }
        // cout<<minimum<<" ";
        ans+=minimum;
        
    }
    cout<<endl;
    return ans;
}


int main(){

    int n,m;
    cout<<"Enter the number of nodes and number of edges in the graph:"<<endl;
    cin>>n>>m;
    vector<vector<int>> graph(26);
    int arr[N][N] = {-1};
    bool visited[N] = {false};
    cout<<"Enter the each edge and its weight:"<<endl;
    for(int i=0;i<m;i++){
        char a,b;
        cin>>a>>b;
        int wt;
        cin>>wt;
        int v,w;
        v = a-'A';
        w = b-'A';
        // cout<<v<<" "<<w<<endl;
        arr[v][w] = wt;
        arr[w][v] = wt;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }
    char a,b;
    cout<<"Enter the starting and the goal node:"<<endl;
    cin>>a>>b;
    // cout<<a<<" "<<b<<endl;
    int st = a-'A',goal = b-'A';
    // cout<<st<<" "<<goal<<endl;
    int BBcost = BB(graph,st,goal,arr,visited);

    cout<<"The optimal path by branch and bound is "<<BBcost<<endl;


    return 0;
}