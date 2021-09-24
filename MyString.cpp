#include "MyString.h"

MyString::MyString() : size_(0), capacity_(0), ptr_(nullptr) {}
MyString::MyString(const char* ptr) : MyString(ptr, (ptr != nullptr ? strlen(ptr) : 0)){}
MyString::MyString(const std::string& str) : MyString(str.c_str(), (str.c_str() != nullptr ? strlen(str.c_str()) : 0)) {}
MyString::MyString(const MyString& str) : MyString(str.c_str(), (str.c_str() != nullptr ? strlen(str.c_str()) : 0)) {}
MyString::MyString(const std::initializer_list<char>& list) : size_(0), capacity_(0), ptr_(nullptr){
    if(list.size() > 0){
        capacity_ = list.size() + 1;
        ptr_ = new char[capacity_];
        for (char i : list)
            ptr_[size_++] = i;
        ptr_[size_] = 0;
    }
}
MyString::MyString(const char* ptr, unsigned int count) : size_(0), capacity_(0), ptr_(nullptr){
    if(ptr != nullptr && (count != 0 || strlen(ptr) != 0)) {
        size_ = (count < strlen(ptr) ? count : strlen(ptr));
        capacity_ = size_ + 1;
        ptr_ = new char[capacity_];
        strncpy(ptr_, ptr, size_);
        ptr_[size_] = 0;
    }
}
MyString::MyString(unsigned int count, char sym) : size_(0), capacity_(0), ptr_(nullptr) {
    if(sym != static_cast<char>(0)){
        size_ = count;
        capacity_ = size_ + 1;
        ptr_ = new char[capacity_];
        for (auto i = 0; i < size_; ++i)
            ptr_[i] = sym;
        ptr_[size_] = 0;
    }
}

MyString MyString::operator+(const char* ptr) {
    if(ptr != nullptr && strlen(ptr) != 0) {
        auto *temp = new char[capacity_ + strlen(ptr)];
        strncpy(temp, ptr_, size_);
        strncpy(temp + size_, ptr, strlen(ptr));
        temp[size_ + strlen(ptr)] = 0;
        return MyString(temp);
    } else return MyString(ptr_);
}
MyString MyString::operator+(const MyString& str) {
    return this->operator+(str.c_str());
}
MyString MyString::operator+(const std::string& str) {
    return this->operator+(str.c_str());
}
MyString MyString::operator+=(const char* ptr) {
    if(ptr != nullptr && strlen(ptr)) {
        auto temp_size = size_;
        this->resize(size_ + strlen(ptr));
        strncpy(ptr_ + temp_size, ptr, strlen(ptr));
        ptr_[size_] = 0;
    }
    return *this;
}
MyString MyString::operator+=(const std::string& str) {
    return this->operator+=(str.c_str());
}
MyString& MyString::operator=(const char* ptr) {
    if(ptr != nullptr && strlen(ptr) != 0) {
        size_ = strlen(ptr);
        capacity_ = size_ + 1;
        delete[] ptr_;
        ptr_ = new char[capacity_];
        strncpy(ptr_, ptr, size_);
        ptr_[size_] = 0;
    } else {
        delete [] ptr_;
        size_ = 0;
        capacity_ = 0;
    }
    return *this;
}
MyString& MyString::operator=(const std::string& str) {
    this->operator=(str.c_str());
    return *this;
}
MyString& MyString::operator=(char sym) {
    if(sym != static_cast<char>(0)){
        size_ = 1;
        capacity_ = 2;
        delete[] ptr_;
        ptr_ = new char[2];
        *ptr_ = sym;
        *(ptr_ + 1) = 0;
    } else this->operator=(nullptr);
    return *this;
}

char MyString::operator[](int index) const {
    if (index < size_) {
        return ptr_[index];
    } else return char();
}

bool MyString::operator>(const MyString& str) const {
    if(ptr_ == nullptr && str.size() != 0)
        return false;
    if(str.size() != 0 && str.c_str() != nullptr)
        return strcmp(ptr_, str.c_str()) > 0;
    else
        return ptr_ != nullptr;
}
bool MyString::operator<(const MyString& str) const {
    if(ptr_ == nullptr && str.size() != 0)
        return true;
    if(str.size() != 0 && str.c_str() != nullptr)
        return strcmp(ptr_, str.c_str()) < 0;
    else
        return false;
}
bool MyString::operator>=(const MyString& str) const {
    if (this->operator==(str))
        return true;
    else
        return this->operator>(str);
}
bool MyString::operator<=(const MyString& str) const {
    if (this->operator==(str))
        return true;
    else
        return this->operator<(str);
}
bool MyString::operator!=(const MyString& str) const {
    return !(this->operator==(str));
}
bool MyString::operator==(const MyString& str) const {
    return (!this->operator<(str) && !this->operator>(str));
}

