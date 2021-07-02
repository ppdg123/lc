class Solution {
public:
    int cross(int a, int b, int c , int d) {
        int l = a<c?c:a;
	int r = b>d?d:b;
	if(l<r) return r - l;
	return 0;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int w = cross(ax1,ax2,bx1,bx2);
	int h = cross(ay1,ay2,by1,by2);
	return (ax2-ax1) * (ay2-ay1) + (bx2 - bx1) * (by2-by1) - w*h;
    }
};
