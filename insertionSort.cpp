#include <iostream>
#include <vector>

template <typename T>
void insertionSort(std::vector<T>& arr, int size)
{
  T key;
  int j = 0;
  for (int i = 1; i < size; ++i)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main()
{
  std::vector<int> arr = { 15, 4, 6, 31, 5 };
  int size = arr.size();
  insertionSort<int>(arr, size);
  std::cout << "Result is\n";
  for (int i = 0; i < size; ++i) { std::cout << arr[i] << " "; }
  std::cout << std::endl;
  
  return {};
}
