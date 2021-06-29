class Trie {
public:
    struct node {struct node * ptr[26]; bool stop[26];};
    struct node * root;
    Trie() {
        root = (struct node *) malloc(sizeof(struct node));
	memset(root->ptr,0,sizeof(root->ptr));
	memset(root->stop,0,sizeof(root->stop));
    }
    
    void insert(string word) {
        struct node * cur = root;
        for (int i = 0; i < word.size(); ++i) {
	    if (cur->ptr[word[i] - 'a'] == nullptr) {
	        cur->ptr[word[i] - 'a'] = (struct node *) malloc(sizeof(struct node));
		memset(cur->ptr[word[i] - 'a']->ptr,0,sizeof(cur->ptr[word[i] - 'a']->ptr));
		memset(cur->ptr[word[i] - 'a']->stop,0,sizeof(cur->ptr[word[i] - 'a']->stop));
	    }
	    if (i == (word.size()-1)) {
	        cur->stop[word[i]-'a'] = true;
	    }
	    cur = cur->ptr[word[i] - 'a'];
	}
    }
    
    bool search(string word) {
        struct node * cur = root;
        for(int i = 0; i < word.size(); ++i) {
	    if (cur == nullptr) return false;
	    if (cur->ptr[word[i]-'a'] == nullptr) return false;
	    if(i != (word.size()-1)) cur = cur->ptr[word[i] - 'a'];
	}
	return cur->stop[word.back()-'a'];
    }
    
    bool startsWith(string word) {
        struct node * cur = root;
        for(int i = 0; i < word.size(); ++i) {
	    if (cur == nullptr) return false;
	    if (cur->ptr[word[i]-'a'] == nullptr) return false;
	    if(i != (word.size()-1)) cur = cur->ptr[word[i] - 'a'];
	}
	return true;
    }
};

