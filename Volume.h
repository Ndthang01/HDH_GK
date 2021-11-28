#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdint.h>
#include "Sector.h"
using namespace std;
struct VOLUME {
	char file_name[256];
	uint32_t size_volume;
	uint32_t size_sector;
	char password[25];
	char raw_byte[223];
};

void createVolume(char* file_name, VOLUME& MyFS);
void readVolume(char* file_name);
void resetPassword(char* file_name, VOLUME& MyFS);