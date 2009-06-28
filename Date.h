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
#include <string>
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
        
         static const std::string months[] = 
         {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
         //number of days on each month
        static const int ndiem[] =   {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        //total of days after each month
        static const int tdaem[] =  {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
        //total of days after each month in leap years
    static const int tdaemil[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
        
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
    	T day;
        T month;
        Month::Month mon;
        T year;
        T epoch; // starts from 1 1 1600
    private:
        // -----
        // valid
        // -----

        /**
         ** this method will be used to check whether
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

            year = 1600;
            T tempDays = days;
            if(tempDays>=146097){
             year += 400 * (tempDays/146097);
              tempDays %= 146097;
              } 
                          
            if(tempDays>=36525){
            year += tempDays/36525 * 100; 
            tempDays %= 36525;
            }             
            if(tempDays>=1461){
            year +=  (std::min(24,(tempDays/1461))) * 4;
            tempDays %= 1461;
            }
            
             if(tempDays<=366) {}
            else{
                tempDays -= 366; // reducing the leap year
            	year +=  (tempDays/365) + 1;  // adding the leap year + remaining years
            	}
            
             day = 1;
             month = -1; 
             if(leapyear(year)){
            	 if(tempDays>365){
            		 tempDays = 30;
            		 month = 11;
            		 --year;
            	 }
            	 else if(tempDays==365)
            	 { 
            		 tempDays = 30;
            		 month = 11;
            	 }
            	 else{
            		 for(int i = 0; i < 12; i++)
            		 {
            			 if(tempDays >= (tdaemil[i]) && tempDays < (tdaemil[i+1]))
            			 {
            				 tempDays -= tdaemil[i];
            				 month = i;
            			 }

            		 }
            	 }
            	 day = ++tempDays;
             }
             else
             {
            	 if(tempDays==365)
            	 { 
            		 tempDays = 31;
            		 month = 11;
            		 --year;
            	 }
            	 else{
            		 while(tempDays>365){
            			 tempDays-= 365; }
            		 if(tempDays==365)
            		 { 
            			 tempDays = 31;
            			 month = 11;
            			 --year;
            		 }
            		 else{
            			 for(int i = 0; i < 12; i++)
            			 {
            				 if(tempDays >= (tdaem[i]) && tempDays < (tdaem[i+1]))
            				 {
            					 tempDays -= tdaem[i];
            					 month = i;
            				 }
            			 }
            		 }
            	 }
            	 day = tempDays;
             }
         	
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
         	T tempDays=0;
         
             int years = year - 1600;
             bool leap = false;
             
             
             if(years>=400) //400 years
             {
		  tempDays += 146097 * (years/400);
		  years %= 400;
		//  cout<<"hitting here1";
		} 
		if(years>=100) //100 years
		{
		//	cout<<"hitting here2";
		  tempDays += years/100 * 36524; 
		  years %= 100;
		} 
		if(years>=4) //4 years
		{
		  tempDays +=  (std::min(24,(years/4))) * 1461;
		  years %= 4;
		//  cout<<"hitting here3";
		}
		if(years == 0)
		  leap=true;
		else if(years==1) 
		{ 
			tempDays +=366;
		
		}
		else{ 	//more than 1 year left			
			
			tempDays +=366;
			years;
			for(int i = 0; i < 3; i++)
			{
				if(years > 1)
				{
				  --years;
				   tempDays +=365; 
				}
			}
              }
              
              
              if(leap)
              {
              	tempDays += tdaemil[month-1];
              	tempDays += day;
              	
              
              }
              else
              {
                  	tempDays += tdaem[month-1];
              	tempDays += day;
              }
              --tempDays;
            
            
            
            assert(days >= 0);
            return tempDays;}

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
        	this->day = day;
        	this->month = month;
        	this->year = year;
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
            return false;}
            }; // end of class DATE!!!
 

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
