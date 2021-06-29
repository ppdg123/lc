class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> buf;
	for (int i = 0; i < tokens.size(); ++i) {
	    if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
	        int r = stoi(buf.back());
		buf.pop_back();
		int l = stoi(buf.back());
		buf.pop_back();
		int res;
		if (tokens[i] == "+") res = l + r;
		else if(tokens[i] == "-") res = l -r;
		else if(tokens[i] == "*") res = l * r;
		else res = l / r;
		buf.push_back(to_string(res));
	    } else buf.push_back(tokens[i]);
	}
	return stoi(buf.back());
    }
};
