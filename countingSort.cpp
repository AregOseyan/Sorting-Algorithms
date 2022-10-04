#include <iostream>
#include <vector>

template <typename T>
T maxElem(std::vector<T>& arr, int size)
{
  T res = arr[0];
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] > res) { res = arr[i]; }
  }
  return res;
}

template <typename T>
void countingSort(std::vector<T>& arr, int size)
{
  T max = maxElem<T>(arr, size);
  std::vector<T> helper;
  std::vector<T> tmp;
  tmp.reserve(size);
  for (int i = 0; i < size; ++i) { tmp.push_back(arr[i]); }
  helper.reserve(max);
  for (int i = 0; i < max; ++i) { helper.push_back(0); }
  for (int i = 0; i < size; ++i) { helper[arr[i]]++; }
  for (int i = 1; i < helper.size(); ++i) { helper[i + 1] += helper[i]; }
  for (int i = 0; i < size; ++i)
  {
    int index = helper[tmp[i]] - 1;
    arr[index] = tmp[i];
  }
}

int main()
{
  std::vector<int> arr = { 15, 4, 6, 31, 5 };
  int size = arr.size();
  countingSort<int>(arr, size);
  std::cout << "Result is\n";
  for (int i = 0; i < size; ++i) { std::cout << arr[i] << " "; }
  std::cout << std::endl;
  
  return {};
}
