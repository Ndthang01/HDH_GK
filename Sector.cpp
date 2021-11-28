#define _CRT_SECURE_NO_WARNINGS
#include "Sector.h"
#include <iostream>
using namespace std;
void WriteSector(char* Vol_, int sector_,int num_, char* buf_) {
	FILE* fp = fopen(Vol_,"r+");
	fseek(fp, sector_ * SECTOR_SIZE, SEEK_SET);
	for (int i = 0; i < num_; i++) {
		fwrite(buf_+(i*SECTOR_SIZE), SECTOR_SIZE, 1, fp);
	}
	
	fclose(fp);
}
void ReadSector(char* Vol_, int sector_,int num_, char* buf_) {
	FILE* fp = fopen(Vol_, "r+");
	fseek(fp, sector_ * SECTOR_SIZE, SEEK_SET);
	for (int i = 0; i < num_; i++) {
		fread(buf_ + (i * SECTOR_SIZE), SECTOR_SIZE, 1, fp);
	}
	
	fclose(fp);
}