//Insertion Sort with check if bottom is reached
void Method1(int*& a, int& n) {

    time_t t0, t1;
    clock_t c0, c1;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = a[i];
    }
    int buff;
    int i = 1;
    int j;

    t0 = time(NULL);
    c0 = clock();
    while (i < n) {
        buff = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > buff)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = buff;
        i++;
    }
    c1 = clock();
    t1 = time(NULL);
    std::cout << "ellapsed wall clock time: " << ((long)(t1 - t0)) << std::endl;
    std::cout << "ellapsed wall clock time: " << (float)(c1 - c0) / CLOCKS_PER_SEC << std::endl;
}


//Insertion Sort with one check
void Method2(int*& a, int n)
{
    time_t t0, t1;
    clock_t c0, c1;

    int* arr = new int[n + 1];

    for (int i = 0; i < n; i++) {
        arr[i] = a[i];
    }

    int i = 1;
    int j;

    t0 = time(NULL);
    c0 = clock();
    while (i < n) {
        arr[n] = arr[i];
        j = i - 1;
        while (arr[j] > arr[n])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = arr[n];
        i++;
    }
    c1 = clock();
    t1 = time(NULL);
    std::cout << "ellapsed wall clock time: " << ((long)(t1 - t0)) << std::endl;
    std::cout << "ellapsed wall clock time: " << (float)(c1 - c0) / CLOCKS_PER_SEC << std::endl;

}

//Insertion with Binary Search
void Method3(int*& a, int n) {
    time_t t0, t1;
    clock_t c0, c1;

    int* arr = new int[n + 1];

    for (int i = 0; i < n; i++) {
        arr[i] = a[i];
    }

    int j;
    int i = 1;
    t0 = time(NULL);
    c0 = clock();
    while (i < n) {
        arr[n] = arr[i];
        j = i - 1;
        int min = 0;
        int max = i;
        int index = (max + min) / 2;


        while (arr[n] != arr[index]) {
            if (min > max) {
                break;
            }
            else if (arr[n] > arr[index]) {
                min = index + 1;
            }
            else { max = index - 1; }
            index = (max + min) / 2;
        }

        if (arr[n] > arr[index]) {
            index++;
        }

        while (j >= index)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[index] = arr[n];
        i++;
    }
    c1 = clock();
    t1 = time(NULL);
    std::cout << std::endl;
    std::cout << "ellapsed wall clock time: " << ((long)(t1 - t0)) << std::endl;
    std::cout << "ellapsed wall clock time: " << (float)(c1 - c0) / CLOCKS_PER_SEC << std::endl;
}

int main() {
    srand(time(NULL));
    int n = 10000;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    std::cout << "Method 1:\n";
    Method1(arr, n);
    std::cout << "\nMethod 2:\n";
    Method2(arr, n);
    std::cout << "\nMethod 3:\n";
    Method3(arr, n);


    return 0;
}