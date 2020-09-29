#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
bool checkSafetyCondition(vector<int> a[],int vis[],int row,int col,int N ,int M){
    return row>=0 && row<N && col>=0 && col<M && a[row][col] && !vis[row*M+col];
}

void BFS(vector<int> a[],int vis[],int N,int M,int x,int y){
    vis[x*M+y]=true;
    int rowGradient[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    int columnGradient[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int l=q.front().first;
        int m=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            if(checkSafetyCondition(a,vis,l+rowGradient[i],m+columnGradient[i],N,M)){
                vis[M*(l+rowGradient[i])+m+columnGradient[i]]=true;
                q.push(make_pair(l+rowGradient[i],m+columnGradient[i]));
            }
        }
    }
}

int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    int ctr=0;
    int vis[N*M];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
           if(!vis[i*M+j]&&A[i][j]){
               BFS(A,vis,N,M,i,j);
               ctr++;
           } 
        }
    }
    return ctr;
}
