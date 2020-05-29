class Solution {
public:
    void go(string instructions, int &i , int &j, int &dir){
	for (int k = 0; k < instructions.size(); ++k) {
	    if (instructions[k] == 'L') {dir = (dir + 3)%4;}
	    if (instructions[k] == 'R') {dir = (dir + 1)%4;}
	    if (instructions[k] == 'G') {
	         if (dir == 0) {
		     i++;
		 } else if(dir == 1) {
		     j--;
		 } else if(dir == 2) {
		    i--;
		 } else {
		     j++;
		 }
	    }
	}
    }
    bool isRobotBounded(string instructions) {
        map<int,map<int,map<int,bool>>> vis;
	int i = 0,j = 0, dir = 0;
	vis[i][j][dir] = true;
	go(instructions,i,j,dir);
	int len = max(abs(i),abs(j));
	int cnt = 0;
	while (!vis[i][j][dir]) {
	    vis[i][j][dir] = true;
	    go(instructions,i,j,dir);
	    if ((abs(i) > len || abs(j) > len)&&cnt > 32) return false;
	    cnt ++;
	}
	return true;
    }
};
