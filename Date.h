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
        namespace Month{
        enum Month{
        	dummy, //0
        	Jan, //1
        	Feb, //2
        	Mar, //3
        	Apr, //4
        	May, //5
        	Jun, //6
        	Jul, //7
        	Aug, //8
        	Sep, //9
        	Oct, //10
        	Nov, //11
        	Dec //12
        };
        }// end namespace months

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
            	T day;
            	T month;
            	Month::Month mon;
            	int monthsNL[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
            	T year;
            	T epoch; // starts from 1 1 1600
            private:
                // -----
                // valid
                // -----
                /**
        	* this method will be used to check whether
        	* the input for the day, month and the year is valid 
                 */
                bool valid () const {
                    bool yearOk = (year >= 1600);
                   bool monthOk = (month>0 && month <= 12);
                    bool dayOk = false;
                    switch(mon){
                    case Month::Feb :
                        if(leapYear())
                    	dayOk = (day>0 && day<=29);
                    	else dayOk  = (day>0 && day<=28);
                    	break;
                    case Month::Apr :
                    case Month::Jun :
                    case Month::Sep :
                    case Month::Nov :
                    	dayOk = (day>0 && day<=30);
                    	break;
                    default:
                    	dayOk = (day>0 && day<=31);
                    }

                    return (dayOk&&monthOk&&yearOk);}
        	// -----------
                // leapyear
                // -----------
                bool leapYear() const{
                assert(year>=1600);
                bool leap = false;
                if((year%4)==0){
                      leap = true;
                     if( ((year%100)==0) && !((year%400)==0))
                     leap = false;
                }
                return leap;
                }
                
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
                    // 146 097 = num of days for every 400 yrs
                    T tempDays = days;
                    int t1 = (days/146097); // t1 is how many 400 yrs there are
                    int rem400 = (days%146097); // t2 is the remaining num of days after / 400yrs
                    //36 524 = num of days for every 100 years if it's not the 400th yrs
                    int t2 = (rem400/36524); // t3 is how many 100 yrs there are
                    int rem100 = (rem400%36524); // t4 is the remaining num of days after / 100yrs
                    //1461 = num of days for every 4 yrs
                    int t3 = (rem100/1461);
                    int rem4 = (rem100%1461);
                    int t4 = (rem4/365);
                    int rem1 = (rem4%365);
                    int realYears = t1*400 + t2*100 + t3*4 + rem4;
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
