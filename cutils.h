#ifndef CUTILS_H
#define CUTILS_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <climits>
#include <stdexcept>
#include <cstdlib>

#define __CEL_TO_FAR__(x) ((x) * 1.8f + 32.f)
#define __FAR_TO_CEL__(f) (((f) - 32.f) / 1.8f)

namespace cutils {

    template <typename T>
    bool contains(const T* arr, size_t size, const T& value) {
        for (size_t i = 0; i < size; ++i) {
            if (arr[i] == value)
                return true;
        }
        return false;
    }

    template <typename T>
    bool contains(const std::vector<T>& vec, const T& value) {
        return std::find(vec.begin(), vec.end(), value) != vec.end();
    }

    template <typename T>
    int count(const std::vector<T>& vec, const T& value) {
        return static_cast<int>(std::count(vec.begin(), vec.end(), value));
    }

    template <typename T>
    int count(const T arr[], const T& value, int arr_size) {
        int cnt = 0;
        for (int i = 0; i < arr_size; i++) {
            if (arr[i] == value)
                cnt++;
        }
        return cnt;
    }

    template <typename T>
    std::vector<T> sort(std::vector<T> arr, char mode = 'a') {
        if (mode == 'a') {
            std::sort(arr.begin(), arr.end());
        } else {
            std::sort(arr.begin(), arr.end(), std::greater<T>());
        }
        return arr;
    }

    template <typename T>
    T* sort(T arr[], size_t size, char mode = 'a') {
        if (mode == 'a') {
            std::sort(arr, arr + size);
        } else {
            std::sort(arr, arr + size, std::greater<T>());
        }
        return arr;
    }

    template <typename T>
    void sort_orgarr(std::vector<T>& arr, char mode = 'a') {
        if (mode == 'a') {
            std::sort(arr.begin(), arr.end());
        } else {
            std::sort(arr.begin(), arr.end(), std::greater<T>());
        }
    }

    template <typename T>
    std::vector<T> toArray(const std::vector<T>& nums) {
        return nums;
    }

    template <typename T>
    T find_duplicate(const std::vector<T>& nums) {
        if (nums.empty()) return T();
        T fast = nums[0], slow = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }

    template <typename T>
    T find_duplicate(const T nums[], size_t size) {
        if (size == 0) return T();
        T fast = nums[0], slow = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }

    template <typename T>
    std::vector<T> split_arr(const std::vector<T>& arr, int begin, int end) {
        if (begin < 0 || end > static_cast<int>(arr.size()) || begin > end) {
            return std::vector<T>();
        }
        return std::vector<T>(arr.begin() + begin, arr.begin() + end);
    }

    inline std::vector<int> strToArray(const std::string& str) {
        std::stringstream ss(str);
        std::vector<int> nums;
        int num;
        char ch;
        while (ss >> num) {
            nums.push_back(num);
            ss >> ch;
        }
        return nums;
    }

    template <typename T>
    std::vector<T> merge_sort(std::vector<T> arr, char mode = 'a') {
        return sort(arr, mode);
    }

    template <typename T>
    void printArray(const std::vector<T>& arr, char _end = '\n') {
        for (const auto& item : arr) {
            std::cout << item << _end;
        }
    }

    template <typename T>
    void printArray(const T arr[], int arr_size, char _end = '\n') {
        for (int i = 0; i < arr_size; i++) {
            std::cout << arr[i] << _end;
        }
    }

    template <typename T>
    T sum(const std::vector<T>& arr) {
        T s = 0;
        for (const auto& item : arr) {
            s += item;
        }
        return s;
    }

    template <typename T>
    T sum(const T arr[], int arr_size) {
        T s = 0;
        for (int i = 0; i < arr_size; i++) {
            s += arr[i];
        }
        return s;
    }

    template <typename T>
    T max(const T arr[], int arr_size) {
        if (arr_size <= 0) return T();
        T n = arr[0];
        for (int i = 1; i < arr_size; i++) {
            if (n < arr[i]) n = arr[i];
        }
        return n;
    }

    template <typename T>
    T max(const std::vector<T>& arr) {
        if (arr.empty()) return T();
        return *std::max_element(arr.begin(), arr.end());
    }

    template <typename T>
    T min(const T arr[], int arr_size) {
        if (arr_size <= 0) return T();
        T n = arr[0];
        for (int i = 1; i < arr_size; i++) {
            if (n > arr[i]) n = arr[i];
        }
        return n;
    }

    template <typename T>
    T min(const std::vector<T>& arr) {
        if (arr.empty()) return T();
        return *std::min_element(arr.begin(), arr.end());
    }

