class TimeMap {
    std::map<std::string, std::vector<std::pair<std::string, int>>> data;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto it = std::ranges::partition_point(data[key], [&](const auto& val) {
            return val.second <= timestamp;
        });

        if(it != data[key].begin()) {
            --it;
            return it->first;
        }
        return "";
    }
};
