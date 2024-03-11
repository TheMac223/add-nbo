#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h> // for htonl, ntohl

int main(int argc, char* args[]) {
    FILE *f1, *f2;
    uint32_t num1, num2, sum;
    int size1,size2;


    if(argc< 3){
    	printf("need more args");
    	return 1;
    }

    f1 = fopen(args[1], "rb");
    f2 = fopen(args[2], "rb");

    if (f1 == NULL || f2 == NULL) {
        printf("파일이 존재하지 않습니다\n");
        return 1;
    }
    
    fseek(f1, 0L, SEEK_END);
    fseek(f2, 0L, SEEK_END);
    size1 = ftell(f1);
    size2 = ftell(f2);
    
    if(size1 < 4 || size2 < 4){
    	printf("file size is too small");
    	return 1;
    }

    fseek(f1,0L,SEEK_SET);
    fseek(f2,0L,SEEK_SET);
    
    
    fread(&num1, sizeof(uint32_t), 1, f1);
    fread(&num2, sizeof(uint32_t), 1, f2);
 
    num1 = ntohl(num1);
    num2 = ntohl(num2);

    sum = num1 + num2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x) \n", num1,num1,num2,num2,sum,sum);

    fclose(f1);
    fclose(f2);

    return 0;
}
