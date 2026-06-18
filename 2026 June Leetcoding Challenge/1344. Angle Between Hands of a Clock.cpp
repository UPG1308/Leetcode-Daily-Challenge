class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) hour = 0;
        double mins_hand_degree = minutes * 6.0;
        double hour_hand_degree = hour * 30 + minutes / 2.0;
        double angle = abs(mins_hand_degree - hour_hand_degree);
        return min(angle, abs(360 - angle));
    }
};
