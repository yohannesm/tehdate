/**
 * @file Decipher.h
 * @author Matthew Paniagua
 * @author Erik Ernst
 * @date Summer Long, 2009
 * @brief This class contains tests for the date class
 */

// ----------------------------
// projects/c++/date/TestDate.h
// Copyright (C) 2009
// Glenn P. Downing
// ----------------------------

#ifndef TestDate_h
#define TestDate_h

// --------
// includes
// --------

#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // string, ==
#include <utility>   // !=, <=, >, >=

#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE

#include "Date.h"
#define NDEBUG
using namespace std::rel_ops;

// --------
// TestDate
// --------

struct TestDate : CppUnit::TestFixture {
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor () {
        try {
            const Date::Date<int> x(0, 1, 1600);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_constructor2 () {
        try {
            const Date::Date<int> x(30, 2, 2000);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_constructor3 () {
        try {
            const Date::Date<int> x(2, 1, 1600);
            CPPUNIT_ASSERT(true);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_constructor4 () {
        try {
            const Date::Date<int> x(29, 2, 1900);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_constructor5 () {
        try {
            const Date::Date<int> x(29, 2, 2000);
            CPPUNIT_ASSERT(true);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    // -------------
    // test_equal_to
    // -------------

    void test_equal_to () {
        try {
            const Date::Date<int> x(28, 2, 2000);
            const Date::Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(x == y);
            CPPUNIT_ASSERT(!(x != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to2 () {
        try {
            const Date::Date<int> x(28, 2, 2000);
            CPPUNIT_ASSERT(x == x);
            CPPUNIT_ASSERT(!(x != x));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to3 () {
        try {
            const Date::Date<int> x(29, 2, 2000);
            const Date::Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(x != y);
            CPPUNIT_ASSERT(!(x == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------
    // test_less
    // ---------

    void test_less () {
        try {
            const Date::Date<int> x(27, 2, 2000);
            const Date::Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(x <  y);
            CPPUNIT_ASSERT(x <= y);
            CPPUNIT_ASSERT(!(x >  y));
            CPPUNIT_ASSERT(!(x >= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less2 () {
        try {
            const Date::Date<int> x(28, 2, 2000);
            const Date::Date<int> y(29, 2, 2000);
            CPPUNIT_ASSERT(x <  y);
            CPPUNIT_ASSERT(x <= y);
            CPPUNIT_ASSERT(!(x >  y));
            CPPUNIT_ASSERT(!(x >= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less3 () {
        try {
            const Date::Date<long> y(29, 2, 5000000);
            const Date::Date<long> x(29, 2, 1000000);
            CPPUNIT_ASSERT(x <  y);
            CPPUNIT_ASSERT(x <= y);
            CPPUNIT_ASSERT(!(x >  y));
            CPPUNIT_ASSERT(!(x >= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------
    // test_plus
    // ---------

   /* void test_plus () {
        try {
            const Date::Date<int> x(1, 1, 2000);
            const Date::Date<int> y(1, 1, 2001);
            CPPUNIT_ASSERT(x + 366 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_plus3 () {
        try {
            const Date::Date<int> x(24, 3, 1777);
            const Date::Date<int> y(20, 1, 2021);
            CPPUNIT_ASSERT(x + 89056 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}*/


    // ---------------
    // test_plus_equal
    // ---------------

   /* void test_plus_equal () {
        try {
            Date::Date<int> x(1, 1, 1600);
            Date::Date<int> y(6, 1, 1600);
            CPPUNIT_ASSERT((x += 5) == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}*/

    void test_plus_equal2 () {
        try {
            Date::Date<int> x(1, 1, 1600);
            Date::Date<int> y(1, 1, 1600);
            CPPUNIT_ASSERT((x += (-1)) == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(true);}}

    // ----------------
    // test_minus_equal
    // ----------------

    void test_minus_equal () {
        try {
            Date::Date<int> x(1, 1, 1600);
            Date::Date<int> y(1, 1, 1600);
            CPPUNIT_ASSERT((x -= 5) == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(true);}}

 /*   void test_minus_equal2 () {
        try {
            Date::Date<int> x(1, 1, 1600);
            Date::Date<int> y(2, 1, 1600);
            CPPUNIT_ASSERT((x -= (-1)) == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}*/


    // ----------
    // test_minus
    // ----------

    /*void test_minus () {
        try {
            const Date::Date<int> x(1, 1, 2000);
            const Date::Date<int> y(1, 1, 2001);
            CPPUNIT_ASSERT(y - 366 == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}*/

    void test_minus2 () {
        try {
            const Date::Date<int> x(1, 1, 2000);
            const Date::Date<int> y(1, 1, 2001);
            CPPUNIT_ASSERT(y - x == 366);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    /*void test_minus3 () {
        try {
            const Date::Date<int> x(4, 5, 2000);
            const Date::Date<int> y(9, 7, 1842);
            CPPUNIT_ASSERT(x - 57643 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}*/

    void test_minus4 () {
        try {
            const Date::Date<int> x(29, 2, 2000);
            const Date::Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(x - y == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // -----------
    // test_output
    // -----------

    void test_output () {
        try {
            const Date::Date<int> x(16, 6, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Jun 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output2 () {
        try {
            const Date::Date<int> x(10, 7, 1986);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "10 Jul 1986");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output3 () {
        try {
            const Date::Date<int> x(25, 12, 1648);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "25 Dec 1648");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output4 () {
        try {
            const Date::Date<int> x(1, 1, 1834);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "1 Jan 1834");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------------
    // test_leap_year
    // --------------

    void test_leap_year () {
        try {
            CPPUNIT_ASSERT( Date::Date<int>(1, 1, 2000).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year2 () {
        try {
            CPPUNIT_ASSERT( !(Date::Date<int>(1, 1, 1700).leap_year()));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year3 () {
        try {
            CPPUNIT_ASSERT( Date::Date<int>(1, 1, 2048).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year4 () {
        try {
            CPPUNIT_ASSERT( Date::Date<int>(1, 1, 1600).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year5 () {
        try {
            CPPUNIT_ASSERT( Date::Date<int>(1, 1, 1604).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // *****************************************
    // Begin testing non-standard custom methods
    // *****************************************

    // ------------
    // test_to_days
    // ------------

    void test_to_days () {
        try {
            Date::Date<int> x(1, 1, 1600);
            CPPUNIT_ASSERT(x.to_days() == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_to_days2 () {
        try {
            Date::Date<int> x(29, 2, 2000);
            CPPUNIT_ASSERT(x.to_days() == 146156);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_to_days3 () {
        try {
            Date::Date<int> x(29, 2, 2900);
            CPPUNIT_ASSERT(x.to_days() == 474875);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(true);}}

/*    void test_to_days4 () {
        try {
            Date::Date<int> x(28, 2, 2900);
            CPPUNIT_ASSERT(x.to_days() == 474874);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
*/


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDate);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);
    CPPUNIT_TEST(test_constructor4);
    CPPUNIT_TEST(test_constructor5);

    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_equal_to2);
    CPPUNIT_TEST(test_equal_to3);

    CPPUNIT_TEST(test_less);
    CPPUNIT_TEST(test_less2);
    CPPUNIT_TEST(test_less3);

   // CPPUNIT_TEST(test_plus);
   // CPPUNIT_TEST(test_plus3);

 //   CPPUNIT_TEST(test_plus_equal);
    CPPUNIT_TEST(test_plus_equal2);

  //  CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus2);
 //   CPPUNIT_TEST(test_minus3);
    CPPUNIT_TEST(test_minus4);

    CPPUNIT_TEST(test_minus_equal);
  //  CPPUNIT_TEST(test_minus_equal2);

    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_output2);
    CPPUNIT_TEST(test_output3);
    CPPUNIT_TEST(test_output4);

    CPPUNIT_TEST(test_leap_year);
    CPPUNIT_TEST(test_leap_year2);
    CPPUNIT_TEST(test_leap_year3);
    CPPUNIT_TEST(test_leap_year4);
    CPPUNIT_TEST(test_leap_year5);

    // **************************************
    // Calls for non-standard tests are below
    // **************************************

    CPPUNIT_TEST(test_to_days);
    CPPUNIT_TEST(test_to_days2);
    CPPUNIT_TEST(test_to_days3);
    //CPPUNIT_TEST(test_to_days4);

    CPPUNIT_TEST_SUITE_END();};

#endif // TestDate::Date<int>_h


