#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(string currentWord,
             unordered_set<string>& dictionary,
             vector<string> currentPath,
             vector<vector<string>>& allPaths,
             unordered_map<string,int>& levelMap)
    {
        currentPath.push_back(currentWord);

        if (levelMap[currentWord] == 1) {
            reverse(currentPath.begin(), currentPath.end());
            allPaths.push_back(currentPath);
            return;
        }

        string originalWord = currentWord;

        for (int i = 0; i < currentWord.size(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == originalWord[i]) continue;

                currentWord[i] = ch;

                if (dictionary.find(currentWord) != dictionary.end() &&
                    levelMap[currentWord] < levelMap[originalWord]) {

                    dfs(currentWord, dictionary, currentPath, allPaths, levelMap);
                }
            }
            currentWord = originalWord;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord,string endWord,vector<string>& wordList){
        vector<vector<string>> allPaths;
        unordered_map<string,int> levelMap;
        unordered_set<string> dictionary(wordList.begin(), wordList.end());

        dictionary.erase(beginWord);

        queue<pair<string,int>> bfsQueue;
        bfsQueue.push({beginWord, 1});

        while (!bfsQueue.empty()) {
            string currentWord = bfsQueue.front().first;
            int currentLevel = bfsQueue.front().second;
            bfsQueue.pop();

            levelMap[currentWord] = currentLevel;

            if (currentWord == endWord) break;

            string originalWord = currentWord;

            for (int i = 0; i < currentWord.size(); i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    currentWord[i] = ch;

                    if (dictionary.find(currentWord) != dictionary.end()) {
                        dictionary.erase(currentWord);
                        bfsQueue.push({currentWord, currentLevel + 1});
                    }
                }
                currentWord = originalWord;
            }
        }

        for (auto& word : wordList) {
            dictionary.insert(word);
        }
        dictionary.insert(beginWord);

        dfs(endWord, dictionary, {}, allPaths, levelMap);

        return allPaths;
    }
};
