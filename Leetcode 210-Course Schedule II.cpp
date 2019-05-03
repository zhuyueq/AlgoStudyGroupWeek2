/**
faster than 27% of the solutions, not very fast
**/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
        vector<int> inDegree(numCourses, 0);
        for(auto val: prerequisites)
        {
            if(graph[val[1]].count(val[0]) == 0)
            {
                graph[val[1]].insert(val[0]);
                inDegree[val[0]]++;
            }
        }
        int j;
        for(int i = 0; i < numCourses; i++)
        {
            for(j = 0; j < numCourses; j++)
                if(inDegree[j] == 0) break;
            if(j == numCourses) return vector<int>();
            result.push_back(j);
            inDegree[j]--;
            for(auto val: graph[j])
                inDegree[val]--;
        }
        return result;
    }
};