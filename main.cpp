#include<bits/stdc++.h>
using namespace std;

class TextProccesor{
    public:
    string becomeLower(string text){

        for (int i = 0; i < text.length(); i++)
        {
            text[i] = tolower((unsigned char)text[i]);
        }
        return text;
    }
    string removeSpeacial(string text){
        string ans = "";

        for (int i = 0; i < text.length(); i++)
        {
                if(isalnum((unsigned char)text[i]) || isspace((unsigned char)text[i])) {
                ans += text[i];
            }
        }
        return ans;
    }
    vector<string> token(string query){
        vector<string> token;
        string arr[] = {
            "a", "an", "the", "is", "am", "are", "was", "were", 
            "what", "who", "where", "when", "how", "why", "in", "on", "at", "to", "of"
        };
        string temp = "";
        temp = becomeLower(query);
        temp = removeSpeacial(temp);

        stringstream ss(temp);
        string word;

        while (ss >> word) {

        bool isStopWord = false;

        for (int i = 0; i < 19; i++) {
            if (word == arr[i]) {
                isStopWord = true;
                break;
            }
        }

        if (!isStopWord) {
            token.push_back(word);
        }
    }
        return token;
    } 

};
    
    int main(){
        TextProccesor test1;
        vector<string> ans;
        ans = test1.token("what is a diffrence between abstraction and polymorphism");
        
        for (const string &t : ans) {
            cout << t << endl;
        }
    return 0;
}