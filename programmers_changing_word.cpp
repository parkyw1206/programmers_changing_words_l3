/************************************************************
 *  name : Youngwoo Park
 *  date : 09-23-2020
 *  level: l3
 *  problem source: programmers
 *  lang: C++
 *  skill: BFS
 * *********************************************************/
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
vector<bool> visited;
vector<string> langs;
queue<pair<string,int>> q;
string START;
string ENDP;
bool checkOne(string one, string two){
    int count = 0;
    
    for(int i = 0; i < one.size() ; i++){
        if(one[i] != two[i])
            count++;
        if(count >= 2)
            return false;
    }
    return true;
}
int bfs(int start){
    int count = 0, theCount;
    string theWord;
    q.push({START,0});
    
    while(q.size() > 0){
        theWord = q.front().first;
        theCount = q.front().second;
        cout << theWord << endl;
        q.pop();
        for(int i = 0  ; i < langs.size() ; i++ ){
            cout << "Check : " << langs[i] << endl;
             if(visited[i] == false && checkOne(langs[i], theWord) == true){
                visited[i] = true;
                if(langs[i] == ENDP)
                {
                    cout << "I FOUND IT" << endl;
                    return theCount+1;
                }
                cout << "Push: " << langs[i] << endl;
                q.push({langs[i],theCount+1});
            }
        }        
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    START = begin;
    ENDP = target;
    langs = words;
    
    for(int i = 0 ; i < words.size() ; i++){
        visited.push_back(false);
    }

    answer = bfs(0);
    return answer;
}