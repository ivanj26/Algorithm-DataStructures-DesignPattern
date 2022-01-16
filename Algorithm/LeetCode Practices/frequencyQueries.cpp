#include <vector>
#include <unordered_map>

using namespace std;

enum Operation {
	INSERT = 1,
	DELETE = 2,
	CHECK = 3
};

void execute(unordered_map<int, int> &map, unordered_map<int, int> &freqMap, int operation, int value, vector<int> &outputs) {
	bool isExists = map.find(value) != map.end();
	
	switch (operation) {
		case Operation::INSERT: {
			if (isExists) {
				map[value]++;
			} else {
				map[value] = 1;
			}
			
			freqMap[map[value]]++;
			int prevFreq = map[value] - 1;
			if (freqMap[prevFreq] > 0) {
				freqMap[prevFreq]--;
			}
			
			break;
		} case Operation::DELETE: {
			if (isExists) map[value]--;
			
			int prevFreq = freqMap[map[value] + 1];
			if (freqMap[prevFreq] > 0) {
				freqMap[prevFreq]--;
			}
			
			freqMap[map[value]]++;
			
			break;
		} case Operation::CHECK:
			if (freqMap[value] > 0) {
				outputs.push_back(1);
				break;
			}
			
			outputs.push_back(0);
		break;
	}
}

vector<int> freqQuery(vector<vector<int>> queries) {
	vector<int> outputs;
	unordered_map<int, int> map;
	unordered_map<int, int> freqMap;
	
	for (auto query : queries) {
		int oper = query.at(0);
		int value = query.at(1);
		
		execute(map, freqMap, oper, value, outputs);
	}
	
	return outputs;
}