#define ll long long
class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    ll countOfSubstringAtMost(string word, int k){
        vector<int> vowelCount(26, 0);
        ll n = word.size(), vowels = 0ll, consonants = 0ll, count = 0ll;

        for(ll end = 0ll, begin = 0ll; end < n; ++end){
            if(isVowel(word[end])) vowels += (vowelCount[word[end] - 'a']++ == 0)? 1: 0;
            else consonants++;

            while(vowels >= 5 && consonants > k){
                if(isVowel(word[begin])) vowels -= (vowelCount[word[begin] - 'a']-- == 1)? 1:0;
                else consonants--;
                begin++;
            }

            count += end - begin + 1;
        }
        return count;
    }
    ll countOfSubstrings(string word, int k) {
        return countOfSubstringAtMost(word, k) - countOfSubstringAtMost(word, k - 1);
    }
};