char* MyString::c_str() const {
    return this->ptr_;
}
char* MyString::data() const {
    return this->ptr_;
}
unsigned MyString::length() const {
    return this->size_;
}
unsigned MyString::size() const {
    return this->size_;
}
bool MyString::empty() const {
    return this->size_ == 0;
}
unsigned MyString::capacity() const {
    return this->capacity_;
}
unsigned MyString::shrink_to_fit() {
    if (capacity_ > size_ + 1) {
        capacity_ = size_ + 1;
        auto* temp = new char[capacity_];
        strncpy(temp, ptr_, size_);
        temp[size_] = 0;
        delete[] ptr_;
        ptr_ = temp;
        return size_;
    }
    else return 1;
}
unsigned MyString::clear() {
    size_ = 0;
    if (ptr_ != nullptr)
        ptr_[0] = 0;
    return 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    for(char i : str)
        os << i;
    return os;
}
std::istream& operator>>(std::istream& is, MyString& str) {
    str.clear();
    str.shrink_to_fit();
    char in = 0;
    is.get(in);
    while (in != '\n' && in != '\r' && !is.eof()) {
        str.append(1, in);
        is.get(in);
    }
    return is;
}

unsigned MyString::insert(unsigned int index, unsigned int count, char sym) {
    if (count != 0) {
        if(index < size_){
            auto *temp = new char[capacity_ + count];
            strncpy(temp, ptr_, index);
            for (auto i = 0; i < count; ++i)
                temp[index + i] = sym;
            strncpy(temp + index + count, ptr_ + index, size_ - index);
            size_ += count;
            capacity_ += count;
            temp[size_] = 0;

            delete[] ptr_;
            ptr_ = temp;
            return size_;
        } else throw std::out_of_range("Index value is greater than size of the string");
    } else return 1;
}
unsigned MyString::insert(unsigned int index, const char* ptr, unsigned int count) {
    if (ptr != nullptr && strlen(ptr) >= count && count != 0) {
        if(index < size_){
            auto *temp = new char[capacity_ + count];
            strncpy(temp, ptr_, index);
            strncpy(temp + index, ptr, count);
            strncpy(temp + index + count, ptr_ + index, size_ - index);
            size_ += count;
            capacity_ += count;
            temp[size_] = 0;
            delete[] ptr_;
            ptr_ = temp;
            return size_;
        } else throw std::out_of_range("Index value is greater than size of the string");
    }
    else return 1;
}
unsigned MyString::insert(unsigned int index, const char* ptr) {
    if(ptr != nullptr)
        return this->insert(index, ptr, strlen(ptr));
    else
        return 1;
}
unsigned MyString::insert(unsigned int index, const std::string& str) {
    if(str.c_str() != nullptr)
        return this->insert(index, str.c_str(), strlen(str.c_str()));
    else
        return 1;
}
unsigned MyString::insert(unsigned int index, const std::string& str, unsigned int count) {
    return this->insert(index, str.c_str(), count);
}

unsigned MyString::erase(unsigned int index, unsigned int count) {
    if (index >= size_)
        throw std::out_of_range("Index value is greater than size of the string");

    for (auto i = index; *(ptr_ + i) != 0 && i < index + count; ++i)
        *(ptr_ + i) = 0;
    if (*(ptr_ + index + count) != 0)
        for (auto i = 0; *(ptr_ + i) != 0; ++i) {
            *(ptr_ + index + i) = *(ptr_ + index + count + i);
            *(ptr_ + index + count + i) = 0;
        }
    size_ -= count;
    return 0;
}

