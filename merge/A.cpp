#include <iostream>

using namespace std;

struct Node{
    int cnt = 0;
    Node *child[26];
};

struct Trie{
    Node *head = new Node;

    void add(string s){
        Node *cur = head;
        for (int i = 0; i < s.size(); i++){
            int x = (int)s[i] - (int)'a';
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
            int x = (int)s[i] - (int)'a';
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
    cin >> n >> m;
    string s;
    Trie *t = new Trie;
    for (int i = 0; i < n; i++){
        cin >> s;
        t->add(s);
    }
    for (int i = 0; i < m; i++){
        cin >> s;
        cout << t->search_pref(s) << endl;
    }
    return 0;
}