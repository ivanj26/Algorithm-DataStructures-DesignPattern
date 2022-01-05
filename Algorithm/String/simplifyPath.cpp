#include <deque>
#include <string>
#include <iostream>
#include <set>


void insertToCommands(std::string subStr, std::deque<std::string> &commands)
{
	if (subStr.length() == 1 && subStr[0] == '.') {
		// skip
	}
	else if (subStr.length() > 1 && subStr == "..") {
		if (!commands.empty()) {
			commands.pop_back();
		}        
	} else {
		if (subStr.length() > 0) commands.push_back(subStr);
	}
}

std::string createSimplePath(std::deque<std::string> &commands) {
	std::string result = "/";
	while (!commands.empty()) {
		std::string c = commands.front();
		commands.pop_front();
		
		result += result.size() == 1 ? c : ("/" + c);
	}
	
	return result;
}

std::string simplifyPath(std::string path)
{
	std::string delim = "/";
	std::deque<std::string> commands;

	int start = 0;
	int end = path.find(delim);

	// consider. e.g. "/abc/bc"
	// start = 0
	// end = 0

	// abc/bc
	// start = 0 + 1 = 1
	// end = 4
	// result:
	// 	substr = abc

	while (end != -1) {
		std::string subStr = path.substr(start, end - start);

		insertToCommands(subStr, commands);

		start = end + delim.size();
		end = path.find(delim, start);
	}

	// handle last command
	std::string lastCommand = path.substr(start, path.size() - start);
	insertToCommands(lastCommand, commands);

	return createSimplePath(commands);
}

int main(int argc, char const *argv[])
{
	std::string path = "/home/ubuntu/ivan//abc";
	std::string simpler = simplifyPath(path);

	std::cout << simpler << std::endl;
	return 0;
}
