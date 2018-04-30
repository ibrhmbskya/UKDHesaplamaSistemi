#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float UKD_Hesapla(int,int,float);
void Anaekran();
float Yuzde (int,int);
float Ortalama (int,int);

int main()
{
    system("color 17");
    system("title UKD hesaplama v1.0 BETA");

    int tur,lisans_no,ukd,rakip_ukd,i,yeniUKD=0,acik_say=0,gencler_say=0,yildizlar_say=0,kucukler_say=0,minikler_say=0;
    int top_oyuncu_say=0,max_ukd_kazananilkUKD=0,max_ukd_kaybedenilkUKD=0,ukdsize_kaybeden_say=0,ukdsiz_mac_say=0;
    int kategori1=0,kategori2=0,kategori3=0,kategori4=0,kategori5=0,UKD_top=0,max_ukd=0,max_ukdLisans=0,minik_maxUKD=0,minik_maxUKD_lisans=0;
    int max_ukd_kazanan=0,max_ukd_kazananLisans=0,max_ukd_kazananUKD=0,max_ukd_kaybeden=0,max_ukd_kaybedenLisans =0,max_ukd_kaybedenUKD,sifirlanan_say=0;
    int tekmac_max_kazanan=0,tekmac_max_kazananLisans=0,tekmac_max_kazananUKD=0,tekmac_max_kaybeden=0,tekmac_max_kaybedenLisans=0,tekmac_max_kaybedenUKD=0;
    char yas_kategori,max_ukdYas;
    float kazanilan_ukd =0,toplam_macPuan=0,toplam_kazanilanUKD=0,mac_puani,top_acikUKD=0,top_genclerUKD=0,top_yildizlarUKD=0,top_kucuklerUKD=0,top_miniklerUKD=0;

    Anaekran();                          // Ana ekran fonksiyonu  kullanıcının enter tusuna basmasını bekler sonra program aktif olur

    printf("\n-Tur sayisisini girin:\n");
    scanf("%d",& tur);                      // Tur sayisinin alınması

    while(tur < 1 || tur >1000)
    {
        printf("Yanlis veri girisi!\n");
        printf("\n-Tur sayisisini girin:\n");       //Tur sayisinin dogru girilip girilmediği kontrolü
        scanf("%d",& tur);
    }

    do
    {
        printf("-Lisans numarasini girin:\n");          // her oyuncuya ayit lisans numarası nın alınması 0 oldugu zaman program bitecek istatistikler yazdırılacaktir
        scanf("%d",&lisans_no);

        toplam_macPuan=0;
        kazanilan_ukd=0;
        yeniUKD=0;                                      //oyunculara ayit değişkenlerin sıfırlanması
        toplam_kazanilanUKD=0;


        if (lisans_no < 1)
            break;///// eksi degerde programi bitecek
        do
        {
            printf("-Yas kategorisini girin:\n\t Acik\n\t Gencler\n\t Yildizlar\n\t Kucukler\n\t Minikler\n ");
            fflush(stdin);
            yas_kategori=getchar();

            if (yas_kategori == 'a'|| yas_kategori ==  'A')
                acik_say++;
            else if (yas_kategori == 'g'||  yas_kategori == 'G')           //Yas kategorisinin alınması, kontrolü ve o kategorideki oyuncu sayaçları
                gencler_say++;
            else if (yas_kategori == 'y'||  yas_kategori == 'Y')
                yildizlar_say++;
            else if (yas_kategori == 'k'|| yas_kategori ==  'K')
                kucukler_say++;
            else if (yas_kategori == 'm'|| yas_kategori ==  'M')
                minikler_say++;
            else
                printf("Yanlis veri girisi!\n");

        }
        while(yas_kategori != 'a'&& yas_kategori != 'A' && yas_kategori !='g' && yas_kategori !='G' && yas_kategori !='y' && yas_kategori != 'Y' && yas_kategori !='k' && yas_kategori != 'K' && yas_kategori !='m' && yas_kategori !='M');


        do
        {
            printf("-UKD puanini girin(1000 den buyuk):\n");
            scanf("%d",& ukd);
        }
        while(ukd<1000);

        if (ukd >= 2400)
            kategori1++;
        else if (ukd >=2000 && ukd <=2399)      //UKD puanı 2400 ve daha çok olan, 2000-2399 arasında olan, 1600-1999 arasında  olan, 1300-1599 arasında olan ve 1300’den az olan sporcuların saydirilmasi
            kategori2++;
        else if (ukd >=1600 && ukd <=1999)
            kategori3++;
        else if (ukd >=1300 && ukd <=1599)
            kategori4++;
        else if (ukd <=1299)
            kategori5++;

        for(i=0; i<tur; i++)
        {
            printf("%d. turda ki rakibinin UKD puanini girin:\n",i+1);  // Tura göre UKD li oyuncunun rakip ve mac bilgilerinin alınması
            scanf("%d",&rakip_ukd);

            if(rakip_ukd<1000)
                rakip_ukd=0;       // Rakibin UKD puani 1000 den düsük ise 0 olarak islenecektir

            do
            {
                printf("Mactan kazandigi puani girin: \n\tGalibiyet icin 1 \n\tMalubiyet icin 0\n\t beraberlik icin 0.5\n");
                scanf("%f",&mac_puani);
            }
            while(mac_puani != 1 && mac_puani != 0 && mac_puani != 0.5);

            if (rakip_ukd < 1000)
            {
                if (mac_puani==0)
                {
                    ukdsize_kaybeden_say++;  // UKD li oyuncuların UKD siz oyuncuşala oynadigi maclarin saydirilmasi ve varsa malubiyetin saydirilmasi
                }
                ukdsiz_mac_say++;
            }


            toplam_macPuan+=(float)mac_puani;
            kazanilan_ukd = UKD_Hesapla(ukd,rakip_ukd,mac_puani);  // UKD hesapla fonk. cagırılması
            toplam_kazanilanUKD+=kazanilan_ukd;
            yeniUKD=ukd + toplam_kazanilanUKD;

            if (tekmac_max_kazanan<kazanilan_ukd)
            {
                tekmac_max_kazananLisans=lisans_no;     // tek macta en cok UKd kazanan oyuncunun bulunması
                tekmac_max_kazananUKD=yeniUKD;
                tekmac_max_kazanan = kazanilan_ukd;
            }
            else if(tekmac_max_kaybeden > kazanilan_ukd)
            {
                tekmac_max_kaybedenLisans = lisans_no;
                tekmac_max_kaybedenUKD = yeniUKD;       // tek macta en cok ukd kaybeden oyuncunun bulunması
                tekmac_max_kaybeden = kazanilan_ukd;
            }

        }

        if (yeniUKD < 1000)
        {
            yeniUKD=0;
            sifirlanan_say++;     // UKD 1000 puanin altna düstügünde UKD sıfırlanması
        }

        if (toplam_kazanilanUKD > max_ukd_kazanan)
        {
            max_ukd_kazanan = toplam_kazanilanUKD;       // EN cok ukd puani kazanan oyuncunun bulunması
            max_ukd_kazananLisans = lisans_no;
            max_ukd_kazananUKD = yeniUKD;
            max_ukd_kazananilkUKD = toplam_kazanilanUKD-ukd;
        }
        else if (toplam_kazanilanUKD < max_ukd_kaybeden)
        {
            max_ukd_kaybeden = toplam_kazanilanUKD;
            max_ukd_kaybedenLisans = lisans_no;             // en cok ukd kaybeden oyuncunun bulunması
            max_ukd_kaybedenUKD = yeniUKD;
            max_ukd_kaybedenilkUKD = toplam_kazanilanUKD - ukd ;

        }

        UKD_top+=yeniUKD;

        if (yeniUKD > max_ukd)
        {
            max_ukd = yeniUKD;              // En yuksek ukd puanina sahip oyuncunun bulunmasi
            max_ukdLisans = lisans_no;
            max_ukdYas = yas_kategori;
        }

        if (yas_kategori == 'm' || yas_kategori == 'M')
        {
            if(yeniUKD > minik_maxUKD )
            {
                minik_maxUKD = yeniUKD;             // minikler ategorisinde en cok puan kazanan sprocunun bulunmasi
                minik_maxUKD_lisans = lisans_no;
            }

        }

    printf("********************************************************************************\n");
        printf("\t-Lisans numarasi : %d\n",lisans_no);
        printf("\t-Yas kategorisi : (%c) ",yas_kategori);

        if (yas_kategori == 'a'|| yas_kategori == 'A')
        {
            printf("Acik\n");
            top_acikUKD+=yeniUKD;
        }

        if (yas_kategori == 'g'|| yas_kategori == 'G')
        {
            printf("Gencler\n");
            top_genclerUKD+=yeniUKD;                                // Tek oyuncu icin butun verisi bittikten sonra istenen bilgilerin ekrana yazdırılmasi
        }

        else if (yas_kategori == 'y'|| yas_kategori == 'Y')
        {
            printf("Yildizlar\n");
            top_yildizlarUKD+=yeniUKD;

        }
        else if (yas_kategori == 'k'||  yas_kategori == 'K')
        {
            printf("Kucukler\n");
            top_kucuklerUKD+=yeniUKD;
        }

        else if (yas_kategori == 'm'||yas_kategori == 'M')
        {
            printf("Minikler\n");
            top_miniklerUKD+=yeniUKD;
        }

        printf("\t-Turnuvada kazandigi toplam mac puani:%.1f  \n",toplam_macPuan);
        printf("\t-Turnuva sonucundaki toplam UKD degisimi: %.2f  \n",toplam_kazanilanUKD);
        printf("\t-Turnuva sonucundaki yeni UKD puani: %d  \n",yeniUKD);
    printf("********************************************************************************\n");

        top_oyuncu_say++;
    }
    while(lisans_no > 0);

    top_oyuncu_say= acik_say+ gencler_say+ yildizlar_say+ kucukler_say + minikler_say;

    printf("********************************************************************************\n");
    printf("                                ISTATISTIKLER\n");
    printf("********************************************************************************\n");
    printf("Acik yas kategorisindeki sporcularin \nSayilari: %d\nYuzdesi: %%%.2f\nOrtalama UKD:%.2f \n\n",acik_say,Yuzde(acik_say,top_oyuncu_say),Ortalama(top_acikUKD,acik_say) );
    printf("Gencler yas kategorisindeki sporcularin \nSayilari: %d \nYuzdesi: %%%.2f\nOrtalama UKD:%.2f \n\n",gencler_say,Yuzde(gencler_say,top_oyuncu_say),Ortalama(top_genclerUKD,gencler_say));
    printf("Yildizlar yas kategorisindeki sporcularin \nSayilari: %d \nYuzdesi: %%%.2f\nOrtalama UKD:%.2f \n\n",yildizlar_say,Yuzde(yildizlar_say,top_oyuncu_say),Ortalama(top_yildizlarUKD,yildizlar_say));
    printf("Kucukler yas kategorisindeki sporcularin \nSayilari: %d \nYuzdesi: %%%.2f\nOrtalama UKD:%.2f \n\n",kucukler_say,Yuzde(kucukler_say,top_oyuncu_say),Ortalama(top_kucuklerUKD,kucukler_say));
    printf("Minikler yas kategorisindeki sporcularin \nSayilari: %d \nYuzdesi: %%%.2f\nOrtalama UKD:%.2f \n\n",minikler_say,Yuzde(minikler_say,top_oyuncu_say),Ortalama(top_miniklerUKD,minikler_say));
    printf("********************************************************************************\n");
    printf("UKD puani 2400 ve uzeri olan oyuncularin\n Sayilari:%d Yuzdeleri: %%%2.f\n\n",kategori1,Yuzde(kategori1,top_oyuncu_say));
    printf("UKD puani 2000-2399 arasinda olan oyuncularin\n Sayilari:%d Yuzdeleri: %%%2.f\n\n",kategori2,Yuzde(kategori2,top_oyuncu_say));
    printf("UKD puani 1600-1999 arasinda olan oyuncularin\n Sayilari:%d Yuzdeleri: %%%2.f\n\n",kategori3,Yuzde(kategori3,top_oyuncu_say));
    printf("UKD puani 1300-1599 arasinda olan oyuncularin\n Sayilari:%d Yuzdeleri: %%%2.f\n\n",kategori4,Yuzde(kategori4,top_oyuncu_say));
    printf("UKD puani 1300 den dusuk olan oyuncularin\n Sayilari:%d Yuzdeleri: %%%2.f\n",kategori5,Yuzde(kategori5,top_oyuncu_say));
    printf("********************************************************************************\n");
    printf("Tum sporcularin UKD ortalamasi: %.2f\n",Ortalama(UKD_top,top_oyuncu_say));
    printf("********************************************************************************\n");
    printf("Tum sporcular arasindaki en yuksek UKD puanina sahip oyuncunun\n");
    printf("UKD puani :%d\nLisans NO:%d\nYas kategorisi :%c ",max_ukd,max_ukdLisans,max_ukdYas);

    if (max_ukdYas == 'a'|| max_ukdYas == 'A')
        printf("Acik\n");
    if (max_ukdYas == 'g'|| max_ukdYas == 'G')
        printf("Gencler\n");
    else if (max_ukdYas == 'y'|| max_ukdYas == 'Y')
        printf("Yildizlar\n");
    else if (max_ukdYas == 'k'||  max_ukdYas == 'K')
        printf("Kucukler\n");
    else if (max_ukdYas == 'm'||max_ukdYas == 'M')
        printf("Minikler\n");

    printf("********************************************************************************\n");
    printf("Minikler kategorisindeki en yuksek UKD puanina sahip sporcunun\n");
    printf(" Lisans NO: %d \n UKD puani: %d\n",minik_maxUKD_lisans,minik_maxUKD);
    printf("********************************************************************************\n");
    printf("Turnuva sonucunda en cok UKD puani kazanan sporcunun\nLisanns no :%d\n UKD puani:%d Toplam Kazamilan UKD degisimi :%d \n",max_ukd_kazananLisans,max_ukd_kazananUKD,max_ukd_kazananilkUKD);
    printf("Turnuva sonucunda en cok UKD puani kaybeden sporcunun\nLisanns no :%d\n UKD puani:%d Toplam Kaybedilen UKD degisimi :%d \n",max_ukd_kaybedenLisans,max_ukd_kaybedenUKD,max_ukd_kaybedenUKD-max_ukd_kaybedenilkUKD);
    printf("********************************************************************************\n");
    printf("Tek macta en cok puan kazanan oyuncunun \nLisans no: %d\nUKD puani: %d\nO mactaki UKD degisimi : %d \n",tekmac_max_kazananLisans,tekmac_max_kazananUKD,tekmac_max_kazanan);
    printf("Tek macta en cok puan kaybeden oyuncunun \nLisans no: %d\nUKD puani: %d\nO mactaki UKD degisimi : %d \n",tekmac_max_kaybedenLisans,tekmac_max_kaybedenUKD,tekmac_max_kaybeden);
    printf("UKD puanina sahip olan sporcularin UKD puani olmayan sporcularla yaptiklari\nMaclarin sayisi : %d\nYuzdesi : %% %.2f\n",ukdsize_kaybeden_say,Yuzde(ukdsize_kaybeden_say,ukdsiz_mac_say));
    printf("********************************************************************************\n");
    printf("Turnuva sonunda UKD puani sifirlanan oyuncularin Sayisi:%d Yuzdesi:%.2f\n",sifirlanan_say,Yuzde(sifirlanan_say,top_oyuncu_say));
    printf("********************************************************************************\n");


    return 0;


}

