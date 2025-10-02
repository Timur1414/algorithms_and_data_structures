#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class HashTable {
private:
    const int SIZE = 3;
    list<pair<string, int>>* arr = nullptr; // реализация через бакеты
    hash<std::string> hasher;
public:
    HashTable() {
        arr = new list<pair<string, int>>[SIZE];
    }
    ~HashTable() {
        delete[] arr;
    }

    size_t get_hashed_key(const string& key) const {
        return hasher(key) % SIZE;
    }
    void add(const string& key, int value) {
        size_t index = get_hashed_key(key);
        pair<string, int> item = make_pair(key, value);
        arr[index].push_front(item);
    }
    pair<string, int> get(const string& key) const {
        size_t index = get_hashed_key(key);
        auto founded = find_if(arr[index].begin(), arr[index].end(), [key](const pair<string, int>& item) {
            return item.first == key;
        });
        if (founded == arr[index].end()) {
            throw runtime_error("Key not found");
        }
        return *founded;
    }
    void show() const {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            for (const auto& item : arr[i]) {
                cout << "{\"" << item.first << "\": " << item.second << "} ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hash_table;
    hash_table.add("one", 1);
    hash_table.add("1", 1);
    hash_table.add("first", 1);
    hash_table.add("One", 1);
    hash_table.add("First", 1);
    hash_table.add("1.0", 1);
    hash_table.add("1.1", 1);
    hash_table.add("1.1", 1);
    hash_table.add("2", 2);
    hash_table.add("two", 2);
    hash_table.add("Two", 2);
    hash_table.add("second", 2);
    hash_table.add("Second", 2);
    hash_table.show();
    auto item = hash_table.get("1.0");
    cout << endl << item.second << endl;


    return 0;
}