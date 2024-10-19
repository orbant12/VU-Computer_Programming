int main(){

    int* ints = new int[10];

    for(int i = 0; i < 10; i++){
        ints[i] = 10 - i;
    }

    int *ptr = &ints[3];
    for(int i = -9; i < 1; i++){
        ptr[i] += i;
    }

    for(int i = 0; i < 10; i++){
        std::cout << ints[i] << " ";
    }

    return 0;
}