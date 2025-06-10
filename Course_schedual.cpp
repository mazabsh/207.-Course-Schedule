#include<iostream> 
#include<vector> 
#include<queue> 

using namespace std; 

class Solution{
public: 
    bool canFinish(int  numCourses, vector<vector<int>> prerequisites){
      vector<int> isDegree(numCourses); 
      vector<vector<int>> adj(numCourses); 

      for(auto p:prerequisites){
        int course = p[0]; 
        int pre = p[1]; 
        isDegree[course]++; 
        adj[pre].push_back(course); 
      }
      int complete=0; 
      queue<int> q; 
      for(int i=0; i<numCourses; ++i){
        if(isDegree[i]==0) q.push(i); 
      }
      while(!q.empty()){
        int course = q.front(); 
        q.pop(); 
        complete++; 
        for(int ne: adj[course]){
          isDegree[ne]--; 
          if(isDegree[ne]==0){
            q.push(ne); 
          }
        }
      }
      return complete ==numCourses; 
    }
};
int main(){
    vector<vector<int>> prerequisites = {{1,0}, {2,1}, {3,2}}; 
    int numCourses = 4; 
    Solution sol; 
    cout <<boolalpha <<  sol.canFinish(numCourses, prerequisites) << endl; 
    return 0; 
}
