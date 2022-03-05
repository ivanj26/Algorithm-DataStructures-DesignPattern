#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/**
 * @brief Soal Kunci Pola 360 (Difficulty: Hard) Problem: (https://www.hackerrank.com/contests/srin-global-software-engineer-27-january-2022/challenges/kunci-pola-360/problem):
 *        
 *        Kunci pola merupakan salah satu pilihan pengamanan yang biasa ditemui di ponsel.
 *        Kunci pola dapat dibentuk dengan cara menghubungkan titik-titik dengan ukuran NxN dalam 1 garis bersambung. Garis dapat berupa garis horisontal,
 *        vertikal ataupun diagonal selama garis-garis tersebut tersambung.
 *
 *        Diberikan sebuah kunci pola dalam array 2 dimensi berukuran NxN, validasi pola pada kunci untuk membuka layar dari segala sisi (360 derajat).
 *        Masukan akan dianggap valid jika urutan masukan dan juga bentuk sesuai dengan kunci yang ditetapkan tanpa memperhitungkan posisi atas, bawah, kiri, kanan.
 * 
 */

/*
 * Complete the 'setup_kunci' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER L
 *  3. STRING_ARRAY langkah
 */

vector< unordered_map<int, pair<int, int>> > possibilities;

bool constructGrid(unordered_map<int, pair<int, int>> &attemptGrid, vector<string> &langkah, int N) {
    assert(N * N >= langkah.size());

	string delim = " ";
	int i = 1;

	for (string l : langkah) {
		int start = 0;
		int end = l.find(delim);

        // input : <x> <y>
        // we need to parse it and convert to integer
		int x = stoi(l.substr(start, end - start));
		int y = stoi(l.substr(end + delim.length()));

        // - check and validate
        // jika step > 1 && koordinat yang ingin dibentuk jaraknya lebih dari 1 kotak dari koordinat yang dibentuk pada step sebelumnya
        // then -> false
        if (i > 1) {
            int prevX = attemptGrid[i - 1].first;
            int prevY = attemptGrid[i - 1].second;

            if (abs(prevX - x) > 1 || abs(prevY - y) > 1) {
                return false;
            }
        }

		attemptGrid[i++] = { x, y };
	}

    return true;
}

void setup_kunci(int N, int L, vector<string> langkah) {
	int i = 0;
    string delim = " ";

    unordered_map<int, pair<int, int>> gMap;
    unordered_map<int, pair<int, int>> gMap90;
    unordered_map<int, pair<int, int>> gMap180;
    unordered_map<int, pair<int, int>> gMap270;

    for (string l : langkah) {
        int start = 0;
		int end = l.find(delim);

        // input : <x> <y>
        // we need to parse it and convert to integer
		int x = stoi(l.substr(start, end - start));
		int y = stoi(l.substr(end + delim.length()));

        // i'll store the key pattern like this:
        //  map[step-i] = { x, y }
        gMap[++i] = { x, y };

        // Suppose, we have the input pattern like this:
        // (note): Left hand: coordinate; Right-hand: value.
        // 
        //      <0,0> <0,1> <0,2>         1 2 3
        //      <1,0> <1,1> <1,2>         0 5 4
        //      <2,0> <2,1> <2,2>         0 6 0
        // 
        // If we rotate from 0' to 90' (Clockwise):
        //      <0,0> <0,1> <0,2>         0 0 1
        //      <1,0> <1,1> <1,2>         6 5 2
        //      <2,0> <2,1> <2,2>         0 4 3
        //
        // Jika kita observasi, maka koordinat dibawah ini saling tukar menukar:
        // -------------
        // from   -> to
        // -------------
        // <0, 0> -> <0, 2>
        // <0, 1> -> <1, 2>
        // <0, 2> -> <2, 2>
        // <1, 0> -> <0, 1>
        // <1, 1> -> <1, 1>
        // <1, 2> -> <2, 1>
        // <2, 0> -> <0, 0>
        // <2, 1> -> <1, 0>
        // <2, 2> -> <2, 0>
        // 
        // In conclusion:
        // <x, y> -> (rotate 90' Clockwise) -> <y, N - 1 - x'>
        // 
        // Note:
        //   - with x' is "previous x value" (we need to store it to temporary variable).
        // 
        // So, i'll determine the pattern for another 3 states (90 degree, 180 degree, 270 degree):
        for (int j = 90; j <= 270; j += 90) {
            int temp = x;
            x = y;
            y = N - 1 - temp;

            if (j == 90) {
                gMap90[i] = { x, y };
            } else if (j == 180) {
                gMap180[i] = { x, y };
            } else if (j == 270) {
                gMap270[i] = { x, y };
            }
        }
    }

    // store the states
    possibilities.push_back(gMap);
    possibilities.push_back(gMap90);
    possibilities.push_back(gMap180);
    possibilities.push_back(gMap270);
}

/*
 * Complete the 'otentikasi' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER L
 *  3. STRING_ARRAY langkah
 */

string otentikasi(int N, int L, vector<string> langkah) {
    unordered_map<int, pair<int, int>> attemptGrid;

    if (!constructGrid(attemptGrid, langkah, N)) {
        return "salah";
    }

    // - check and validate for every possibilities (4 states, 0 until 270 degree)
    for (unordered_map<int, pair<int, int>> p : possibilities) {
        for (int i = 1; i <= L; i++) {
            pair<int, int> coor = attemptGrid[i];
            pair<int, int> coorKey = p[i];

            // we need to break the loop if current coordinate is not same with current possibility coordinate
            // because we know the attempt's pattern is not longer same with stored pattern
            // let's check another possibility
            if (coor.first != coorKey.first || coor.second != coorKey.second) {
                break;
            }

            // if we got the solution (authenticated), return "berhasil"
            if (coor.first == coorKey.first && coorKey.second == coor.second && i == L) {
                return "berhasil";
            }
        }
    }

    return "gagal";
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string N_temp;
	getline(cin, N_temp);

	int N = stoi(ltrim(rtrim(N_temp)));

	string L_temp;
	getline(cin, L_temp);

	int L = stoi(ltrim(rtrim(L_temp)));

	vector<string> pola_kunci(L);

	for (int i = 0; i < L; i++) {
		string pola_kunci_item;
		getline(cin, pola_kunci_item);

		pola_kunci[i] = pola_kunci_item;
	}

	setup_kunci(N, L, pola_kunci);

	string T_temp;
	getline(cin, T_temp);

	int T = stoi(ltrim(rtrim(T_temp)));

	for (int T_itr = 0; T_itr < T; T_itr++) {

		vector<string> kunci_masuk(L);

		for (int i = 0; i < L; i++) {
			string kunci_masuk_item;
			getline(cin, kunci_masuk_item);

			kunci_masuk[i] = kunci_masuk_item;
		}

		string status = otentikasi(N, L, kunci_masuk);

		fout << status << "\n";
	}

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}
