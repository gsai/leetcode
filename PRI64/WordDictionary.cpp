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

class WordDictionary
{
public:
	//adds a word into the data structure
	void addWord(string word)
	{
		if (root == nullptr)
			root = new TrieNode();

		TrieNode *p = root;
		for (auto c : word)
		{
			if (p->next[c - 'a'] == nullptr)
				p->next[c - 'a'] = new TrieNode();
			p = p->next[c - 'a'];
		}
		if (p == nullptr)
			p = new TrieNode();
		p->isWord = true;
	}

	bool search(string word)
	{
		TrieNode *p = root;

		size_t n = word.size();
		for (int i = 0; i < n; i++)
		{
			if (word[i] == '.')
			{
				if (i == n - 1)
				{
					for (int j = 0; j < 26; j++)
					{
						if (p->next[j]->isWord)
							return true;
					}
					return false;
				}
				//避免substr为空串，分成了两类
				for (int j = 0; j < 26; j++)
				{
					if (find(word.substr(i + 1), p->next[j]))
						return true;
				}
				return false;
			}
			else
			{
				if (p->next[word[i] - 'a'] == nullptr)
					return false;
				else
					p = p->next[word[i] - 'a'];
			}
		}

		return p && p->isWord;
	}

private:
	TrieNode *root = nullptr;

	bool find(string word, TrieNode *ptr)
	{
		if (ptr == nullptr) return false;
		
		TrieNode *p = ptr;
		for (auto c : word)
		{
			if (p->next[c - 'a'] == nullptr)
				return false;
			else
				p = p->next[c - 'a'];
		}
		return p->isWord;
	}
};