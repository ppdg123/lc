class LRUCache {
public:
    struct node {int tm,key;};
    LRUCache(int capacity) {
        cap = capacity;
        tm = 0;
    }

    int get(int key) {
        if(data.find(key) == data.end()) return -1;
        struct node tmp;
        tmp.key = key;
        tmp.tm = tm;
        tmd[key] = tm;
        tm ++;
        qu.push(tmp);
        return data[key];
    }

    void put(int key, int value) {
        data[key] = value;
        tmd[key] = tm;
        struct node tmp;
        tmp.tm = tm;
        tmp.key = key;
        qu.push(tmp);
        tm ++;
        if (data.size() > cap) {
            while(qu.front().tm != tmd[qu.front().key]) qu.pop();
            data.erase(qu.front().key);
            qu.pop();
        }
    }
    map<int,int> data;
    map<int,int> tmd;
    queue<struct node> qu;
    int cap;
    int tm;
};
