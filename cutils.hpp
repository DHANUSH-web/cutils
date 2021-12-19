/*
 * Library Name : cutils.hpp
 * Programmer   : DHANUSH H V
*/


#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define __CEL_TO_FAR__(x) x * 1.8f + 32.f
#define __FAR_TO_CEL__(f) (f - 32.f) / 1.8f

class __CUTILS__
{
public:
    // function to check that an item is present int the array
    bool contains(const char str[], const char c)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == c)
                return true;
        }

        return false;
    }

    bool contains(const vector<int> arr, const int el)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == el)
                return true;
        }

        return false;
    }

    bool contains(const int arr[], const int el, const int arr_size)
    {
        for (int i = 0; i < arr_size; i++)
        {
            if (arr[i] == el)
                return true;
        }

        return false;
    }

    // function to count an item appeared in the vector and arrays
    int count(const vector<int> arr, const int n)
    {
        int cnt = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == n)
                cnt++;
        }

        return cnt;
    }

    int count(const int arr[], const int n, const int arr_size)
    {
        int cnt = 0;

        for (int i = 0; i < arr_size; i++)
        {
            if (arr[i] == n)
                cnt++;
        }

        return cnt;
    }
    
    int count(const char str[], const char c)
    {
        int sz = strlen(str), cnt = 0;

        for (int i = 0; i < sz; i++)
        {
            if (str[i] == c)
                cnt++;
        }

        return cnt;
    }

    // bubble sort algorithm to sort a vector array
    vector<int> sort(vector<int> arr, const char mode = 'a')
    {
        size_t sz = arr.size(); // find the length of the array

        for (int i = 0; i < sz - 1; i++)
        {
            for (int j = 0; j < sz - 1 - i; j++)
            {
                bool condition = (mode == 'a') ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1]);

                if (condition)
                {
                    swap(arr[j], arr[j+1]);
                }
            }
        }

        return arr;
    }

    int* sort(int arr[], const int size, const char mode='a')
    {
        for (int i = 0; i < size; i++)
        {
            for (int j=0; j < size-1-i; j++)
            {
                bool condition = (mode == 'a') ? (arr[j] > arr[j+1]) : (arr[j] < arr[j+1]);

                if (condition){
                    swap(arr[j], arr[j+1]);
                }
            }
        }

        return arr;
    }

    // sorting the orignal array
    void sort_orgarr(vector<int>& arr, const char mode='a')
    {
        size_t sz = arr.size();

        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz-1-j; j++)
            {
                bool condition = (mode == 'a') ? (arr[j] > arr[j+1]) : (arr[j] < arr[j+1]);

                if (condition) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    // function to convert vector datatype to normal array
    int* toArray(const vector<int> nums)
    {
        int *arr = new int[nums.size()+1];

        for (int i = 0; i < nums.size(); i++)
        {
            arr[i] = nums[i];
        }

        return arr;
    }

    // Floyd's tortoise and hare cycle detection algorithm to find a duplicate item from a vector array
    int find_duplicate(const vector<int> nums)
    {
        int fast = nums[0], slow = nums[0];

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

    int find_duplicate(const int nums[], const int arr_size)
    {
        int fast = nums[0], slow = nums[0];

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
    vector<int> split_arr(const vector<int> arr, const int begin, const int end)
    {
        vector<int> new_arr;

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

    vector<int> merge_sort(vector<int> arr, const char mode = 'a')
    {
        int sz = arr.size(), mid, i = 0, j = 0, k = 0;
        vector<int> L, R;

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

    void printArray(const vector<int> arr, const char _end = '\n')
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << _end;
        }
    }

    void printArray(const int arr[], const int arr_size, const char _end = '\n')
    {
        for (int i = 0; i < arr_size; i++)
        {
            cout << arr[i] << _end;
        }
    }

    int sum(const vector<int> arr)
    {
        int s = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            s += arr[i];
        }

        return s;
    }

    int sum(const int arr[], const int arr_size)
    {
        int s = 0;

        for (int i = 0; i < arr_size; i++)
        {
            s += arr[i];
        }

        return s;
    }

    // function returns the largest number in the array
    int max(const int arr[], const int arr_size)
    {
        int n = arr[0];

        for (int i = 0; i < arr_size; i++)
        {
            if (n < arr[i])
                n = arr[i];
        }

        return n;
    }

    int max(const vector<int> arr)
    {
        int n = arr[0], sz = arr.size();

        for (int i = 0; i < sz; i++)
        {
            if (n < arr[i])
                n = arr[i];
        }

        return n;
    }

    // function returns the smallest number in the array
    int min(const int arr[], const int arr_size)
    {
        int n = arr[0];

        for (int i = 0; i < arr_size; i++)
        {
            if (n > arr[i])
                n = arr[i];
        }

        return n;
    }

    int min(const vector<int> arr)
    {
        int n = arr[0], sz = arr.size();

        for (int i = 0; i < sz; i++)
        {
            if (n > arr[i])
                n = arr[i];
        }

        return n;
    }

    int power(const int base, const int pow)
    {
        int p = 1;

        for (int i = 0; i < pow; i++)
        {
            p *= base;
        }

        return p;
    }

    int indexOf(const int arr[], const int e, const int arr_size)
    {
        for (int i = 0; i < arr_size; i++)
        {
            if (arr[i] == e)
                return i;
        }

        return -1;
    }

    int indexOf(const vector<int> arr, const int e)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == e) return i;
        }

        return -1;
    }

    int indexOf(const char str[], const char c)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == c)
                return i;
        }

        return -1;
    }

    char* reverse_str(char *str)
    {
        int size = strlen(str);

        for (int i = 0; i < int(size/2); i++)
        {
            swap(str[i], str[size-i-1]);
        }

        return str;
    }

    string reverse_str(string str)
    {
        int sz = str.size();

        for (int i = 0; i < int(sz/2); i++)
        {
            swap(str[i], str[sz-i-1]);
        }

        return str;
    }

    vector<int> reverse_arr(vector<int> nums, const bool sorted=false, const char mode='a')
    {
        if (sorted) nums = sort(nums, (mode=='a')?'d':'a');

        for (int i = 0, j = nums.size()-1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }

        return nums;
    }

    void reverse_orgarr(vector<int>& nums, const bool sorted=false, const char mode='a')
    {
        if (sorted) nums = sort(nums, (mode=='a')?'d':'a');

        for (int i = 0, j = nums.size()-1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }
    }

    int to_decimal(const char binary[])
    {
        int dec = 0, sz = strlen(binary);
        int index = sz-1;

        for (int i = 0; i < sz; i++)
        {
            if (binary[i] == '1'){
                dec += power(2, index);
            }

            index--;
        }

        return dec;
    }

    int to_decimal(const vector<char> binary)
    {
        int dec = 0, sz = binary.size();
        int index = sz-1;

        for (int i = 0; i < sz; ++i)
        {
            if (binary[i] == '1') dec += power(2, index);

            index--;
        }

        return dec;
    }

    int to_decimal(const string binary)
    {
        int dec = 0, sz = binary.length();
        int index = sz-1;

        for (int i = 0; i < sz; i++)
        {
            if (binary[i] == '1') dec += power(2, index);

            index--;
        }

        return dec;
    }

    char* to_binary(int dec)
    {
        char* bin = new char[dec];
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

template <class T>

class SortingAlgos
{
    public:

        T* bubble_sort(T arr[], const int size, const char mode='a')
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size-1-i; j++)
                {
                    bool condition = (mode == 'a') ? (arr[j] > arr[j+1]) : (arr[j] < arr[j+1]);

                    if (condition)
                        swap(arr[j], arr[j+1]);
                }
            }

            return arr;
        }

        T* merge_sort(T arr[], const int size, const char mode='a')
        {
            // merge sort algorithm
            return arr;
        }

        T* selection_sort(T arr[], const int size, const char mode='a')
        {
            // selection sort algorithm
            return arr;
        }

        T* quick_sort(T arr[], const int size, const char mode='a')
        {
            // quick sort algorithm
            return arr;
        }

        T* insertion_sort(T arr[], const int size, const char mode='a')
        {
            // insertion sort algorithm
            return arr;
        }

        void printArray(const T arr[], const int size)
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << endl;
            }
        }
};