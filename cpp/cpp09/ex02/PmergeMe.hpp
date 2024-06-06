#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &copy);

    void sort(std::vector<int> &numbers);
    void sort(std::deque<int> &numbers);
    void print(const std::vector<int> &numbers) const;
    void print(const std::deque<int> &numbers) const;

private:
    void mergeInsertSortVector(std::vector<int> &arr, int left, int right);
    void mergeInsertSortDeque(std::deque<int> &arr, int left, int right);
    void mergeVector(std::vector<int> &arr, int left, int mid, int right);
    void mergeDeque(std::deque<int> &arr, int left, int mid, int right);
};

#endif
