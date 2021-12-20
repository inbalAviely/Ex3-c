#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
#define TXT 1024
#define WORD 30
int calc_num(char l);
void remove_element(char *array, int index, int array_length);
int main()
{
    int lenWord = 0;
    char txt[TXT]={0};
    int lenTxt = 1;
    char abc[] = "abcdefghijklmnopqrstuvwxyz";
    char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char word[WORD]={0};

    char *atabash;
    char inputWord;
    scanf("%c", &inputWord);

    while (inputWord!='\n' && inputWord!='\t' && inputWord!=' ')
    {
        strncat(word, &inputWord, 1);

        lenWord++;
        scanf("%c", &inputWord);



    }
    char inputTxt;
    scanf("%c", &inputTxt);
    while (inputTxt != '~')
    {
        strncat(txt, &inputTxt, 1);
        scanf("%c", &inputTxt);
        lenTxt++;
    }
    int numWord = 0;
    for (int i = 0; i < lenWord; i++)
    {
        int index=calc_num(word[i]);

        numWord += index;


    }
    char * numWords=malloc(sizeof(char));

    for (int i = 0; i < lenTxt; i++)
    {
        char currWord[TXT] = {0};
        int curNum = 0;
        int j = i;
        char c='~';
        if(txt[i]=='\n' && txt[i]=='\t' && txt[i]==' ')continue;
        while (curNum < numWord && j < lenTxt)
        {
            curNum = curNum + calc_num(txt[j]);
            strncat(currWord, &txt[j], 1);
            if (curNum == numWord)
            {
                numWords=(char*)realloc(numWords,sizeof(char)*(strlen(numWords)+strlen(currWord)));
            	strcat(numWords, currWord);
                strcat(numWords, &c);
            }
            j = j + 1;
        }
    }
    char *sameLatters=malloc(sizeof(char));
    for (int i = 0; i < lenTxt; i++)
    {
        char currWord[] = "";
        char theWord[lenWord];
        strcpy(theWord,word);
        int out = 0;
        int j = i;
        char c='~';
        if(txt[i]=='\n' && txt[i]=='\t' && txt[i]==' ')continue;

        while ((out == 0) && (j < lenTxt))
        {
            if (txt[j] != '\n' && txt[j] != '\t' && txt[j] != ' ')
            {

                if(strchr(theWord,txt[j])==NULL){
                    out=1;
                    continue;
                }else{
                    int index=strchr(theWord,txt[j])-theWord;
                    remove_element(theWord,index,strlen(theWord));
                }
            }
            strncat(currWord, &txt[j],1);
            if (strlen(theWord)==0)
            {
                sameLatters=(char*)realloc(sameLatters,sizeof(char)*(strlen(sameLatters)+strlen(currWord)));
                strcat(sameLatters, currWord);
                strncat(sameLatters, &c,1);
                out = 1;
            }
            j = j + 1;
        }

    }
    char wordAtbash[] = "";
    for (int i = 0; i < lenWord; i++)
    {
        char l;
        int index = calc_num(word[i]) ;
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            l = abc[strlen(abc) - index];
            
        }
        else{
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            l = ABC[strlen(ABC) - index];
            
        }
        else
        {
            l = word[i];
        }
        }
        strncat(wordAtbash,&l,1);
    }
    for (int i = 0; i < lenTxt; i++)
    {
        char currWord[] = "";
        int out = 0;
        int len1 = 0;
        int len2=0;
        int j = i;
        char c='~';
        if(txt[i]=='\n' && txt[i]=='\t' && txt[i]==' ')continue;
        while ((out == 0) && (j < lenTxt))
        {
            if (txt[j] != '\n' && txt[j] != '\t' && txt[j] != ' ')
            {
                char l = txt[j];

                if (wordAtbash[len1]==l)
                {
                    len1++;
                }
                if(word[len2]==l)
                {
                    len2++;
                }
                if (wordAtbash[len1]!=l&&word[len2]!=l)
                {
                    out = 1;
                }
            }
            strncat(currWord, &txt[j],1);

            if (len1 == lenWord||len2==lenWord)
            {
            	strncat(atabash, &txt[j],1);
                strncat(atabash, &c,1);
                out = 1;
            }
            j = j + 1;
        }
        printf("Gematria Sequences: %s\nAtbash Sequences: %s\nAnagram Sequences: %s", numWords, atabash, sameLatters);
        free(numWords);
        return 0;
    }
}
void remove_element(char  * array, int index, int array_length)
{
    char * newArr=malloc(sizeof(char)*(array_length-1));
    int i;
    for(i = 0; i < index; i++) newArr[i] = array[i];
    for(i = index; i < array_length - 1; i++) newArr[i] = array[i + 1];
    array=newArr;
}
int calc_num(char l)
{
    int index;
    char abc[] = "abcdefghijklmnopqrstuvwxyz";
    char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *num = strchr(abc, l);
    if (num != NULL)
    {
        index = num-abc+1;
    }
    else{
        num=strchr(ABC, l);

        if (num == NULL||num-ABC==26)
        {
            return 0;
        }
        if(num!=NULL){
            index = num-ABC+1;
        }

    }
    
    if(index==27){
        return 0;
    }
    return index;
}