#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(int argc,char *argv[]){if(argc==1){printf("Fatal error: No file provided\n");return 1;}char x,k[1000][11]={"+0000000000"};int y,o,t,b,d[1000]={0},n[1000]={0},q=0,w=0;srand(time(NULL));FILE*f=fopen(argv[1],"r");if(f==0){printf("Fatal error: File \"%s\" does not exist\n",argv[1]);exit(2);}char l[12];int i=0;while(fscanf(f,"%s",l)!=EOF){if(strcmp(l,"+9999999999")==0){i=0;break;}d[i++]=atoi(l);}while(fscanf(f,"%s",l)!=EOF){if(strcmp(l,"+9999999999")==0){i=0;break;}strcpy(k[i],l);i++;}while(fscanf(f,"%s",l)!=EOF){n[i++]=atoi(l);}fclose(f);while(q<1000){x=k[q][0];y=k[q][1]-'0';o=((k[q][2]-'0')*100)+((k[q][3]-'0')*10)+(k[q][4]-'0');t=((k[q][5]-'0')*100)+((k[q][6]-'0')*10)+(k[q][7]-'0');b=((k[q][8]-'0')*100)+((k[q][9]-'0')*10)+(k[q][10]-'0');switch(x){case'+':switch(y){case 0:exit(0);break;case 1:q=b-1;break;case 2:d[b]=d[o]+d[t];break;case 3:d[b]=d[o]-d[t];break;case 4:d[b]=d[o]*d[t];break;case 5:if(d[t]!=0){d[b]=d[o]/d[t];}else{printf("Fatal Arithmetic Error\n");exit(2);}break;case 6:d[b]=d[o]%d[t];break;case 7:d[b]=d[t];break;case 8:d[b]=d[w++];break;case 9:printf("%d\n",d[b]);break;}break;case '-':switch(y){case 0:if(d[o]==d[t]){q=b-1;}break;case 1:if(d[o]<d[t]){q=b-1;}break;case 2:if(d[o]>d[t]){q=b-1;}break;case 3:if(d[o]<=d[t]){q=b-1;}break;case 4:if(d[o]>=d[t]){q=b-1;}break;case 5:if(d[o]!=d[t]){q=b-1;}break;case 6:printf("%c",(char)d[o]);break;case 7:d[b]=t;break;case 8:if(d[t]>=0&&d[t]<1000){d[b]=d[d[t]];}else{printf("Fatal SEGFAULT at instruction %d\n",q);exit(1);}break;case 9:d[b]=rand()%d[t];break;}break;}q++;}return 0;}
