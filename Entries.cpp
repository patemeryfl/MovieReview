/**
* This is based on code taken from
* Manley, E.D., & Urness, T. M.,
* http://nifty.stanford.edu/2016/manley-urness-movie-review-sentiment/CS2SentimentStarterCode.zip,
* last access Sep 15, 2016.
*
*/

#include "Entries.h"
#include <cstring>

/**
* Creates a new Entries object.
*/
Entries::Entries() { }

/**
* Returns true iff the word is in the entries.
* @param word the word to search for.
* @return true iff the word is in the entries.
*/
bool Entries::contains(string word) const {
	for (int index = 0; index < data.size(); index++) {
		if (strcmp((data[index]).get_word().c_str(), word.c_str()) == 0) {
			return true;
		}
	}
	return false;
}

/**
*  First, look to see if word already exists in the Entries
*  + if so, add_new_appearence with the score to the WordEntry
*  + if not, create a new WordEntry and insert it
*
* @param word the word to enter
* @param score the score of the word to enter
*/
void Entries::put(string word, int score) {
	if (contains(word)) {
		for (int index = 0; index < data.size(); index++) {
			if (strcmp((data[index]).get_word().c_str(), word.c_str()) == 0) {
				//add_new_appearence with the score to the WordEntry
				data[index].add_new_appearance(score);
			}
		}
	}
	else {
		//is not, create a new WordEntry and insert it
		WordEntry wordEntry(word, score);
		data.push_back(wordEntry);
	}

}

/**
* Returns the average value for the word.  If not found,
* returns 2.0 (neutral result).
* Must first find the corresponding word in the entries
* and then return the average.
*
* @param the word to find.
* @return the average value for the word.  If not found,
* returns 2.0 (neutral result).
*/
double Entries::get_average(string word) const {
	if (contains(word)) {
		for (int index = 0; index < data.size(); index++) {
			if (strcmp((data[index]).get_word().c_str(), word.c_str()) == 0) {
				return data[index].get_average();
			}
		}
	}
	return 2.0;
}

/**
* Returns the WordEntry for the given word.  If the word
* is not among the entries it returns the result of calling the
* no-argument constructor of the WordEntry class.
*
* @param word the word to search for.
* @return the WordEntry for the given word.  If the word
* is not among the entries it returns the result of calling the
* no-argument constructor of the WordEntry class.
*/
WordEntry Entries::find(string word) const {
	WordEntry entry;

	if (contains(word)) {
		for (int index = 0; index < data.size(); index++) {
			if (strcmp((data[index]).get_word().c_str(), word.c_str()) == 0) {
				return data[index];
			}
		}
	}
	return entry;
}