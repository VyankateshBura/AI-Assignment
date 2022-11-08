#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the number of nodes and number of edges in the graph: "<<endl;
    cin>>n>>m;
    cout<<"Enter the starting node of BFS Traversal:"<<endl;
    int st;
    cin>>st;
    int key;
    cout<<"Enter the element you want to find: "<<endl;
    cin>>key;
    vector<int> adj[n+1];
    vector<int> visited(n+1,0);

    cout<<"Enter the links between the nodes"<<endl;
    for(int i=0;i<m;i++){
        char a,b;
        cin>>a>>b;
        int var1,var2;
        var1 = a-'A';
        var2  = b - 'A';
        adj[var1].push_back(var2);
        adj[var2].push_back(var1);
    }


    queue<int> q;
    q.push(1);
    visited[1]=1;
    while(!q.empty()){
        int data = q.front();
        char ch = data +'A';
        cout<<ch<<" ";
        if(data==key){
            break;
        }
        q.pop();
        for(auto it:adj[data]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }

    }
    return 0;
}