/*
	CHƯƠNG TRÌNH TẠO, ĐỊNH DẠNG VOLUME MyFS.dat
*/
#include "Volume.h"

void createVolume(char* file_name,VOLUME& MyFS){
	//open volume file_name (MyFS.dat)
	FILE* fp = fopen(file_name, "wb");
	//initialize info for volume
	strcpy(MyFS.file_name, file_name);
	cout << "-----CREATE YOUR VOLUME-----" << endl;
	cout << "Enter your volume size: ";
	cin >> MyFS.size_volume;
	MyFS.size_sector = SECTOR_SIZE;
	cout << "SET PASSWORD FOR VOLUME" << endl;
	cout << "Enter your password: ";
	cin.ignore();
	cin.getline(MyFS.password, 24);

	fwrite(&MyFS, sizeof(MyFS), 1, fp);
	fclose(fp);
	cout << "COMPLETE!!!!" << endl;
}

void readVolume(char* file_name) {
	VOLUME MyFS;
	FILE* fp = fopen(file_name, "rb");
	fread(&MyFS, sizeof(VOLUME), 1, fp);
	fclose(fp);
	
	cout << "-----VOLUME MyFS.dat-----" << endl;
	char pass[25];
	do
	{
		cout << "Enter password for volume MyFS.dat: ";
		cin.getline(pass, 24);
		cin.ignore();
	} while (strcmp(MyFS.password,pass) != 0);

	cout << "-----INFO OF VOLUME-----" << endl;
	cout << "Volume name: " << MyFS.file_name << endl;
	cout << "Size of volume: " << MyFS.size_volume << " GB" << endl;
	cout << "Size of sector: " << MyFS.size_sector << " byte" << endl;
	cout << "Your password for this volume: " << MyFS.password << endl;
}

void resetPassword(char* file_name, VOLUME& MyFS) {
	char current_password[25];
	do
	{
		cout << "Enter your current password: ";
		cin.getline(current_password, 24);
	} while (strcmp(MyFS.password,current_password) != 0);
	cout << "Enter your new password: ";
	cin.getline(current_password, 24);
	cin.ignore();
	strcpy(MyFS.password, current_password);
	FILE* fp = fopen(file_name, "r+");
	fseek(fp, 0l, SEEK_SET);
	fwrite(&MyFS, sizeof(VOLUME), 1, fp);
	fclose(fp);
}
