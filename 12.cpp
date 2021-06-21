class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> smb;
	smb[0] = "I";
	smb[1] = "IV";
	smb[2] = "V";
	smb[3] = "IX";
	smb[4] = "X";
	smb[5] = "XL";
	smb[6] = "L";
	smb[7] = "XC";//90
	smb[8] = "C";
	smb[9] = "CD";
	smb[10] = "D";
	smb[11] = "CM";
	smb[12] = "M";
	int val[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	int i = 12;
	string ans;
	while(i >= 0) {
	    if (val[i] <= num) {
	        ans += smb[i];
		num -= val[i];
	    } else {
	        --i;
	    }
	}
	return ans;
    }
};
