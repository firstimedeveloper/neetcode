// #include <bits/stdc++.h>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> order;
    int cap;
    int size;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        // printf("getting: %d\n", key);
        if (cache.count(key)) {
            if (cache[key] != order.end())
                order.splice(order.begin(), order, cache[key]);
            cache[key] = order.begin();
            return cache[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // printf("putting: %d %d %d\n", key, value, size);
        if (cache.count(key)) {
            order.push_front(make_pair(key, value));
            if (cache[key] != order.end())
                order.erase(cache[key]);
            cache[key] = order.begin();
        } else {
            if (size < cap) {
                order.push_front(make_pair(key, value));
                cache[key] = order.begin();
                size++;
            } else {
                auto temp = order.back();
                // printf("popping: %d\n", temp.first);
                cache.erase(temp.first);
                order.pop_back();
                order.push_front(make_pair(key, value));
                cache[key] = order.begin();
            }
        
        }
        // printf("[ ");
        // for (auto i: cache) {
        //     printf("(%d, %d) ", i.first, *i.second);
        // }
        // printf("]\n");
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 * ["LRUCache","put","put","get","put","get","put","get","get","get"]
 * [[2],[1,0],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
 */

int main() {
	LRUCache *obj = new LRUCache(2);
	obj->put(1, 0);
	obj->put(2, 2);
	printf("\t\toutput: %d\n", obj->get(1));
	obj->put(3, 3);
	printf("\t\toutput: %d\n", obj->get(2));
	obj->put(4, 4);
	printf("\t\toutput: %d\n", obj->get(1));
	printf("\t\toutput: %d\n", obj->get(3));
	printf("\t\toutput: %d\n", obj->get(4));


}
