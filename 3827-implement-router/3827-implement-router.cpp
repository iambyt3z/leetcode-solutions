class Router {
private:
    int limit;

    map<tuple<int, int, int>, bool> packets;
    unordered_map<int, vector<int>> destinations;
    queue<tuple<int, int, int>> q;

    int getFrontInd(int dest) {
        int left = 0, right = destinations[dest].size()-1;
        int res = 0;
    
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(destinations[dest][mid] == -1) {
                left = mid+1;
            } else {
                res = mid;
                right = mid-1;
            }
        }

        return res;
    }

    int getLeftBoundInd(int dest, int timestamp) {
        int left = 0, right = destinations[dest].size()-1;
        int res = -1;
    
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(destinations[dest][mid] < timestamp) {
                left = mid+1;
            } else {
                res = mid;
                right = mid-1;
            }
        }

        return res;
    }

    int getRightBoundInd(int dest, int timestamp) {
        int left = 0, right = destinations[dest].size()-1;
        int res = -1;
    
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(destinations[dest][mid] > timestamp) {
                right = mid-1;
            } else {
                res = mid;
                left = mid+1;
            }
        }

        return res;
    }

public:
    Router(int memoryLimit) {
        this->limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(packets.count({source, destination, timestamp}) != 0)
            return false;

        if(q.size() == this->limit) {
            auto [src, dest, time] = q.front();
            int ind = getFrontInd(dest);

            q.pop();
            packets.erase({src, dest, time});
            destinations[dest][ind] = -1;
        }

        q.push({source, destination, timestamp});
        packets[{source, destination, timestamp}] = true;
        destinations[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size() == 0)
            return {}; 

        auto [src, dest, time] = q.front();
        int ind = getFrontInd(dest);

        q.pop();
        packets.erase({src, dest, time});
        destinations[dest][ind] = -1;

        return {src, dest, time};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int left = getLeftBoundInd(destination, startTime);
        int right = getRightBoundInd(destination, endTime);

        if(left == -1 || right == -1)
            return 0;

        return (right - left + 1);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */