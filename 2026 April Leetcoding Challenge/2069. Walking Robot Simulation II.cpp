class Robot {
public:
    int n, m, pos, started;
    Robot(int width, int height) {
        n = height, m = width;
        pos = started = 0;
    }
    
    void step(int num) {
        started = 1;
        pos += num;
        pos %= (2 * (n + m - 2));
    }
    
    vector<int> getPos() {
        if(pos < m) return {pos % m, 0};
        else if(pos < (m + n - 2)) return {m - 1, pos - m + 1};
        else if(pos < (m + m + n - 2)) {
            int rem = pos - (m - 1 + n - 2);
            return {m - rem, n - 1};
        } else {
            int rem = pos - (m - 1 + n - 2 + m);
            return {0, n - 1 - rem};
        }
    }
    
    string getDir() {
        if(pos == 0) return started? "South": "East";
        if(pos && pos < m) return "East";
        else if(pos < (m + n - 1)) return "North";
        else if(pos < (m + m + n - 2)) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