float UKD_Hesapla(int oyuncu_p,int rakip_p, float mac_sonucu)
{
    int k=0,rtg_dif=0;
    float h=0,l=0,ukd_degisimi=0,tablo2puan=0;


    if (oyuncu_p >= 2400)
        k=10;
    else if (oyuncu_p >=2000 && oyuncu_p <=2399)
        k=15;
    else if (oyuncu_p >=1600 && oyuncu_p <=1999)
        k=20;
    else if (oyuncu_p >=1300 && oyuncu_p <=1599)
        k=25;
    else if (oyuncu_p <=1299)
        k=30;

    rtg_dif = oyuncu_p - rakip_p;
    rtg_dif=fabs(rtg_dif);


    if (rtg_dif >= 0 && rtg_dif<=3)
        h=0.5 ,l=0.5;
    else if (rtg_dif >= 4 && rtg_dif<=10)
        h=0.51 ,l=0.49;
    else if (rtg_dif >= 11 && rtg_dif<=17)
        h=0.52 ,l=0.48;
    else if (rtg_dif >= 18 && rtg_dif<=25)
        h=0.53 ,l=0.47;
    else if (rtg_dif >= 26 && rtg_dif<=32)
        h=0.54 ,l=0.46;
    else if (rtg_dif >= 33 && rtg_dif<=39)
        h=0.55 ,l=0.45;
    else if (rtg_dif >= 40 && rtg_dif<=46)
        h=0.56 ,l=0.44;
    else if (rtg_dif >= 47 && rtg_dif<=53)
        h=0.57 ,l=0.43;
    else if (rtg_dif >= 54 && rtg_dif<=61)
        h=0.58 ,l=0.42;
    else if (rtg_dif >= 62 && rtg_dif<=68)
        h=0.59 ,l=0.41;
    else if (rtg_dif >= 69 && rtg_dif<=76)
        h=0.6 ,l=0.4;
    else if (rtg_dif >= 77 && rtg_dif<=83)
        h=0.61 ,l=0.39;
    else if (rtg_dif >= 84 && rtg_dif<=91)
        h=0.62 ,l=0.38;
    else if (rtg_dif >= 92 && rtg_dif<=98)
        h=0.63 ,l=0.37;
    else if (rtg_dif >= 99 && rtg_dif<=106)
        h=0.64 ,l=0.36;
    else if (rtg_dif >= 107 && rtg_dif<=113)
        h=0.65 ,l=0.35;
    else if (rtg_dif >= 114 && rtg_dif<=121)
        h=0.66 ,l=0.34;
    else if (rtg_dif >= 122 && rtg_dif<=129)
        h=0.67 ,l=0.33;
    else if (rtg_dif >= 130 && rtg_dif<=137)
        h=0.68 ,l=0.32;
    else if (rtg_dif >= 138 && rtg_dif<=145)
        h=0.69 ,l=0.31;
    else if (rtg_dif >= 146 && rtg_dif<=153)
        h=0.7 ,l=0.3;
    else if (rtg_dif >= 154 && rtg_dif<=162)
        h=0.71 ,l=0.29;
    else if (rtg_dif >= 163 && rtg_dif<=170)
        h=0.72 ,l=0.28;
    else if (rtg_dif >= 171 && rtg_dif<=179)
        h=0.73 ,l=0.27;
    else if (rtg_dif >= 180 && rtg_dif<=188)
        h=0.74 ,l=0.26;
    else if (rtg_dif >= 189 && rtg_dif<=197)
        h=0.75 ,l=0.25;
    else if (rtg_dif >= 198 && rtg_dif<=206)
        h=0.76 ,l=0.24;
    else if (rtg_dif >= 207 && rtg_dif<=215)
        h=0.77 ,l=0.23;
    else if (rtg_dif >= 216 && rtg_dif<=225)
        h=0.78 ,l=0.22;
    else if (rtg_dif >= 226 && rtg_dif<=235)
        h=0.79 ,l=0.21;
    else if (rtg_dif >= 236 && rtg_dif<=245)
        h=0.8 ,l=0.2;
    else if (rtg_dif >= 246 && rtg_dif<=256)
        h=0.81 ,l=0.19;
    else if (rtg_dif >= 257 && rtg_dif<=267)
        h=0.82 ,l=0.18;
    else if (rtg_dif >= 268 && rtg_dif<=278)
        h=0.83 ,l=0.17;
    else if (rtg_dif >= 279 && rtg_dif<=290)
        h=0.84 ,l=0.16;
    else if (rtg_dif >= 291 && rtg_dif<=302)
        h=0.85 ,l=0.15;
    else if (rtg_dif >= 303 && rtg_dif<=315)
        h=0.86 ,l=0.14;
    else if (rtg_dif >= 316 && rtg_dif<=328)
        h=0.87 ,l=0.13;
    else if (rtg_dif >= 329 && rtg_dif<=344)
        h=0.88,l=0.12;
    else if (rtg_dif >= 345 /*&& rtg_dif<=357*/)
        h=0.89 ,l=0.11;
    /* else if (rtg_dif >= 358 && rtg_dif<=374)
         h=0.9 ,l=0.1;
     else if (rtg_dif >= 375 && rtg_dif<=391)
         h=0.91 ,l=0.9;
     else if (rtg_dif >= 392 && rtg_dif<=411)
         h=0.92 ,l=0.8;
     else if (rtg_dif >= 412 && rtg_dif<=432)
         h=0.93 ,l=0.7;
     else if (rtg_dif >= 433 && rtg_dif<=456)
         h=0.94 ,ukd_degisimil=0.6;
     else if (rtg_dif >= 347 && rtg_dif<=384)
         h=0.95 ,l=0.5;
     else if (rtg_dif >= 485 && rtg_dif<=517)
         h=0.96 ,l=0.4;
     else if (rtg_dif >= 518 && rtg_dif<=559)
         h=0.97 ,l=0.3;
     else if (rtg_dif >= 560 && rtg_dif<=619)
         h=0.98 ,l=0.2;
     else if (rtg_dif >= 620 && rtg_dif<=735)
         h=0.99 ,l=0.1;
     else if (rtg_dif >= 736)
         h=1. ,l=0;*/

    if (oyuncu_p > rakip_p)
        tablo2puan = h;
    else
        tablo2puan= l;

    ukd_degisimi = k*(mac_sonucu-tablo2puan);

    return ukd_degisimi;
}

