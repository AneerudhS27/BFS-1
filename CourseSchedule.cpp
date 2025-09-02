#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
/*
We use BFS to perform topological sort by starting with nodes that have zero incoming edges (indegree 0).
As we visit each course, we reduce the indegree of its dependents and add them to the queue if their indegree becomes zero.
If we can visit all courses this way, there's no cycle, and the courses can be completed
*/
class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> indegrees(numCourses, 0);
        unordered_map<int, vector<int>> map;

        for(auto& pr : prerequisites){
            indegrees[pr[0]]++;
            map[pr[1]].push_back(pr[0]);
        }

        queue<int> q;
        int count = 0;

        for(int i=0; i<numCourses; i++){
            if(indegrees[i] == 0){
                q.push(i);
                count++;
            }
        }
        if(q.empty()) return false;
        if(count == numCourses) return true;

        while(!q.empty()){
            int curr = q.front(); q.pop();
            if(map.count(curr)){
                for(int dep : map[curr]){
                    if(indegrees[dep] == 0){
                        q.push(dep);
                        count++;
                        if(count == numCourses) return true;
                    }
                }
            }
        }
        return false;
    }
};
