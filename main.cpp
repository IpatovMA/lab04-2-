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

size_t findtext(char str[128], char* data)
{
    size_t strlength = strlen(str);
    size_t count = 0;
   for ( size_t i=0; data[i]!='\0';i++ )
   {
      for (size_t j =0; j<strlength;j++){
              if (data[i+j]==str[j]){
                if (j==strlength-1){count++;};
              }else break;
      }
   }
   return count;
}

int main()
{
    char filename[128];
    enter(filename);
    cout<<filename;

    FILE * file = fopen(filename, "r");

    fseek(file, SEEK_SET,SEEK_END-SEEK_SET);
    size_t length = ftell(file);
    length/=sizeof(char);

    char *data = new char[length];

   fseek(file,0,0);
     length = fread(data, sizeof(char),length,file);
    data[length]='\0';
    fclose(file);

    char usstring[128];
    cout << endl<< "Enter string" << endl;
    cin>> usstring;

    cout << endl;

  size_t srtcount = findtext(usstring, data);
    cout << srtcount;

    delete[] data;

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
