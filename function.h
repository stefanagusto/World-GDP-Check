#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

//Struct untuk menyimpan data negara
typedef struct {
    char nama[100];
    int gdp;
    int peringkat;
//struct diinialisasi dengan tipe data negara
}negara;

//Struct untuk menyimpan data user
typedef struct {
    char nama[100];
    int npm;
//struct diinialisasi dengan tipe data mahasiswa
}mahasiswa;

struct Node {
    negara Negara;
    struct Node* next;
} Node;
  
/*Function to swap the nodes */
struct Node* swap(struct Node* ptr1, struct Node* ptr2)
{
    struct Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void insertAtTheBegin(struct Node** start_ref, int data, char name[100])
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->Negara.gdp = data;
	strcpy(new_node->Negara.nama, name);
	new_node->next = (*start_ref);
	(*start_ref) = new_node;
}
//Function untuk print data user
void pengguna(mahasiswa Mahasiswa){
	//Menampilkan nama user
	printf("\nNama\t: %s", Mahasiswa.nama);
    //Menampilkan NPM user
	printf("\nNPM\t: %d", Mahasiswa.npm);
}

//Function untuk rumus pembuatan tabel
int maxLength(negara Negara[100]){
    int i;
    int maxL = 0;
    int tempL = 0;
    //Ukuran maksimum array pada struct
    int size = 100; 
    for (i = 0; i < size; i++)
    {
        tempL  = strlen(Negara[i].nama);
        if (maxL < tempL)
        {
            maxL = tempL;
        }
    }
    // return nilai maksimum Array
    return maxL;
}

//Function untuk menampilkan animasi opening
void animasiOpening(mahasiswa Mahasiswa){
	//system("CLS");
	//Menampilkan animasi opening
    printf("  ======================================================\n");
    Sleep(300);
    printf("||                                                      ||\n");
    Sleep(300);
	printf("||             PROYEK UJIAN TENGAH SEMESTER             ||\n");
    Sleep(300);
    printf("||      NEGARA Negara DI DUNIA UNTUK MAHASISWA FEB      ||\n");
    Sleep(300);
    printf("||                       OLEH :                         ||\n");
    Sleep(300);
    printf("||               STEFAN AGUSTO HUTAPEA                  ||\n");
    Sleep(300);
    printf("||          MOCHAMMAD DYENTA DWIANTOMITARA              ||\n");
    Sleep(300);
    printf("||              JEREMY GANDA PANDAPOTAN                 ||\n");
    Sleep(300);
    printf("||                                                      ||\n");
    Sleep(300);
    printf("  ======================================================\n");
}

//Function untuk menampilkan animasi closing dan mengakhiri program
void animasiClosing(mahasiswa Mahasiswa){
    int keluar;
    //Function Call pengguna
    pengguna(Mahasiswa);
    //Memastikan apakah pilihan sudah benar
	printf("\n\nAnda yakin Ingin keluar dari program\n");
    printf("1. Ya\t2. Tidak \n\nPilihan : ");
    scanf("%d", &keluar);
    //Menampilkan animasi closing
	if (keluar == 1){
        printf( "\n  ===========================================  \n"
                "||                                           ||\n"
                "||             Program Berakhir              ||\n"
                "||  Terima kasih telah memakai program kami  ||\n"
                "||                                           ||\n"
                "  ===========================================  \n");
        exit(0);
    }
}

