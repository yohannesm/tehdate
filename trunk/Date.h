// ------------------------
// projects/c++/date/Date.h
// Copyright (C) 2009
// Glenn P. Downing
// ------------------------

#ifndef Date_h
#define Date_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument

// ----------
// namespaces
// ----------

namespace Date {

// ----
// Date
// ----

template <typename T>
class Date {
    private:
        // ----
        // data
        // ----

        // <your data>

    private:
        // -----
        // valid
        // -----

        /**
		 * <your documentation>
         */
        bool valid () const {
            // <your code>
            return true;}

        // -----------
        // constructor
        // -----------

        /**
         * O(1)   in space
         * O(1)   in time
         * @param days >= 0
         * Date(0) -> 1 Jan 1600
         * you can loop through an array of month days
         */
        Date (const T& days) {
            assert(days >= 0);
            // <your code>
            if (!valid())
                throw std::invalid_argument("Date::Date()");}

        // -------
        // to_days
        // -------

        /**
         * O(1)    in space
         * O(1)    in time
         * @return the number of days since 1 Jan 1600, >= 0
         * 1 Jan 1600 -> 0
         */
        T to_days () const {
            T days = 0;
            // <your code>
            assert(days >= 0);
            return days;}

    public:
        // -----------
        // constructor
        // -----------

        /**
         * O(1)    in space
         * O(1)    in time
         * @param  day   >= 1 && <= 31
         * @param  month >= 1 && <= 12
         * @param  year  >= 1600
         * @throws std::invalid_argument if the resulting date is invalid
         */
        Date (const T& day, const T& month, const T& year) {
            // <your code>
            if (!valid())
                throw std::invalid_argument("Date::Date()");}

        // Default copy, destructor, and copy assignment.
        // Date (const Date&);
        // ~Date ();
        // Date& operator = (const Date&);

        // -----------
        // operator +=
        // -----------

        /**
		 * <your documentation>
         * @param  days the number of days to add (may be negative!)
         * @return the date resulting from adding days
         * @throws std::invalid_argument if the resulting date precedes 1 Jan 1600
         */
        Date& operator += (const T& days) {
            // <your code>
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
		 * <your documentation>
         * @param  days the number of days to subtract (may be negative!)
         * @return the date resulting from subtracting days
         * @throws std::invalid_argument if the resulting date precedes 1 Jan 1600
         */
        Date& operator -= (const T& days) {
            // <your code>
            return *this;}

        // ---------
        // leap_year
        // ---------

        /**
		 * <your documentation>
         */
        bool leap_year () const {
            // <your code>
            return false;}};

// -----------
// operator ==
// -----------

/**
 * <your documentation>
 */
template <typename T>
bool operator == (const Date<T>& lhs, const Date<T>& rhs) {
	// <your code>
	return false;}

// ----------
// operator <
// ----------

/**
 * <your documentation>
 */
template <typename T>
bool operator < (const Date<T>& lhs, const Date<T>& rhs) {
	// <your code>
	return false;}

// ----------
// operator +
// ----------

/**
 * <your documentation>
 * @throws std::invalid_argument if the resulting date precedes 1 Jan 1600
 */
template <typename T>
Date<T> operator + (Date<T> lhs, const T& rhs) {
	return lhs += rhs;}

// ----------
// operator -
// ----------

/**
 * <your documentation>
 * @throws std::invalid_argument if the resulting date precedes 1 Jan 1600
 */
template <typename T>
Date<T> operator - (Date<T> lhs, const T& rhs) {
	return lhs -= rhs;}

/**
 * <your documentation>
 * @return the number of days between the dates (lhs - rhs)
 */
template <typename T>
T operator - (const Date<T>& lhs, const Date<T>& rhs) {
	// <your code>
	return 0;}

// -----------
// operator <<
// -----------

/**
 * O(1)    in space
 * O(1)    in time
 * @param  lhs an ostream
 * @param  rhs a date
 * @return the ostream
 * output a string representation of the date (e.g. "3 Feb 2008")
 * you can loop through an array of month names
 */
template <typename T>
std::ostream& operator << (std::ostream& lhs, const Date<T>& rhs) {
	// <your code>
	return lhs << "1 Jan 2008";}

} // Date

#endif // Date_h
