#include<iostream>
#include<pthread.h>
#include<vector>
#include<cstdlib>
using namespace std;
int max_size;
int m;
int x;
vector<int> arr;
int sum[4] = { 0 };
int part = 0;

void* sum_array(void* arg)
{
    max_size = sizeof(arr)/sizeof(arr[0]);
    // Each thread computes sum of 1/4th of array
    int thread_part = part++;

    for (int i = thread_part * (max_size / 4); i < (thread_part + 1) * (max_size/ 4); i++)
        sum[thread_part] += arr[i];
}

int main(int argc,char* argv[]){
    x = atoi(argv[1]);
    m = atoi(argv[2]);
    for(int i=0;i<m;i++){
    arr.push_back(i);
    }
    pthread_t threads[x];
    for (int i = 0; i < x; i++){
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);
    }

    for (int i = 0; i < x; i++)
        pthread_join(threads[i], NULL);

    int total_sum = 0;
    for (int i = 0; i < x; i++)
        total_sum += sum[i];

    cout << "sum is " << total_sum << endl;

return 0;
}
