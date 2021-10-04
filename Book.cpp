#include <cmath>                                                      // abs(), pow()
#include <iomanip>                                                    // quoted()
#include <iostream>
#include <string>
#include <type_traits>                                                // is_floating_point_v, common_type_t
#include <utility>                                                    // move()

#include "Book.hpp"

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Default and Conversion Constructor
Book::Book(std::string title, std::string author, std::string isbn, double price)
///////////////////////// TO-DO (2) //////////////////////////////
{
    Book();
}
/////////////////////// END-TO-DO (2) ////////////////////////////




// Copy constructor
Book::Book(Book const& other)
///////////////////////// TO-DO (3) //////////////////////////////
{
    _title = other._title;
    _author = other._author;
    _isbn = other._isbn;
    _price = other._price;
}
/////////////////////// END-TO-DO (3) ////////////////////////////




// Copy Assignment Operator
Book& Book::operator=(Book const& rhs)&
///////////////////////// TO-DO (5) //////////////////////////////
{
    _title = rhs._title;
    _author = rhs._author;
    _isbn = rhs._isbn;
    _price = rhs._price;
}
/////////////////////// END-TO-DO (5) ////////////////////////////



// Destructor
Book::~Book() noexcept
///////////////////////// TO-DO (7) //////////////////////////////
{
    _title.clear();
    _author.clear();
    _isbn.clear();
    //price would clear when object goes out of scope
}
/////////////////////// END-TO-DO (7) ////////////////////////////








/*******************************************************************************
**  Accessors
*******************************************************************************/

// isbn() const
std::string const& Book::isbn() const&
{
    ///////////////////////// TO-DO (8) //////////////////////////////
    return isbn();
    /////////////////////// END-TO-DO (8) ////////////////////////////
}




// title() const
std::string const& Book::title() const&
{
    ///////////////////////// TO-DO (9) //////////////////////////////
    return title();
    /////////////////////// END-TO-DO (9) ////////////////////////////
}




// author() const
std::string const& Book::author() const&
{
    ///////////////////////// TO-DO (10) //////////////////////////////
    return author();
    /////////////////////// END-TO-DO (10) ////////////////////////////
}



// price() const
double Book::price() const&
{
    ///////////////////////// TO-DO (11) //////////////////////////////
    return price();
    /////////////////////// END-TO-DO (11) ////////////////////////////
}




// isbn()
std::string Book::isbn()&&
{
    ///////////////////////// TO-DO (12) //////////////////////////////
    return isbn();
    /////////////////////// END-TO-DO (12) ////////////////////////////
}




// title()
std::string Book::title()&&
{
    ///////////////////////// TO-DO (13) //////////////////////////////
    return title();
    /////////////////////// END-TO-DO (13) ////////////////////////////
}




// author()
std::string Book::author()&&
{
    ///////////////////////// TO-DO (14) //////////////////////////////
    return author();
    /////////////////////// END-TO-DO (14) ////////////////////////////
}








/*******************************************************************************
**  Modifiers
*******************************************************************************/

// isbn()
Book& Book::isbn(std::string newIsbn)&
{
    ///////////////////////// TO-DO (15) //////////////////////////////
    _isbn = newIsbn;
    /////////////////////// END-TO-DO (15) ////////////////////////////
}




// title()
Book& Book::title(std::string newTitle)&
{
    ///////////////////////// TO-DO (16) //////////////////////////////
    _title = newTitle;
    /////////////////////// END-TO-DO (16) ////////////////////////////
}




// author()
Book& Book::author(std::string newAuthor)&
{
    ///////////////////////// TO-DO (17) //////////////////////////////
    _author = newAuthor;
    /////////////////////// END-TO-DO (17) ////////////////////////////
}




// price()
Book& Book::price(double newPrice)&
{
    ///////////////////////// TO-DO (18) //////////////////////////////
    _price = newPrice;
    /////////////////////// END-TO-DO (18) ////////////////////////////
}



/*******************************************************************************
**  Relational Operators
*******************************************************************************/


// operator==
bool Book::operator==(const Book& rhs) const noexcept
{
    // All attributes must be equal for the two books to be equal to the other.  This can be done in any order, so put the quickest
    // and then the most likely to be different first.

    ///////////////////////// TO-DO (20) //////////////////////////////
    if (price() == rhs.price())
    {
        return true;
    }
    /////////////////////// END-TO-DO (20) ////////////////////////////
}

