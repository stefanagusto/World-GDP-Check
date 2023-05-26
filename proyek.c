#include <stdio.h>
#include <stdlib.h>
#include "function.h"

//Function prototype
void insertAtTheBegin (struct Node** start_ref, int data, char name[100]);
void pengguna(mahasiswa Mahasiswa);
int maxLength(negara Negara[100]);
void animasiOpening(mahasiswa Mahasiswa);
void animasiClosing(mahasiswa Mahasiswa);
struct Node* swap(struct Node* ptr1, struct Node* ptr2);
void sortUp(struct Node** start_ref);
void sortDown(negara Negara[100], int jum);
void urutan(negara Negara[100], int jumlah);
void linearSearchGdp (negara Negara[100], int gdp);
void linearSearchName (negara Negara[100], char nama[100], int jum);
void help(mahasiswa Mahasiswa);
void menu(negara Negara[100], mahasiswa Mahasiswa);
void urutanlink(struct Node** start_ref, int jumlah);
void urutanlink(struct Node** start_ref, int jumlah);

int main(){
    //100 Daftar Negara dan GPD yang ada di dunia
    negara Negara[100] = {
    {"Indonesia", 3869, 1},
    {"Malaysia", 10412, 2},
    {"Singapura", 59797, 3},
    {"Thailand", 7186, 4},
    {"Brunei", 27443, 5},
    {"Bangladesh", 1961, 6},
    {"Belgia", 45159, 7},
    {"Liberia", 632, 8},
    {"Bulgaria", 10079, 9},
    {"Yemen", 758, 10},
    {"Barbados", 15373, 11},
    {"Uganda", 822, 12},
    {"Bolivia", 3133, 13},
    {"Bahrain", 20410, 14},
    {"Burundi", 239, 15},
    {"Benin", 1291, 16},
    {"Bhutan", 3000, 17},
    {"Jamaika", 4664, 18},
    {"Botswana", 6404, 19},
    {"Samoa", 4067, 20},
    {"Brazil", 6796, 21},
    {"Belarus", 6424, 22},
    {"Kenya", 1878, 23},
    {"Filipina", 3298, 24},
    {"Mozambik", 448, 25},
    {"Kuba", 9477, 26},
    {"Etiopia", 936, 27},
    {"Madagaskar", 471, 28},
    {"Jepang", 40193, 29},
    {"Guyana", 6955, 30},
    {"Nigeria", 567, 31},
    {"Iran", 2422, 32},
    {"Gabon", 6881, 33},
    {"Vietnam", 2785, 34},
    {"Somalia", 438, 35},
    {"Hongkong", 46323, 36},
    {"Portugal", 22176, 37},
    {"Peru", 6126, 38},
    {"Nepal", 1155, 39},
    {"China", 10434, 40},
    {"Suriname", 4916, 41},
    {"Kuwait", 24811, 42},
    {"Senegal", 1471, 43},
    {"Kazakhstan", 9122, 44},
    {"Sudan", 486, 45},
    {"Algeria", 3306, 46},
    {"Lebanon", 4649, 47},
    {"Turki", 8536, 48},
    {"Afghanistan", 516, 49},
    {"Iraq", 4145, 50},
    {"Kongo", 544, 51},
    {"Malawi", 636, 52},
    {"Gambia", 727, 53},
    {"Chad", 659, 54},
    {"Rwanda", 797, 55},
    {"Tajikistan", 859, 56},
    {"Mali", 862, 57},
    {"Togo", 915, 58},
    {"Amerika", 63593, 59},
    {"Inggris", 41059, 60},
    {"Myanmar", 1467, 61},
    {"Kamboja", 1543, 62},
    {"Laos", 2629, 63},
    {"Ukraina", 3724, 64},
    {"Rusia", 10126, 65},
    {"Korea", 31631, 66},
    {"Kanada", 43924, 67},
    {"Ekuador", 5600, 68},
    {"Australia", 51693, 69},
    {"Tanzania", 1076, 70},
    {"Taiwan", 32787, 71},
    {"Pakistan", 1188, 72},
    {"Zimbabwe", 1214, 73},
    {"Haiti", 1272, 74},
    {"Uzbekistan", 1750, 75},
    {"Angola", 1776, 76},
    {"India", 1927, 77},
    {"Kwait", 32373, 78},
    {"Ghana", 2205, 79},
    {"Monako", 173688, 80},
    {"Liechtenstein", 173813, 81},
    {"Luxembourg", 107079, 82},
    {"Swiss", 87097, 83},
    {"Norwegia", 67389, 84},
    {"Denmark", 61063, 85},
    {"Islandia", 59270, 86},
    {"Belanda", 52397, 87},
    {"Greenland", 53041, 88},
    {"Swedia", 52371, 89},
    {"Qatar", 50124, 90},
    {"Austria", 48586, 91},
    {"Jerman", 46308, 92},
    {"Prancis", 39030, 93},
    {"Israel", 44168, 94},
    {"Italia", 31714, 95},
    {"Spanyol", 27063, 96},
    {"Kiribati", 1653, 97},
    {"Maroko", 3058, 98},
    {"Chile", 13231, 99},
    {"Mesir", 3569, 100}
	};
    //Data User Mahasiswa
	mahasiswa Mahasiswa;

    //Function Call animasi opening
    animasiOpening(Mahasiswa);
    //Meminta User untuk memasukkan nama dan NPM
	printf("\nMasukkan Nama anda : ");
    scanf(" %[^\n]", &Mahasiswa.nama);
	printf("\nMasukkan NPM anda  : ");
    scanf("%d", &Mahasiswa.npm);
    printf("\nLoading");
    //Membuat animasi loading
	int i, exit = 0;
	for(i = 0; i < 3; i++){
		printf(".");
		Sleep(1000);
	}
    //Clear System
	system ("CLS");

	//Function Call menu
    do {    
        menu(Negara, Mahasiswa);
    } while (exit != 1);
    return 0;
}
