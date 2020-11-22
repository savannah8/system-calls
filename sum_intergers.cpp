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

void *sum_arr(void* arg)
{
    max_size = sizeof(arr)/sizeof(arr[0]);
    int thread_part = part++;

    for (int i = thread_part * (max_size / 4); i < (thread_part + 1) * (max_size/ 4); i++){
        sum[thread_part] += arr[i];
    }
    return NULL;
}

int main(int argc,char* argv[]){
    for(int i=0;i<argc;i++){
    x = atoi(argv[i]);
    m = atoi(argv[i]);
    }
    for(int i=0;i<m;i++){
    arr.push_back(i);
    }
    pthread_t threads[x];
    for (int i = 0; i < x; i++){
        pthread_create(&threads[i], NULL, sum_arr, (void*)NULL);
    }

    for (int i = 0; i < x; i++)
        pthread_join(threads[i], NULL);

    int total_sum = 0;
    for (int i = 0; i < x; i++)
        total_sum += sum[i];

    cout << "The sum is " << total_sum << endl;

return 0;
}
