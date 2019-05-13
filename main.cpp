#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void enter(char filename[128]){
   for (bool valid = false; !valid;)
    {valid = true;
    cout << "Enter filename" << endl;
    cin>> filename;
    //проверка на особые символы
    const char* bansymbols= "*\"<>?|";
    for (int i = 0; i<6; i++){
        if (strchr(filename,bansymbols[i])){
      valid = false;
       cout<<"incorrect filename\n";
        }
    }
    //проверка на двоеточие
    for (int i = 0; i<128; i++){
        if (filename[i] == ':') {
            if ((i!=1) || !isalpha(filename[0]) || (filename[2]!='\\')) {
                     valid = false;
                    cout<<"incorrect filename\n";
            }
        }
    }
    //проверка расширения
    const char* format = strrchr(filename,'.');
    const char* txt = ".txt";

     if (!strrchr(filename,'.') || strcmp(format,txt)){
    strcat(filename,txt);
    }
    }
}

int main()
{
    char filename[128];
    enter(filename);
    cout<<filename;

    return 0;
}