// operator!=
bool Book::operator!=(const Book& rhs) const noexcept
{
    // Two books are unequal if any of their attributes are unequal.

    ///////////////////////// TO-DO (20) //////////////////////////////
    if (price() != rhs.price())
    {
        return true;
    }


    /////////////////////// END-TO-DO (20) ////////////////////////////
}

// operator<
bool Book::operator<(const Book& rhs) const noexcept
{
    // Books are ordered (sorted) by ISBN, author, title, then price.

    ///////////////////////// TO-DO (20) //////////////////////////////
    if (isbn() < rhs.isbn())
    {
        return true;
    }

    if (author() < rhs.author())
    {
        return true;
    }
    /////////////////////// END-TO-DO (20) ////////////////////////////
}

// operator<=
bool Book::operator<=(const Book& rhs) const noexcept
{
    // Books are ordered (sorted) by ISBN, author, title, then price.

    ///////////////////////// TO-DO (20) //////////////////////////////
    if (isbn() <= rhs.isbn())
    {
        return true;
    }
    /////////////////////// END-TO-DO (20) ////////////////////////////
}

// operator>
bool Book::operator>(const Book& rhs) const noexcept
{
    // Books are ordered (sorted) by ISBN, author, title, then price.

    ///////////////////////// TO-DO (20) //////////////////////////////
    if (isbn() > rhs.isbn())
    {
        return true;
    }
    /////////////////////// END-TO-DO (20) ////////////////////////////
}

// operator>=
bool Book::operator>=(const Book& rhs) const noexcept
{
    // Books are ordered (sorted) by ISBN, author, title, then price.

    ///////////////////////// TO-DO (20) //////////////////////////////
    if (isbn() >= rhs.isbn())
    {
        return true;
    }
    /////////////////////// END-TO-DO (20) ////////////////////////////
}







/*******************************************************************************
**  Insertion and Extraction Operators
*******************************************************************************/

// operator>>
std::istream& operator>>(std::istream& stream, Book& book)
{
    ///////////////////////// TO-DO (21) //////////////////////////////
      /// A lot can go wrong when reading from streams - no permission, wrong types, end of file, etc. Minimal exception guarantee says
      /// there should be no side affects if an error or exception occurs, so let's do our work in a local object and move it into place
      /// at the end if all goes well.
      ///
      /// This function should be symmetrical with operator<< below.  Read what your write, and write what you read
      ///
      ///
      /// Assume fields are separated by commas and string attributes are enclosed with double quotes.  For example:
      ///    ISBN             | Title                 | Author             | Price
      ///    -----------------+-----------------------+--------------------+-----
      ///    "9789998287532",   "Over in the Meadow",   "Ezra Jack Keats",   91.11
      ///
      ///
      /// Hint:  Use std::quoted to read and write quoted strings.  See
      ///        1) https://en.cppreference.com/w/cpp/io/manip/quoted
      ///        2) https://www.youtube.com/watch?v=Mu-GUZuU31A
      std::cout << "ISBN" << std::setfill(' ') << "|" << "Title" << std::setfill(' ') << "|" << "Author" << std::setfill(' ') << "|" << "Price";
      std::cout << "-----------------+-----------------------+--------------------+-----";
      std::cin >> title() >> author() >> isbn() >> price() ;
      std::cout << std::quoted(isbn()) << ", " << std::quoted(title()) << ", " << std::quoted(author()) << ", " << price();
      //someone dude said it's a while loop, but it doesn't make sense since eof stream require the fstream header :()
      while (!stream.eof()) {
        code here
      }
      return stream;
    /////////////////////// END-TO-DO (21) ////////////////////////////
}




// operator<<
std::ostream& operator<<(std::ostream& stream, const Book& book)
{
    ///////////////////////// TO-DO (22) //////////////////////////////
      /// This function should be symmetrical with operator>> above.  Read what your write, and write what you read

    //cout << setfill('-') << setw(WIDTH) << right << '-' << setfill(' ') << endl;
    std::cout << "ISBN" << std::setfill(' ') << "|" << "Title" << std::setfill(' ') << "|" << "Author" << std::setfill(' ') << "|" << "Price";
    std::cout << "-----------------+-----------------------+--------------------+-----";
    std::cin >> title() >> author() >> isbn() >> price() ;
    std::cout << std::quoted(isbn()) << ", " << std::quoted(title()) << ", " << std::quoted(author()) << ", " << price();

      /////////////////////// END-TO-DO (22) ////////////////////////////
}
