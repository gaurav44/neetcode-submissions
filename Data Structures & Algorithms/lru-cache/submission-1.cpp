class LRUCache {
    int capacity_;
    std::list<std::pair<int, int>> order_;
    unordered_map<int, std::list<std::pair<int, int>>::iterator> data_;
public:
    LRUCache(int capacity) : capacity_(capacity) {
        
    }
    
    int get(int key) {
        if(!data_.contains(key)) return -1;

        auto it = data_[key];
        int val = it->second;

        order_.splice(order_.begin(), order_, it);

        return val;

    }
    
    void put(int key, int value)
    {

        if(data_.contains(key)) 
        {
            auto it = data_[key];
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
