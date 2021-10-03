#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class ShortenerService
{
	private:
		unordered_map<string, string> map;
		string baseUrl = "tiny.url/";
		char dict[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		unsigned int id;

		string generate(unsigned int e)
		{
			string shortUrl = "";

			while (e)
			{
				char c = dict[e % 62];
				e /= 62;

				shortUrl += c;
			}

			reverse(shortUrl.begin(), shortUrl.end());

			return shortUrl;
		}

	public:
		ShortenerService()
		{
			this->id = 1000001;
		}
		string toShortUrl(string longUrl)
		{
			string shortUrl = "";
			do
			{
				shortUrl = this->generate(this->id++);
			} while (map.find(shortUrl) != map.end());

			map.insert(make_pair(shortUrl, longUrl));

			return baseUrl + shortUrl;
		}

		string toLongUrl(string shortUrl)
		{
			if (shortUrl.length() < baseUrl.length())
			{
				cout << "The given URL is too short";
			}

			return map.at(shortUrl.substr(baseUrl.length()));
		}
};

int main(int argc, char const *argv[])
{
	ShortenerService service;
	string shortUrl = service.toShortUrl("https://example.com/blablabla");

	cout << "ShortURL: " << shortUrl << endl;
	cout << "LongURL: " << service.toLongUrl(shortUrl) << endl;
	return 0;
}
