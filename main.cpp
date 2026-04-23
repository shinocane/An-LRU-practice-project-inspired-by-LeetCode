#include "lru.h"
#include <iostream>
#include <string>
int main() {
    int capacity;
    cout << "Enter capacity: ";
    cin >> capacity;

    LRUCache cache(capacity);

    string cmd;
    cout << "Commands: put k v | get k | show | stats | exit" << endl;

    while (true) {
        cin >> cmd;

        if (cmd == "put") {
            int k, v;
            cin >> k >> v;
            cache.put(k, v);
        }
        else if (cmd == "get") {
            int k;
            cin >> k;
            cout << "Result: " << cache.get(k) << endl;
        }
        else if (cmd == "show") {
            cache.show();
        }
        else if (cmd == "stats") {
            cache.printStats();
        }
        else if (cmd == "exit") {
            break;
        }
        else { 
            cout << "Enter error,please enter again correctly"; 
        }
    }

    return 0;
}