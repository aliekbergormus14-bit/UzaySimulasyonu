#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void serbestDusme(float *g,char **isimler);
void yukariAtis(float *g,char **isimler);
void agirlik(float *g,char **isimler);
void potansiyelEnerji(float *g,char **isimler);
void hidrostatikBasinc(float *g,char **isimler);
void arsimet(float *g,char **isimler);
void basitSarkac(float *g,char **isimler);
void ipGerilmesi(float *g,char **isimler);
void asansor(float *g,char **isimler);

int main()
{
    float g_ivmeleri[]={3.70, 8.87, 9.806, 3.71, 24.79, 10.44, 8.69, 11.15};

    char *gezegen_isimleri[]={"Merkur","Venus","Dunya","Mars","Jupiter","Saturn","Uranus","Neptun"};

    char bilim_insani[50];
    int secim;

    printf("--- UZAY SIMULASYONU ---\n");
    printf("Bilim Insani Adi ve Soyadi: ");
    scanf(" %[^\n]s",bilim_insani);

    do {
        printf("\n------------------------------------------------\n");
        printf("Sayin %s, lutfen bir deney seciniz:\n", bilim_insani);
        printf("1. Serbest Dusme Deneyi\n");
        printf("2. Yukari Atis Deneyi\n");
        printf("3. Agirlik Deneyi\n");
        printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n");
        printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
        printf("7. Basit Sarkac Periyodu Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n");
        printf("9. Asansor Deneyi\n");
        printf("------------------------------------------------\n");
        printf("Seciminiz (Cikis icin -1): ");
        scanf("%d", &secim);

        switch(secim){
            case 1:
                serbestDusme(g_ivmeleri,gezegen_isimleri);
                break;
            case 2:
                yukariAtis(g_ivmeleri,gezegen_isimleri);
                break;
            case 3:
                agirlik(g_ivmeleri,gezegen_isimleri);
                break;
            case 4:
                potansiyelEnerji(g_ivmeleri,gezegen_isimleri);
                break;
            case 5:
                hidrostatikBasinc(g_ivmeleri,gezegen_isimleri);
                break;
            case 6:
                arsimet(g_ivmeleri,gezegen_isimleri);
                break;
            case 7:
                basitSarkac(g_ivmeleri,gezegen_isimleri);
                break;
            case 8:
                ipGerilmesi(g_ivmeleri,gezegen_isimleri);
                break;
            case 9:
                asansor(g_ivmeleri,gezegen_isimleri);
                break;
            case -1:
                printf("Simulasyondan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }

    }while(secim!=-1);

    return 0;
}

// 1. Serbest Düþme Deneyi
void serbestDusme(float *g,char **isimler){
    float t,h;
    printf("\n--- SERBEST DUSME DENEYI ---\n");
    printf("Dusus suresini giriniz (sn): ");
    scanf("%f",&t);

    // KURAL: Negatif ise ternary ile pozitife cevir
    t=(t<0)? -t:t;

    printf("\n--- Sonuclar ---\n");
    for(int i=0;i<8;i++){
        // KURAL: Pointer aritmetigi ile diziye erisim *(g+i)
        float yercekimi=*(g+i);

        // Formul: h=0.5*g*t^2
        h=0.5*yercekimi*t*t;

        printf("%-10s icin dusus mesafesi (h): %.2f m\n",*(isimler+i),h);
    }
    printf("\n");
}

// 2. Yukarý Atýþ Deneyi
void yukariAtis(float *g,char **isimler){
    float v0,h_max;
    printf("\n--- YUKARI ATIS DENEYI ---\n");
    printf("Firlatma hizini giriniz (m/s): ");
    scanf("%f",&v0);

    // Negatif kontrolu
    v0=(v0<0)? -v0:v0;

    printf("\n--- Sonuclar ---\n");
    for(int i=0;i<8;i++) {
        float yercekimi=*(g+i);

        // Formul: h_max=v0^2 / (2*g)
        h_max=(v0*v0)/(2*yercekimi);

        printf("%-10s icin maks. yukseklik: %.2f m\n",*(isimler+i),h_max);
    }
    printf("\n");
}

// 3. Aðýrlýk Deneyi
void agirlik(float *g,char **isimler){
    float m,G;
    printf("\n--- AGIRLIK DENEYI ---\n");
    printf("Cismin kutlesini giriniz (kg): ");
    scanf("%f",&m);

    // Negatif kontrolu
    m=(m<0)? -m:m;

    printf("\n--- Sonuclar ---\n");
    for(int i=0;i<8;i++){
        float yercekimi=*(g+i);

        // Formul: G=m*g
        G=m*yercekimi;

        printf("%-10s icin agirlik: %.2f N\n",*(isimler+i),G);
    }
    printf("\n");
}
// 4. Kütleçekimsel Potansiyel Enerji Deneyi
void potansiyelEnerji(float *g,char **isimler){
    float m,h,Ep;
    printf("\n--- KUTLECEKIMSEL POTANSIYEL ENERJI DENEYI ---\n");

    printf("Cismin kutlesini giriniz (kg): ");
    scanf("%f",&m);
    // Ternary ile negatif kontrolü
    m=(m<0)? -m:m;

    printf("Yerden yuksekligi giriniz (m): ");
    scanf("%f",&h);
    // Ternary ile negatif kontrolü
    h=(h<0)? -h:h;

    printf("\n--- Sonuclar ---\n");
    for(int i=0;i<8;i++) {
        float yercekimi=*(g+i); // Pointer eriþimi

        // Formül: Ep=m*g*h
        Ep=m*yercekimi*h;

        printf("%-10s icin potansiyel enerji: %.2f J\n",*(isimler+i),Ep);
    }
    printf("\n");
}

// 5. Hidrostatik Basýnç Deneyi
void hidrostatikBasinc(float *g,char **isimler){
    float rho,h,P;
    printf("\n--- HIDROSTATIK BASINC DENEYI ---\n");

    printf("Sivinin yogunlugunu giriniz (kg/m^3): ");
    scanf("%f",&rho);
    rho=(rho<0)? -rho:rho; // Negatif düzeltme

    printf("Derinligi giriniz (m): ");
    scanf("%f",&h);
    h=(h<0)? -h:h; // Negatif düzeltme

    printf("\n--- Sonuclar ---\n");
    for(int i=0;i<8;i++) {
        float yercekimi=*(g+i);

        // Formül: P=rho*g*h
        P=rho*yercekimi*h;

        printf("%-10s icin basinc: %.2f Pa\n",*(isimler+i),P);
    }
    printf("\n");
}

// 6. Arþimet Kaldýrma Kuvveti Deneyi
void arsimet(float *g,char **isimler){
    float rho,V,Fk;
    printf("\n--- ARSIMET KALDIRMA KUVVETI DENEYI ---\n");

    printf("Sivinin yogunlugunu giriniz (kg/m^3): ");
    scanf("%f",&rho);
    rho=(rho<0)? -rho:rho;

    printf("Cismin batan hacmini giriniz (m^3): ");
    scanf("%f",&V);
    V=(V<0)? -V:V;

    printf("\n--- Sonuclar ---\n");
    for(int i=0;i<8;i++) {
        float yercekimi=*(g+i);

        // Formül: Fk=rho*g*V
        Fk=rho*yercekimi*V;

        printf("%-10s icin kaldirma kuvveti: %.2f N\n",*(isimler+i),Fk);
    }
    printf("\n");
}
// 7. Basit Sarkaç Periyodu Deneyi
void basitSarkac(float *g,char **isimler){
    float L,T;
    const float PI=3.14159; // Pi sayisi
    printf("\n--- BASIT SARKAC PERIYODU DENEYI ---\n");

    printf("Sarkacin ip uzunlugunu giriniz (m): ");
    scanf("%f",&L);
    // KURAL: Negatif ise ternary ile pozitife cevir
    L=(L<0)? -L:L;

    printf("\n--- Sonuclar ---\n");
    for(int i=0;i<8;i++) {
        float yercekimi=*(g+i); // Pointer eriþimi

        // Formül: T=2*pi*karekök(L/g)
        // sqrt fonksiyonu math.h kütüphanesinden gelir
        T=2*PI*sqrt(L/yercekimi);

        printf("%-10s icin periyot: %.2f sn\n",*(isimler+i),T);
    }
    printf("\n");
}

// 8. Sabit Ýp Gerilmesi Deneyi
void ipGerilmesi(float *g,char **isimler){
    float m,T;
    printf("\n--- SABIT IP GERILMESI DENEYI ---\n");

    printf("Asili cismin kutlesini giriniz (kg): ");
    scanf("%f",&m);
    // Negatif kontrolü
    m=(m<0)? -m:m;

    printf("\n--- Sonuclar ---\n");
    for(int i=0;i<8;i++) {
        float yercekimi=*(g+i);

        // Formül: T=m*g (Aðýrlýk ile ayný mantýk)
        T=m*yercekimi;

        printf("%-10s icin ip gerilmesi: %.2f N\n",*(isimler+i),T);
    }
    printf("\n");
}

// 9. Asansör Deneyi
void asansor(float *g,char **isimler){
    float m,a,N;
    int durum;

    printf("\n--- ASANSOR DENEYI ---\n");

    printf("Cismin kutlesini giriniz (kg): ");
    scanf("%f",&m);
    m=(m<0)? -m:m; // KURAL: Negatif input kontrolü ternary ile

    printf("Asansorun ivmesini giriniz (m/s^2): ");
    scanf("%f",&a);
    a=(a<0)? -a:a; // KURAL: Negatif input kontrolü ternary ile

    printf("\nLutfen asansorun hareket durumunu seciniz:\n");
    printf("1. Yukari yonlu HIZLANIYOR veya Asagi yonlu YAVASLIYOR (Agirlik artar)\n");
    printf("2. Asagi yonlu HIZLANIYOR veya Yukari yonlu YAVASLIYOR (Agirlik azalir)\n");
    printf("Seciminiz: ");
    scanf("%d",&durum);

    printf("\n--- Sonuclar ---\n");
    for(int i=0;i<8;i++) {
        float yercekimi=*(g+i); // Pointer eriþimi

        // Buradaki if-else AKIÞ kontrolüdür.
        // Çünkü burada bir sayýyý pozitife çevirmiyoruz, formül seçiyoruz.
        if(durum==1){
            // Formül 9: N=m*(g+a)
            N=m*(yercekimi+a);
        }else{
            // Formül 9.1: N=m*(g-a)
            N=m*(yercekimi-a);
        }

        N=(N<0)? -N:N; // KURAL: Hesaplanan degerin mutlak degeri ternary operatoru ile aliniyor

        printf("%-10s icin etkin agirlik: %.2f N\n",*(isimler+i),N);
    }
    printf("\n");
}
