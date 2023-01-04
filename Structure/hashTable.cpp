// Hash Table
// 1. Hash Table is a data structure that stores data in an associative manner.

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class HashTable
{
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const
{
    int sum{};
    for (int i = 0; i < hashGroups; i++)
    {
        sum += table[i].size();
    }
    if (!sum)
    {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key)
{
    return key % hashGroups;
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr->second = value;
            cout << "Key exists. Value replaced" << endl;
            break;
        }
    }
    if (!keyExists)
    {
        cell.emplace_back(key, value);
    }
    return;
}

void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "Key removed" << endl;
            break;
        }
    }
    if (!keyExists)
    {
        cout << "Key not found" << endl;
    }
    return;
}

string HashTable::searchTable(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            return bItr->second;
        }
    }
    if (!keyExists)
    {
        return "No value found";
    }
};

void HashTable::printTable()
{
    for (int i = 0; i < hashGroups; i++)
    {
        if (table[i].size() == 0)
        {
            continue;
        }
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++)
        {
            cout << "Key: " << bItr->first << " Value: " << bItr->second << endl;
        }
    }
}

int main()
{
    HashTable HT;
    int key{};
    string value{};
    int choice{};
    do
    {
        cout << "1. Insert item into the table" << endl;
        cout << "2. Remove item from the table" << endl;
        cout << "3. Search the table" << endl;
        cout << "4. Print the table" << endl;
        cout << "5. Clear the screen" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter key and value to be inserted: ";
            cin >> key >> value;
            HT.insertItem(key, value);
            break;
        case 2:
            cout << "Enter key of the item to be deleted: ";
            cin >> key;
            HT.removeItem(key);
            break;
        case 3:
            cout << "Enter key of the item to be searched: ";
            cin >> key;
            cout << "Value at key " << key << " is " << HT.searchTable(key) << endl;
            break;
        case 4:
            HT.printTable();
            break;
        case 5:
            system("cls");
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Enter proper choice" << endl;
        }
    } while (choice != 6);
    return 0;
}
