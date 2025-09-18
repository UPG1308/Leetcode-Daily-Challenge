
class TaskManager {
public:    

    set<vector<int>> st;
    map<int, pair<int, int>> mp;

    TaskManager(vector<vector<int>>& tasks) {
        for(vector<int> task: tasks){
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority, taskId, userId});
        mp[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        auto [priority, userId] = mp[taskId];
        rmv(taskId);
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        auto [priority, userId] = mp[taskId];
        st.erase({priority, taskId, userId});
        mp.erase(taskId);
    }
    
    int execTop() {
        if(st.empty()) return -1;
        auto top = *st.rbegin();
        rmv(top[1]);
        return top[2];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
