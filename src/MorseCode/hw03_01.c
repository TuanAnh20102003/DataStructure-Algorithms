//Convert Morse code to text
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//use your own path
#define INPUT_PATH "C:/Users/anhtu/Downloads/20217545_AnhTT/HW03_01/input.txt"
#define OUTPUT_PATH "C:/Users/anhtu/Downloads/20217545_AnhTT/HW03_01/output.txt"

typedef struct MorseCode //Like a map to store Morse code and its corresponding character
{
    char letter;
    char code[10];
} MorseCode;

//Morse code table
MorseCode morseTable[] = 
{
    {'a', ".-"},{'b', "-..."},{'c', "-.-."},{'d', "-.."},{'e', "."},{'f', "..-."},{'g', "--."},
    {'h', "...."},{'i', ".."},{'j', ".---"},{'k', "-.-"},{'l', ".-.."},{'m', "--"},{'n', "-."},
    {'o', "---"},{'p', ".--."},{'q', "--.-"},{'r', ".-."},{'s', "..."},{'t', "-"},{'u', "..-"},
    {'v', "...-"},{'w', ".--"},{'x', "-..-"},{'y', "-.--"},{'z', "--.."},
    {'1', ".----"},{'2', "..---"},{'3', "...--"},{'4', "....-"},{'5', "....."},{'6', "-...."},
    {'7', "--..."},{'8', "---.."},{'9', "----."},{'0', "-----"},{' ', "/"},{'#', "........"},
    {'.', ".-.-.-"},{',', "--..--"},{'?', "..--.."},{'-', "-....-"},{':', "---..."},
};

char getCharacterFromMorseCode(char* code) //Get character from morse code
{
    int tableSize = sizeof(morseTable) / sizeof(MorseCode);
    for (int i = 0; i < tableSize; i++) {
        if (strcmp(morseTable[i].code, code) == 0) //Compare the morse code with the code in the table
        {
            return morseTable[i].letter;
        }
    }
    return '*'; //Return * if the morse code is not found
}

void readInput(char* input) //Read input file
{
    
    if (freopen(INPUT_PATH, "r", stdin) == NULL)
    {
        printf("input.txt could not be opened\n");
    }
    else
    {
        printf("input.txt opened\n");
        char c; //Character read from file
        int numLines = 1; //Number of lines in the file
        int index = 0; //Index of the morseCode array
        char morseCode[10]; //Temporary Array to store morse code
        int inputIndex = 0; //Index of the output array
            while((c = fgetc(stdin)) != EOF) //Read character by character
            {
                
                if (c == '\n')
                {
                    numLines++;
                }
                if(c == '.' || c == '-')
                {
                    if(index < 9)
                    {
                    morseCode[index] = c;
                    index++;
                    }
                }
                else if(c == ' ' || c == '\n' || c == '/') //Check if the character is space or new line
                { 
                    if (index > 0)
                    {
                    morseCode[index] = '\0';
                    char character = getCharacterFromMorseCode(morseCode);    
                    input[inputIndex] = character;
                    inputIndex++;
                    index = 0;
                    memset(morseCode, 0, sizeof(morseCode));
                    }
                    if(c == '\n')
                    {
                        //printf("\n");
                        input[inputIndex] = '\n';
                        inputIndex++;
                    }
                    if(c == '/')
                    {
                        //printf(" ");
                        input[inputIndex] = ' ';
                        inputIndex++;
                    }
                }
                else
                {
                    /* example '-cc' then it it will print the below line before the letter 't' 
                    *so that I added this line
                    */
                    morseCode[index] = '\0'; 
                    printf("Invalid Morse code %c on line %d.\n", c, numLines);
                }
            }
                if (index > 0) //Check if there is any morse code left
            {
                morseCode[index] = '\0';
                char character = getCharacterFromMorseCode(morseCode);
                input[inputIndex] = character;
            }
        
    }
    fclose(stdin);
    
}

void writeOutput(char* output) //Write output file
{
    
    FILE* file = fopen(OUTPUT_PATH, "w");
    if (file == NULL)
    {
        printf("output.txt could not be opened\n");
    }
    else
    {
        printf("output.txt opened\n");   
        for(int i = 0; i < 10000; i++)
        {
            if(output[i] == '\0')
            {
                break;
            }
            fprintf(file, "%c", output[i]);
        }
    }
    fclose(file);
}

int main()
{
    char arr[10000];
    readInput(arr);
    writeOutput(arr);
    
    return 0;
}
