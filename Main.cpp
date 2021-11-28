#include "Volume.h"

int main() {
	/*VOLUME MyFS;
	char file_name[] = "MyFS.dat";
	createVolume(file_name, MyFS);
	cout << '\n';
	readVolume(file_name);
	cout << '\n';
	resetPassword(file_name,MyFS);
	cout << '\n';
	readVolume(file_name);*/

	char file_name[] = "MyFS.dat";
	char content[512];
	for (int i = 0; i < 511; i++) {
		content[i] = 'a';
	}
	char content1[512];
	for (int i = 0; i < 511; i++) {
		content1[i] = 'b';
	}
	WriteSector(file_name, 1, 1,content);
	WriteSector(file_name, 2, 1, content1);
	return 0;
}