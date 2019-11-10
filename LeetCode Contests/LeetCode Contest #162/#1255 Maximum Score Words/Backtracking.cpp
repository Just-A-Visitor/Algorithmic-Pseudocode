class Solution
{
public:
	vector<bool> taken;
	vector<int> count;
	vector<int> score;
	int max_sum = 0;
	
	void update_score(vector<string>& words);
	void generate_subset(vector<string>& words, int n);
	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score);
};

void Solution :: generate_subset(vector<string>& words, int n)
{
	if(n == 0)
	{
		update_score(words);
		return;
	}
	
	taken[n-1] = true;
	generate_subset(words, n-1);
	
	taken[n-1] = false;
	generate_subset(words, n-1);
}

void Solution :: update_score(vector<string>& words)
{
	int current_score = 0;
	vector<int> freq(26, 0);
	
	for(int i = 0; i < words.size(); i++)
	{
		if(taken[i])
		{
			for(auto ele : words[i])
			{
				int ind = ele - 'a';
				current_score += score[ind];
				freq[ind]++;
				
				if(freq[ind] > count[ind])
					  return;
			}
		}
	}
					  
	max_sum = max(max_sum, current_score);
}
					  
int Solution :: maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
{
	taken.resize(words.size(), false);
	count.resize(26, 0);
	this->score = score;
	
	for(auto ele : letters)
		count[ele - 'a']++;
	
	int n = words.size();
	generate_subset(words, n);
	
	return max_sum;
}
