class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector <int> fq (26,0);
        
        for(char c  : s){
            fq[c-'a']++;
        }

        string ans;

        // add all cahr
        for(char c = 'a' ; c <= 'z' ; c++){
            if(c == x || c == y) continue;
            ans.append(fq[c- 'a'],c);            
        }

        // add all x
        ans.append(fq[y-'a'],y);

        // add all x 

        ans.append(fq[x - 'a'],x);

        return ans;
    }
};