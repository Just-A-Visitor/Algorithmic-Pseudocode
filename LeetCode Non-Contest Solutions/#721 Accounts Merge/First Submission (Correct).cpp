class Solution
{
	unordered_map<string, string> parent;
public:
	string find_set(string &str);
	void union_sets(string &first, string &second);
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts);
};

string Solution :: find_set(string &str)
{
	if(parent[str] == str)
		return str;
	
	string root_str = find_set(parent[str]);
	parent[str] = root_str;
	
	return root_str;
}

void Solution :: union_sets(string &first, string &second)
{
	string first_root = find_set(first);
	string second_root = find_set(second);
	
	if(first_root != second_root)
		parent[second_root] = first_root;
}

vector<vector<string>> Solution :: accountsMerge(vector<vector<string>>& accounts)
{
	for(auto vec : accounts)
		for(int i = 1; i < vec.size(); i++)
			parent[vec[i]] = vec[i];
	
	for(auto vec : accounts)
		for(int i = 2; i < vec.size(); i++)
			union_sets(vec[i], vec[i-1]);
	
	unordered_map<string, vector<string>> collection;
	for(auto str_pair : parent)
	{
		string str = str_pair.first;
		collection[find_set(str)].push_back(str);
	}
	
	vector<vector<string>> result;
	
	for(auto vec : accounts)
	{
		string name = vec.front();
		vector<string> current_vec;
		
		string one_email = vec.back();
		string leader = find_set(one_email);
		
		if(collection.count(leader))
		{
			current_vec.push_back(name);
			for(auto ele : collection[leader])
				current_vec.push_back(ele);
			
			collection.erase(leader);
		}
		
		sort(current_vec.begin(), current_vec.end());
		if(!current_vec.empty())
			result.push_back(current_vec);
	}
	
	return result;
	
}
