class MyCalendar {
public:
    vector<pair<int,int>> ranges;


    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       
        
        for(int pair = 0;pair<ranges.size();pair++){
            int r_start = ranges[pair].first;
            int r_end = ranges[pair].second;
            if(start< r_end && end>r_start) return false;
        }
        ranges.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */