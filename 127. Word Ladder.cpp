class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        // Two sets for bidirectional search
        unordered_set<string> head, tail;
        head.insert(beginWord);
        tail.insert(endWord);

        int ladder = 2; // Starting word and ending word make length 2

        while (!head.empty() && !tail.empty()) {
            // Always expand the smaller set to keep the branching factor low
            if (head.size() > tail.size()) {
                swap(head, tail);
            }

            unordered_set<string> next_level;
            for (string word : head) {
                // Remove word from dict to prevent revisiting
                // (Already removed from head/tail in previous steps)

                for (int i = 0; i < word.size(); i++) {
                    char originalChar = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;

                        // Check if the two frontiers meet
                        if (tail.count(word)) return ladder;

                        if (dict.count(word)) {
                            next_level.insert(word);
                            dict.erase(word); // Consume the word
                        }
                    }
                    word[i] = originalChar;
                }
            }
            head = next_level;
            ladder++;
        }

        return 0;
    }
};