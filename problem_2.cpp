class Solution {
public:
    
    int scheduleCourse(vector<vector<int>>& courses) {
        int total=0;
        multiset<int> select_course;
        sort(courses.begin(),courses.end(),[](const vector<int>& a,const vector<int>& b) {
        return a[1] < b[1];
        });
        for(auto ele:courses){
            for(auto ele1:ele) cout<<ele1<<' ';
        }
        for(auto ele:courses){
            if(total+ele[0]<=ele[1]){
                select_course.insert(ele.front());
                total+=ele[0];
            }
            else{
                select_course.insert(ele.front());
                auto it=select_course.end();
                it--;
                total+=ele.front()-(*it);
                select_course.erase(it);
            }
        }

        return select_course.size();
    }
};