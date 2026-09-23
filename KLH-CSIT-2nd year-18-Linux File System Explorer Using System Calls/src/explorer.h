#ifndef EXPLORER_H
#define EXPLORER_H

// File operations
void createFile();
void writeFile();
void readFile();
void deleteFile();
void renameFile();

// Directory operations
void showCurrentDirectory();
void listFiles();
void createDirectory();
void removeDirectory();
void changeDirectory();

// File information
void showFileInfo();

// Search
void searchFile();
void searchDirectory(const char *path, const char *filename);
#endif
