#include "Processes.hpp"

int main(){
    Processes process; //Processes sınıfımdan nesne olusturdum
    process.AddToTreeAndWrite(); //verileri dosyadan okuyup agaca ekleyen ve eklediği düğümlerin ilgili bilgilerini level order biçinde yazdıran metodu cagırdım
    
    return 0;
}