 
// --------------------------
// projects/c++/date/main.c++
// Copyright (C) 2009
// Glenn P. Downing
// --------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "cppunit/TestSuite.h"      // TestSuite
#include "cppunit/TextTestRunner.h" // TestRunner

#include "Date.h"
#include "TestDate.h"
#define NDEBUG
// ----
// main
// ----

int main () {
    using namespace std;
    using namespace Date;
    using namespace CppUnit;

    // ----------
    // unit tests
    // ----------

    TextTestRunner tr;
    tr.addTest(TestDate::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}

