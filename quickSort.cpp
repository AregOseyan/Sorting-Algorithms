#include <iostream>
#include <vector>

template <typename T>
int partition(std::vector<T>& arr, int start, int end)
{
  int pivot = arr[start];
  
  int i = start + 1;
  for (int j = start + 1; j <= end; ++j)
  {
    if (arr[j] < pivot)
    {
      std::swap(arr[j], arr[i]);
      i++;
    }
  }
  std::swap(arr[start], arr[i - 1]);
  return i - 1;
}

template <typename T>
void quickSort(std::vector<T>& arr, int start, int end)
{
  if (start < end)
  {
    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
  }
}

int main()
{
  std::vector<int> arr = { 15, 4, 6, 31, 5, 1 }; 
  quickSort<int>(arr, 0, arr.size() - 1);
  std::cout << "Result is\n";
  for (int i = 0; i < arr.size(); ++i) { std::cout << arr[i] << " "; }
  std::cout << std::endl;

  return {};
}
