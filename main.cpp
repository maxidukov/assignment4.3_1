#include <iostream>

int* merge(int*, int*, int, int);
//int* merge_sort(int*, int);
void merge_sort(int*, int);

int main() {
  int aa[3][18] = {
     {3,43,38,29,18,72,57,61,2,33},
     {88,91,87,59,53,49,29,16,4,27,28,89,2,25,74},
     {24,66,20,79,30,16,19,62,94,59,0,7,59,90,84,60,95,62},
  };  //CLUMSY, MAKESHIFT C-STYLE JAGGED 2D ARRAY
  int asizes[3] = {10,15,18};
  //int a[] = {3,2,1};
  for(int j{};j<3;j++){
     //std::cout<<asizes[j]<<std::endl;
     //int* a_sorted = new int[asize];
     //a_sorted = merge_sort(a,asize);
     std::cout<<"Исходный массив: ";
     for(int i{};i<asizes[j];i++){
        std::cout<<aa[j][i]<<" ";
     }
     std::cout << "\n";
     merge_sort(aa[j],asizes[j]);
     std::cout<<"Отсортированный массив: ";
     for(int i{};i<asizes[j];i++){
        std::cout<<aa[j][i]<<" ";
     }
     std::cout << "\n\n";
  }
}

int* merge(int* a, int* b, int asize, int bsize ){
  int ai{};
  int bi{};
  int* c = new int[asize+bsize]();
  for(int ci{};ci<asize+bsize;ci++){
    if(ai>=asize){
       *(c+ci) = *(b+bi++);
    }else if(bi>=bsize){
       *(c+ci) = *(a+ai++);
    }else{
       if(*(a+ai)<=*(b+bi)){
         *(c+ci) = *(a+ai++);
       }else{
         *(c+ci) = *(b+bi++);
       }
    }
  }
  return c; //WILL BE FREED BY MERGE_SORT()
}

//int* merge_sort(int* a, int asize){
void merge_sort(int* a, int asize){
   //a_sorted = new int[asize]();
   if(asize>1){
      int* a_sorted = new int[asize]();
      merge_sort(a,asize/2);
      merge_sort(a+asize/2,asize-asize/2);
      a_sorted = merge(
        //merge_sort(a,asize/2),
        //merge_sort(a+asize/2,asize-asize/2),
        a,a+asize/2,asize/2,asize-asize/2);
      //return a_sorted;
      for(int i{}; i<asize;i++){
        a[i] = a_sorted[i];
      }
      delete [] a_sorted;
   }
}

