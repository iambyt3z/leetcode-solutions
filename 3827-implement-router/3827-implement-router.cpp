#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source, destination, timestamp;
    bool operator==(const Packet &o) const {
        return source == o.source && destination == o.destination && timestamp == o.timestamp;
    }//oop function overloading
};

// Custom hash for unordered_set
struct PacketHash {
    size_t operator()(const Packet &p) const {
        return ((size_t)p.source * 1315423911u) ^
               ((size_t)p.destination * 2654435761u) ^
               ((size_t)p.timestamp * 97531u);
    }//It allows you to use an object of PacketHash like a function:
    //return type is size_t (standard unsigned integer used for hashing).
   //operator() in PacketHash → lets unordered_set compute a hash for a packet. 
};

class Router {
private:
    int memoryLimit;
    queue<Packet> q;
    unordered_set<Packet, PacketHash> seen;
    unordered_map<int, vector<int>> destTimes;  // sorted timestamps

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        if (seen.count(p)) return false;

        if ((int)q.size() == memoryLimit) forwardPacket();  // auto forward oldest

        q.push(p);
        seen.insert(p);
        destTimes[destination].push_back(timestamp);  // append timestamps
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};  // no packet to forward

        Packet p = q.front(); 
        q.pop();
        seen.erase(p);

        // remove timestamp
        auto &vec = destTimes[p.destination];
        auto it = lower_bound(vec.begin(), vec.end(), p.timestamp);
        if (it != vec.end() && *it == p.timestamp) vec.erase(it);

        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimes.find(destination);
        if (it == destTimes.end()) return 0;

        auto &vec = it->second;
        auto left = lower_bound(vec.begin(), vec.end(), startTime);
        auto right = upper_bound(vec.begin(), vec.end(), endTime);
        return right - left;
    }
};