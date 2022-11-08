#include<bits/stdc++.h>
using namespace std;
map<int,char> mp;

void printpath(vector<int> &p){
    for(int i=0;i<p.size();i++){
        cout<<mp[p[i]]<<" ";
    }
    cout<<endl;
}

int NotVisited(int x,vector<int> &path){
    for(int i=0;i<path.size();i++){
        if(path[i]==x){
            return 0;
        }
    }
    return 1;
}

void findpaths(vector<vector<int>> &g,int src,int dst, int n){
    queue<vector<int>> q;

    vector<int> path;
    path.push_back(src);
    q.push(path);
    while(!q.empty()){
        path = q.front();
        q.pop();
        int last = path[path.size()-1];
        if(last==dst){
            printpath(path);
        }

        for(int i=0;i<g[last].size();i++){
            if(NotVisited(g[last][i],path)){
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }


}

int main(){
    int n,m;
    // cout<<"Enter the number of nodes and number of edges in the graph:"<<endl;
    cin>>n>>m;

    char ch = 'A';
    for(int i=0;i<25;i++){
        mp[i] = ch;
        ch++;
    }

    //Declaring 
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        char a,b;
        cin>>a>>b;
        int u,v;
        u = a-'A';
        v=b-'A';
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // cout<<"Enter the start and the destination node:"<<endl;
    // char start,end;
    // cin>>start,end;
    // int st,en;
    // st = (int)start - 'A';
    // en = (int)end-'A';

    
    findpaths(g,0,3,n);


    return 0;
}