#include <string>

using namespace std;

class TrieNode
{
public:
	TrieNode *next[26];
	bool isWord;

	TrieNode()
	{
		for (int i = 0; i < 26; i++)
			next[i] = nullptr;

		isWord = false;
	}
};

class Trie
{
public:
	Trie()
	{
		root = new TrieNode();
	}

	//Inserts a word into the tire.
	void insert(string word)
	{
		TrieNode *p = root;
		for (auto c : word)
		{
			if (p->next[c - 'a'] == nullptr)
			{
				p->next[c - 'a'] = new TrieNode();
			}
			p = p->next[c - 'a'];
		}
		//p可能是nullptr
		if (p == nullptr)
			p = new TrieNode();

		p->isWord = true;
	}

	//Returns if the word is in the trie
	bool search(string word)
	{
		TrieNode *p = root;
		for (auto c : word)
		{
			if (p->next[c - 'a'] == nullptr)
				return false;
			else
				p = p->next[c - 'a'];
		}

		//p可能是nullptr
		return p == nullptr ? false : p->isWord;
	}

	bool StartWith(string prefix)
	{
		TrieNode *p = root;
		
		for (auto c : prefix)
		{
			if (p->next[c - 'a'] != nullptr)
				p = p->next[c - 'a'];
			else
				return false;
		}

		return p == nullptr ? false : true;
	}
private:
	TrieNode *root;
};