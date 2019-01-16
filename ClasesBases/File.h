//
// Created by tania on 1/11/2019.
//

#ifndef UNTITLED_FILE_H
#define UNTITLED_FILE_H


#include <string>
using namespace std;

class File {
private:
    string name = "Resumen Planificacion.txt";
    bool fileExist();

public:
    void openNewFile();
    void deleteFile();
};


#endif //UNTITLED_FILE_H