unsigned MyString::append(unsigned int count, char sym) {
    if(count != 0 && sym != static_cast<char>(0)){
        auto temp_size = size_;
        this->resize(size_ + count);
        for (auto i = 0; i < count; ++i)
            ptr_[temp_size + i] = sym;
        ptr_[size_] = 0;
    }
    return size_;
}
unsigned MyString::append(const char* ptr, unsigned index, unsigned count) {
    if(ptr != nullptr){
        auto temp_size = size_;
        auto adding_size = (index + count < strlen(ptr) ? count : strlen(ptr));
        this->resize(size_ + adding_size);
        strncpy(ptr_ + temp_size, ptr + index, adding_size);
        ptr_[size_] = 0;
    }
    return size_;
}
unsigned MyString::append(const char* ptr) {
    if(ptr != nullptr)
        return this->append(ptr, 0, strlen(ptr));
    else
        return 1;
}
unsigned MyString::append(const std::string& str) {
    if(str.c_str() != nullptr)
        return this->append(str.c_str(), 0, strlen(str.c_str()));
    else
        return 1;
}
unsigned MyString::append(const std::string& str, unsigned int index, unsigned int count) {
    return this->append(str.c_str(), index, count);
}

unsigned MyString::replace(unsigned int index, unsigned int count, const char* ptr) {
    if (index >= size_ || index + count >= size_)
        throw std::out_of_range("String is not long enough");
    if (ptr == nullptr)
        return -1;
    this->resize(size_ - count + strlen(ptr));
    for (auto i = 0; i < strlen(ptr) - count; ++i) /* Shifting string after the replacement part */
        *(ptr_ + i + index + strlen(ptr)) = *(ptr_ + i + index + count);

    strncpy(ptr_ + index, ptr, strlen(ptr));
    return 0;
}
unsigned MyString::replace(unsigned int index, unsigned int count, const std::string& str) {
    return this->replace(index, count, str.c_str());
}

MyString MyString::substr(unsigned int index, unsigned int count) {
    if (index >= size_ || index + count > size_)
        throw std::out_of_range("String is not long enough");
    auto* temp = new char[count + 1];
    strncpy(temp, ptr_ + index, count);
    temp[count] = 0;
    return MyString(temp);
}
MyString MyString::substr(unsigned int index) {
    return this->substr(index, size_ - index);
}

int MyString::find(const char* ptr, unsigned int index) const {
    if (ptr != nullptr && strlen(ptr) != 0 && strstr(ptr_ + index, ptr) != nullptr)
        return static_cast<int>(strstr(ptr_ + index, ptr) - ptr_);
    else
        return -1;
}
int MyString::find(const char* ptr) const {
    return find(ptr, 0);
}
int MyString::find(const std::string& str) const {
    return find(str.c_str(), 0);
}
int MyString::find(const std::string& str, unsigned int index) const {
    return this->find(str.c_str(), index);
}

/* New_size - size for actual characters. Not new capacity */
unsigned MyString::resize(unsigned int new_size) {
    if (new_size > size_) {
        auto* temp = new char[new_size + 1];
        if(ptr_ != nullptr)
            strncpy(temp, ptr_, size_);
        temp[size_] = 0;
        size_ = new_size;
        capacity_ = new_size + 1;   /* Size stays the same. */
        delete[] ptr_;
        ptr_ = temp;
        return new_size;
    }
    else return 1;
}

