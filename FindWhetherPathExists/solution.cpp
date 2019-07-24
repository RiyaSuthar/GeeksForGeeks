#include<bits/stdc++.h>
using namespace std;
int DFS(vector<int> A[], int row, int col, int N, vector<int> vis[])
{
    if(row<0 || row>=N || col<0 || col>=N || vis[row][col]==1 || A[row][col] == 0 )
        return 0;
    
    //mark visited
    vis[row][col]=1;
    
    if(A[row][col]==2)
        return 1;
    
    //traverse in the 4 directions if A[row][col] == 3
    if( DFS(A, row-1, col, N, vis) ||  DFS(A, row, col-1, N, vis) || DFS(A, row, col+1, N, vis) || DFS(A, row+1, col, N, vis))
        return 1;
        
}
int main()
 {
	//thakur
	int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> v[N];
        vector <int> vis[N];
        
        int start_row, start_col;
        for(int i=0; i<N; i++)
        {
            for(int j = 0; j<N;  j++)
            {
                int x;
                cin>>x;
                v[i].push_back(x);
                vis[i].push_back(0);
                //find the position of source cell
                if(x==1)
                {
                    start_row = i;
                    start_col = j;
                }
            }
        }
        
        int x;
        x = DFS(v, start_row, start_col, N, vis);
        
        cout<<x<<endl;
    }
}
