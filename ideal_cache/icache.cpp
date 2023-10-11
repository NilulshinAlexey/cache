#include "icache.hpp"

int main(){

    int num_page = 1024, size = 0, elem = 0, heat = 0;

    cout << "Enter cache size: ";
    cin >> size;

    CacheList<int> icache(size);

    while(1){

        cin >> elem;
        if (elem < 0) break;
    }

    
    
    return 0;
}