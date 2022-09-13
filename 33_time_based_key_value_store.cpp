#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string, map<int, string>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        string ret = "";
			
		if (store.count(key)) {
			unordered_map<string, map<int, string>>::iterator it = store.find(key);
			map<int, string>::iterator i = (it->second).find(timestamp);
			if (i != store[key].end())
				ret = i->second;
			else {
				while (i != store[key].begin()) {
					--i; // decrement first since begin is technically past the end and this also allows us to access the first element.
					if (i->first <= timestamp) {
						ret = i->second;
						break ;
					}
				}
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

