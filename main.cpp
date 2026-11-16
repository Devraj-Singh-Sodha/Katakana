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

    while (true)
    {
        int choice;
        cout << "Katakana ""Search Engine""" << endl
             << "1. Search" << endl
             << "2. Exit:" << endl;
        cin >> choice;

        if (choice == 1)
        {
            string query;
            cout << "Enter Query = ";
            cin.ignore();
            getline(cin, query);
            
            vector<string> ans;
            ans = test1.token(query);
                
            for (const string &t : ans) {
                cout << t << endl;
            }

        }
        else if (choice == 2)
        {
            break;
        }
        else{
            cout << "Invalid Chocie:" << endl;
        }
        
    }
    
    return 0;
}