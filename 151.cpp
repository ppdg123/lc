class Solution {
public:
    string reverseWords(string s) {
        int head;
	int tail = s.size() - 1;
	string ans;
	while(tail >= 0) {
	    head = s.rfind(" ", tail);
	    if (head == string::npos) {
	        head = 0;
	        if (ans == "") {
	            ans = s.substr(head ,tail-head+1);
	        } else {
	            ans += (" " + s.substr(head,tail-head+1));
	        }
		break;
	    }
	    if ((tail-head) == 0) {
	        tail --;
		continue;
	    }
	    if (ans == "") {
	        ans = s.substr(head + 1,tail-head);
	    } else {
	        ans += (" " + s.substr(head + 1,tail-head));
	    }
	    tail = head;
	}
	return ans;
    }
};

