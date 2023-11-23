// TC: 0(N) // N is number logs
class Logger {
public:
    unordered_map<string, int> logs;
    Logger() {
        logs = {};
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(logs.count(message) && logs[message] > timestamp) {
            return false;
        }
        logs[message] = timestamp + 10;
        return true;
    }
};