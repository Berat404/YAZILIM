#include <iostream>
#include <cmath>

using namespace std;

// Sayının asal olup olmadığını kontrol eden fonksiyon
bool asal(int n) {
    // 2'den küçük sayılar (0 ve 1) asal değildir
    if (n < 2) return false;
    
    // Sayının kareköküne kadar bölünebilirlik kontrolü yapılır
    for (int i = 2; i <= sqrt(n); i++) {
        // Eğer sayı herhangi bir değere tam bölünürse asal değildir
        if (n % i == 0) return false;
    }
    
    // Hiçbir bölen bulunamadıysa sayı asaldır
    return true;
}

int main() {
    int limit = 10000000; // 10^7 sınırı
    int kuvvet = 1;       // 2^0 = 1 başlangıç değeri

    cout << "2^k Civarindaki Asal Sayilar:" << endl;
    cout << "---------------------------------" << endl;

    // Kuvvet değeri limiti geçmediği sürece döngü devam eder
    while (kuvvet <= limit) {
        
        cout << "2^k = " << kuvvet << " icin civardaki asallar: ";
        
        // 2^k değerinin -5 ve +5 aralığındaki sayıları kontrol et
        for (int i = kuvvet - 5; i <= kuvvet + 5; i++) {
            
            // Fonksiyonu çağırarak sayının asal olup olmadığını kontrol et
            if (asal(i)) {
                cout << i << " "; 
            }
        }
        
        cout << endl; 
        kuvvet *= 2;  // Bir sonraki 2'nin kuvvetini hesapla (2 katına çıkar)
    }

    return 0;
}
