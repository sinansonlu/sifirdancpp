#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int f = 0; // kullanıcı girdisini tutacak değişken
    int ff = 0; // kullanıcı girdisinin bu kopyası üzerinden işlem yapacağız
    
    // program f'değeri 0'dan büyük eşit olduğu sürece devam edecek
    while (f >= 0) {
        // overflow ihtimaline karşı sonucun doğru olup olmadığını belirtiyoruz
        bool sonucDogruMu = true;
        bool sonucDogruMu2 = true;
        
        // kullanıcıdan sayı alıyoruz
        cout << "Hesaplanacak sayıyı girin: ";
        cin >> f;
        
        // işlemde kullanmak üzere f'nin bir kopyasını oluşturduk
        ff = f;
        
        // faktöryel hesabı için sonuç 1'den başlıyor
        int sonuc = 1;
        
        // ff değeri 1'den büyük olduğu müddetçe devam ediyoruz
        while(ff > 1) {
            // eğer mevcut ff ile sonucu çarptığımızda sonucun orijinal halinden büyük çıkıyorsa overflow yok
            if(sonuc * ff > sonuc) {
                // bu durumda sonucu güncelliyoruz
                sonuc *= ff;
                // ve ff'yi bir eksiltiyoruz
                ff--;    
            }
            else {
                // çarptıktan sonra daha küçük bir sayıya ulaşıyorsak overflow olmuştur
                // bu durumda gerekli bool'u false yapıp döngüden çıkmak için ff'yi 1'e eşitliyoruz
                sonucDogruMu = false;
                ff = 1;
                
                // çarpım için daha sağlıklı overflow fark etme yöntemleri var:
                // https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-multiply-overflow
            }
        }
        
        // ikinci hesapta sayıyı her seferinde 2 azaltarak sonuc2'ye eklediğimiz bir hesap yapacağız
        int sonuc2 = 0;
        
        // for döngüsü en başta ff'yi f'ye eşitliyor
        // ff değeri 0'dan büyük olduğu sürece döngüye devam ediyor
        // her döngü sonunda ff'yi 2 azaltıyor
        for(ff = f; ff > 0; ff-=2){
            // toplama işlemi sırasında overflow varsa tespit ediyoruz
            if(sonuc2 > INT_MAX - ff) {
                // yine gerekli bool'u false yapıp döngüden çıkmak için ff'yi sıfıra eşitliyoruz
                sonucDogruMu2 = false;
                ff = 0;
            }
            else{
                // eğer overflow yoksa mevcut ff değerini sonuc2'ye ekliyoruz
                sonuc2 += ff;
            }
        }

        // sonuçlar doğruysa görüntüleyip yanlışsa kullanıcıya bildiriyoruz
        if(sonucDogruMu2)
            cout << "2'li toplamanın sonucu: " << sonuc2 << "\n";
        else
            cout << "2'li toplama hesaplanamadı!\n";
        
        if(f >= 0 && sonucDogruMu)
            cout << f << "! = " << sonuc << "\n";
        else if(!sonucDogruMu)
            cout << "Faktöryel hesaplanamadı.\n";
    }
    
    // f negatif olursa program döngüsü bitiyor
    cout << "Program sonlandırıldı";

    return 0;
}
