#include <unordered_set>
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict) {
  
  // use BFS
  unordered_map<string, int> dis;
  queue<string> q; // FIFO for bfs purpose
  dis[start] = 1;
  q.push(start);
  if(dict.count(end)==0) dict.insert(end);
  while(!q.empty()){
    string word = q.front();
    q.pop();
    if(word==end) break;
    for(int i=0;i<word.size();++i){
      string temp=word;
      for(char j='a';j<='z';++j){
	temp[i] = j;
	if(dict.count(temp)>0 && dis.count(temp)==0){
	  dis[temp] = dis[word] + 1;
	  q.push(temp);
	}
      }
    }
  }
  if(dis.count(end)==0) return 0;
  return dis[end];
  
}


int main(){
  string start = "hit";
  string end = "cog";
  unordered_set<string> dict = {"hot","dot","dog","lot","log"};
  cout<< ladderLength(start, end, dict);
  



}
