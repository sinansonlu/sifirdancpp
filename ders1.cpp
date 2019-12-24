#include <iostream>

using namespace std;

int main()
{
    int secim; // Kullanıcı bir seçim girecek
    // Onu tutacak bir int değişken belirle
    
    // Menüyü göster
    cout << "Programa hoşgeldiniz.\n";
    cout << "İşlem seçiniz:\n";
    cout << "1. Toplama\n";
    cout << "2. Çıkartma\n";
    cout << "3. Bölme\n";
    cout << "4. Çarpma\n";
    cout << "Seçenek: ";
    
    // Kullanıcıdan seçimini al
    cin >> secim;
    
    // Kullanıcının seçimi geçerli bir seçim mi (seçim [1,4] aralığında olmalı)
    // Kontrol et
    if(secim >= 1 && secim <= 4) {
        // Kullanıcın seçimi geçerli bir seçim
        int a, b; // İki değişken, a ve b'yi int olarak belirle
        // Kullanıcıdan bu iki değişkeni al
        cout << "A=";
        cin >> a;
        cout << "B=";
        cin >> b;
        
        // Sonucu atayacak bir değişken belirle
        int sonuc;
        
        // Seçimin ne olduğuna bakarak sonucu hesapla
        if(secim == 1) sonuc = a + b;
        else if(secim == 2) sonuc = a - b;
        else if(secim == 3) {
            // Seçim 3 ise bölen'i kontrol et
            if(b==0) {
                // Bölen 0 ise işlemi yapma
                cout << "0'a bölme işlemi geçersiz.";
            }
            else {
                // 0 değilse bölme işlemini yap
                sonuc = a / b;
            }
        }
        else if(secim == 4) sonuc = a * b;
        
        // Sonucu ekrana yaz
        cout << "İşlem sonucu: " << sonuc;
    }
    else {
        // Kullanıcının seçimi geçerli bir seçim değil!
        // Kullanıcıya bilgi ver!
        cout << "Yanlış seçim!\n";
    }
}