//Function untuk mengurutkan dari Negara termiskin hingga terkaya menggunakan linkedlist
void sortUp(struct Node** start_ref)
{
	struct Node* current = *start_ref;
	struct Node* next = NULL;
	struct Node* prev = NULL;
	int swapped = 0;
	int i = 0;
	//Looping untuk mengurutkan data
	while (current != NULL && current->next != NULL)
	{
		next = current->next;
		prev = current;
		//Jika data negara kaya maka tidak diurutkan
		if (current->Negara.gdp > next->Negara.gdp)
		{
			current = swap(current, next);
			swapped = 1;
		}
		else
		{
			current = current->next;
		}
	}
	//Looping untuk mengurutkan data
	while (swapped)
	{
		swapped = 0;
		current = *start_ref;
		next = NULL;
		prev = NULL;
		//Looping untuk mengurutkan data
		while (current != NULL && current->next != NULL)
		{
			next = current->next;
			prev = current;
			//Jika data negara kaya maka tidak diurutkan
			if (current->Negara.gdp > next->Negara.gdp)
			{
				current = swap(current, next);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}
	}
}

//Function untuk mengurutkan dari negara terkaya hingga termiskin
void sortDown(negara Negara[100], int jum){
    int i, j, temp;
    char tempe[100];
    //Penggunaan rekursif bubble sort
	if (jum == 1){
      return;
   	}
    for (i = 0; i < jum-1; i++){
            if (Negara[i].gdp < Negara[i+1].gdp){
                temp = Negara[i].gdp;
                Negara[i].gdp = Negara[i+1].gdp;
                Negara[i+1].gdp = temp;
                strcpy(tempe, Negara[i].nama);
                strcpy(Negara[i].nama , Negara[i+1].nama);
                strcpy(Negara[i+1].nama , tempe);
            }
        }
	jum = jum - 1;
    //Function Memanggil diri sendiri
   	sortDown(Negara, jum);
}

//Function untuk mengurutkan data negara berdasarkan GDP per kapita yang dimilikinya
void urutan(negara Negara[100], int jumlah){
	int i, j;
	printf("\nUrutan %d negara terNegara\n", jumlah);
    //Pembuatan Tabel Urutan menggunakan function call maxLength
	printf("Urutan\tNegara\t\tGDP per kapita\n");
    for(i = 0; i < jumlah; i++){
		printf("%d.\t%s   ", Negara[i].peringkat, Negara[i].nama);
        for(j = 0; j < maxLength(Negara) - strlen(Negara[i].nama); j++){
            printf(" ");
		}
        printf("$ %d", Negara[i].gdp);
        printf("\n");
    }
}

//Function untuk print urutan data negara menggunakan linked list
void urutanlink(struct Node** start_ref, int jumlah){
	struct Node* current = *start_ref;
	int i=0;
	while (current!=NULL && i<jumlah){
		printf("Negara: %s GDP: %d\n", current->Negara.nama , current->Negara.gdp);
		i++;
		current=current->next;
	}
}

//Function untuk melakukan searching berdasarkan GDP per kapita yang dimasukkan oleh user
void linearSearchGdp (negara Negara[100], int gdp){
    int i, j;
    printf("\nNegara yang memiliki GDP per kapita dibawah GDP per kapita yang anda cari\n");
 	//Penggunaan linear seacrh
	printf("Urutan\tNegara\t\tGDP per kapita\n");  
   	for (i = 0; i < 100; i++){
        if (Negara[i].gdp <= gdp){
            printf("%d.\t%s   ", Negara[i].peringkat, Negara[i].nama);
        for(j = 0; j < maxLength(Negara) - strlen(Negara[i].nama); j++){
            printf(" ");
		}
        printf("$ %d", Negara[i].gdp);
        printf("\n");
        }
    }
}
//Function untuk melakukan searching secara berdasarkan nama negara yang dimasukkan oleh user
void linearSearchName (negara Negara[100], char nama[100], int jum){
    int i, count = 0, ubah;
	struct Node* start;
    for (i = 0; i < jum; i++){
    	//Penggunaan linear seacrh
        if (strcmp(Negara[i].nama, nama) == 0){
        	printf("\nNegara yang anda cari berdasarkan namanya ada di database dengan rincian\n\n");
            printf("Negara %s dengan GDP per kapita sebesar $ %d berada di peringkat %d\n\n", Negara[i].nama, Negara[i].gdp, Negara[i].peringkat);
			count++;
			//Pilihan untuk mengubah nilai GDP per kapita dari negara yang diinput
			printf("Apakah anda merasa GDP negara tersebut tidak sesuai dan ingin mengubahnya\n");
        	printf("1. Ya\t2. Tidak \n\nPilihan : ");
            scanf("%d", &ubah);
            if (ubah == 1){
            //Mengubah nilai GDP per kapita
			printf("\nMasukan GDP yang sesuai : ");	
            scanf("%d", &Negara[i].gdp);
            //Function call sortUp untuk sorting ulang
			sortUp(&start);
			//Function call urutan untuk menampilkan data negara yang telah diurutkan
			}
		}
    }
    if (count == 0) printf("\nNegara tidak ditemukan di dalam database\n");
}
//Function untuk menampilkan panduan penggunaan aplikasi untuk user
void help(mahasiswa Mahasiswa){
    int pilihan;
    //Function Call pengguna 
  	pengguna(Mahasiswa);
    printf("\n\n");
	//Menampilkan pilihan panduan untuk user
	printf( "  ================================  \n"
			"||                                ||\n"
			"||  Panduan Menggunakan Aplikasi  ||\n"
			"||                                ||\n"
			"  ================================  \n"
			"\n1. Menu 1"
			"\n2. Menu 2"
			"\n3. Menu 3"
			"\n4. Menu 4"
			"\n5. Menu 5"
			"\n6. Kembali ke Menu Utama"
			"\n\nPilihan anda : ");
	scanf("%d", &pilihan);
	//Pemilihan menu panduan yang diinginkan user
	switch(pilihan){
		//Panduan menu 1
		case 1: printf( "\nMasukkan pilihan 1 pada saat berada menu awal.\n"
					  	"Program akan menampilkan peringkat negara dengan GDP per kapita sesuai dengan yang dicari.\n\n");
				system ("pause");
				system ("CLS");
				//Function Call help
            	help(Mahasiswa);
				break;
		//Panduan menu 2
		case 2: printf( "\nMasukkan pilihan 2 pada saat berada menu awal.\n"
						"Program akan menampilkan peringkat negara dengan GDP per kapita dibawah GDP per kapita yang dicari data.\n\n");
				system ("pause");
				system ("CLS");
				//Function Call help
				help(Mahasiswa);
				break;
		//Panduan menu 3
		case 3: printf( "\nMasukkan pilihan 3 pada saat berada menu awal.\n"
						"Program akan menampilkan peringkat negara dengan GDP per kapita dengan jumlah yang diinginkan.\n\n");
				system ("pause");
				system ("CLS");
				//Function Call help
				help(Mahasiswa);
				break;
		//Panduan menu 4
		case 4: printf( "\nMasukkan pilihan 4 pada saat berada menu awal.\n"
						"Anda akan diberikan petunjuk penggunaan.\n\n");
				system ("pause");
				system ("CLS");
				//Function Call help
				help(Mahasiswa);
				break;
        //Panduan menu 5
		case 5: printf( "\nMasukkan pilihan 5 pada saat berada menu awal.\n"
						"Anda akan keluar dari program.\n\n");
				system ("pause");
				system ("CLS");
				//Function Call help
				help(Mahasiswa);
				break;
		//Keluar menu panduan		
		case 6: break;	
		// error handling jika pilhan tidak sesuasi
		default:printf("Error ! Masukkan pilihan 1-6\n");
      			system ("pause");
				system ("CLS");
				//Function Call help
				help(Mahasiswa);
				break;
	}
}
//Function untuk menampilkan menu program
void menu(negara Negara[100], mahasiswa Mahasiswa){
	//Inisialisasi variabel
    int i, pilihan, gdp, jumlah, jum = 100, ulang, jenis;
    char nama[100];
	//linkedlist
    struct Node* start = NULL;
    // int list_size = sizeof(Negara) / sizeof(Negara[0]);
    int j;
    /* Create linked list from the array arr[] */
    for (j = 0; j < 100; j++)
    insertAtTheBegin(&start, Negara[j].gdp, Negara[j].nama);
    //Menampilkan menu program
	do{
		//Function Call pengguna
        pengguna(Mahasiswa);
        //Memampilkan pilhan menu program
        printf("\n\n");
        printf("================================================================================\n");
	    printf("              Program untuk menampilkan negara termiskin di dunia\n");
        printf("Pemeringkatan negara berdasarkan GDP per kapita yang dimiliki oleh setiap negara\n");
        printf("================================================================================\n");
        printf("\nData yang ingin ditampilkan\n");
        printf("1. Negara dengan GDP per kapita sesuai nama negara yang dicari\n");
        printf("2. Negara dengan GDP per kapita dibawah besar GDP per kapita yang dicari\n");
        printf("3. Urutan daftar negara termiskin di dunia berdasarkan GDP per kapita\n");
        printf("4. Panduan penggunaan program\n");
        printf("5. Menutup program\n");
        printf("\nMasukan pilihan yang diinginkan : ");
        scanf("%d", &pilihan);
        //Function Call SortUp
        sortUp(&start);
        system ("CLS");
        //Pemilihan menu panduan yang diinginkan user
        switch (pilihan){
        	//Menu program untuk mencari negara berdasarkan input nama
            case 1: do {
            		//Function Call pengguna
					pengguna(Mahasiswa);
    				printf("\n\n");
    				//Meminta input nama yang ingin dicari
					printf("Negara yang hendak Anda cari (diawali dengan huruf kapital) : ");
    	            scanf("%s", nama);
    	            //Function call linearSearchName
        	        linearSearchName (Negara, nama, jum);
        	        //Pilihan untuk mengulang lagi menu
            	    printf("\nApakah mau mencari negara yang lain\n");
                	printf("1. Ya\t2. Tidak \n\nPilihan : ");
    	            scanf("%d", &ulang);
        	        system ("CLS");
            	    } while (ulang != 2);
                	break;
            //Menu program untuk mencari negara berdasarkan input GPD per kapita
			case 2: do {
					//Function Call pengguna
					pengguna(Mahasiswa);
    				printf("\n\n");
    				//Meminta input GDP yang ingin dicari
					printf("Masukan jumlah GDP per kapita yang hendak Anda cari (Misal : 530 ) dalam satuan dollar : ");
            	    scanf("%d", &gdp);
            	    //Function call linearSearchGdp
                	linearSearchGdp (Negara, gdp);
                	//Pilihan untuk mengulang lagi menu
	                printf("\n\nApakah mau mencari Urutan negara yang lain\n");
    	            printf("1. Ya\t2. Tidak \n\nPilihan : ");
        	        scanf("%d", &ulang);
            	    system ("CLS");
               		} while (ulang != 2);
					break;
            //Menu program untuk mengurutkan peringkat negara berdasarkan GDP per kapita
			case 3: do{
					//Function Call pengguna
					pengguna(Mahasiswa);
    				printf("\n\n");
    				//Pilihan untuk menentukan jenis urutan
    				printf("Jenis Urutan yang ingin ditampilkan : \n");
    				printf("1. Termiskin sampai Terkaya\n2. Terkaya sampai Termiskin \n\nPilihan : ");
					scanf("%d", &jenis);
					switch (jenis){
					//Menampilkan urutan dari negara termiskin hingga terkaya
					case 1 :printf("\nMasukkan jumlah negara yang hendak ditampilkan : ");
                			scanf("%d", &jumlah);
                			//Function Call urutan
							urutanlink(&start, jumlah);
							break;
					//Menampilkan urutan dari negara terkaya hingga termiskin
					case 2 :printf("\nMasukkan jumlah negara yang hendak ditampilkan : ");
                			scanf("%d", &jumlah);
                			//Function Call sortDown
                			sortDown(Negara, jum);
                			//Function Call urutan
							urutan(Negara, jumlah);
							break;
					//Error handling jika input tidak sesuai		
					default:printf("\nError ! Masukkan pilihan 1 atau 2\n");
							break;
						}
					//Pilihan untuk mengulang lagi menu
					printf("\nApakah mau mencari Urutan negara yang lain\n");
                	printf("1. Ya\t2. Tidak \n\nPilihan : ");
                	scanf("%d", &ulang);
					system ("CLS");
                	} while (ulang != 2);
					break;
			//Menu program untuk menampilkan panduan penggunaan program
            case 4: //Function Call help
					help(Mahasiswa);
        			system ("pause");
        			system ("CLS");
					break;
			//Menu program untuk keluar program	
            case 5: //Function Call animasiClosing
					animasiClosing(Mahasiswa);
                	system ("CLS");
                	break;
            //Error handling jika input tidak sesuai
            default:printf("Error! Pilih antara 1-5\n");
        			system ("pause");
					system ("CLS");
                	break;
        }
    }while (pilihan > 1 || pilihan < 5);
}

