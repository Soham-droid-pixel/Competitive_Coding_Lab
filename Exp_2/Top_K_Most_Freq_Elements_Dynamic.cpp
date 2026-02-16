#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class TopKStream {
private:
    int K;
    unordered_map<int, int> freqMap;
    set<pair<int, int>> treeSet;

public:
    TopKStream(int k) {
        this->K = k;
    }

    void add(int num) {
        if (freqMap.find(num) != freqMap.end()) {
            int oldFreq = freqMap[num];
            treeSet.erase({oldFreq, num});
        }

        freqMap[num]++;
        int newFreq = freqMap[num];

        treeSet.insert({newFreq, num});
    }

    vector<int> getTopK() {
        vector<int> result;
        int count = 0;
        
        for (auto it = treeSet.rbegin(); it != treeSet.rend(); ++it) {
            result.push_back(it->second);
            count++;
            if (count == K) break;
        }
        
        return result;
    }
};

int main() {
    TopKStream* obj = new TopKStream(2);

    obj->add(1);
    obj->add(1);
    obj->add(2);
    
    vector<int> res1 = obj->getTopK();
    cout << "Current Top 2: ";
    for(int x : res1) cout << x << " ";
    cout << endl;

    obj->add(2);
    obj->add(1);
    obj->add(3);

    vector<int> res2 = obj->getTopK();
    cout << "Final Top 2: ";
    for(int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}