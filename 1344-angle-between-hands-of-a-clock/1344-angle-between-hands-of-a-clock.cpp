class Solution {
public:
    double getHourAngle(int hour, int minutes) {
        hour = hour % 12;
        double part1 = (double) (hour * 30);
        double part2 = (double) (minutes * 0.5);
        return part1 + part2;
    }

    double getMinAngle(int minutes) {
        return (double) minutes * 6;
    }

    double angleClock(int hour, int minutes) {
        double hourAngle = getHourAngle(hour, minutes);
        double minAngle =  getMinAngle(minutes);

        double diff = abs(hourAngle - minAngle);
        return min(diff, 360-diff);
    }
};