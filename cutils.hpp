/*
 * Library Name : cutils.hpp
 * Programmer   : DHANUSH H V
 */

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define __CEL_TO_FAR__(x) x * 1.8f + 32.f
#define __FAR_TO_CEL__(f) (f - 32.f) / 1.8f

template <class T, class U>

class __CUTILS__
{
public:
    // function to check that an item is present int the array
    bool contains(const T str[], const T c)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == c)
                return true;
        }

        return false;
    }

    // function to count an item appeared in the vector and arrays
    int count(const vector<T> arr, const int n)
    {
        int cnt = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == n)
                cnt++;
        }

        return cnt;
    }

    int count(const T arr[], const T n, const int arr_size)
    {
        int cnt = 0;

        for (int i = 0; i < arr_size; i++)
        {
            if (arr[i] == n)
                cnt++;
        }

        return cnt;
    }

    // bubble sort algorithm to sort a vector array
    vector<T> sort(vector<T> arr, const char mode = 'a')
    {
        size_t sz = arr.size(); // find the length of the array

        for (int i = 0; i < sz - 1; i++)
        {
            for (int j = 0; j < sz - 1 - i; j++)
            {
                bool condition = (mode == 'a') ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1]);

                if (condition)
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        return arr;
    }

    T *sort(T arr[], const T size, const char mode = 'a')
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                bool condition = (mode == 'a') ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1]);

                if (condition)
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        return arr;
    }

    // sorting the orignal array
    void sort_orgarr(vector<T> &arr, const char mode = 'a')
    {
        size_t sz = arr.size();

        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz - 1 - j; j++)
            {
                bool condition = (mode == 'a') ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1]);

                if (condition)
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // function to convert vector datatype to normal array
    T *toArray(const vector<T> nums)
    {
        int *arr = new int[nums.size() + 1];

        for (int i = 0; i < nums.size(); i++)
        {
            arr[i] = nums[i];
        }

        return arr;
    }

    // Floyd's tortoise and hare cycle detection algorithm to find a duplicate item from a vector array
    T find_duplicate(const vector<T> nums)
    {
        T fast = nums[0], slow = nums[0];

        while (true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];

            if (slow == fast)
                break;
        }

        fast = nums[0];

        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    T find_duplicate(const T nums[], const int arr_size)
    {
        T fast = nums[0], slow = nums[0];

        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
                break;
        }

        fast = nums[0];

        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }

        return slow;
    }

    // function to split a vector array to a given index from the original vector array
    vector<T> split_arr(const vector<T> arr, const int begin, const int end)
    {
        vector<T> new_arr;

        for (int i = begin; i < end; i++)
        {
            new_arr.push_back(arr[i]);
        }

        return new_arr;
    }

    vector<int> strToArray(const string str)
    {
        stringstream ss(str);
        vector<int> nums;
        int num;
        char ch;

        while (ss >> num)
        {
            nums.push_back(num);
            ss >> ch;
        }

        return nums;
    }

    vector<T> merge_sort(vector<T> arr, const char mode = 'a')
    {
        int sz = arr.size(), mid, i = 0, j = 0, k = 0;
        vector<T> L, R;

        if (sz > 1)
        {
            mid = sz / 2;

            L = split_arr(arr, 0, mid);
            R = split_arr(arr, mid, sz);

            L = merge_sort(L);
            R = merge_sort(R);

            while (i < L.size() && j < R.size())
            {
                bool condition = (mode == 'a') ? (L[i] < R[j]) : (L[i] > R[j]);

                if (condition)
                {
                    arr[k] = L[i];
                    i++;
                }
                else
                {
                    arr[k] = R[j];
                    j++;
                }

                k++;
            }

            while (i < L.size())
            {
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < R.size())
            {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        return arr;
    }

    void printArray(const vector<T> arr, const char _end = '\n')
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << _end;
        }
    }

    void printArray(const T arr[], const int arr_size, const char _end = '\n')
    {
        for (int i = 0; i < arr_size; i++)
        {
            cout << arr[i] << _end;
        }
    }

    T sum(const vector<T> arr)
    {
        T s = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            s += arr[i];
        }

        return s;
    }

    T sum(const T arr[], const int arr_size)
    {
        T s = 0;

        for (int i = 0; i < arr_size; i++)
        {
            s += arr[i];
        }

        return s;
    }

    // function returns the largest number in the array
    T max(const T arr[], const int arr_size)
    {
        T n = arr[0];

        for (int i = 0; i < arr_size; i++)
        {
            if (n < arr[i])
                n = arr[i];
        }

        return n;
    }

    T max(const vector<T> arr)
    {
        T n = arr[0], sz = arr.size();

        for (int i = 0; i < sz; i++)
        {
            if (n < arr[i])
                n = arr[i];
        }

        return n;
    }

    // function returns the smallest number in the array
    T min(const T arr[], const int arr_size)
    {
        T n = arr[0];

        for (int i = 0; i < arr_size; i++)
        {
            if (n > arr[i])
                n = arr[i];
        }

        return n;
    }

    T min(const vector<T> arr)
    {
        T n = arr[0], sz = arr.size();

        for (int i = 0; i < sz; i++)
        {
            if (n > arr[i])
                n = arr[i];
        }

        return n;
    }

    T power(const T base, const int pow)
    {
        T p = 1;

        for (int i = 0; i < pow; i++)
        {
            p *= base;
        }

        return p;
    }

    int indexOf(const T arr[], const T e, const int arr_size)
    {
        for (int i = 0; i < arr_size; i++)
        {
            if (arr[i] == e)
                return i;
        }

        return -1;
    }

    T indexOf(const vector<T> arr, const T e)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == e)
                return i;
        }

        return -1;
    }

    // int indexOf(const char str[], const char c)
    // {
    //     for (int i = 0; i < strlen(str); i++)
    //     {
    //         if (str[i] == c)
    //             return i;
    //     }

    //     return -1;
    // }

    char *reverse_str(char *str)
    {
        int size = strlen(str);

        for (int i = 0; i < int(size / 2); i++)
        {
            swap(str[i], str[size - i - 1]);
        }

        return str;
    }

    string reverse_str(string str)
    {
        int sz = str.size();

        for (int i = 0; i < int(sz / 2); i++)
        {
            swap(str[i], str[sz - i - 1]);
        }

        return str;
    }

    int reverse_num(int num)
    {
        int rev_bit = 0;

        do {
            int last_bit = num % 10;
            rev_bit = rev_bit * 10 + last_bit;
            num /= 10;
        } while (num != 0);

        return rev_bit;
    }

    vector<T> reverse_arr(vector<T> nums, const bool sorted = false, const char mode = 'a')
    {
        if (sorted)
            nums = sort(nums, (mode == 'a') ? 'd' : 'a');

        for (int i = 0, j = nums.size() - 1; i < j; i++, --j)
        {
            swap(nums[i], nums[j]);
        }

        return nums;
    }

    T *reverse_arr(T nums[], const int size, const bool sorted = false, const char mode = 'a')
    {
        if (sorted)
            nums = sort(nums, (mode == 'a') ? 'd' : 'a');

        for (int i = 0, j = size - 1; i < j; i++, --j)
        {
            swap(nums[i], nums[j]);
        }

        return nums;
    }

    void reverse_orgarr(vector<T> &nums, const bool sorted = false, const char mode = 'a')
    {
        if (sorted)
            nums = sort(nums, (mode == 'a') ? 'd' : 'a');

        for (int i = 0, j = nums.size() - 1; i < j; i++, --j)
        {
            swap(nums[i], nums[j]);
        }
    }

    int to_decimal(const char binary[])
    {
        int dec = 0, sz = strlen(binary);
        int index = sz - 1;

        for (int i = 0; i < sz; i++)
        {
            if (binary[i] == '1')
            {
                dec += power(2, index);
            }

            index--;
        }

        return dec;
    }

    int to_decimal(const vector<char> binary)
    {
        int dec = 0, sz = binary.size();
        int index = sz - 1;

        for (int i = 0; i < sz; ++i)
        {
            if (binary[i] == '1')
                dec += power(2, index);

            index--;
        }

        return dec;
    }

    int to_decimal(const string binary)
    {
        int dec = 0, sz = binary.length();
        int index = sz - 1;

        for (int i = 0; i < sz; i++)
        {
            if (binary[i] == '1')
                dec += power(2, index);

            index--;
        }

        return dec;
    }

    char *to_binary(int dec)
    {
        char *bin = new char[dec];
        int i = 0;

        while (dec > 0)
        {
            bin[i] = (dec % 2 == 1) ? '1' : '0';
            dec /= 2;
            i++;
        }

        return reverse_str(bin);
    }
};

