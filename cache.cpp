#include "cache.hpp"

int main(){

    int num_page = 0, size = 0, elem, heat = 0;
    CacheList<int> cache(5);

    cout << "Enter page number: ";
    cin >> num_page;
    cout << "Enter cache size: ";
    cin >> size;

    vector<Node<int> *> CacheTable(size);
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