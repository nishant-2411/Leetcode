class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        stringstream ss(path);
        string token;
        string result;

        while(getline(ss, token, '/')){
            if(token == "" || token == "."){
                continue;
            }
            if(token == ".."){
                if(!stk.empty()){
                    stk.pop_back();
                }
            }
            else{
                stk.push_back(token);
            }
        }

        for (const auto& dir : stk) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};