MyString::~MyString() {
    delete[] ptr_;
    size_ = 0;
    capacity_ = 0;
}
/* --------------- Additional task #2 --------------- */
MyString::bad_from_string::bad_from_string(const char* str) : info(str) {}
const char* MyString::bad_from_string::what() const noexcept {
    return info;
}
MyString::MyString(MyString&& move) noexcept {
    ptr_ = move.ptr_;
    move.ptr_ = nullptr;

    size_ = move.size_;
    move.size_ = 0;

    capacity_ = move.capacity_;
    move.capacity_ = 0;
}
MyString& MyString::operator=(MyString&& move) noexcept {
    auto* temp = ptr_;
    ptr_ = move.ptr_;
    move.ptr_ = temp;

    auto size = size_;
    size_ = move.size_;
    move.size_ = size;

    auto capacity = capacity_;
    capacity_ = move.capacity_;
    move.capacity_ = capacity;
    return *this;
}
int* MyString::find(const char** words, unsigned count) {
    if(count > 50)
        throw std::logic_error("Too much words in pointer. Limit is 50.");
    static const int MAXS = 50;
    static const int MAXC = 26;

    static int out[MAXS];
    static int f[MAXS];
    static int g[MAXS][MAXC];

    static class Queue {
        int *store; /* Queue itself */
        unsigned size_; /* Number of elements in queue */
        unsigned space_; /* Maximum number of elements, which can be stored in queue */
    public:
        Queue(unsigned max_size) : store(new int[max_size]), size_(0), space_(max_size) {};

        void push(int value) {
            if (size_ == space_)
                throw std::length_error("There is no more space in queue");

            store[size_++] = value;
        }

        int pop() {
            if (size_ > 0) {
                int result = store[0];

                for (auto i = 0; i < size_; ++i)
                    store[i] = store[i + 1];
                size_--;

                return result;
            } else throw std::logic_error("There is no elements in queue (front())");
        }

        int front() {
            if (size_ > 0) {
                return store[0];
            } else throw std::logic_error("There is no elements in queue (front())");
        }

        void free() {
            for (auto i = 0; i < space_; ++i)
                store[i] = -1;
            size_ = 0;
        }

        unsigned size() const {
            return size_;
        }

    } queue(MAXC);
    class result {
        int *ptr;
        unsigned size;
    public:
        result(unsigned size) : ptr(new int[size]), size(size) {
            for (auto i = 0; i < size; ++i)
                ptr[i] = -1;
        };

        int *results() const {
            return ptr;
        }

        void push(int value, unsigned index) {
            if (index < size)
                ptr[index] = value;
        }
    } results(count);
    queue.free();

    memset(out, 0, sizeof out);
    memset(g, -1, sizeof g);
    memset(f, -1, sizeof f);

    int states = 1;
    for (int i = 0; i < count; ++i) {
        const char* word = words[i];
        int curr_state = 0;
        for (int j = 0; j < strlen(word); ++j) {
            int ch = word[j] - 'a';
            if (g[curr_state][ch] == -1)
                g[curr_state][ch] = states++;

            curr_state = g[curr_state][ch];
        }
        out[curr_state] |= (1 << i);
    }
    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;

    for (int ch = 0; ch < MAXC; ++ch) {
        if (g[0][ch] != 0) {
            f[g[0][ch]] = 0;
            queue.push(g[0][ch]);
        }
    }
    while (queue.size()) {
        int state = queue.front();
        queue.pop();
        for (int ch = 0; ch <= MAXC; ++ch) {
            if (g[state][ch] != -1) {
                int failure = f[state];

                while (g[failure][ch] == -1)
                    failure = f[failure];

                failure = g[failure][ch];
                f[g[state][ch]] = failure;
                out[g[state][ch]] |= out[failure];

                queue.push(g[state][ch]);
            }
        }
    }

    int currentState = 0;
    for (int i = 0; i < strlen(ptr_); ++i) {
        int answer = currentState;
        int ch = ptr_[i] - 'a';
        while (g[answer][ch] == -1)
            answer = f[answer];

        currentState = g[answer][ch];

        if (out[currentState] == 0)
            continue;

        for (int j = 0; j < count; ++j)
            if (out[currentState] & (1 << j))
                results.push(i - strlen(words[j]) + 1, j);
    }
    return results.results();
}
char MyString::at(unsigned index) {
    if (index < size_)
        return *(ptr_ + index);
    else
        throw std::out_of_range("String index is out of range");
}
MyString::MyString(long value) : size_(0), capacity_(100), ptr_(new char[100]) {
    sprintf(ptr_, "%ld", value);
    size_ = strlen(ptr_);
    this->shrink_to_fit();
}
MyString::MyString(double value) : size_(0), capacity_(100), ptr_(new char[100]) {
    sprintf(ptr_, "%f", value);
    size_ = strlen(ptr_);
    this->shrink_to_fit();
}
long MyString::to_int() {
    long result = strtol(ptr_, nullptr, 10);

    if(result == 0)
        throw bad_from_string("Error in conversion to integer");
    return result;
}
double MyString::to_float() {
    double result = strtod(ptr_, nullptr);

    if(result == 0.0)
        throw bad_from_string("Error in conversion to double");
    return result;
}
/* -------------------------------------------------- */
/* --------------- Additional task #3 --------------- */
/* -------------------- Iterator -------------------- */
MyString::iterator::iterator() : ptr_(nullptr), base_(nullptr) {}
MyString::iterator::iterator(char* ptr, unsigned int index) : ptr_(ptr), base_(ptr) {
    if(ptr_ != nullptr)
        ptr_ += index;
}
MyString::iterator& MyString::iterator::operator++() {
    /* (Ptr_ == nullptr) means that this iterator is pointing on the cell before the beginning of the string. */
    /* (*ptr_ == 0) means that this iterator is pointing to the cell after the last character in the string. */
    if (ptr_ != nullptr) {
        if (*ptr_ != 0)
            ++ptr_;
    }
    else
        ptr_ = base_;
    return *this;
}
MyString::iterator MyString::iterator::operator++(int) {
    iterator temp = *this;
    ++* this;
    return temp;
}
MyString::iterator& MyString::iterator::operator--() {
    if (ptr_ != nullptr && base_ != nullptr && ptr_ > base_) /* There is no option for moving the c-pointer before the beginning. */
        --ptr_;                                             /* Let's do this : iterator on char BEFORE the beginning of the string  */
    else                                                    /* will have nullptr in ptr_ field and only pointer in the base_ field. */
        ptr_ = nullptr;
    return *this;
}
MyString::iterator MyString::iterator::operator--(int) {
    iterator temp = *this;
    --* this;
    return temp;
}
bool MyString::iterator::operator==(const MyString::iterator& it) const {
    return it.ptr_ == ptr_ && it.base_ == base_;
}
bool MyString::iterator::operator!=(const MyString::iterator& it) const {
    return !(this->operator==(it));
}
char& MyString::iterator::operator*() const {
    if (ptr_ == nullptr)
        throw std::out_of_range("Iterator is pointing on element before the beginning of the string");
    else
    if (*ptr_ == 0)
        throw std::out_of_range("Iterator is pointing on element after the last character of the string");
    else
        return *ptr_;
}
const char &MyString::const_iterator::operator*() const {
    if (ptr_ == nullptr)
        throw std::out_of_range("Iterator is pointing on element before the beginning of the string");
    else
    if (*ptr_ == 0)
        throw std::out_of_range("Iterator is pointing on element after the last character of the string");
    else
        return *ptr_;
}
std::pair<char *, char *> MyString::iterator::values() const {
    return std::pair<char *, char *>(ptr_, base_);
}

