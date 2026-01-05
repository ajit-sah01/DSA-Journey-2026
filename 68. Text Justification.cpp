class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n)
        {
            int lineLen = words[i].length();
            int j = i + 1;

            // Greedily add words to the current line
            while (j < n && lineLen + 1 + words[j].length() <= maxWidth)
            {
                lineLen += 1 + words[j].length();
                j++;
            }

            int wordCount = j - i;
            int totalWordLength = 0;
            for (int k = i; k < j; k++)
            {
                totalWordLength += words[k].length();
            }

            int totalSpaces = maxWidth - totalWordLength;
            string line;

            // Last line or single-word line
            if (j == n || wordCount == 1)
            {
                for (int k = i; k < j; k++)
                {
                    line += words[k];
                    if (k < j - 1)
                        line += ' ';
                }
                line += string(maxWidth - line.length(), ' ');
            }
            // Fully justified line
            else
            {
                int gaps = wordCount - 1;
                int spaceEach = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++)
                {
                    line += words[k];
                    if (k < j - 1)
                    {
                        line += string(spaceEach + (extraSpaces > 0 ? 1 : 0), ' ');
                        if (extraSpaces > 0)
                            extraSpaces--;
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
