class LRUCache {
    int capacity_;
    std::list<std::pair<int, int>> order_;
    unordered_map<int, std::list<std::pair<int, int>>::iterator> data_;
public:
    LRUCache(int capacity) : capacity_(capacity) {
        
    }
    
    int get(int key) {
            auto found = data_.find(key);
            if (found == data_.end()) return -1;

            auto it = found->second;
            order_.splice(order_.begin(), order_, it);

            return it->second;

    }
    
    void put(int key, int value)
    {
        auto found = data_.find(key);
        if(found != data_.end()) 
        {
            auto it = found->second;
            it->second = value;

            order_.splice(order_.begin(), order_, it);
            return;
        }

        if(data_.size() == capacity_)
        {
            int k = order_.back().first;
            data_.erase(k);
            order_.pop_back();
        } 

        order_.push_front({key, value});
        data_[key] = order_.begin();        
    }
};
