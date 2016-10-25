/**
 * This is a lightly edited version of code taken from
 * Manley, E.D., & Urness, T. M.,
 * http://nifty.stanford.edu/2016/manley-urness-movie-review-sentiment/CS2SentimentStarterCode.zip,
 * last access Sep 15, 2016.
 *
 */

#include "WordEntry.h"
#include "Entries.h"
#include "Utils.h"
#include <fstream>


using namespace std;

// prototypes for functions you will implement at the bottom of this file

void main_menu(const Entries& entries);
void single_word_score(const Entries& entries);
void average_score_of(const Entries& entries);
void highest_lowest_words(const Entries& entries);
void split_pos_neg(const Entries& entries);

int main() {
	//declare a few needed variables for inputting the data
	string message = " ";
	string fileName = " ";
	cout << "Enter name of file with movie reviews (movieReviewsSmall.txt): ";
	getline(cin, fileName);
	Entries entries = read_input_file(fileName);
	main_menu(entries);
}

/**
 * Display the menu, process the choice, exit when selected.
 * @param entries the entries read from the original movie reviews.
 */

void main_menu(const Entries& entries) {
	int choice = 0;
	while (true) {
		cout << "\n1) Get score of a word" << endl;
		cout << "2) Get the average score of a word in a file (one per line)" << endl;
		cout << "3) Sort the words in a file into positive.txt and negative.txt" << endl;
		cout << "4) Find the highest and lowest scoring words in a file" << endl;
		cout << "5) Exit" << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			single_word_score(entries);
			break;
		case 2:
			average_score_of(entries);
			break;
		case 3:
			split_pos_neg(entries);
			break;
		case 4:
			highest_lowest_words(entries);
			break;
		default:
			break;
		}
	}
}

/**
 * Prompts user for a word and then prints how many times
 * the word occurs and it's average score.
 * @param entries the entries read from the original movie reviews.
 */
void single_word_score(const Entries& entries) {
	string word;
	WordEntry wordEntry;
	cin.ignore();
	cout << "Enter word: ";
	getline(cin, word);
	wordEntry = entries.find(word);
	cout << "The word " << word << " appeared " << wordEntry.get_num_appearances() << " times with an average score of " << wordEntry.get_average() << endl;
}

/**
 * Prompts user for the name of a file that contains 1 word
 * per line, reads that file and then prints the average score
 * for all words in a file together.
 * This will also print the overall sentiment of the phrase
 * represented by words in the file.
 * Consider an average word score
 * - above 2.01 as an overall positive sentiment,
 * - below 1.9 to have an overall negative sentiment,
 * - othewise to have an overall neutral sentiment.
 *
 * @param entries the entries read from the original movie reviews.
 */
void average_score_of(const Entries& entries) {
	string fileName;
	ifstream inputFile;
	double average = 0.0;
	double sum = 0.0;
	string sentiment("sentiment");
	int count = 0;
	cin.ignore();
	cout << "Enter name of file (containing one word per line): ";
	getline(cin, fileName);

	//Open file
	inputFile.open(fileName.c_str());
	if (inputFile.fail()) {
		cout << "could not open file" << endl;
		exit(0);
	}
	while (!inputFile.eof()) {
		string word;
		getline(inputFile, word);

		sum += entries.get_average(word);
		count++;
	}

	average = sum / count;

    size_t index;
	if(average>2.01) {
        while ((index = sentiment.find("sentiment")) != string::npos)
        sentiment.replace(index, 9, "Positive");
	}
	if(average<1.9) {
        while ((index = sentiment.find("sentiment")) != string::npos)
        sentiment.replace(index, 9, "Negative");
	}
	else {
        while ((index = sentiment.find("sentiment")) != string::npos)
        sentiment.replace(index, 9, "Neutral");
	}

	cout << "The average score for the words in " << fileName << " is: " << average << endl;
	cout << "The overall sentiment of " << fileName << " is: " << sentiment << endl;
	inputFile.close();
}

/**
 * Prompts user for the name of a file that contains 1 word
 * per line, reads that file and then
 * prints the highest and lowest scoring words in the specified file,
 * including the average score for each.
 *
 * @param entries the entries read from the original movie reviews.
 */
void highest_lowest_words(const Entries& entries) {
	string fileName;
	ifstream inputFile;
	double min = 999999.0;
	double max = 0.0;
	WordEntry highScore;
	WordEntry lowScore;
	cin.ignore();

	cout << "Enter the file name: ";
	getline(cin, fileName);

	//Open file
	inputFile.open(fileName.c_str());
	while (inputFile.eof() == false) {
		string word;
		getline(inputFile, word);

		if (entries.get_average(word) > max) {
			highScore = entries.find(word);
			max = entries.get_average(word);
		}
		if (entries.get_average(word) < min) {
			lowScore = entries.find(word);
			min = entries.get_average(word);
		}
	}

	cout << "The most positive word is " << highScore << endl;
	cout << "The most negative word is " << lowScore << endl;
	inputFile.close();
}

/**
 * Prompts user for the name of a file that contains 1 word
 * per line, reads that file and then
 * creates 2 new files, positive.txt and negative.txt
 * sorting words that have scores below 1.9 into negative.txt,
 * and words that have scores above 2.1 into positive.txt
 * (and just leave out words in between).
 *
 * @param entries the entries read from the original movie reviews.
 */
void split_pos_neg(const Entries& entries) {
	string fileName;
	ifstream inputFile;
	ofstream  outputP;
	ofstream  outputN;

	cin.ignore();
	cout << "Enter the file name: ";
	getline(cin, fileName);

	outputP.open("positive.txt");
	outputN.open("negative.txt");

	inputFile.open(fileName.c_str());
	while (inputFile.eof() == false) {
		string word;
		getline(inputFile, word);

		WordEntry wordEntry;
		wordEntry = entries.find(word);
		if ((wordEntry.get_average() < 1.9) && (wordEntry.get_average() > 0.0)) {
			outputN << wordEntry << endl;
		} else if (wordEntry.get_average() > 2.1) {
			outputP << wordEntry << endl;
		}
	}
	inputFile.close();
	outputP.close();
	outputN.close();
	cout << "Files saved into negative.txt & positive.txt\n";
}
