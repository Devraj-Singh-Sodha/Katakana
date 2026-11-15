#include<bits/stdc++.h>
using namespace std;

class TextProccesor{
    public:
    unordered_set<string> stopWords = {
        "a", "an", "the", "is", "am", "are", "was", "were", 
        "what", "who", "where", "when", "how", "why", "in", "on", "at", "to", "of"
    };
    vector<string> tokenization(string query){
            vector<string> tokens;
            string ans;

            transform(query.begin(), query.end(), query.begin(),
              [](unsigned char c) { return tolower(c); });

            query.erase(remove_if(query.begin(), query.end(), 
               [](unsigned char c) { return ispunct(c); }), 
               query.end());

            stringstream ss(query);
            string word;

            while (ss >> word) {
            if (stopWords.find(word) == stopWords.end()) {
                tokens.push_back(word);
            }
        }

            
            return tokens;
        }
    };
    
    int main(){
        TextProccesor test1;
        vector<string> ans;
        ans = test1.tokenization("A, apple is a Apple!");
        
        for (const string &t : ans) {
            cout << t << endl;
        }
    // cout << ans;
    return 0;
}