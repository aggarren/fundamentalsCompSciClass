#include "Airport.h"
#include "Airline.h"
//PRE:two char arrays end in EOS
//POST:returns true if lexicographically, the left goes before the right
bool lessThan(char left[], char right[]);

//PRE:sorts an array using merge sort; beg<end
//POST:array is sorted by codes in lexicographic order
void sortLine(Airline* allAirlines[],int beg, int end);

//PRE:array exists and beg,mid,and end are increasing ints
//POST:array is merged and sorted when merged
void mergeLine(Airline* allAirlines[],int beg, int mid, int end);

//PRE:sorts an array using merge sort; beg<end
//POST:array is sorted by codes in lexicographic order
void sortPort(Airport* allAirports[],int beg, int end);

//PRE:array exists and beg,mid,and end are increasing ints
//POST:array is merged and sorted when merged
void mergePort(Airport* allAirports[],int beg, int mid, int end);
                    
