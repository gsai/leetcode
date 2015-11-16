#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) :label(x){};
};

class Solution
{
public:
	UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node)
	{
		if (node == nullptr)
			return node;
		if (hashTable.find(node) == hashTable.end())
		{
			hashTable[node] = new UndirectedGraphNode(node->label);
			for (auto x : node->neighbors)
			{
				(hashTable[node]->neighbors).push_back( cloneGraph(x) );
			}
		}
		return hashTable[node];
	}
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>  hashTable;
};