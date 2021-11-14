//derleyici ayar� c99
#include <stdio.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include <stdlib.h>
#include <unistd.h>//sleep fonk ve system fonk var
int menu1Secim,yonetimSecim,ogrenciSecim,ogretmenSecim;
typedef struct yonetim
{
	char *kAdi;//kulan�c� adi
	char *sifre;
	char *ad;
	char *soyad;
}yntm;
typedef struct ogrenci
{
	long long int tc;//tc kimlik giri� bilgisinde kullan�c� ad� olacak long long tan�m�n�n nedeni 10 haneden fazla olmas�
	int sifre;//sifrede 6 hadeden olusacak
	char *ogrAd;//��rencinin ad�
	char *ogrSoyad;//�rencinin soyad�
	int ogrNo;//��renci numaras�
	float vizeNotu;//-��r Algoritma ve Programlama II Vize notu
	//(Vize s�nav�na girmediyse default yani �ntan�ml� olarak -1 ile belirleyiniz).
	float finalNotu;//-��r Algoritma ve Programlama II Final notu
	//(Final s�nav�na girmediyse default yani �ntan�ml� olarak -1 ile belirleyiniz).
	float butNotu;//-��r Algoritma ve Programlama II B�t notu
	//(B�te girmediyse default yani �ntan�ml� olarak -1 ile belirleyiniz).
 	float ortalama;//-Algoritma ve Programlama II not ortalamas� (�rn. 90)
 	char *harfNotu;//-Algoritma ve Programlama II harf Notu (�rn. AA)
}ogr;
void yonetimEkle();
void harflendirme(float ortalama, ogr ders1);
void menu1();//ilk men�m�z giri� yapn kimdir tarz� k�sacas�
void menu1SwitchCase(int secim);//men� 1 in switch casesi
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
	setlocale(LC_ALL,"Turkish");//t�rkce karakter kullanmam�z� sa�l�yor
	yonetimEkle();
	menu1();
	
	return 0;
}
void yonetimEkle()
{
	yntm yonetim1;
	FILE *fp = fopen("D:/erg�l/dev c ++/Yeni klas�r/1/yonetim/yonetim.txt", "w");
	yonetim1.kAdi = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	yonetim1.sifre = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	yonetim1.ad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	yonetim1.soyad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
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
		printf("\n\n\n\t\t\tHO�GELD�N�Z->>\n\n");
		for(int i=0; i<25; i++)
		{
			printf("* ");
		}
		printf("\n1->> ��RENC� G�R���\n");
		printf("2->> ��RET�M G�REVL�S� G�R���\n");
		printf("3->> YONET�M G�R���\n");
		printf("4->> EKRANI TEM�ZLE\n");
		printf("5->> ��K��\n");
		for(int i=0; i<25; i++)
		{
			printf("* ");
		}
		printf("\n");
		printf("L�TLEN B�R�S�N� SEC�N�Z->>");
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
			system("CLS");//Ekrandaki her �eyin silinmesi sa�lanmaktad�r.
			break;
		default:
			printf("yanli� bir bilgi girdiniz->>");
	}
}
void menu1Ogrenci()
{
	ogr ogr1;
	printf("KULLANICI AD�(T.C K�ML�K NO)->> ");
	scanf("%lld",&ogr1.tc);
	printf("6 HANEL� ��FREN�Z� G�R�N�Z->> ");
	scanf("%d",&ogr1.sifre);
	
}
void menu1Ogretmen()
{
	
}
void menu1Yonetim()
{
	yntm yonetim2, yonetim1;
	int sayac=0;
	yonetim1.kAdi = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	yonetim1.sifre = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	yonetim1.ad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	yonetim1.soyad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	yonetim2.kAdi = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	yonetim2.sifre = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	yonetim2.ad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	yonetim2.soyad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	while(sayac!=1)
	{
		printf("\nKULLANICI AD�->> ");
		scanf("%s",yonetim2.kAdi);
		printf("��FREN�Z� G�R�N�Z->> ");
		scanf("%s",yonetim2.sifre);
		FILE *fp;
		if ((fp = fopen("D:/erg�l/dev c ++/Yeni klas�r/1/yonetim/yonetim.txt", "r")) == NULL)
		{
     		printf("Dosya a�ma hatas�!\n");
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
			printf("Kulanici Adi veya Sifre Yanli�!!!\n");
		fclose(fp); // islem bittiginde dosyayi kapatir
	}
	while(1)
	{
		printf("Ho�Geldiniz\n Kulan�c� ->> %s %s\n", yonetim2.ad, yonetim2.soyad);
		for(int i=0; i<25; i++)
		{
			printf("* ");
		}
		printf("\n1->> ��RENC� G�R�� B�LG�S� EKLEME\n");
		printf("2->> ��RENC� G�R�� B�LG�S� S�LME\n");
		printf("3->> ��RET�M G�REVL�S� G�R�� B�LG�S� EKLEME\n");
		printf("4->> ��RET�M G�REVL�S� G�R�� B�LG�S� S�LME\n");
		printf("5->> ��RENC�LER�N HEPS�N�N G�R�� B�LG�LER�N� S�LME\n");
		printf("6->> ��RET�M G�REVL�LER�N�N HEPS�N�N G�R�� B�LG�LER�N� S�LME\n");
		printf("7->> EKRANI TEM�ZLE\n");
		printf("8->> GER�\n");
		printf("9->> ��K��\n");
		for(int i=0; i<25; i++)
		{
			printf("* ");
		}
		printf("\nL�TLEN B�R�S�N� SEC�N�Z->>");
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
			system("CLS");//Ekrandaki her �eyin silinmesi sa�lanmaktad�r.
			break;
		case 8:
			menu1();
			break;
		default:
			printf("yanli� bir bilgi girdiniz->>");
	}
}
void ogrenciEkle()
{
	ogr ogr1,ogr2;
	ogr1.ogrAd = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	ogr1.ogrSoyad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	ogr2.ogrAd = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	ogr2.ogrSoyad = (char *)malloc(sizeof(char)*20);//sistemden bir kelime * 300 alanl�k yer istiyorum ge�i�i
	FILE *fp;
  	int denetim=0;//e�er  ayn� tc varsa hata vericegimiz k�s�m
	while(denetim!=1)
	{
		printf("KAYIT ED�LECEK ��RENC�N�N \nKULLANICI AD�(T.C K�ML�K NO)->> ");
		scanf("%lld",&ogr1.tc);
		//while icinde acma nedim e�er ikninci hata olursa sat�rabakmaz son sat�r oldugu icin hata vermez devam eder
		if ((fp = fopen("D:/erg�l/dev c ++/Yeni klas�r/1/ogrenci giris bilgileri/ogrenciBilgileri.txt", "r")) == NULL)
		{
     		printf("Dosya a�ma hatas�!\n");
      		exit(1);
  		}
  		
		if(ogr1.tc<9999999999 || ogr1.tc>100000000000)
			printf("bir TC kimliknumaras� 11 hanelidir!!!\n"); 
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
	denetim=0;//ayn� olmamas� laz�m olan di�er i�lemler i�in tekrar edilecek
	printf("Kayit Edilecek ��rencinin Adi->>");
	scanf("%s",ogr1.ogrAd);
	printf("Kayit Edilecek ��rencinin Soyadi->>");
	scanf("%s",ogr1.ogrSoyad);
	
	while(denetim!=1)
	{
		printf("Kayit Edilecek ��rencinin Okul Numarasi(5 hane)->>");
		scanf("%d",&ogr1.ogrNo);
		//while icinde acma nedim e�er ikninci hata olursa sat�rabakmaz son sat�r oldugu icin hata vermez devam eder
		if ((fp = fopen("D:/erg�l/dev c ++/Yeni klas�r/1/ogrenci giris bilgileri/ogrenciBilgileri.txt", "r")) == NULL)
		{
     		printf("Dosya a�ma hatas�!\n");
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
	denetim=0;//ayn� olmamas� laz�m olan di�er i�lemler i�in tekrar edilecek
	while(denetim!=1)
	{
		printf("Kayit Edilecek ��rencinin Giri� �ifresi->>");
		scanf("%d",&ogr1.sifre);
		//while icinde acma nedim e�er ikninci hata olursa sat�rabakmaz son sat�r oldugu icin hata vermez devam eder
		if ((fp = fopen("D:/erg�l/dev c ++/Yeni klas�r/1/ogrenci giris bilgileri/ogrenciBilgileri.txt", "r")) == NULL)
		{
     		printf("Dosya a�ma hatas�!\n");
      		exit(1);
  		}
		if(ogr1.sifre>99999 && ogr1.sifre<1000000)
		{
			while(!feof(fp))
			{
				fscanf(fp,"%lld %d %s %s %d\n", &ogr2.tc, &ogr2.sifre, ogr2.ogrAd, ogr2.ogrSoyad, &ogr2.ogrNo);
				if(ogr2.sifre == ogr1.sifre)
				{
					printf("�ifre Bulunmaktadir...\n");
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
	denetim=0;//ayn� olmamas� laz�m olan di�er i�lemler i�in tekrar edilecek
	if ((fp = fopen("D:/erg�l/dev c ++/Yeni klas�r/1/ogrenci giris bilgileri/ogrenciBilgileri.txt", "ab")) == NULL)
	{
     	printf("Dosya a�ma hatas�!\n");
      	exit(1);
  	}
	fprintf(fp,"%lld %d %s %s %d\n", ogr1.tc, ogr1.sifre, ogr1.ogrAd, ogr1.ogrSoyad, ogr1.ogrNo);
	fclose(fp); // islem bittiginde dosyayi kapatir
	printf("\n\t\t--Kayit Basari Ile Gerceklestirilmistir--\n");
	sleep(1);
	system("CLS");//Ekrandaki her �eyin silinmesi sa�lanmaktad�r.
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
void Karsilama( void )//giri�
{
	printf("\ngiri� ba�arili...\n\n");
	sleep(2);//burda bekletmek i�in bir fonksiyon
  	printf("\n\n\t\tY�kleniyor!!!\n\n\t\t");
    sleep(2);//burda bekletmek i�in bir fonksiyon
    printf("Y�kleme Tamamland�...\n");
    sleep(2);//burda bekletmek i�in bir fonksiyon
    system("CLS");//Ekrandaki her �eyin silinmesi sa�lanmaktad�r.
}//fonksiyonun sonu
void menu2()
{
	printf("\n\n\n\t\t\tHO�GELD�N�Z->>\n\n");
	for(int i=0; i<15; i++)
	{
		printf("* ");
	}
	printf("\n1->> ��RENC� B�LG�S� EKLEME\n");
	printf("2->> ��RENC� B�LG�S� L�STELEME\n");
	printf("2->> ��RENC� B�LG�S� S�LME\n");
	printf("2->> ��RENC� B�LG�LE�N�N HEPS�N� S�LME\n");
	
}

void harflendirme(float ortalama, ogr ders1)
{
	ders1.harfNotu=(char *)malloc(sizeof(char)*2);//sistemden bir kelime * 2 alanl�k yer istiyorum ge�i�i
	
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


