#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
int calc_num(char l);
int main(){
    char word[]="";
    char txt[]="";
    char abc[]="abcdefghijklmnopqrstuvwxyz";
    char ABC[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char inputWord;
    scanf("%c",inputWord);
    while(inputWord!="\n"&&inputWord!="\t"&&inputWord!=" "){
        strcat(word,inputWord);
        scanf("%c",inputWord);
    }
    char inputTxt;
    while(inputTxt!="~"){
        scanf("%c",inputTxt);
        strcat(txt,inputTxt);
    }
    int numWord=0;
    for(int i=0;i<strlen(word);i++){
        numWord=numWord+calc_num(word[i]);
    }
    char numWords[]="";
    for(int i=0;i<strlen(txt);i++){
        char currWord[]="";
        int curNum=0;
        int j=i;
        while(curNum<numWord&& j<strlen(txt)){
            curNum=curNum+calc_num(txt[j]);
            strcat(currWord,txt[j]);
            if(curNum==numWord){
                strcat(strcat(numWords,txt[j]),"~");
            }
            j=j+1;
        }
    }
    char sameLatters[]="";
    for(int i=0;i<strlen(txt);i++){
         char currWord[]="";
        int out=0;
        int len=0;
        int j=i;
        while(out==0){
            if(txt[j]!="\n"&&txt[j]!="\t"&&txt[j]!=" "){
                if(strstr(word,txt[j])){
                    len++;
                }if(!strstr(word,txt[j])){
                    out=1;
                }
            }
            strcat(currWord,txt[j]);
            if(len==strlen(word)){
                strcat(strcat(sameLatters,txt[j]),"~");
                out=1;
            }
            j=j+1;
        }
    }
    return 0;
}
int calc_num(char l){
    char abc[]="abcdefghijklmnopqrstuvwxyz";
    char ABC[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int num=strcspn(abc,l)+1;
    if(num>26){
        num=strcspn(ABC,l)+1;
    }
    if(num>26){
        return 0;
    }
    return num;
}