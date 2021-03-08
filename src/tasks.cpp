#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    // напишите код здесь ...
    if ((lhs) && (rhs)) {
        int temp = *lhs;
        *lhs = *rhs;
        *rhs = temp;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    // напишите код здесь ...
    if ((num_rows < 1) || (num_cols < 1)) {
        return nullptr;
    }

    int **array_2d = new int *[num_rows];
    for (int i = 0; i < num_rows; i++) {
        array_2d[i] = new int[num_cols];
        for (int j = 0; j < num_cols; j++) {
            array_2d[i][j] = init_value;
        }
    }
    return array_2d;
}


// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    // напишите код здесь ...
    if ((!arr_2d_source) || (!arr_2d_target) || (num_rows < 1) || (num_cols < 1)) {
        return false;
    }
    for (int i = 0; i < num_rows; i++) {
        if ((arr_2d_source[i]) && (arr_2d_target[i])) {
            for (int j = 0; j < num_cols; j++) {
                arr_2d_target[i][j] = arr_2d_source[i][j];
            }
        } else {
            return false;
        }
    }
    return true;
}


// Задание 4
void reverse_1d_array(vector<int> &arr) {
    // напишите код здесь ...
    if (arr.size() != 0) {
        int half_len = arr.size() / 2;
        int last = arr.size() - 1;
        for (int i = 0; i < half_len; i++) {
            swap_args(&arr[i], &arr[last - i]);
        }
    }
}


// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    // напишите код здесь ...
    if (arr_begin && arr_end) {
        int *ptr_beg = arr_begin;
        int *ptr_end = arr_end;
        while (ptr_beg != ptr_end && ptr_beg + 1 != ptr_end) {
            swap_args(ptr_beg, ptr_end);
            ptr_beg++;
            ptr_end--;
        }
        if (ptr_beg + 1 == ptr_end)
            swap_args(ptr_beg, ptr_end);
    }
}


// Задание 6
int *find_max_element(int *arr, int size) {
    // напишите код здесь ...
    if (!arr || size < 1)
        return nullptr;
    else {
        int *max = &arr[0];
        for (int i = 0; i < size; i++) {
            if (arr[i] > *max) {
                max = &arr[i];
            }
        }
        return max;
    }
}


// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    // напишите код здесь ...
    vector<int> odd_numbers;
    for (int i = 0; i < arr.size(); i++) {
        if (abs(arr[i]) % 2 == 1) {
            odd_numbers.push_back(arr[i]);
        }
    }
    if (!odd_numbers.empty()) {
        return odd_numbers;
    }
    return {};
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    // напишите код здесь ...
    vector<int> common_elements;
    vector<int> temp = arr_b;
    for (int i = 0; i < arr_a.size(); i++) {
        auto iter = find(temp.begin(), temp.end(), arr_a[i]);
        if (iter != temp.end()) {
            common_elements.push_back(*iter);
            temp.erase(iter);
        }
    }

    return common_elements;
}
