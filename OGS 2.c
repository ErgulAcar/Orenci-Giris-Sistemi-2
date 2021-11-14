//derleyici ayarý c99
#include <stdio.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include <stdlib.h>
#include <unistd.h>//sleep fonk ve system fonk var
int menu1Secim,yonetimSecim,ogrenciSecim,ogretmenSecim;
typedef struct yonetim
{
	char *kAdi;//kulanýcý adi
	char *sifre;
	char *ad;
	char *soyad;
}yntm;
typedef struct ogrenci
{
	long long int tc;//tc kimlik giriþ bilgisinde kullanýcý adý olacak long long tanýmýnýn nedeni 10 haneden fazla olmasý
	int sifre;//sifrede 6 hadeden olusacak
	char *ogrAd;//öðrencinin adý
	char *ogrSoyad;//örencinin soyadý
	int ogrNo;//öðrenci numarasý
	float vizeNotu;//-Öðr Algoritma ve Programlama II Vize notu
	//(Vize sýnavýna girmediyse default yani öntanýmlý olarak -1 ile belirleyiniz).
	float finalNotu;//-Öðr Algoritma ve Programlama II Final notu
	//(Final sýnavýna girmediyse default yani öntanýmlý olarak -1 ile belirleyiniz).
	float butNotu;//-Öðr Algoritma ve Programlama II Büt notu
	//(Büte girmediyse default yani öntanýmlý olarak -1 ile belirleyiniz).
 	float ortalama;//-Algoritma ve Programlama II not ortalamasý (örn. 90)
 	char *harfNotu;//-Algoritma ve Programlama II harf Notu (Örn. AA)
}ogr;
void yonetimEkle();
void harflendirme(float ortalama, ogr ders1);
void menu1();//ilk menümüz giriþ yapn kimdir tarzý kýsacasý
void menu1SwitchCase(int secim);//menü 1 in switch casesi
void menu1Ogrenci();
void menu1Ogretmen();
void menu1Yonetim();
void yonetimSwitchCase(int yonetimSecim);
void ogrenciEkle();
void ogrenciSil();
void ogretmenEkle();
void ogretmenSil();
void ogrenciTopluSil();
void ogretmenTopluSil();
void Karsilama();
void menu2();


