int main(){

// Appending a new element to dynamically allocated array :------------------------:------------------------:------------------------:------------------------:------------------------

    int newData = 111;
    int startSize = 3;

    int* startArray = new int[startSize];
    int* newArray = new int[startSize + 1];

    for(int i = 0; i < startSize; ++i){
        newArray[i] = startArray[i];
    }

    delete[] startArray;

    startArray = newArray;

    startArray[startSize] = newData; // Modifying Last Element
    ++startSize;

// Appending array to another :------------------------:------------------------:------------------------:------------------------:------------------------:------------------------

    int start_1_Size = 3;
    int start_2_Size = 5;

    int* start_1_Array = new int[start_1_Size];
    int* start_2_Array = new int[start_2_Size];

    int* newArray = new int[start_1_Size + start_2_Size];

    //FIRST ARRAY
    for(int i = 0; i < start_1_Size; ++i){
        newArray[i] = start_1_Array[i];
    }

    //SECOND ARARY
    for(int i = 0; i < start_2_Size; ++i){
        newArray[start_1_Size + i] = start_2_Array[i];
    }

    delete[] start_1_Array;
    start_1_Array = newArray;

    start_1_Size += start_2_Size;

// Doubling capacity :------------------------:------------------------:------------------------:------------------------:------------------------:------------------------

    int startCurrentSize = 3;
    int startCapacity = 3;

    int* startArray = new int[startCapacity];

    if(startCurrentSize == startCapacity){

        int* newArray = new int[startCapacity * 2];

        for(int i = 0; i < startCurrentSize; ++i){
            newArray[i] = startArray[i];
        }

        delete[] startArray;

        startArray = newArray;

        startCapacity *= 2;
    }

// Delete element :------------------------:------------------------:------------------------:------------------------:------------------------:------------------------

    int deleteIndex = 1;
    int startSize = 3;
    int startCapacity = 5;

    int* startArray = new int[startCapacity];

    --startSize;

    for(int i = deleteIndex; i < startSize; ++i){
        startArray[i] = startArray[i + 1];
    }

//:------------------------:------------------------:------------------------:------------------------:------------------------:------------------------

    return 0;


}