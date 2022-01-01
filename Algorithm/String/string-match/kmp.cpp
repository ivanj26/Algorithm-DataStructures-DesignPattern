#include <string>
#include <iostream>

using namespace std;

void computeLPSArray(int *lps, string pat)
{
	int m = pat.length();
	int i = 1;
	int len = 0;

	lps[0] = 0;

	while (i < m)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
			else
			{
				len = lps[len - 1];
			}
		}
	}
}

void kmpSearch(string text, string pat)
{
	int n = text.length();
	int m = pat.length();

	int *lps = new int[m];
	computeLPSArray(lps, pat);

	int i = 0; // index for text
	int j = 0; // index for pat

	// AACAABAABAABA
	// AABA
	// lps = [0, 1, 0, 1]

	while (i < n)
	{
		if (pat[j] == text[i])
		{
			i++;
			j++;
		}

		if (j == m)
		{
			cout << "Found pattern at index " << (i - j) << endl;
			j = lps[m - 1];
		}
		else if (i < n)
		{
			if (pat[j] != text[i])
			{
				if (j != 0)
				{
					j = lps[j - 1];
				}
				else
				{
					i++;
				}
			}
		}
	}

	delete[] lps;
}

int main(int argc, char const *argv[])
{
	string pat = "AABA";
	string text = "AACAABAABAABA";

	kmpSearch(text, pat);

	return 0;
}