int main(int argc, char** argv)
{
	setlocale(LC_ALL,"Turkish");//türkce karakter kullanmamýzý saðlýyor
	yonetimEkle();
	menu1();
	
	return 0;
}
void yonetimEkle()
{
	yntm yonetim1;
	FILE *fp = fopen("D:/ergül/dev c ++/Yeni klasör/1/yonetim/yonetim.txt", "w");
	yonetim1.kAdi = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim1.sifre = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim1.ad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim1.soyad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim1.kAdi = "admin";
	yonetim1.sifre = "123456";
	yonetim1.ad = "Ali";
	yonetim1.soyad = "Kulsoy";
	fprintf(fp,"%s %s %s %s", yonetim1.kAdi, yonetim1.sifre, yonetim1.ad, yonetim1.soyad);
	fclose(fp); // islem bittiginde dosyayi kapatir
}
void menu1()
{
	while(1)
	{
		printf("\n\n\n\t\t\tHOÞGELDÝNÝZ->>\n\n");
		for(int i=0; i<25; i++)
		{
			printf("* ");
		}
		printf("\n1->> ÖÐRENCÝ GÝRÝÞÝ\n");
		printf("2->> ÖÐRETÝM GÖREVLÝSÝ GÝRÝÞÝ\n");
		printf("3->> YONETÝM GÝRÝÞÝ\n");
		printf("4->> EKRANI TEMÝZLE\n");
		printf("5->> ÇÝKÝÞ\n");
		for(int i=0; i<25; i++)
		{
			printf("* ");
		}
		printf("\n");
		printf("LÜTLEN BÝRÝSÝNÝ SECÝNÝZ->>");
		scanf("%d", &menu1Secim);
		if(menu1Secim!=5)
			menu1SwitchCase(menu1Secim);
		else 
			break;
	}
	
}
void menu1SwitchCase(int secim)
{
	switch(secim)
	{
		case 1:
			menu1Ogrenci();
			break;
		case 2:
			menu1Ogretmen();
			break;
		case 3:
			menu1Yonetim();
			break;
		case 4:
			system("CLS");//Ekrandaki her þeyin silinmesi saðlanmaktadýr.
			break;
		default:
			printf("yanliþ bir bilgi girdiniz->>");
	}
}
void menu1Ogrenci()
{
	ogr ogr1;
	printf("KULLANICI ADÝ(T.C KÝMLÝK NO)->> ");
	scanf("%lld",&ogr1.tc);
	printf("6 HANELÝ ÞÝFRENÝZÝ GÝRÝNÝZ->> ");
	scanf("%d",&ogr1.sifre);
	
}
void menu1Ogretmen()
{
	
}
void menu1Yonetim()
{
	yntm yonetim2, yonetim1;
	int sayac=0;
	yonetim1.kAdi = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim1.sifre = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim1.ad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim1.soyad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim2.kAdi = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim2.sifre = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim2.ad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	yonetim2.soyad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	while(sayac!=1)
	{
		printf("\nKULLANICI ADÝ->> ");
		scanf("%s",yonetim2.kAdi);
		printf("ÞÝFRENÝZÝ GÝRÝNÝZ->> ");
		scanf("%s",yonetim2.sifre);
		FILE *fp;
		if ((fp = fopen("D:/ergül/dev c ++/Yeni klasör/1/yonetim/yonetim.txt", "r")) == NULL)
		{
     		printf("Dosya açma hatasý!\n");
      		exit(1);
  		}
		else
		{
  			fscanf(fp,"%s", yonetim1.kAdi);
  			fscanf(fp,"%s", yonetim1.sifre);
  			fscanf(fp,"%s", yonetim1.ad);
  			fscanf(fp,"%s", yonetim1.soyad);
		}
		if(strcmp(yonetim1.kAdi,yonetim2.kAdi)==0 && strcmp(yonetim1.sifre,yonetim2.sifre)==0 )
		{
			yonetim2.ad = yonetim1.ad;
			yonetim2.soyad = yonetim1.soyad;
			sayac=1;
		}
		else 
			printf("Kulanici Adi veya Sifre Yanliþ!!!\n");
		fclose(fp); // islem bittiginde dosyayi kapatir
	}
	while(1)
	{
		printf("HoþGeldiniz\n Kulanýcý ->> %s %s\n", yonetim2.ad, yonetim2.soyad);
		for(int i=0; i<25; i++)
		{
			printf("* ");
		}
		printf("\n1->> ÖÐRENCÝ GÝRÝÞ BÝLGÝSÝ EKLEME\n");
		printf("2->> ÖÐRENCÝ GÝRÝÞ BÝLGÝSÝ SÝLME\n");
		printf("3->> ÖÐRETÝM GÖREVLÝSÝ GÝRÝÞ BÝLGÝSÝ EKLEME\n");
		printf("4->> ÖÐRETÝM GÖREVLÝSÝ GÝRÝÞ BÝLGÝSÝ SÝLME\n");
		printf("5->> ÖÐRENCÝLERÝN HEPSÝNÝN GÝRÝÞ BÝLGÝLERÝNÝ SÝLME\n");
		printf("6->> ÖÐRETÝM GÖREVLÝLERÝNÝN HEPSÝNÝN GÝRÝÞ BÝLGÝLERÝNÝ SÝLME\n");
		printf("7->> EKRANI TEMÝZLE\n");
		printf("8->> GERÝ\n");
		printf("9->> ÇÝKÝÞ\n");
		for(int i=0; i<25; i++)
		{
			printf("* ");
		}
		printf("\nLÜTLEN BÝRÝSÝNÝ SECÝNÝZ->>");
		scanf("%d", &yonetimSecim);
		if(yonetimSecim==9)
			break;
   		yonetimSwitchCase(yonetimSecim);
	}
		
}
void yonetimSwitchCase(int yonetimSecim)
{
	switch(yonetimSecim)
	{
		case 1:
			ogrenciEkle();
			break;
		case 2:
			ogrenciSil();
			break;
		case 3:
			ogretmenEkle();
			break;
		case 4:
			ogretmenSil();
			break;
		case 5:
			ogrenciTopluSil();
			break;
		case 6:
			ogretmenTopluSil();
			break;
		case 7:
			system("CLS");//Ekrandaki her þeyin silinmesi saðlanmaktadýr.
			break;
		case 8:
			menu1();
			break;
		default:
			printf("yanliþ bir bilgi girdiniz->>");
	}
}
void ogrenciEkle()
{
	ogr ogr1,ogr2;
	ogr1.ogrAd = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	ogr1.ogrSoyad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	ogr2.ogrAd = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	ogr2.ogrSoyad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanlýk yer istiyorum geçiçi
	FILE *fp;
  	int denetim=0;//eðer  ayný tc varsa hata vericegimiz kýsým
	while(denetim!=1)
	{
		printf("KAYIT EDÝLECEK ÖÐRENCÝNÝN \nKULLANICI ADÝ(T.C KÝMLÝK NO)->> ");
		scanf("%lld",&ogr1.tc);
		//while icinde acma nedim eðer ikninci hata olursa satýrabakmaz son satýr oldugu icin hata vermez devam eder
		if ((fp = fopen("D:/ergül/dev c ++/Yeni klasör/1/ogrenci giris bilgileri/ogrenciBilgileri.txt", "r")) == NULL)
		{
     		printf("Dosya açma hatasý!\n");
      		exit(1);
  		}
  		
		if(ogr1.tc<9999999999 || ogr1.tc>100000000000)
			printf("bir TC kimliknumarasý 11 hanelidir!!!\n"); 
		else
		{
			while(!feof(fp))
			{
				fscanf(fp,"%lld %d %s %s %d\n", &ogr2.tc, &ogr2.sifre, ogr2.ogrAd, ogr2.ogrSoyad, &ogr2.ogrNo);
				if(ogr2.tc == ogr1.tc)
				{
					printf("T.C. Kimlik Numarasi Bulunmaktadir...\n");
					break;
				}
			}
			if(ogr2.tc != ogr1.tc)
				denetim=1;
		}
		fclose(fp); // islem bittiginde dosyayi kapatir
	}
	denetim=0;//ayný olmamasý lazým olan diðer iþlemler için tekrar edilecek
	printf("Kayit Edilecek Öðrencinin Adi->>");
	scanf("%s",ogr1.ogrAd);
	printf("Kayit Edilecek Öðrencinin Soyadi->>");
	scanf("%s",ogr1.ogrSoyad);
	
	while(denetim!=1)
	{
		printf("Kayit Edilecek Öðrencinin Okul Numarasi(5 hane)->>");
		scanf("%d",&ogr1.ogrNo);
		//while icinde acma nedim eðer ikninci hata olursa satýrabakmaz son satýr oldugu icin hata vermez devam eder
		if ((fp = fopen("D:/ergül/dev c ++/Yeni klasör/1/ogrenci giris bilgileri/ogrenciBilgileri.txt", "r")) == NULL)
		{
     		printf("Dosya açma hatasý!\n");
      		exit(1);
  		}
		if(ogr1.ogrNo>9999 && ogr1.ogrNo<100000)
		{
			while(!feof(fp))
			{
				fscanf(fp,"%lld %d %s %s %d\n", &ogr2.tc, &ogr2.sifre, ogr2.ogrAd, ogr2.ogrSoyad, &ogr2.ogrNo);
				if(ogr2.ogrNo == ogr1.ogrNo)
				{
					printf("Okul Numarasi Bulunmaktadir...\n");
					break;
				}
			}
			if(ogr2.ogrNo != ogr1.ogrNo)
				denetim=1;
		}
		else
			printf("sifre rakam ve 5 haneli olmalidir!!!\n");
		fclose(fp); // islem bittiginde dosyayi kapatir
	}
	denetim=0;//ayný olmamasý lazým olan diðer iþlemler için tekrar edilecek
	while(denetim!=1)
	{
		printf("Kayit Edilecek Öðrencinin Giriþ Þifresi->>");
		scanf("%d",&ogr1.sifre);
		//while icinde acma nedim eðer ikninci hata olursa satýrabakmaz son satýr oldugu icin hata vermez devam eder
		if ((fp = fopen("D:/ergül/dev c ++/Yeni klasör/1/ogrenci giris bilgileri/ogrenciBilgileri.txt", "r")) == NULL)
		{
     		printf("Dosya açma hatasý!\n");
      		exit(1);
  		}
		if(ogr1.sifre>99999 && ogr1.sifre<1000000)
		{
			while(!feof(fp))
			{
				fscanf(fp,"%lld %d %s %s %d\n", &ogr2.tc, &ogr2.sifre, ogr2.ogrAd, ogr2.ogrSoyad, &ogr2.ogrNo);
				if(ogr2.sifre == ogr1.sifre)
				{
					printf("Þifre Bulunmaktadir...\n");
					break;
				}
			}
			if(ogr2.sifre != ogr1.sifre)
				denetim=1;
		}
		else
			printf("sifre rakam ve 6 haneli olmalidir!!!\n");
		fclose(fp); // islem bittiginde dosyayi kapatir
	}
	denetim=0;//ayný olmamasý lazým olan diðer iþlemler için tekrar edilecek
	if ((fp = fopen("D:/ergül/dev c ++/Yeni klasör/1/ogrenci giris bilgileri/ogrenciBilgileri.txt", "ab")) == NULL)
	{
     	printf("Dosya açma hatasý!\n");
      	exit(1);
  	}
	fprintf(fp,"%lld %d %s %s %d\n", ogr1.tc, ogr1.sifre, ogr1.ogrAd, ogr1.ogrSoyad, ogr1.ogrNo);
	fclose(fp); // islem bittiginde dosyayi kapatir
	printf("\n\t\t--Kayit Basari Ile Gerceklestirilmistir--\n");
	sleep(1);
	system("CLS");//Ekrandaki her þeyin silinmesi saðlanmaktadýr.
}
void ogrenciSil()
{
	
}
void ogretmenEkle()
{
	
}
void ogretmenSil()
{
	
}
void ogrenciTopluSil()
{
	
}
void ogretmenTopluSil()
{
	
}
void Karsilama( void )//giriþ
{
	printf("\ngiriþ baþarili...\n\n");
	sleep(2);//burda bekletmek için bir fonksiyon
  	printf("\n\n\t\tYükleniyor!!!\n\n\t\t");
    sleep(2);//burda bekletmek için bir fonksiyon
    printf("Yükleme Tamamlandý...\n");
    sleep(2);//burda bekletmek için bir fonksiyon
    system("CLS");//Ekrandaki her þeyin silinmesi saðlanmaktadýr.
}//fonksiyonun sonu
void menu2()
{
	printf("\n\n\n\t\t\tHOÞGELDÝNÝZ->>\n\n");
	for(int i=0; i<15; i++)
	{
		printf("* ");
	}
	printf("\n1->> ÖÐRENCÝ BÝLGÝSÝ EKLEME\n");
	printf("2->> ÖÐRENCÝ BÝLGÝSÝ LÝSTELEME\n");
	printf("2->> ÖÐRENCÝ BÝLGÝSÝ SÝLME\n");
	printf("2->> ÖÐRENCÝ BÝLGÝLEÝNÝN HEPSÝNÝ SÝLME\n");
	
}

void harflendirme(float ortalama, ogr ders1)
{
	ders1.harfNotu=(char *)malloc(sizeof(char)*2);//sistemden bir kelime * 2 alanlýk yer istiyorum geçiçi
	
	if ( ortalama < 40 )
		strcpy(ders1.harfNotu,"FF");
	else if ( ortalama < 50 )
		strcpy(ders1.harfNotu,"FD");
	else if ( ortalama < 55 )
		strcpy(ders1.harfNotu,"DD");
	else if ( ortalama < 60 )
		strcpy(ders1.harfNotu,"DC");
	else if ( ortalama < 70 )
		strcpy(ders1.harfNotu,"CC");
	else if ( ortalama < 75 )
		strcpy(ders1.harfNotu,"CB");
	else if ( ortalama < 85 )
		strcpy(ders1.harfNotu,"BB");
	else if ( ortalama < 90 )
		strcpy(ders1.harfNotu,"BA");
	else
		strcpy(ders1.harfNotu,"AA");
	free(ders1.harfNotu);
}