MyString::iterator MyString::begin() const {
    return MyString::iterator(ptr_);
}
MyString::iterator MyString::end() const {
    return MyString::iterator(ptr_, size_);
}

MyString::const_iterator MyString::cbegin() const {
    return MyString::const_iterator(ptr_);
}
MyString::const_iterator MyString::cend() const {
    return MyString::const_iterator(ptr_, size_);
}

/* ---------------- Reverse iterator ---------------- */
MyString::reverse_iterator::reverse_iterator() : ptr_(nullptr), base_(nullptr) {}
MyString::reverse_iterator::reverse_iterator(char* ptr, unsigned int index) : ptr_(ptr), base_(ptr) {
    if(ptr_ != nullptr)
        ptr_ += index;}
MyString::reverse_iterator::reverse_iterator(const MyString::iterator& it) {
    auto values = it.values();
    ptr_ = values.first;
    base_ = values.second;

    /* When converting straight iterator into reverse, it moves backwards for one cell */
    if (ptr_ != nullptr && base_ != nullptr && ptr_ > base_)
        --ptr_;
    else
        ptr_ = nullptr;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator++() {
    if (ptr_ != nullptr && base_ != nullptr && ptr_ > base_)
        --ptr_;
    else
        ptr_ = nullptr;
    return *this;
}
MyString::reverse_iterator MyString::reverse_iterator::operator++(int) {
    reverse_iterator temp = *this;
    ++* this;
    return temp;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator--() {
    if (*ptr_ != 0)
        ++ptr_;
    return *this;
}
MyString::reverse_iterator MyString::reverse_iterator::operator--(int) {
    reverse_iterator temp = *this;
    --* this;
    return temp;
}
bool MyString::reverse_iterator::operator==(const MyString::reverse_iterator& it) const {
    return it.ptr_ == ptr_ && it.base_ == base_;
}
bool MyString::reverse_iterator::operator!=(const MyString::reverse_iterator& it) const {
    return !(this->operator==(it));
}
char& MyString::reverse_iterator::operator*() const {
    if (ptr_ == nullptr)
        throw std::out_of_range("Iterator is pointing on element before the beginning of the string");
    else
    if (*ptr_ == 0)
        throw std::out_of_range("Iterator is pointing on element after the last character of the string");
    else
        return *ptr_;
}
const char &MyString::const_reverse_iterator::operator*() const {
    if (ptr_ == nullptr)
        throw std::out_of_range("Iterator is pointing on element before the beginning of the string");
    else
    if (*ptr_ == 0)
        throw std::out_of_range("Iterator is pointing on element after the last character of the string");
    else
        return *ptr_;
}
std::pair<char *, char *> MyString::reverse_iterator::values() const {
    return std::pair<char *, char *>(ptr_, base_);
}

MyString::reverse_iterator MyString::rbegin() const {
    return reverse_iterator(end());
}
MyString::reverse_iterator MyString::rend() const {
    return reverse_iterator(begin());
}

MyString::const_reverse_iterator MyString::rcbegin() const {
    return MyString::const_reverse_iterator(end());
}
MyString::const_reverse_iterator MyString::rcend() const {
    return MyString::const_reverse_iterator(begin());
}

/* ------ Functions overloading with iterators ------ */
unsigned MyString::insert(MyString::iterator it, unsigned int count, char sym) {
    auto pair = it.values();
    if(pair.second != ptr_)
        throw std::logic_error("Iterator is based on different string");
    if(pair.first != nullptr && *(pair.first) != 0)
        return this->insert(pair.first - ptr_, count, sym);
    else
        throw std::out_of_range("Iterator is pointing out of the string");
}
unsigned MyString::insert(MyString::iterator it, const char *ptr) {
    auto pair = it.values();
    if(pair.second != ptr_)
        throw std::logic_error("Iterator is based on different string");
    if(pair.first != nullptr && *(pair.first) != 0)
        return this->insert(pair.first - ptr_, ptr);
    else
        throw std::out_of_range("Iterator is pointing out of the string");
}
unsigned MyString::insert(MyString::iterator it, const char *ptr, unsigned int count) {
    auto pair = it.values();
    if(pair.second != ptr_)
        throw std::logic_error("Iterator is based on different string");
    if(pair.first != nullptr && *(pair.first) != 0)
        return this->insert(pair.first - ptr_, ptr, count);
    else
        throw std::out_of_range("Iterator is pointing out of the string");
}
unsigned MyString::insert(MyString::iterator it, const std::string &str) {
    auto pair = it.values();
    if(pair.second != ptr_)
        throw std::logic_error("Iterator is based on different string");
    if(pair.first != nullptr && *(pair.first) != 0)
        return this->insert(pair.first - ptr_, str);
    else
        throw std::out_of_range("Iterator is pointing out of the string");
}
unsigned MyString::insert(MyString::iterator it, const std::string &str, unsigned int count) {
    auto pair = it.values();
    if(pair.second != ptr_)
        throw std::logic_error("Iterator is based on different string");
    if(pair.first != nullptr && *(pair.first) != 0)
        return this->insert(pair.first - ptr_, str, count);
    else
        throw std::out_of_range("Iterator is pointing out of the string");
}

unsigned MyString::erase(MyString::iterator it, unsigned int count) {
    auto pair = it.values();
    if(pair.second != ptr_)
        throw std::logic_error("Iterator is based on different string");
    if(pair.first != nullptr && *(pair.first) != 0)
        return this->erase(pair.first - ptr_, count);
    else
        throw std::out_of_range("Iterator is pointing out of the string");
}

unsigned MyString::replace(MyString::iterator it, unsigned int count, const char *ptr) {
    auto pair = it.values();
    if(pair.second != ptr_)
        throw std::logic_error("Iterator is based on different string");
    if(pair.first != nullptr && *(pair.first) != 0)
        return this->replace(pair.first - ptr_, count, ptr);
    else
        throw std::out_of_range("Iterator is pointing out of the string");
}
unsigned MyString::replace(MyString::iterator it, unsigned int count, const std::string &str) {
    auto pair = it.values();
    if(pair.second != ptr_)
        throw std::logic_error("Iterator is based on different string");
    if(pair.first != nullptr && *(pair.first) != 0)
        return this->replace(pair.first - ptr_, count, str);
    else
        throw std::out_of_range("Iterator is pointing out of the string");
}

MyString MyString::substr(MyString::iterator it) {
    auto pair = it.values();
    if(pair.second != ptr_)
        throw std::logic_error("Iterator is based on different string");
    if(pair.first != nullptr && *(pair.first) != 0)
        return this->substr(pair.first - ptr_);
    else
        throw std::out_of_range("Iterator is pointing out of the string");
}
MyString MyString::substr(MyString::iterator it, unsigned int count) {
    auto pair = it.values();
    if(pair.second != ptr_)
        throw std::logic_error("Iterator is based on different string");
    if(pair.first != nullptr && *(pair.first) != 0)
        return this->substr(pair.first - ptr_, count);
    else
        throw std::out_of_range("Iterator is pointing out of the string");
}