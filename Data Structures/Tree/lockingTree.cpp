#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct StateTree {
    bool isLock = false;
    int parent;
    int userId = INT_MIN;
    
    StateTree() {}
    StateTree(int parent) : parent(parent) {}
    StateTree(int parent, int userId) : parent(parent), userId(userId) {}
    StateTree(int parent, int userId, bool isLock) : parent(parent), userId(userId), isLock(isLock) {}
};

class LockingTree {
private:
    unordered_map<int, StateTree> map;
    unordered_map<int, vector<int>> parentToChildren;
    int size;
    
    bool anyLockedAncestor(int p) {
        if (p!=-1) {
            StateTree tr = map[p];
            
            if (tr.isLock) {
                return true;
            }
            
            return anyLockedAncestor(tr.parent);
        }
        
        return false;
    }
    
    vector<int> checkLockedDescendantsOf(int num) {
        bool isParent = true;
        queue<int> q;
        vector<int> res;
        
        q.push(num);
        
        while (!q.empty()) {
            int n = q.front();
            vector<int> v = parentToChildren[n];
            
            if (!isParent) {
                StateTree tr = map[n];
                if (tr.isLock) {
                    res.push_back(n);
                }   
            }
            
            isParent = false;
            
            for (int i : v) {
                q.push(i);
            }
            
            q.pop();
        }
        
        return res;
    }
    
    void unlockAllDescendantsOf(vector<int> &lockedDesc) {
        for (auto u : lockedDesc) {
            StateTree tr = map[u];
            tr.isLock = false;
            tr.userId = INT_MIN;
            
            map[u] = tr;
        }
    }
    
public:
    LockingTree(vector<int>& parent) {
        this->size = parent.size();
        
        for (int i = 0; i < parent.size(); i++) {
            map[i] = StateTree(parent[i]);
            
            if (parent[i] != -1) {
                vector<int> v = parentToChildren[parent[i]];
                v.push_back(i);
                
                parentToChildren[parent[i]] = v;
            }
        }
    }
    
    bool lock(int num, int userId) {
        // assert num >= 0 && num < size
        assert(num >= 0 && num < size);
        
        StateTree tr = map[num];
        
        // if state is locked already
        if (tr.isLock) {
            return false;
        }
        
        // if state is unlocked
        // then user with userId can lock the resource
        tr.isLock = true;
        tr.userId = userId;
        
        map[num] = tr;
        
        return true;
    }
    
    bool unlock(int num, int userId) {
        // assert num >= 0 && num < size
        assert(num >= 0 && num < size);
        
        StateTree tr = map[num];
        bool isSuccess = tr.isLock && tr.userId != INT_MIN && tr.userId == userId;
        
        // if unlocked by different user id
        if (!isSuccess) {
            return false;
        }
    
        // if unlocked by valid user id
        tr.isLock = false;
        tr.userId = INT_MIN;
        
        map[num] = tr;
        return isSuccess;
    }
    
    bool upgrade(int num, int user) {
        StateTree tr = map[num];
        
        if (tr.isLock) {
            return false;
        }
        
        // check whenever any ancestor in locked state
        bool lockedAnc = anyLockedAncestor(tr.parent);
        if (lockedAnc) {
            return false;
        }
        
        // check descendant in locked state or not
        vector<int> lockedDesc = checkLockedDescendantsOf(num);
        if (lockedDesc.size() < 1) {
            return false;
        }
        
        // unlock the descendants
        unlockAllDescendantsOf(lockedDesc);
        
        // lock the current node
        tr.isLock = true;
        tr.userId = user;
        
        map[num] = tr;
        
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */