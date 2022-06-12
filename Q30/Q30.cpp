// Runtime: 104 ms, faster than 79.24% of C++ online submissions for Substring with Concatenation of All Words.
// Memory Usage: 28.5 MB, less than 47.55% of C++ online submissions for Substring with Concatenation of All Words.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> words_dict, current_words;
        vector<int> result;
        // vector<string> current_words;
        int word_length = words[0].size(), words_length, start;

        for (string word : words) {
            words_dict[word]++;
        }

        for (int i = 0; i < word_length; i++) {
            current_words.clear();
            words_length = words.size();
            start = i;
            for (int j = i; j < s.size(); j += word_length) {
                string current_word = s.substr(j, word_length);
                if (words_dict[current_word] > 0) {
                    if (current_words[current_word] < words_dict[current_word]){
                        current_words[current_word]++;
                        words_length--;
                    }
                    else{
                        while (start < j) {
                            string tmp_word = s.substr(start, word_length);
                            current_words[tmp_word]--;
                            start += word_length;
                            if (current_words[current_word] < words_dict[current_word]){
                                current_words[current_word]++;
                                break;
                            }
                            else {
                                words_length++;
                            }
                        }
                    }
                    if (words_length == 0) {
                        result.push_back(start);
                    }
                }
                else {
                    words_length = words.size();
                    current_words.clear();
                    start = j + word_length;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "syvsjefxttjyqamnntfucrpeoculzlzsjukuarrtmbuddiqsbxmdodjdffqfrpzcjjxmcofprzuwikpjhbpxhycmettxiuzufwginlxgnrdxduimxxjewmtchmzpjyjovrwifvqsmtprpxdnxprtdkvkzuziulwpcvzhqqbflswbscqprhiuufetbfdvsznvwoengisuaqvssnhjurfoyljbrmzjomgkcnxjvrdviaqanzmjtrardjvwwufmgowibwtwnwtxwjyljmvcfvvigqgekmqscpddlwbatuyreyfpkarpxoadhgiruamyppbancdgxbadbfsnhleezejgntajumijdlmqqpzpqbstgkgpxkvwpefeyfpstzdwlpodenswokpwwvltgirxpydndshyumwhclkiycfpoulmszhyjyxyzancuwdojzxlkhtllaczxpnpqupavmyuomykibbrbyengaarcctzsgoibdkyrjsfvqqfurzvpfkxfnripkjjqyutdervnlckcuqylrtdwfccstmkfxtwvprbulwjwawavoyiftnbbqftltfrrbpmqgpmtlysouujivrpqfqrxwnirszitoxmxmyqaykosfxcaqtqvkksizbzrcknrhbotbgvarjuyizyzsquccpmbsovuyklflbamiwobhjzqkzpcrlhuctxuhsrhcempgpeqlsrudsknrbskpzerscocwfjbjyqpnuhapauushklicwxdcpxgdzfklgtlwlatsaktwgndqzouxlxbcxihwprjvlwtwwoqyyjvhzaxaouxataeqkmpzdauqxomtcfudopkprjpgdoizpmpzyezehvuejhzomtrckbsckjiqyspnegofnnjujdaukziytbddcxhpgphghytogkttxcpifpdsrnsmpxrtuzkdqtlathoarhvollzqcektrdficxezwocmkpmdwcdnlzcwmdpohziaepjhmngkdkznznrwqwlbvnahspwzqgaxvlgkyoudatrzhkxzgjceycnttlskruhpfpzfdtldpceyoexwpbcpeqixbbjtxskfhjkkcvntzsrpyomnqocwglviofdlznqhwdrayhuablrzcdmuuosabnkpunbuatbywubxdvzeiqfmuriqiasjodzkqcetvhtueurhpqoaitmcnvuxxngnqhyiledhoxdsrubjmpjujxzysvvsidfaldlyiofylkqferoshxnsuospjnhusmwfsjecylalwqqajevsdkmayerjtyfmmcrglviljkxfcpfmwcgzmtzmzqwtqdhffaltywghgfmlvtxrwdskyuxymvtfyakgaxbavhhentpknobltvvspsscpljontwpsxqoexuttjdizgtscqmtlexapgqcbmsulkkqhelappiovdizuvvfzsfrbyvckpywzkojqzjhquxmxgnrdiyedgxgetkqklomvcvoeevuatiybwregsilyirebcunnjzknuytbuobpwbquvwdngonogrrknfzyejobihcevftuhloehrtnggcoztamaznfibgqikweppayaochivxqdbgcwgrxfeenfmgnwctnstmukqeuobkreqwawnxbtdqypwnlbjztenpodtitwulakhbiwajpecptyehzniusvmiaftucnhe";
    vector<string> words = {"qbflswbscqprhiuufetbfd","vsznvwoengisuaqvssnhju","rfoyljbrmzjomgkcnxjvrd","viaqanzmjtrardjvwwufmg","owibwtwnwtxwjyljmvcfvv","igqgekmqscpddlwbatuyre","yfpkarpxoadhgiruamyppb","ancdgxbadbfsnhleezejgn","tajumijdlmqqpzpqbstgkg","pxkvwpefeyfpstzdwlpode","nswokpwwvltgirxpydndsh","yumwhclkiycfpoulmszhyj","yxyzancuwdojzxlkhtllac","zxpnpqupavmyuomykibbrb","yengaarcctzsgoibdkyrjs","fvqqfurzvpfkxfnripkjjq","yutdervnlckcuqylrtdwfc","cstmkfxtwvprbulwjwawav","oyiftnbbqftltfrrbpmqgp","mtlysouujivrpqfqrxwnir"};
    vector<int> output;

    auto started = std::chrono::high_resolution_clock::now();

    output = solution.findSubstring(s, words);

    auto done = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }

    cout << std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count() << "ms" << endl;
}