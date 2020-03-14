#include <iostream>
#include <string.h>

using namespace std;

//m -> length of pat string, pat -> pattern text
void computeLPSArray(int* lps, int m, char* pat) {
  lps[0] = 0;
  int len = 0;

  int i = 1; //Mulai dari 1 sampai M-1
             //Inget, longest prefix itu dari [0..m-1] cocokin dengan suffix [1..m]
  while (i < m) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len == 0) {
        lps[i] = 0;
        i++;
      } else { //len != 0
        len = lps[len-1];
      }
    }
  }
}

int KMPSearch(char* text, char* pat) {
  int n = strlen(text);
  int m = strlen(pat);
  int *lps = new int[m];

  computeLPSArray(lps, m, pat);

  int i = 0; //index untuk text
  int j = 0; //index untuk pat

  while (i < n) {
    if (text[i] == pat[j]) {
      i++;
      j++;
    }

    if (j == m) {
      printf("Found at index %d", i - j);
    }

    if (i < n && pat[j] != text[i]) {
      if (j != 0) { //udah ditengah jalan lalu mismatch
        j = lps[j-1];
      } else {
        i++;
      }
    }
  }

  delete[] lps;
  return -1;
}

int main(int argc, char const *argv[])
{
  char text[] = "ABABDABACDABABCABAB";
  char pat[] = "ABABCABA";
  
  KMPSearch(text, pat);

  return 0;
}
