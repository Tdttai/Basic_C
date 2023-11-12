#include <stdint.h>
#include <stdio.h>

#define Square    1
#define Rectangle 2
#define Triangle  3


void PrintSquare(uint8_t size);
void PrintRectangle(uint8_t length ,uint8_t width);
void PrintTriangle(uint8_t size);
void UserCmdHandler(uint8_t ucmd);


int main()
{
    uint8_t ucmd;
    printf("1. Square\n2. Rectangle\n3. Triangle\n");
    printf("Chose the shape that you want : ");
    scanf("%d",&ucmd);
    UserCmdHandler(ucmd);

    
    return 0;
}



void PrintSquare(uint8_t size)
{
    for (int i = 0; i < size; i++)
    {
        
        for (int j = 0; j < size; j++)
        {
            printf("*  ");
        }
        printf("\n");
    }
    
}
void PrintRectangle(uint8_t length ,uint8_t width)
{
        for (int i = 0; i < length; i++)
    {
        
        for (int j = 0; j < width; j++)
        {
            printf("*  ");
        }
        printf("\n");
    }
}
void PrintTriangle(uint8_t size)
{
    for(int i=0; i<size; i++) 
    {
        for(int j=0; j<=i; j++) 
        {
            printf("* ");
        }
        printf("\n");
    }
}

void UserCmdHandler(uint8_t ucmd)
{
    uint8_t size, length, width;
    switch (ucmd)
    {
    case Square:
        printf("You have chosen Square\nNow type in the size that you want\n");
        printf("Size:");
        scanf("%hhu",&size);
        PrintSquare(size);
        break;
    case Rectangle:
        printf("You have chosen Rectangle\nNow type in the size that you want\n");
        printf("Length: ");
        scanf("%hhu",&length);
        printf("Width: ");
        scanf("%hhu",&width);
        PrintRectangle(length,width);
        break;
    case Triangle:
        printf("You have chosen Triangle\nNow type in the size that you want\n");
        printf("Size:");
        scanf("%hhu",&size);
        PrintTriangle(size);
        break;
    default:
    printf("Your number is wrong. The number must be within 1 to 3 and be an interger/n Try again!!!");
        break;
    }
}

