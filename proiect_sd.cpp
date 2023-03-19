#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace std::chrono;


void quicksort(int lo, int hi, int v[])
{
    if (hi > lo)
    {
        int pivot = v[hi];
        int j = lo;
        int i = lo - 1;

        while (j < hi)
        {
            if (v[j] < pivot)
            {
                i++;
                swap(v[i], v[j]);
            }
            j++;
        }
        swap(v[hi], v[i + 1]);

        quicksort(lo, i, v);
        quicksort(i + 2, hi, v);
    }
}

int vasIsMax(int v[], int n)
{
    int ma = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > ma)
            ma = v[i];
    return ma;
}

void countSort(int v[], int n, int exp)
{
    int *afisare = new int[n];

    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(v[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        afisare[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        v[i] = afisare[i];

    delete[] afisare;
}

void radixsort(int v[], int n)
{
    int m = vasIsMax(v, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(v, n, exp);
}

void MergeSort(int v[], int lo, int hi)
{
    if (lo < hi)
    {
        int mi = (lo + hi)/2;
        MergeSort(v, lo, mi);
        MergeSort(v, mi + 1, hi);

        int *temp = new int[hi - lo + 1];

        int i = lo, j = mi + 1, k = 0;
        while (i <= mi && j <= hi)
            if (v[i] < v[j])
                temp[k++] = v[i++];
            else
                temp[k++] = v[j++];

        while (i <= mi)
            temp[k++] = v[i++];
        while (j <= hi)
            temp[k++] = v[j++];

        for (i = lo; i <= hi; i++)
            v[i] = temp[i - lo];

        delete[] temp;
    }   
    
}

void shellSort(int v[], int n)
{
    for (int gaura = n / 2; gaura > 0; gaura /= 2)
    {
        for (int i = gaura; i < n; i++)
        {
            int temp = v[i];

            int j;

            for (j = i; j >= gaura && v[j - gaura] > temp; j -= gaura)
                v[j] = v[j - gaura];

            v[j] = temp;

        }
    }
}

void prostSort(int v[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (v[i] > v[j])
            {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
}

void print(int v[], int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}

int nrfabi()
{
    int nr = 0;
    int p = 1;
    for (int i = 0; i < 9; i++)
    {
        nr += p * (rand() % 10);
        p *= 10;
    }
      
    return nr;
}

void generareVector(int v[], int range, int size)
{
    for (int i = 0; i < size; i++)
    {
        v[i] = nrfabi() % range;
    }
}

class TimpSort
{
public:
    double min;
    double max;
    double mid;

    TimpSort()
    {
        min = DBL_MAX;
        max = 0;
        mid = 0;
    }
    void AddTime(int time, int nrteste)
    {
        if (time < min)
            min = time;
        if (time > max)
            max = time;
        mid += double(time) / nrteste;
    }
    void printTimp()
    {
        cout << "A avut un timp minim de: " << min << endl;
        cout << "A avut un timp maxim de: " << max << endl;
        cout << "A avut in medie un timp de: " << mid << endl;
    }
};


int main()
{
    int size, range, nrteste;

    cout << "Marimea vectorului:";
    cin >> size;
    cout << "Valoarea maxima a elementelor:";
    cin >> range;
    cout << "Cate teste sa facem?";
    cin >> nrteste;


    int *v = new int[size];

    TimpSort Merge, Quick, Radix, Prost, Shell, Intro;

    for (int test = 0; test < nrteste; test++)
    {

        generareVector(v, range, size); 

        // bubbleSort
        
        auto start = high_resolution_clock::now();
        prostSort(v, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        int durata = duration.count();
        Prost.AddTime(durata, nrteste);
        
        // quickSort

        generareVector(v, range, size);

        start = high_resolution_clock::now();
        quicksort(0, size, v);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

        durata = duration.count();
        Quick.AddTime(durata, nrteste);

        //shellSort

        generareVector(v, range, size);

        start = high_resolution_clock::now();
        shellSort(v, size);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

        durata = duration.count();
        Shell.AddTime(durata, nrteste);

        //mergesort

        generareVector(v, range, size);

        start = high_resolution_clock::now();
        MergeSort(v, 0, size);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

        durata = duration.count();
        Merge.AddTime(durata, nrteste);

        //radixsort

        generareVector(v, range, size);

        start = high_resolution_clock::now();
        radixsort(v, size-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

        durata = duration.count();
        Radix.AddTime(durata, nrteste);

        //introsort
        
        generareVector(v, range, size);

        start = high_resolution_clock::now();
        sort(v, v+size);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

        durata = duration.count();
        Intro.AddTime(durata, nrteste);



    }
    cout << "prostSort: " << endl;
    Prost.printTimp();

    cout << "quickSort: " << endl;
    Quick.printTimp();

    cout << "shellSort: " << endl;
    Shell.printTimp();

    cout << "mergeSort: " << endl;
    Merge.printTimp();

    cout << "radixsort: " << endl;
    Radix.printTimp();

    cout << "introsort: " << endl;
    Intro.printTimp();

    return 0;
}


// we have radixsort
// we have mergesort
// we have shellsort
// we have quicksort
// we have usorSort