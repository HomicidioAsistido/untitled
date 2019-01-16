//
// Created by tania on 1/11/2019.
//

#include <fstream>
#include <iostream>
#include "File.h"

bool File::fileExist() {
    ifstream fileOpen(File::name,ios::in);
    if(fileOpen.fail()){
        return false;
    }else{
        fileOpen.close();
        return true;
    }
}

void File::openNewFile() {
    if(!fileExist()){
        ofstream newFile(File::name,ios::out);
        cout << "Archivo \"" << File::name << "\" creado" << endl;
        newFile.close();
    } else{
        cout << "El archivo ya existe" << endl;
    }
}

void File::deleteFile() {
    if(fileExist()){
        ifstream fileExisting(File::name,ios::trunc);
        cout << "Contenido del archivo \"" << File::name << "\" eliminado" << endl;
    }
}