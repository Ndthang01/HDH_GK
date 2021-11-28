#pragma once
#define SECTOR_SIZE 512
void WriteSector(char* Vol_, int sector_,int num_, char* buf_);
void ReadSector(char* Vol_, int sector_, int num_, char* buf_);