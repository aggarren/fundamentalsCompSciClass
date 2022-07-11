#include "MergeSort.h"
#include "constants.h"

//PRE:two char arrays end in EOS
//POST:returns true if lexicographically, the left goes before the right
bool lessThan(char left[], char right[]) {
  int index = 0;//goes through chars in array
  bool done = false;//we are not done determining order
  bool answer = false;//denotes if is less than
  while(!done) {//we have not determined order
    if(left[index] == right[index]) {//these chars are equal
      if(left[index+1] != EOS && right[index+1] != EOS) {//we are not at end of either code
	index++;//move to next char
      }
      else {//we have reached the end of one of the codes
	if(left[index+1] == EOS || (left[index+1] == EOS && right[index+1] == EOS)) {//the left one ended first or both ended
	  answer = true;//left goes first
	}
	if(right[index+1] == EOS) {//the right one ended first
	  answer = false;//right goes first
	}
	done = true;//we have determined order
      }
    }
    else if(left[index] < right[index]) {//less than
      answer = true;//it is true that it is less than
      done = true;//we have determined order
    }
    else {//more than
      answer = false;//it is false that it is less than
      done = true;//we have determined order
    }
  }
  return answer;
}

//PRE:sorts an array using merge sort; beg<end
//POST:array is sorted by codes in lexicographic order
void sortLine(Airline* allAirlines[],int beg, int end){
  if(beg<end) {//the beginning index is less than the end index
    int mid = (beg+end)/2;//the mid index is halfway between the beginning and the end indexes
    sortLine(allAirlines,beg,mid);//sort the left half
    sortLine(allAirlines,mid+1,end);//sort the right half
    mergeLine(allAirlines,beg,mid,end);//merge the halves
  }
}

//PRE:array exists and beg,mid,and end are increasing ints
//POST:array is merged and sorted when merged
void mergeLine(Airline* allAirlines[],int beg, int mid, int end){
  int numLeft = mid - beg + 1;//number of elements on the left
  int numRight = end-mid;//number of elements on the right
  Airline* * left;//holds a copy of the left elements
  Airline* * right;//holds a copy of the right elements
  left = new Airline*[numLeft];//length is number of elements on the left
  right = new Airline*[numRight];//length is number of elements on the right
  for(int i=0; i<numLeft; i++) {//copies left elements into temporary array
    left[i] = allAirlines[beg+i];
  }
  for(int j=0; j<numRight;j++) {//copies right elements into temporary array
    right[j] = allAirlines[mid+1+j];
  }
  int indexLeft=0;//indexes through left array
  int indexRight=0;//indexes through right array
  int indexMerged=beg;//indexes through original array
  while(indexLeft<numLeft && indexRight<numRight) {//we have not reached end of left or right arrays
    if(lessThan(left[indexLeft]->getCode(),right[indexRight]->getCode())) {//left is less than right
      allAirlines[indexMerged] = left[indexLeft];//left goes here
      indexLeft++;//move on in left array
    }
    else {
      allAirlines[indexMerged] = right[indexRight];//right goes here
      indexRight++;//move on in right array
    }
    indexMerged++;//move on in original array
  }
  while(indexLeft<numLeft) {//copies left array back into original array
    allAirlines[indexMerged] = left[indexLeft];
    indexLeft++;
    indexMerged++;
  }
  while(indexRight<numRight) {//copies right array back into original array
    allAirlines[indexMerged] = right[indexRight];
    indexRight++;
    indexMerged++;
  }
}

//PRE:sorts an array using merge sort; beg<end
//POST:array is sorted by codes in lexicographic order
void sortPort(Airport* allAirports[],int beg, int end){
  if(beg<end) {//the beginning index is less than the end index
    int mid = (beg+end)/2;//the mid index is halfway between the beginning and the end indexes
    sortPort(allAirports,beg,mid);//sort the left half
    sortPort(allAirports,mid+1,end);//sort the right half
    mergePort(allAirports,beg,mid,end);//merge the halves
  }
}

//PRE:array exists and beg,mid,and end are increasing ints
//POST:array is merged and sorted when merged
void mergePort(Airport* allAirports[],int beg, int mid, int end){
  int numLeft = mid - beg + 1;//number of elements on the left
  int numRight = end-mid;//number of elements on the right
  Airport* * left;//holds a copy of the left elements
  Airport* * right;//holds a copy of the right elements
  left = new Airport*[numLeft];//length is number of elements on the left
  right = new Airport*[numRight];//length is number of elements on the right
  for(int i=0; i<numLeft; i++) {//copies left elements into temporary array
    left[i] = allAirports[beg+i];
  }
  for(int j=0; j<numRight;j++) {//copies right elements into temporary array
    right[j] = allAirports[mid+1+j];
  }
  int indexLeft=0;//indexes through left array
  int indexRight=0;//indexes through right array
  int indexMerged=beg;//indexes through original array
  while(indexLeft<numLeft && indexRight<numRight) {//we have not reached end of left or right arrays
    if(lessThan(left[indexLeft]->getCode(),right[indexRight]->getCode())) {//left is less than right
      allAirports[indexMerged] = left[indexLeft];//left goes here
      indexLeft++;//move on in left array
    }
    else {
      allAirports[indexMerged] = right[indexRight];//right goes here
      indexRight++;//move on in right array
    }
    indexMerged++;//move on in original array
  }
  while(indexLeft<numLeft) {//copies left array back into original array
    allAirports[indexMerged] = left[indexLeft];
    indexLeft++;
    indexMerged++;
  }
  while(indexRight<numRight) {//copies right array back into original array
    allAirports[indexMerged] = right[indexRight];
    indexRight++;
    indexMerged++;
  }
}
