#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
void shellSort(std::vector<T>& arr)
{
  int i = arr.size() / 2;
  while (i)
  {
    for (int k = 0; k < arr.size(); ++k)
    {
      if (k + i >= arr.size()) { break; }
      if (arr[k] > arr[k + i]) 
      {
        std::swap(arr[k], arr[k + i]);
        for (int j = k; j >= 0; --j)
        {
          if (j - i < 0) { break; }
          if (arr[j] < arr[j - i]) { std::swap(arr[j], arr[j - i]); } 
        }
      }
    }
    i /= 2;
  }
}

int main()
{
  std::vector<int> arr = { 15, 4, 6, 31, 5, 54, 36, 66, 0, 0, 45, 1, 0, 25, 125, 124, 3 };
  int size = arr.size();
  shellSort<int>(arr);
  std::cout << "After insertion sort\n";
  for (int i = 0; i < size; ++i) { std::cout << arr[i] << " "; }
  std::cout << std::endl;

  return {};
}
