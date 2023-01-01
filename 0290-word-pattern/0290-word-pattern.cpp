class Solution
{
    public:
        bool wordPattern(string pattern, string s)
        {
            vector<string> words;
            string temp = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ' ')
                {
                    words.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp += s[i];
                }
            }
            words.push_back(temp);
            if (words.size() != pattern.size())
            {
                return false;
            }
            unordered_map<char, string> um;
            set<string> st;
            for (int i = 0; i < pattern.size(); i++)
            {
                if (um.find(pattern[i]) != um.end())
            {
                if (um[pattern[i]] != words[i])
                {
                    return false;
                }
            }
            else
            {
                if (st.count(words[i]) > 0)
                {
                    return false;
                }
                um[pattern[i]] = words[i];
                st.insert(words[i]);
            }
        }
    return true;
}
};