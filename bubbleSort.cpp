#include <iostream>
#include <vector>

template <typename T>
void bubbleSort(std::vector<T>& arr, int size)
{
  bool swapped;
  for (int i = 0; i < size - 1; ++i)
  {
    swapped = false;
    for (int j = 0; j < size - i - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) { return; }
  }
}

int main()
{
  std::vector<int> arr = { 15, 4, 6, 31, 5 };
  int size = arr.size();
  bubbleSort<int>(arr, size);
  std::cout << "Result is\n";
  for (int i = 0; i < size; ++i) { std::cout << arr[i] << " "; }
  std::cout << std::endl;

  return {};
}
