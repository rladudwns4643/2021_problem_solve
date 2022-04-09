#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string convert(string m) {
    for (int i = 0; i < m.size() - 1; i++) {
        if (m[i + 1] == '#') {
            m[i] = tolower(m[i]);
            m.erase(m.begin() + i + 1);
            i--;
        }
    }
    return m;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    stringstream ss;

    int answer_music_len = 0;
    m = convert(m);

    for (string s : musicinfos) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ':' || s[i] == ',') s[i] = ' ';
        }
        ss.str(s);
        int hs, he, ms, me;
        string title, mel;
        ss >> hs >> ms >> he >> me >> title >> mel;
        ss.clear();

        int now_music_len = (he * 60 + me) - (hs * 60 + ms);
        mel = convert(mel);

        if (m.length() > now_music_len) continue;

        while (mel.size() < now_music_len) {
            mel += mel;
        }
        mel = mel.substr(0, now_music_len);

        if (mel.find(m) != string::npos) {
            if (answer_music_len < now_music_len) {
                answer = title;
                answer_music_len = now_music_len;
            }
        }
    }

    return answer;
}