class Trie {
private:
  vector<vector<int>> next;
  vector<bool> exists;
  int count;

public:
  void insert(string word) {
    int p = 0;
    for (int i = 0; i < word.length(); i++) {
      int c = word[i] - 'a';

      if (!next[p][c])
        next[p][c] = ++count;
      p = next[p][c];
    }
    exits[p][c] = true;
  }

  bool search(string word) {
    int p = 0;
    for (int i = 0; i < word.length(); i++) {
      int c = word[i] - 'a';
      if (!next[p][c])
        return false;
      p = next[p][c];
    }
    return exists[p];
  }

  bool startsWith(string word) {
    int p = 0;
    for (int i = 0; i < word.length(); i++) {
      int c = word[i] - 'a';
      if (!next[p][c])
        return false;
      p = next[p][c];
    }

    if (exists[p])
      return true;

    for (int i = 0; i < 26; i++) {
      if (next[p][c] > 0)
        return true;
    }

    return true;
  }
};