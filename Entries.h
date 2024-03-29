/**
 * This is based on code taken from
 * Manley, E.D., & Urness, T. M.,
 * http://nifty.stanford.edu/2016/manley-urness-movie-review-sentiment/CS2SentimentStarterCode.zip,
 * last access Sep 15, 2016.
 *
 * NOTE: DO NOT EDIT THIS FILE!
 */

#ifndef MOVIEREVIEW_ENTRIES_H
#define MOVIEREVIEW_ENTRIES_H


#include "WordEntry.h"
#include <vector>
#include <functional> // for function

using namespace std;

class Entries {
    /**
     * Stores the processed data in the form of WordEntry objects
     * read from the tagged movie reviews.
     */
    vector<WordEntry> data;

public:
    Entries();
    bool contains(string word) const;
    double get_average(string word) const;
    void put(string word, int score);
    WordEntry find(string word) const;
};

#endif //MOVIEREVIEW_ENTRIES_H
