class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> v;
        vector<int> result(obstacles.size(),1);
        for(int i=0; i<obstacles.size(); i++){
            int index = upper_bound(v.begin(), v.end(), obstacles[i])- v.begin();  //finding index of element just bigger than obstacles[i] in obstacles  (index_found - 0(v.begin())
            if(index == v.size()){
                v.push_back(obstacles[i]);
            }
            else{
                v[index] = obstacles[i];
            }
            result[i] = index +1;
        }
        return result;
    }
};
