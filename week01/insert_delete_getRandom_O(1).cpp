// TC: O(1)
// SC: O(N)
class RandomizedSet {
public:
    vector<int> randSet;  // randon set
    unordered_map<int, int> valToIndex;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valToIndex.count(val)) return false;
        valToIndex[val] = randSet.size();
        randSet.push_back(val);

        return true;
    }
    
    bool remove(int val) {
        if(valToIndex.count(val) == 0) return false;

        int index = valToIndex[val];
        swap(randSet[index], randSet[randSet.size() - 1]);
        randSet.pop_back();
        valToIndex[randSet[index]] = index;
        valToIndex.erase(val);

        return true;
        
    }
    
    int getRandom() {
        return randSet[rand() % randSet.size()];
    }
};