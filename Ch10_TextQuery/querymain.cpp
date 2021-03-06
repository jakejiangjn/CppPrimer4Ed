// program takes single argument specifying the file to query

#include "TextQuery.h"

using namespace std;

int main(int argc, char **argv)
{
    // open the file from which user will query words
	ifstream infile;
	if (argc < 2 || !open_file(infile, argv[1])) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.read_file(infile); // builds query map
	// iterate with the user: prompt for a word to find and print results
	// loop indefinitely; the loop exit is inside the while
	while (true) {
		cout << "enter word to look for,or q to quit" << endl;
		string s;
		cin >> s;
		// stop if hit eof on input or a 'q'is entered
		if (!cin || s == "q")
			break;
        	// get the set of line numbers on which this word appears
		set<TextQuery::line_no> locs = tq.run_query(s);
		// print count and all occurrences, if any
		print_results(locs, s, tq);
	}
	return 0;
}
