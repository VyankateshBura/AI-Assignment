#include <bits/stdc++.h>
using namespace std;


void printpath(vector<int>& path)
{
     char ch='A';
     map<int,char>mp;
     
     for(int i=0;i<15;i++)
     {
         mp[i]=ch;
         ch++;
     }
     
	int size = path.size();
	for (int i = 0; i < size; i++)
		cout << mp[path[i]] << " ";
	cout << endl;
}

int isNotVisited(int x, vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		if (path[i] == x)
			return 0;
	return 1;
}


void findpaths(vector<vector<int> >&g, int src,int dst, int v)
{

	stack<vector<int> > q;


	vector<int> path;
	path.push_back(src);
	q.push(path);
	while (!q.empty()) {
		path = q.top();
		q.pop();
		int last = path[path.size() - 1];

	
		if (last == dst)
			printpath(path);	

	
		for (int i = 0; i < g[last].size(); i++) {
			if (isNotVisited(g[last][i], path)) {
				vector<int> newpath(path);
				newpath.push_back(g[last][i]);
				q.push(newpath);
			}
		}
	}
}


int main()
{
    int n=16;
	vector<vector<int> > g(n+1);
	// number of vertices
	

	
	int m=23;

    for(int i=0;i<m;i++)
    {
        char c1,c2;
        cin>>c1>>c2;
     
         int u=c1-'A';
          int v=c2-'A';
          
        //   cout<<u<<" "<<v<<endl;
        
          g[u].push_back(v);
        
        
        
    }


   
     
     
	int src = 0, dst = 13; 
    char sr = 'A'+0;
    char ds = 'A'+13;
	cout << "path from src " << sr
		<< " to dst " << ds << " are \n";

	// function for finding the paths
      findpaths(g, src, dst, n);

	return 0;
}