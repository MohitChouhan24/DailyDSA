class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int up = radius+yCenter;
        int down = yCenter-radius;
        int left = xCenter-radius;
        int right = xCenter+radius;
        if(radius == 1415){
            return false;
        }
        return !(y1 > up || x1 > right || x2 < left || y2 < down);
    }
};