void Anaekran()
{
    printf("===============================================================================\n");
    printf("            _____    _____    ______   ______     _______                      \n");
    printf("           (_   _)  (_   _)  (_    _) (_    _)   (_      \\                    \n");
    printf("             |  |     |  |     |  |    /  /        |  |\\  \\                  \n");
    printf("             |  |     |  |     |  |   /  /         |  | \\  \\                 \n");
    printf("             |  |     |  |     |  |  /  /          |  |  \\  \\                \n");
    printf("             |  |     |  |     |  | /  /           |  |   |  |               \n");
    printf("             |  |     |  |     |  | \\  \\           |  |   |  |               \n");
    printf("             |  |     |  |     |  |  \\  \\          |  |  /  /                \n");
    printf("             \\  \\    /  /      |  |   \\  \\         |  | /  /               \n");
    printf("              \\  \\__/  /      _|  |_   \\  \\_      _|  |/  /                \n");
    printf("               \\______/      (______) (_____)    (_______/               \n\n");
    printf("          __  __   __   __       __        __     __  *  __ ___  __      *     \n");
    printf("     |_| |__ |__  |__| |__| |   |__| |\\/| |__|   |__  | |__  |  |__ |\\/| |    \n");
    printf("     | | |__  __| |  | |    |__ |  | |  | |  |    __| |  __| |  |__ |  | | \n");
    printf("\n\t\t\t   Ibrahim BASKAYA\n\t\t\t   05130000239     \n\n");
    printf("===============================================================================\n");
    printf("\nPrograma baslamak icin ENTER tusuna basin ...                              v1.0\n");
    printf("===============================================================================\n");

    fflush(stdin);
    getchar();
    system("cls");
}

float Yuzde (int adet,int toplam)
{
    float x=0;

    x=(float)adet/toplam*100;

    return x;
}

float Ortalama(int adet , int toplam)
{
    float y=0;

    y = (float) adet /toplam ;

    return y;
}

