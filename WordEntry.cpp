/**
 * This is a lightly edited version of code taken from
 * Manley, E.D., & Urness, T. M.,
 * http://nifty.stanford.edu/2016/manley-urness-movie-review-sentiment/CS2SentimentStarterCode.zip,
 * last access Sep 15, 2016.
 *
 */

#include "WordEntry.h"

/**
 * No-arg constructor creating a sentinel WordEntry that
 * represents no word & no appearances.
 * This only exists to allow Entries::find to return something
 * if the word was not found among the entries.
 */
WordEntry::WordEntry() : word{""}, num_appearances{0}, total_score(-1) { }

/**
 * Creates a new WordEntry with the given text and score.
 * Note that the num_appearances should be set to 1 here.
 *
 * @param the_word the word.
 * @param the_score the initial score assigned to the word.
 */
// TODO: implement this constructor
WordEntry::WordEntry(string the_word, int the_score) {
	this->word = the_word;
	this->total_score = the_score;
	this->num_appearances = 1;
}

/**
 * Should increase total score by score,
 * also should increase num_appearances
 * @param score a new score for the word.
 */
void WordEntry::add_new_appearance(int score) {
	// TODO: your implementation here.
	total_score +=score;
    num_appearances++;
}

/**
 * Returns the word field.
 * @return the word field.
 */
string WordEntry::get_word() const {
	// TODO: your implementation here.
   return word;
}

/**
 * Returns the num_appearances field.
 * @return the num_appearances field.
 */
int WordEntry::get_num_appearances() const {
	// TODO: your implementation here.
	return num_appearances;
};

/**
 * Returns the average score of the word.
 * based on total_score and num_appearances
 * @return the average score of the word.
 */
double WordEntry::get_average() const {
	// TODO: your implementation here.
	double average = total_score /(double) num_appearances;
	return average;
}

/**
 * Outputs WordEntry in format:
 *    word, total_score/num_appearances = average_score
 * so given the movieReviewsSmall.txt file here is how the
 * entry for the word "the" is displayed"
 *    the, 139/74 = 1.87838
 *
 * @param ostr the output stream
 * @param entry the word entry
 */
ostream& operator<<(ostream& ostr, const WordEntry& entry) {
	// TODO: your implementation here.
    ostr<<entry.get_word() <<" with a score of "<<entry.total_score <<"/"<<entry.num_appearances<<" = "<<entry.get_average();
	return ostr;
}
