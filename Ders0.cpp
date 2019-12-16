#include <iostream>

using namespace std;

int main()
{
    // a ve b değişkenlerini bildir
    int a, b;
    
    // kullanıcıdan a'nın değerini iste
    cout << "A'nin degerini gir: ";
    
    // kullanıcının girdiği "şeyi" a tam sayısında sakla
    cin >> a;
    
    // kullanıcıdan b değerini iste ve b'de sakla
    cout << "B'nin degerini gir: ";
    cin >> b;
    
    // sonucu a + b olarak hesapla
    int sonuc = a + b;
    
    // sonucu kullanıcıya göster
    cout << "Islem sonucu: " << sonuc;
}
