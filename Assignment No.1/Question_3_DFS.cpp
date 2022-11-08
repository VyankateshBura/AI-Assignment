#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the number of nodes and number of edges in the graph: "<<endl;
    cin>>n>>m;
    int key;
    cout<<"Enter the element you want to find: "<<endl;
    cin>>key;
    vector<int> adj[n+1];
    vector<int> visited(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<<"Enter the links between the nodes"<<endl;
    stack<int> q;
    q.push(1);
    visited[1]=1;
    while(!q.empty()){
        int data = q.top();
        cout<<data<<" ";
        if(data==key){
            break;
        }
        q.pop();
        reverse(adj[data].begin(),adj[data].end());
        for(auto it:adj[data]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }

    }
    return 0;
}