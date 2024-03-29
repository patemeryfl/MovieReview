/**
 * This file contains helper utilities.
 * DO NOT EDIT THIS FILE.
 */
#include "Utils.h"
#include <fstream>
#include <sstream>  // for istringstream
#include <iterator> // for istream_iterator

/**
 * Reads the given file into an Entries object.
 *
 * Code based on code from Manley, E.D., & Urness, T. M.,
 * http://nifty.stanford.edu/2016/manley-urness-movie-review-sentiment/CS2SentimentStarterCode.zip,
 * last access Sep 15, 2016.
 *
 * @param filename the filename of movie reviews.
 * @return an Entries objects (containing WordEntry objects) that
 * tracks the sentiment of the words in the movei reviews.
 */
Entries read_input_file(string filename) {
    //declare a few needed variables for inputing the data
    string line;
    int score;
    string message = " ";

    //open input file
    ifstream myfile (filename);
    if (myfile.fail() )
    {
        cout << "could not open file" <<endl;
        exit(0);
    }

    Entries entries;

    cout << "Reading data from " << filename << endl;

    while (! myfile.eof() )
    {
        myfile >> score;  //get score
        myfile.get();    // get blank space
        getline(myfile,line);
        for (string word : split(line)) {
            entries.put(word, score);
        }
    }

    cout << "Done reading data." << endl;

    return entries;
}

/**
 * Splits a string based on whitespace.
 *
 * Based on code from http://stackoverflow.com/a/237280,
 * last access Sep 16, 2016
 *
 * @param s the string to split.
 * @return a vector of the individual strings (tokens)
 */
vector<string> split(string s) {
    istringstream iss {s};
    vector<string> results { istream_iterator<string>{iss},
                             istream_iterator<string> {} };
    return results;
}

/**
 * Flushes cin of remaining input.
 * Taken from http://faq.cprogramming.com/cgi-bin/smartfaq.cgi?id=1043284392&answer=1044873249,
 * last access Sep 17, 2016
 */
void flush() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
