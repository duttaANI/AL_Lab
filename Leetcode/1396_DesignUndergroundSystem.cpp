class UndergroundSystem {
public:
    
    
    
    map<int,pair<string,int>>one;
    map<pair<string,string>,pair<int,int>>two;
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        pair<string,int>temp(stationName,t);
        one[id]=temp;
    }

    void checkOut(int id, string stationName, int t) {
        int avg=abs(one[id].second-t);
        string s=one[id].first;
        two[make_pair(s,stationName)].first++;
        two[make_pair(s,stationName)].second+=avg;

    }

    double getAverageTime(string startStation, string endStation) {
        double ans=two[make_pair(startStation,endStation)].second;
        return ans/two[make_pair(startStation,endStation)].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */