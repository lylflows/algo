#include <iostream>

using namespace std;

struct Node{
    int cnt = 0;
    Node *child[10];
};

struct Trie{
    Node *head;

    void init(){
        head = new Node();
    }

    void add(string s){
        Node *cur = head;
        for (int i = 0; i < s.size(); i++){
            int x = (int)s[i] - (int)'0';
            if(cur->child[x] == NULL){
                cur->child[x] = new Node();
            }
            cur = cur->child[x];
            cur->cnt++;
        }
    }

    int search_pref(string s){
        Node *cur = head;
        for (int i = 0; i < s.size(); i++){
            int x = (int)s[i] - (int)'0';
            if (cur->child[x] == NULL)
                return 0;
            else
                cur = cur->child[x];
        }
        return cur->cnt;
    }
};


int main()
{
    int n, m;
    cin >> n;
     Trie *t = new Trie();
    for (int i = 0; i < n; i++){
        t->init();
        cin >> m;
        string s[m];
        for (int j = 0; j < m; j++){
            cin >> s[j];
            t->add(s[j]);
        }
        string ans = "YES";
        for (int j = 0; j < m; j++){
            if (t->search_pref(s[j]) > 1){
                ans = "NO";
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}