class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return {};

        unordered_set<string> head, tail;
        head.insert(beginWord);
        tail.insert(endWord);

        unordered_map<string, vector<string>> children;
        bool reversed = false;
        bool found = false;

        while (!head.empty() && !tail.empty() && !found) {
            // Always expand the smaller set for efficiency
            if (head.size() > tail.size()) {
                swap(head, tail);
                reversed = !reversed;
            }

            // Remove current level words from dict to prevent cycles
            for (const string& w : head) dict.erase(w);

            unordered_set<string> next_level;
            for (string word : head) {
                string parent = word;
                for (int i = 0; i < word.length(); ++i) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (tail.count(word)) {
                            found = true;
                            add_edge(parent, word, children, reversed);
                        } else if (!found && dict.count(word)) {
                            next_level.insert(word);
                            add_edge(parent, word, children, reversed);
                        }
                    }
                    word[i] = original;
                }
            }
            head = next_level;
        }

        vector<vector<string>> results;
        if (found) {
            vector<string> path = {beginWord};
            backtrack(beginWord, endWord, children, path, results);
        }
        return results;
    }

private:
    void add_edge(string& u, string& v, unordered_map<string, vector<string>>& children, bool reversed) {
        if (reversed) children[v].push_back(u);
        else children[u].push_back(v);
    }

    void backtrack(string& word, string& endWord, unordered_map<string, vector<string>>& children, vector<string>& path, vector<vector<string>>& res) {
        if (word == endWord) {
            res.push_back(path);
            return;
        }
        if (children.find(word) == children.end()) return;
        for (string& child : children[word]) {
            path.push_back(child);
            backtrack(child, endWord, children, path, res);
            path.pop_back();
        }
    }
};