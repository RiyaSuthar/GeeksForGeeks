{
#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> , int ,int );
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
int minDis(int dist[], bool inc[], int v)
{
    int min=INT_MAX,min_index=-1;
    for(int i=0;i<v;i++)
    {
        if(!inc[i] && dist[i]<min)
            min=dist[i], min_index=i;
    }
    return min_index;
}
void dijkstra(vector<vector<int>> graph, int src, int v)
{
    // Your code here
    int dist[v];
    bool inc[v];
    for(int i=0;i<v;i++)
        dist[i]=INT_MAX, inc[i]=false;
    dist[src]=0;
    for(int i=0;i<v-1;i++)
    {
        int u=minDis(dist,inc,v);
        inc[u]=true;
        for (int p = 0; p < v; p++) 
   
         // Update dist[v] only if is not in sptSet, there is an edge from  
         // u to v, and total weight of path from src to  v through u is  
         // smaller than current value of dist[v] 
         if (!inc[p] && graph[u][p] && dist[u] != INT_MAX  
                                       && dist[u]+graph[u][p] < dist[p]) 
            dist[p] = dist[u] + graph[u][p]; 
    }
    for(int i=0;i<v;i++)
        cout<<dist[i]<<" ";
}