// Implementing Stack Operation for FIFO technology

template <class T>
class Stack
{
    private:
        vector<T> temp;
        int i;

    public:

        vector<T> arr;
        size_t length;

        Stack(vector<T> arr)
        {
            this->arr = arr;    // default array
            this->length = this->arr.size();    // size of the array
        }

        // update memory buffers
        void update_buffer();

        // method to push an item to last index in the array
        void push(const T item)
        {
            // push an item to the last index
            this->arr.push_back(item);
        }

        // method to remove the last item from the array
        void pop()
        {
            // store the array in other array
            temp = this->arr;

            this->arr = vector<T>();    // clear the items of array

            // store all the item except the last item
            for (i = 0; i < temp.size()-1; i++)
                this->arr.push_back(temp[i]);
        }

        // method to insert an item in a specific index without removing other
        void insert(const int index, const T item)
        {
            temp = vector<T>();

            // append all the items from beginning to given index
            for (i = 0; i < index; i++)
                temp.push_back(this->arr[i]);

            // adding the new item to the array
            temp.push_back(item);

            // continue to add the rest item from the index
            for (i = index; i < this->arr.size(); i++)
                temp.push_back(this->arr[i]);

            // now store the updated array back to default array
            this->arr = temp;
        }

        // method to remove an item present in the given index 
        // from the array without disturbing others
        void remove(const int index)
        {
            // initialize an empty array
            temp = vector<T>();

            for (i = 0; i < this->arr.size(); i++)
            {
                // skip the item present in the index
                if (i == index)
                    continue;
                
                // append all the reachable item to the array
                temp.push_back(this->arr[i]);
            }

            // update the default array
            this->arr = temp;
        }

