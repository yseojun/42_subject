#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) { (void)copy; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
  (void)copy;
  return *this;
}

void PmergeMe::sort(std::vector<int> &numbers) {
  mergeInsertSortVector(numbers, 0, numbers.size() - 1);
}

void PmergeMe::sort(std::deque<int> &numbers) {
  mergeInsertSortDeque(numbers, 0, numbers.size() - 1);
}

void PmergeMe::print(const std::vector<int> &numbers) const {
  for (size_t i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::print(const std::deque<int> &numbers) const {
  for (size_t i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &arr, int left,
                                     int right) {
  if (left >= right)
    return;
  if (right - left < 10) {
    for (int i = left + 1; i <= right; ++i) {
      int key = arr[i];
      int j = i - 1;
      while (j >= left && arr[j] > key) {
        arr[j + 1] = arr[j];
        --j;
      }
      arr[j + 1] = key;
    }
  } else {
    int mid = left + (right - left) / 2;
    mergeInsertSortVector(arr, left, mid);
    mergeInsertSortVector(arr, mid + 1, right);
    mergeVector(arr, left, mid, right);
  }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &arr, int left, int right) {
  if (left >= right)
    return;
  if (right - left < 10) {
    for (int i = left + 1; i <= right; ++i) {
      int key = arr[i];
      int j = i - 1;
      while (j >= left && arr[j] > key) {
        arr[j + 1] = arr[j];
        --j;
      }
      arr[j + 1] = key;
    }
  } else {
    int mid = left + (right - left) / 2;
    mergeInsertSortDeque(arr, left, mid);
    mergeInsertSortDeque(arr, mid + 1, right);
    mergeDeque(arr, left, mid, right);
  }
}

void PmergeMe::mergeVector(std::vector<int> &arr, int left, int mid,
                           int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  std::vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; ++i)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; ++j)
    R[j] = arr[mid + 1 + j];
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void PmergeMe::mergeDeque(std::deque<int> &arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  std::deque<int> L(n1), R(n2);

  for (int i = 0; i < n1; ++i)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; ++j)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}
