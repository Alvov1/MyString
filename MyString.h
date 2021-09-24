#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
#include <cstring>
#include <exception>

class MyString {
    unsigned size_;
    unsigned capacity_;
    char *ptr_;

    unsigned resize(unsigned new_size);

    /* --------------- Additional task #2 --------------- */
    class bad_from_string {
        const char* info;
    public:
        explicit bad_from_string(const char* str);
        const char* what() const noexcept;
    };
    /* -------------------------------------------------- */
    /* --------------- Additional task #3 --------------- */
    class iterator {
        char* base_; /* Pointer to the beginning of the string */
    protected:
        char* ptr_;
    public:
        iterator();
        explicit iterator(char* ptr, unsigned index = 0);

        /* Prefix increment impl */
        iterator & operator++();
        /* Postfix increment impl */
        iterator operator++(int);
        /* Prefix decrement impl */
        iterator & operator--();
        /* Postfix decrement impl */
        iterator operator--(int);

        bool operator==(const iterator& it) const;
        bool operator!=(const iterator& it) const;

        char& operator*() const;

        std::pair<char*, char*> values() const;
    };
    class const_iterator : public iterator {
        using iterator::iterator; /* Using iterator constructor for const_iterator. */
    public:
        const char& operator*() const;
    };
    class reverse_iterator {
    protected:
        char* ptr_;
        char* base_;
    public:
        reverse_iterator();
        explicit reverse_iterator(char* ptr, unsigned index = 0);
        explicit reverse_iterator(const iterator& it);

        reverse_iterator & operator++();
        reverse_iterator operator++(int);
        reverse_iterator & operator--();
        reverse_iterator operator--(int);

        bool operator==(const reverse_iterator& it) const;
        bool operator!=(const reverse_iterator& it) const;

        char& operator*() const;

        std::pair<char*, char*> values() const;
    };
    class const_reverse_iterator : public reverse_iterator {
        using reverse_iterator::reverse_iterator; /* Using reverse_iterator constructor for const_reverse_iterator. */
    public:
        const char& operator*() const;
    };

//    template <MyString::iterator, typename ...>
//    auto call
    /* -------------------------------------------------- */
public:
    MyString();
    explicit MyString(const char* ptr);
    MyString(const std::initializer_list<char>& list);
    explicit MyString(const std::string& str);
    MyString(const char* ptr, unsigned count);
    MyString(unsigned count, char sym);
    MyString(const MyString& str);

    MyString operator+(const MyString& str);
    MyString operator+(const char* ptr);
    MyString operator+(const std::string& str);
    MyString operator+=(const char* ptr);
    MyString operator+=(const std::string& str);
    MyString& operator=(const char* ptr);
    MyString& operator=(const std::string& str);
    MyString& operator=(char sym);

    char operator[](int index) const;

    bool operator>(const MyString& str) const;
    bool operator<(const MyString& str) const;
    bool operator>=(const MyString& str) const;
    bool operator<=(const MyString& str) const;
    bool operator!=(const MyString& str) const;
    bool operator==(const MyString& str) const;

    char* c_str() const;
    char* data() const;
    unsigned length() const;
    unsigned size() const;
    bool empty() const;
    unsigned capacity() const;
    unsigned shrink_to_fit();
    unsigned clear(); /* Only erases characters. Capacity stays the same*/

    unsigned insert(unsigned index, unsigned count, char sym);
    unsigned insert(unsigned index, const char* ptr);
    unsigned insert(unsigned index, const char* ptr, unsigned count);
    unsigned insert(unsigned index, const std::string& str);
    unsigned insert(unsigned index, const std::string& str, unsigned count);

    unsigned insert(MyString::iterator it, unsigned count, char sym);
    unsigned insert(MyString::iterator it, const char* ptr);
    unsigned insert(MyString::iterator it, const char* ptr, unsigned count);
    unsigned insert(MyString::iterator it, const std::string& str);
    unsigned insert(MyString::iterator it, const std::string& str, unsigned count);

    unsigned erase(unsigned index, unsigned count);

    unsigned erase(MyString::iterator it, unsigned count);

    unsigned append(unsigned count, char sym);
    unsigned append(const char* ptr);
    unsigned append(const char* ptr, unsigned index, unsigned count); /* Index - number in ptr, not in MyString */
    unsigned append(const std::string& str);
    unsigned append(const std::string& str, unsigned index, unsigned count); /* Index - number in ptr, not in MyString */

    unsigned replace(unsigned index, unsigned count, const char* ptr);
    unsigned replace(unsigned index, unsigned count, const std::string& str);

    unsigned replace(MyString::iterator it, unsigned count, const char* ptr);
    unsigned replace(MyString::iterator it, unsigned count, const std::string& str);

    MyString substr(unsigned index);
    MyString substr(unsigned index, unsigned count);

    MyString substr(MyString::iterator it);
    MyString substr(MyString::iterator it, unsigned count);

    int find(const char* ptr) const;
    int find(const char* ptr, unsigned index) const;
    int find(const std::string& str) const;
    int find(const std::string& str, unsigned index) const;

    ~MyString();

    /* --------------- Additional task #2 --------------- */
    MyString(MyString&& move) noexcept;
    MyString(long value);
    MyString(double value);
    MyString& operator=(MyString&& move) noexcept;
    int* find(const char** words, unsigned count); /* Aho-Corasick Algorithm */
    char at(unsigned index);
    long to_int();
    double to_float();
    /* -------------------------------------------------- */
    /* --------------- Additional task #3 --------------- */
    iterator begin() const;
    iterator end() const;

    const_iterator cbegin() const;
    const_iterator cend() const;

    reverse_iterator rbegin() const;
    reverse_iterator rend() const;

    const_reverse_iterator rcbegin() const;
    const_reverse_iterator rcend() const;
    /* -------------------------------------------------- */
};

std::ostream& operator<<(std::ostream& os, const MyString & str);
std::istream& operator>>(std::istream& is, MyString & str);

#endif // _MYSTRING_H_
