using namespace std;

class TimeMap {
public:
    map<string, vector<pair<string, int>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(value, timestamp);
    }

    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return "";
        }

        const auto&vec = it->second;
        int s = 0;
        int e = vec.size() - 1;
        int resultIndex = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (vec[mid].second == timestamp) {
                return vec[mid].first;
            } else if (vec[mid].second < timestamp) {
                resultIndex = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return (resultIndex != -1) ? vec[resultIndex].first : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
