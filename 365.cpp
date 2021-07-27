class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity) return true;
	if (targetCapacity > max(jug1Capacity,jug2Capacity)) return false;
        while (targetCapacity != 0) {
	    int diff = abs(jug1Capacity - jug2Capacity);
	    if (diff == 0) break;
	    targetCapacity = targetCapacity % diff;
	    if (jug1Capacity == 0 || jug2Capacity == 0) break;
	    if (jug1Capacity > jug2Capacity) {
	        jug1Capacity = jug1Capacity % jug2Capacity;
	    } else {
	        jug2Capacity = jug2Capacity % jug1Capacity;
	    }
	}
	if (targetCapacity == 0) return true;
	return false;
    }
};
