class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int n = path.length();

        for (int i = 0; i < n; ++i) {
            if (path[i] == '/') continue;

            string temp = "";
            while (i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }

            if (temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(temp);
            }
        }

        string res = "";
        for (auto &s : st) {
            res += "/" + s;
        }

        return res.empty() ? "/" : res;
    }
};