class Solution {
public:
    int getArea(int left, int right, int top, int bottom) {
        return (abs(right - left) * abs(top - bottom));
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ax1 = A;
        int ay1 = B;
        int ax2 = C;
        int ay2 = D;
        
        int bx1 = E;
        int by1 = F;
        int bx2 = G;
        int by2 = H;
        
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int top = min (ay2, by2);
        int bottom = max(ay1, by1);
        
        int a1 = getArea(ax1, ax2, ay2, ay1);
        int a2 = getArea(bx1, bx2, by2, by1);
        int a3 = getArea(left, right, top, bottom);
        
        if (left < right && bottom < top) {
            return a1 + a2 - a3;
        }
        
        return a1 + a2;
    }
};