/*

Nama:   Faisal Hanif
NPM:    19081010080

*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Mahasiswa {
    char npm[12];
    char nama[64];
    char prodi[48];
    char fakultas[64];
    char alamat[128];
    float ipk;
    int usia;
}; 

//Deklarasi variabel global
int jumlahMahasiswa = 0;
typedef struct Mahasiswa Mhs;
Mhs info[50], tmp;

bool Create(int jumlah) {
    int i = 1;
    int counter = 1;
    if(jumlahMahasiswa > 0) {
        i = jumlah+1;
    }
    jumlahMahasiswa += jumlah;
    for(i; i <= jumlahMahasiswa; i++) {
        printf("\nMasukkan data mahasiswa ke-%d dari %d", counter, jumlah);
        printf("\nMasukkan NPM: ");
        scanf(" %[^\n]s", &info[i].npm);
        printf("\nMasukkan Nama: ");
        scanf(" %[^\n]c", &info[i].nama);
        printf("\nMasukkan Program Studi: ");
        scanf(" %[^\n]c", &info[i].prodi);
        printf("\nMasukkan Fakultas: ");
        scanf(" %[^\n]c", &info[i].fakultas);
        printf("\nMasukkan Alamat: ");
        scanf(" %[^\n]c", &info[i].alamat);
        printf("\nMasukkan IPK: ");
        scanf(" %f", &info[i].ipk);
        printf("\nMasukkan Usia: ");
        scanf(" %d", &info[i].usia);
        counter++;
    }
    return true;
}

void Read() {
    for(int i = 1; i<= jumlahMahasiswa; i++) {

        //Periksa apabila ada array dengan nilai yang telah dihapus
        if(strcmp(info[i].npm, "")) {
            printf("\n\n[%d]", i);
            printf("\nNPM     : %s", info[i].npm);
            printf("\nNama    : %s", info[i].nama);
            printf("\nProdi   : %s", info[i].prodi);
            printf("\nFakultas: %s", info[i].fakultas);
            printf("\nAlamat  : %s", info[i].alamat);
            printf("\nIPK     : %f", info[i].ipk);
            printf("\nUsia    : %d", info[i].usia);   
        }
        
    }
}

bool ReadNPM(char npm[12]) {
    for(int i = 1; i <= jumlahMahasiswa; i++) {
            if(!strcmp(info[i].npm, npm)) {
                printf("\n\nNPM     : %s", info[i].npm);
                printf("\nNama    : %s", info[i].nama);
                printf("\nProdi   : %s", info[i].prodi);
                printf("\nFakultas: %s", info[i].fakultas);
                printf("\nAlamat  : %s", info[i].alamat);
                printf("\nIPK     : %f", info[i].ipk);
                printf("\nUsia    : %d", info[i].usia);
                return true;
        } 
    }
    return false;
}

bool Update(int index) {
    printf("\nNPM sekarang adalah %s\nMasukkan NPM baru: ", info[index].npm);
    scanf(" %[^\n]s", &info[index].npm);
    printf("\nNama sekarang adalah %s\nMasukkan Nama: ", info[index].nama);
    scanf(" %[^\n]c", &info[index].nama);
    printf("\nProdi saat ini adalah %s\nMasukkan Program Studi: ", info[index].prodi);
    scanf(" %[^\n]c", &info[index].prodi);
    printf("\nFakultas saat ini adalah %s\nMasukkan Fakultas: ", info[index].fakultas);
    scanf(" %[^\n]c", &info[index].fakultas);
    printf("\nAlamat saat ini adalah %s\nMasukkan Alamat: ", info[index].alamat);
    scanf(" %[^\n]c", &info[index].alamat);
    printf("\nIPK saat ini adalah %f\nMasukkan IPK: ", info[index].ipk);
    scanf(" %f", &info[index].ipk);
    printf("\nUsia saat ini adalah %d\nMasukkan Usia: ", info[index].usia);
    scanf(" %d", &info[index].usia);
    return true;
}

bool Delete(int index) {
    strcpy(info[index].npm, "");
    strcpy(info[index].nama, "");
    strcpy(info[index].alamat, "");
    strcpy(info[index].prodi, "");
    strcpy(info[index].fakultas, "");
    info[index].ipk = 0;
    info[index].usia = 0;
    return true; 
}

int main() {
    //Menu
    int menuinput;
    char input[12];
    bool run = true;

    while(run == true) {
        printf("\nSilahkan pilih opsi:\n");
        printf("1 - Buat mahasiswa baru\n2 - Lihat semua data mahasiswa\n3 - Perbarui data mahasiswa\n4 - Hapus data mahasiswa\n5 - Lihat data mahasiswa tertentu\n6 - Urutkan berdasarkan IPK\n0 - Keluar\n> ");
        scanf(" %d", &menuinput);
        if(menuinput > 0 && menuinput < 7) {
            if(menuinput == 1) {
                int inputJmlMhs;
                printf("Masukkan jumlah mahasiswa: ");
                scanf(" %d", &inputJmlMhs);
                if(inputJmlMhs > 0) {
                    if(Create(inputJmlMhs) == true) printf("Data berhasil ditambahkan untuk %d mahasiswa.", inputJmlMhs);
                    else printf("Gagal menambahkan data.");
                } else printf("Input tidak valid");
            }
            if(menuinput == 2) {
                printf("Menampilkan semua data: \n\n");
                Read();
            }
            if(menuinput == 3) {
                printf("\nMasukkan NPM: ");
                scanf(" %[^\n]s", &input);
                for(int i = 1; i <= jumlahMahasiswa; i++) {
                    if(!strcmp(info[i].npm, input)) {
                        if(Update(i)==true) printf("\nData untuk NPM %s berhasil diperbarui!", input);
                    } 
                }
                
            }
            if (menuinput == 4) {
                printf("\nMasukkan NPM: ");
                scanf(" %[^\n]s", &input);
                for(int i = 1; i<= jumlahMahasiswa; i++) {
                    if(!strcmp(info[i].npm, input)) {
                        if(Delete(i)==true) printf("Data untuk NPM %s berhasil dihapus!", input);
                    }
                }
            }
            if (menuinput == 5) {
                printf("\nMasukkan NPM: ");
                scanf(" %[^\n]s", &input);
                ReadNPM(input);
            }
            if (menuinput == 6) {
                int sortinput;
                printf("\nMengurutkan berdasarkan IPK\nPilih mode pengurutan:\n1 - Ascending\n2 - Descending\n> ");
                scanf(" %d", &sortinput);
                int x, y;
                if (sortinput == 1) {
                    //asc
                    for(x=1;x<=jumlahMahasiswa;x++) {
                        for(y=1;y<=jumlahMahasiswa-1;y++) {
                            if(info[y].ipk > info[y+1].ipk) {
                                tmp = info[y];
                                info[y] = info[y+1];
                                info[y+1] = tmp;
                            }
                        }
		            }
                    printf("\nData berhasil diurutkan secara ascending! Silahkan lihat data di menu lihat semua data.");
                } else if (sortinput == 2) {
                    //dsc
                    for(x=1;x<=jumlahMahasiswa;x++) {
                        for(y=1;y<=jumlahMahasiswa-1;y++) {
                            if(info[y].ipk < info[y+1].ipk) {
                                tmp = info[y];
                                info[y] = info[y+1];
                                info[y+1] = tmp;
                            }
                        }
		            }
                    printf("\nData berhasil diurutkan secara descending! Silahkan lihat data di menu lihat semua data.");
                } else printf("Input tidak valid.");

            }
        } else if (menuinput ==0) return 0;
        else {
            printf("\nInput tidak valid!");
        }
    }
}