        // method to print the stack array
        void printStack()
        {
            for (i = 0; i < this->arr.size(); i++)
                cout << "Index: " << i << " ==> Item: " << this->arr[i] << endl;
        }
};

// Implementing Stack Operation for FIFO technology

class Stack
{
private:
    vector<U> temp;
    int i;

public:
    vector<U> arr;
    size_t length;

    Stack(vector<U> arr)
    {
        this->arr = arr;                 // default array
        this->length = this->arr.size(); // size of the array
    }

    // update memory buffers
    void update_buffer();

    // method to push an item to last index in the array
    void push(const U item)
    {
        // push an item to the last index
        this->arr.push_back(item);
    }

    // method to remove the last item from the array
    void pop()
    {
        // store the array in other array
        temp = this->arr;

        this->arr = vector<U>(); // clear the items of array

        // store all the item except the last item
        for (i = 0; i < temp.size() - 1; i++)
            this->arr.push_back(temp[i]);
    }

    // method to insert an item in a specific index without removing other
    void insert(const int index, const U item)
    {
        temp = vector<U>();

        // append all the items from beginning to given index
        for (i = 0; i < index; i++)
            temp.push_back(this->arr[i]);

        // adding the new item to the array
        temp.push_back(item);

        // continue to add the rest item from the index
        for (i = index; i < this->arr.size(); i++)
            temp.push_back(this->arr[i]);

        // now store the updated array back to default array
        this->arr = temp;
    }

    // method to remove an item present in the given index
    // from the array without disturbing others
    void remove(const int index)
    {
        // initialize an empty array
        temp = vector<U>();

        for (i = 0; i < this->arr.size(); i++)
        {
            // skip the item present in the index
            if (i == index)
                continue;

            // append all the reachable item to the array
            temp.push_back(this->arr[i]);
        }

        // update the default array
        this->arr = temp;
    }

    // method to print the stack array
    void printStack()
    {
        for (i = 0; i < this->arr.size(); i++)
            cout << "Index: " << i << " ==> Item: " << this->arr[i] << endl;
    }
};
