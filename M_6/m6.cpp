class MyVector{
    public:
        MyVector();
        // creates an empty vector
        MyVector(int newSize);
        // creates a vector with newSize elements
        // throws std::out_of_range("MyVector::MyVector") if newSize is negative
        ~MyVector();
        // deletes the current vector, cleans up allocated data
        int& at(int index);
        // returns a reference to the value at position index
        // throws std::out_of_range("MyVector::at") if index is out of bounds
        int size();
        // returns the number of elements that can be stored inside the vector
        void resize(int newsize);
        // changes the size() of the vector to newSize
        // when newSize > allocatedSize, then resize() allocates a new data array, and copies existing values into it
        // otherwise, only the result of size() will be adjusted
        //      add a private variable for implementing this
        // throws std::out_of_range("MyVector::resize") if newSize is negative

    private:
        int allocatedSize;
        int* data;
};

MyVector::MyVector() : allocatedSize(0), data(nullptr) {}

MyVector::MyVector(int newSize) : allocatedSize(newSize)
{
    if ( newSize < 1){
        throw std::out_of_range("MyVector::MyVector");
    }
    data = new int[newSize];
}

MyVector::~MyVector()
{
    delete[] data;
}

int MyVector::size()
{
    return allocatedSize;
}

int& MyVector::at(int index)
{
    if ( (index < 0) || (index >=allocatedSize) ){
        throw std::out_of_range("MyVector::at");
    }
    return data[index];
}

void MyVector::resize(int newSize)
{   
    int nForCopy;
    int nForEmpty;

    int* newArray = new int[newSize];

    if(allocatedSize > newSize){
        nForCopy = allocatedSize;
        nForEmpty = allocatedSize - newSize;
    } else {
        nForCopy = newSize - allocatedSize;
        nForEmpty = 0;
    }

    for(int i = 0; i < nForCopy; ++i){
        newArray[i] = data[i];
    }

    for (int i = nForCopy; i < nForCopy + nForEmpty; ++i) {
        newArray[i] = 0; 
    }

    delete[] data;

    data = newArray;
    allocatedSize = newSize;
    allocatedSize = (allocatedSize < newSize) ? allocatedSize : newSize;
}