#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T>& arr, std::vector<T> const& left, std::vector<T> const& right)
{
  size_t i = 0;
  size_t j = 0;
  while (i < left.size() || j < right.size())
  {
    if (i == left.size())
    {
      arr[i + j] = right[j];
      j++;
    }
    else if (j == right.size())
    {
      arr[i + j] = left[i];
      i++;
    }
    else if (left[i] <= right[j])
    {
      arr[i + j] = left[i];
      i++;
    }
    else
    {
      arr[i + j] = right[j];
      j++;
    }
  }
}

template <typename T>
void sort(std::vector<T>& arr)
{
  if (arr.size() < 2) { return; }

  size_t leftSize = arr.size() / 2;
  size_t rightSize = arr.size() - leftSize;
  std::vector<T> left;
  left.reserve(leftSize);
  std::vector<T> right;
  right.reserve(rightSize);
  for (int i = 0; i < leftSize; ++i) { left.push_back(arr[i]); }
  for (int j = leftSize; j < arr.size(); ++j) { right.push_back(arr[j]); }

  sort(left);
  sort(right);
  merge(arr, left, right);
}

int main()
{
  std::vector<int> arr = { 15, 4, 6, 31, 5 };
  int size = arr.size();
  sort<int>(arr);
  std::cout << "Result is\n";
  for (int i = 0; i < size; ++i) { std::cout << arr[i] << " "; }
  std::cout << std::endl;

  return {};
}
