#include "cache.hpp"

int main(){

    int num_page = 1024, size = 0, elem, heat = 0;
    int isex;

    cout << "Enter cache size: ";
    cin >> size;

    CacheList<int> cache(size);

    vector<Node<int> *> CacheTable(num_page);
    while(1){

        cin >> elem;
        if (elem < 0) break;

        if (CacheTable[elem] == NULL) cache.pushtop(CacheTable, 0, elem);
    
        else{ 

            cache.movetop(CacheTable, 0, elem);
            heat++;
        }
        
        cache.desplayList();    
    }

    cout << "Number of heat: " << heat << endl;
    cache.clear();

    return 0;
}