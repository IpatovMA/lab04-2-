#include <iostream>
#include <cstdio>
#include <cstring>
#include<vector>
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
    /*
    for (int i = 0; i<128; i++){
        if (filename[i] == ':') {
            if ((i!=1) || !isalpha(filename[0]) || (filename[2]!='\\')) {
                     valid = false;
                    cout<<"incorrect filename\n";
            }
        }
    }*/
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
   char dir[128] = "C:\\Users\\u211-19\\Desktop\\laba2\\";
    strcat(dir,filename);
    cout<<dir;

    FILE * file = fopen(dir, "r");

    fseek(file, SEEK_SET,SEEK_END-SEEK_SET);
    size_t length = ftell(file);
    length/=sizeof(char);
    cout << endl;
    cout<< length;
    cout << endl;
    char *data = new char[length];

   //char * data = (char*) malloc(sizeof(char) * length);
   //
   // data = "qqipt";
   fseek(file,0,0);
    int len = fread(data, sizeof(char),length,file);
    data[len]='\0';
    cout<<len;
  //  fgets(data,length,file);

    //fclose(file)
    cout << endl;
    //cout.write(data, length);
    cout<< (data);
    cout << endl;
    char usstring[128];
    cout << "Enter string" << endl;
   // cin>> usstring;



   /*
    const size_t MAX_SIZE = 256;
    char text[MAX_SIZE];
    char* fgets(char* str, int count, FILE* stream);
    //stdin       expression of type FILE* associated with the input stream;
    fgets(text, MAX_SIZE, stdin);
    const char* separators = " \r\n,.!?:;()-";
    const char* start = text;
    while (true)
    {
        const size_t separator_count = strspn(start, separators);
        start += separator_count;
        if (start[0] == '\0')
        {
            break;
        }
        const size_t word_length = strcspn(start, separators);
        cout.write(start, word_length);
        cout << '\n';
        start += word_length;
    }

*/
    return 0;
}
