#include "OnlyConnect.h"
#include "strlib.h"
#include <cctype>
using namespace std;

bool isConsonant(char ch) {
    ch = tolower(ch);
    return (isalpha(ch) && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u');
}

string onlyConnectize(string phrase) {
    if (phrase.empty()) {
        return "";
    }
    char first = toupper(phrase[0]);
    string rest = onlyConnectize(phrase.substr(1));

    if (isConsonant(first)) {
        return first + rest;
    }
    return rest;
}

#include "GUI/SimpleTest.h"

PROVIDED_TEST("Various cases") {
    EXPECT_EQUAL(onlyConnectize("For sale: baby shoes, never worn."), "FRSLBBYSHSNVRWRN");
    EXPECT_EQUAL(onlyConnectize("I'm the bad guy. (Duh!)"), "MTHBDGYDH");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Different cases") {
    EXPECT_EQUAL(onlyConnectize("Annie Mae, My Sea Anemone Enemy!"), "NNMMYSNMNNMY");
    EXPECT_EQUAL(onlyConnectize("Antonin Scalia"), "NTNNSCL");
}

PROVIDED_TEST("Extreme cases") {
    EXPECT_EQUAL(onlyConnectize("......."), "");
    EXPECT_EQUAL(onlyConnectize("0AAIII_-3214'////''(#@!$@"), "");
}

STUDENT_TEST("Custom Test Case for Caucasus University") {
    EXPECT_EQUAL(onlyConnectize("Caucasus University"), "CCSSNVRSTY");
}