    template <typename T>
    T power(T base, int exp) {
        T res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) res *= base;
            base *= base;
            exp /= 2;
        }
        return res;
    }

    template <typename T>
    int indexOf(const T arr[], const T& e, int arr_size) {
        for (int i = 0; i < arr_size; i++) {
            if (arr[i] == e) return i;
        }
        return -1;
    }

    template <typename T>
    int indexOf(const std::vector<T>& arr, const T& e) {
        for (size_t i = 0; i < arr.size(); i++) {
            if (arr[i] == e) return static_cast<int>(i);
        }
        return -1;
    }

    inline char* reverse_str(char* str) {
        if (!str) return nullptr;
        size_t size = strlen(str);
        std::reverse(str, str + size);
        return str;
    }

    inline std::string reverse_str(std::string str) {
        std::reverse(str.begin(), str.end());
        return str;
    }

    inline int reverse_num(int num) {
        int rev = 0;
        bool negative = num < 0;
        if (negative) num = -num;
        while (num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return negative ? -rev : rev;
    }

    template <typename T>
    std::vector<T> reverse_arr(std::vector<T> nums, bool sorted = false, char mode = 'a') {
        if (sorted) sort_orgarr(nums, (mode == 'a') ? 'd' : 'a');
        std::reverse(nums.begin(), nums.end());
        return nums;
    }

    template <typename T>
    T* reverse_arr(T nums[], size_t size, bool sorted = false, char mode = 'a') {
        if (sorted) sort(nums, size, (mode == 'a') ? 'd' : 'a');
        std::reverse(nums, nums + size);
        return nums;
    }

    template <typename T>
    void reverse_orgarr(std::vector<T>& nums, bool sorted = false, char mode = 'a') {
        if (sorted) sort_orgarr(nums, (mode == 'a') ? 'd' : 'a');
        std::reverse(nums.begin(), nums.end());
    }

    inline int to_decimal(const char binary[]) {
        if (!binary) return 0;
        int dec = 0;
        for (int i = 0; binary[i] != '\0'; ++i) {
            dec = (dec << 1) | (binary[i] == '1' ? 1 : 0);
        }
        return dec;
    }

    inline int to_decimal(const std::vector<char>& binary) {
        int dec = 0;
        for (char c : binary) {
            dec = (dec << 1) | (c == '1' ? 1 : 0);
        }
        return dec;
    }

    inline int to_decimal(const std::string& binary) {
        int dec = 0;
        for (char c : binary) {
            dec = (dec << 1) | (c == '1' ? 1 : 0);
        }
        return dec;
    }

    inline std::string to_binary(int dec) {
        if (dec == 0) return "0";
        std::string bin = "";
        while (dec > 0) {
            bin += (dec % 2 == 1) ? '1' : '0';
            dec /= 2;
        }
        std::reverse(bin.begin(), bin.end());
        return bin;
    }

    template <typename U>
    class Stack {
    private:
        std::vector<U> arr;
        size_t max_size;

    public:
        Stack(size_t max = 200000) : max_size(max) {}

        Stack(const std::vector<U>& initial_arr) : arr(initial_arr), max_size(200000) {}

        bool isFull() const {
            return arr.size() >= max_size;
        }

        bool isEmpty() const {
            return arr.empty();
        }

        size_t length() const {
            return arr.size();
        }

        void push(const U& item) {
            if (isFull()) {
                std::cout << "Stack Overflow" << std::endl;
            } else {
                arr.push_back(item);
            }
        }

        U pop() {
            if (isEmpty()) {
                throw std::underflow_error("Stack is Empty");
            } else {
                U item = arr.back();
                arr.pop_back();
                return item;
            }
        }

        U peek() const {
            if (isEmpty()) {
                throw std::underflow_error("Stack is Empty");
            }
            return arr.back();
        }

        void printStack() const {
            if (isEmpty()) {
                std::cout << "Stack is Empty" << std::endl;
            } else {
                for (int i = static_cast<int>(arr.size()) - 1; i >= 0; i--) {
                    std::cout << arr[i] << std::endl;
                }
            }
        }

        void showStack() const {
            if (isEmpty()) {
                std::cout << "Stack is Empty" << std::endl;
            } else {
                for (int i = static_cast<int>(arr.size()) - 1; i >= 0; i--) {
                    std::cout << arr[i] << "\t--> |===========| --> Memory Address: " << &arr[i] << std::endl;
                }
                std::cout << "\nTotal Stack Items : " << length() << std::endl;
                std::cout << "Stack Item Size   : " << sizeof(U) << " Bytes" << std::endl;
                std::cout << "Stack Total Size  : " << (length() * sizeof(U)) << " Bytes" << std::endl;
            }
        }

        void insert(size_t index, const U& value) {
            if (index > arr.size()) {
                throw std::out_of_range("Index out of range");
            }
            arr.insert(arr.begin() + index, value);
        }

        void remove(size_t index) {
            if (index >= arr.size()) {
                throw std::out_of_range("Index out of range");
            }
            arr.erase(arr.begin() + index);
        }

        const std::vector<U>& getInternalVector() const {
            return arr;
        }
    };
}

#endif
