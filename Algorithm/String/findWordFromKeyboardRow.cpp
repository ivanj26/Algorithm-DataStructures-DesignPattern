#include <vector>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution {
	private:
		vector<set<char>>& initKeyboardRows() const {
			set<char> row1;
			set<char> row2;
			set<char> row3;

			row1.insert('q');
			row1.insert('w');
			row1.insert('e');
			row1.insert('r');
			row1.insert('t');
			row1.insert('y');
			row1.insert('u');
			row1.insert('i');
			row1.insert('o');
			row1.insert('p');
			row1.insert('Q');
			row1.insert('W');
			row1.insert('E');
			row1.insert('R');
			row1.insert('T');
			row1.insert('Y');
			row1.insert('U');
			row1.insert('I');
			row1.insert('O');
			row1.insert('P');
			
			row2.insert('a');
			row2.insert('s');
			row2.insert('d');
			row2.insert('f');
			row2.insert('g');
			row2.insert('h');
			row2.insert('j');
			row2.insert('k');
			row2.insert('l');
			row2.insert('A');
			row2.insert('S');
			row2.insert('D');
			row2.insert('F');
			row2.insert('G');
			row2.insert('H');
			row2.insert('J');
			row2.insert('K');
			row2.insert('L');
			
			row3.insert('z');
			row3.insert('x');
			row3.insert('c');
			row3.insert('v');
			row3.insert('b');
			row3.insert('n');
			row3.insert('m');
			row3.insert('Z');
			row3.insert('X');
			row3.insert('C');
			row3.insert('V');
			row3.insert('B');
			row3.insert('N');
			row3.insert('M');

			vector<set<char>> v;
			v.push_back(row3);
			v.push_back(row2);
			v.push_back(row1);

			return v;
		}

	public:
		vector<string> findWords(vector<string>& words) {
			vector<set<char>> v = initKeyboardRows();
			
			vector<string> res;
			
			for (string w : words) {
				int j = 0;
				set<char> s = v[j];
				
				bool found = false;
				if (w.length() == 1) {
					found = true;
				} else {
					for (int i = 0; i < w.length();) {
						char c = w[i];

						if (s.find(c) != s.end()) {
							found = (i == w.length() - 1);
							i++;
							continue;
						} else {
							if (j == v.size() - 1) {
								break;
							}

							i = 0;
							s = v[++j];
						}
					}   
				}
				
				if (found) {
					res.push_back(w);
				}
			}
			
			return res;
		}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
