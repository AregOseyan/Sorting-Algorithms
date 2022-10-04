#include <iostream>
#include <vector>

template <typename T>
void selectionSort(std::vector<T>& arr, int size)
{
  for (int i = 0; i < size; ++i)
  {
    int k = i;
    for (int j = i; j < size; ++j)
    {
      if (arr[k] > arr[j]) { k = j; }
    }
    if (arr[k] < arr[i]) { std::swap(arr[i], arr[k]); }
  }
}

int main()
{
  std::vector<int> arr = { 15, 4, 6, 31, 5 };
  int size = arr.size();
  selectionSort<int>(arr, size);
  std::cout << "Result is\n";
  for (int i = 0; i < size; ++i) { std::cout << arr[i] << " "; }
  std::cout << std::endl;

  return {};
}
