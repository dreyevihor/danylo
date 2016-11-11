#include <iostream>
#include <typeinfo>
#include <float.h>
#include <cmath>
#include <stdio.h>

#define SIZE 4
struct coord
{
  int firstCoord;
  int secondCoord;
};

double** createArr(size_t dimentionArr)
{
  double** hArr = new double*[dimentionArr];
      for (size_t i = 0; i <= dimentionArr; i++)
          {
          hArr[i] = new double[dimentionArr+1];
          }
      for (size_t j = 0; j < dimentionArr; j++) {
        for (size_t i = 0; i < dimentionArr+1; i++) {
          hArr[j][i] = -1 * DBL_MAX;
        }
      }
  return hArr;
}

void fillArr(double** arr)
{

  /**std::cout << "pidor" << std::endl;
  for (size_t j= 0; j < SIZE; j++) {
      for (size_t i = 0; i < 1+SIZE; i++) {
        std::cin >> arr[j][i];
      }
    }**/
    arr[SIZE][SIZE+1] = {13, 14, 17, 14, 146, 9, 26, 7, 9, 135, 8, 4, 24, 11, 119, 15, 11, 5,16, 109};
}

void printArr(double** arr, size_t dimentionArr = SIZE)
{
  for (size_t j= 0; j < dimentionArr; j++) {
      for (size_t i = 0; i < 1+dimentionArr; i++) {
            printf("%.2f ", arr[j][i]);
      }
      std::cout <<  std::endl;
      }
      std::cout <<  std::endl;

}
void swapRow(double** arr, size_t first , size_t second)
{
double* ptr = new double[SIZE];
ptr = arr[first];
arr[first] = arr[second];
arr[second] = ptr;
}

void deleteArr(double** arr,size_t  dimentionArr = SIZE)
{
  for (size_t i = 0; i < dimentionArr; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}

coord maxElement(double** arr, size_t countOfColl = SIZE, size_t countOfRow = SIZE)
{
  coord coordOfMax;
  double max = 0;
  for (size_t j= 0; j < countOfColl; j++) {
      for (size_t i = 0; i < countOfRow; i++) {
            if ( std::abs(arr[j][i]) > std::abs(max)) {
              coordOfMax.firstCoord = j;
              coordOfMax.secondCoord = i;
              max = arr[j][i];
      }
      }
      }
  return coordOfMax;
}

void diffRow(double** arr, size_t i, size_t j, size_t dimentionArr = SIZE)
{
  for (size_t k = 0; k < dimentionArr+1; k++) {
    arr[i][k]-=arr[j][k];
  }
}

void multRow(double** arr, size_t i, double a, size_t dimentionArr = SIZE)
{
  for (size_t k = 0; k <dimentionArr+1; k++) {
    arr[i][k]*=a;
  }
}

void shemaZVyboromGolovnogoElementu(double** arr, size_t dimentionArr = SIZE)
{
  coord coordOfMax;
  size_t aaa=0;
  size_t countOfColl = dimentionArr;
  for (size_t i = 0; i < dimentionArr; i++) {

    aaa++;
      coordOfMax = maxElement(arr, dimentionArr, countOfColl);
      for (size_t j = 0; j < countOfColl; j++) {
        if (j == coordOfMax.firstCoord)
            continue;
      multRow(arr, j, arr[coordOfMax.firstCoord][coordOfMax.secondCoord]/arr[j][coordOfMax.secondCoord] );
      diffRow(arr, j, coordOfMax.firstCoord);
      printArr(arr);
      }
      swapRow(arr, coordOfMax.secondCoord, countOfColl-i-1);
      printArr(arr);
      countOfColl--;
      std::cout << aaa << std::endl;
    }
}

int main(int argc, char const *argv[]) {
double** a = createArr(SIZE);
shemaZVyboromGolovnogoElementu(a);
//multRow(a, 1, 10, SIZE);
//diffRow(a, 1, 3);
//swapRow(a,1 ,2);
printArr(a);
//coord a1 = maxElement(a);
//std::cout << a1.firstCoord << a1.secondCoord << a[a1.firstCoord][a1.secondCoord]<< std::endl;
//deleteArr(a);
return 0;
}
