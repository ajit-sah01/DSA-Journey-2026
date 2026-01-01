class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> result;
        if (words.empty())
            return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return result;

        unordered_map<string, int> freq;
        for (auto &w : words)
            freq[w]++;

        // Try each offset
        for (int offset = 0; offset < wordLen; offset++)
        {
            unordered_map<string, int> window;
            int left = offset, count = 0;

            for (int right = offset; right + wordLen <= s.size(); right += wordLen)
            {
                string word = s.substr(right, wordLen);

                if (freq.count(word))
                {
                    window[word]++;
                    count++;

                    while (window[word] > freq[word])
                    {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount)
                    {
                        result.push_back(left);
                    }
                }
                else
                {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return result;
    }
};
