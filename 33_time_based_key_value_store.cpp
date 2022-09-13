#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        string ret = "";
			
		if (store.count(key)) {
            for (auto i=store[key].rbegin(); i != store[key].rend(); ++i) {
                if (i->first <= timestamp)
                    return i->second;
            }   
		}
        return ret;
    }
};
int main() {
	string key = "foo";
	string value = "bar";
	int timestamp = 1;

	TimeMap* obj = new TimeMap();
	obj->set(key,value,timestamp);
	obj->set(key,value,2);
	obj->set(key,value,3);
	obj->set(key,"hello",4);
	string param_2 = obj->get(key,5);

	cout << param_2;
}

