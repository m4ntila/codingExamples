#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_logo(void);
void display_menu(void);
char ask_command(void);
void read_string(char s[]);
void print_string(char s[]);
int count_vowels(char s[]);
int count_consonants(char s[]);
void to_lower(char s[]);
void to_upper(char s[]);
void read_file(char s[]);
void write_file(char s[]);

int main()
{
    
    char input_string[50];
    
    print_logo();
    
    display_menu();
    
    char input = ask_command();
    
    while(input != 'X'){
        
        switch(input){
            case 'A':
            printf("String has %d vowels\n", count_vowels(input_string));
            break;
            case 'B':
            printf("String has %d consonants\n", count_consonants(input_string));
            break;
            case 'C':
            to_upper(input_string);
            break;
            case 'D':
            to_lower(input_string);
            break;
            case 'E':
            print_string(input_string);
            break;
            case 'F':
            read_string(input_string);
            break;
            case 'G':
            read_file(input_string);
            break;
            case 'H':
            write_file(input_string);
            break;
            case 'M':
            display_menu();
            break;
            default:
            printf("Error, wrong command\n");
            break;
        }
        
        input = ask_command();
    }
    
    return 0;
}

/* Printtaa menun */
void display_menu(void)
{
    
    printf("A) Count the number of vowels in the string\n");
    printf("B) Count the number of consonants in the string\n");
    printf("C) Convert the string to uppercase\n");
    printf("D) Convert the string to lowercase\n");
    printf("E) Display the current string\n");
    printf("F) Enter another string\n");
    printf("G) Read string from file\n");
    printf("H) Write string to file\n\n");
    printf("M) Display this menu\n");
    printf("X) Exit the program\n\n\n");
    
}

/* Printtaa logon ohjelman alkuun */
void print_logo(void)
{

    puts("          __         .__\n"
    "  _______/  |________|__| ____    ____\n"
    " /  ___/\\   __\\_  __ \\  |/    \\  / ___\\\n"
    " \\___ \\  |  |  |  | \\/  |   |  \\/ /_/  >\n"
    "/____  > |__|  |__|  |__|___|  /\\___  /\n"
    "     \\/                      \\//_____/\n");
    
}

/* Pyytää komennon */
char ask_command(void)
{

    char user_input[5];
    char uppercase_input;
    int user_input_number;
    
    /* Pyydetään input käyttäjältä */
    printf("Give command: ");
    fgets(user_input, 5, stdin);
    user_input_number = (int)user_input[0];
    
    /* Jos input on jo iso, palautetaan se */
    if(user_input_number < 91 && user_input_number > 64){
        
        /* Input on jo oikein, joten palautetaan se */
        uppercase_input = user_input[0];
        
    }else{
        
        /* Pyydetään uusi input, kunnes saadaan oikea input */
        while(user_input_number < 96 || user_input_number > 122){
            printf("Give command: ");
            fgets(user_input, 5, stdin);
            user_input_number = (int)user_input[0];
        }
    
        /* Muutetaan input isoksi */
        uppercase_input = toupper(user_input[0]);
        
    }
    
    /* Palautetaan hyväksytty input mainiin */
    return uppercase_input;

}


/* Ottaa vastaan uuden stringin */
void read_string(char s[])
{
    
    printf("Give string: ");
    fgets(s, 100, stdin);
    printf("\n");
    
}

/* Printtaa nykyisen stringin */
void print_string(char s[])
{
    
    printf("%s\n", s);
    
}

/* Laskee vokaalit */
int count_vowels(char s[])
{
    int i = 0;
    int vowels = 0;

    while(s[i] != '\0'){
        
        if(s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i' || 
           s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u' || s[i] == 'Y' || s[i] == 'y'){
            vowels++;
        }
        
        i++;
        
    }
    
    return vowels;
    
}

/* Laskee konsonantit */
int count_consonants(char s[])
{

    int i = 0;
    int consonants = 0;
    int char_to_num;
    char temp;

    while(s[i] != '\0'){
        
        temp = tolower(s[i]);
        char_to_num = (int)temp;
        
        if(char_to_num < 123 && char_to_num > 96){
            consonants++;
        }
        
        if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u' || temp == 'y'){
            consonants--;
        }
        
        i++;
        
    }
    
    return consonants;
    
}

/* Muuttaa stringin pieniksi kirjaimiksi */
void to_lower(char s[])
{
    int i = 0;
    
    while(s[i] != '\0'){
        
        if((int)s[i] < 91 && (int)s[i] > 64){
            s[i] = tolower(s[i]);
        }
        
        i++;
        
    }
    
}

/* Muuttaa stringin isoiksi kirjaimiksi */
void to_upper(char s[])
{
    int i = 0;
    
    while(s[i] != '\0'){
        
        if((int)s[i] < 123 && (int)s[i] > 96){
            s[i] = toupper(s[i]);
        }
        
        i++;
        
    }
    
}

/* Avaa, lukee ja sulkee tiedoston */
void read_file(char s[])
{
    
    FILE *fp;
    
    /*  Avataan tiedosto */
    fp = fopen("string.txt", "r");
    
    /* Tarkistetaan, onko tiedosto saatu auki */
    if(fp == NULL){
        
        /* Antaa error viestin, jos tiedostoa ei saa auki */
        printf("File cannot be read\n");
        
    }else{
        
       /* Jos auki, luetaan sisältö */
        fgets(s, 100, fp);
        printf("%s\n", s); 
        
        /* Suljetaan tiedosto */
        fclose(fp);
        
    }
    
}

/* Kirjoittaa annetun stringin tiedostoon */
void write_file(char s[])
{
    
    FILE *fp;
    
    /*  Avataan tiedosto */
    fp = fopen("string.txt", "w");
    
    /* Tarkistetaan, onko tiedosto saatu auki */
    if(fp == NULL){
        
        /* Antaa errorin, jos tiedostoa ei saa auki */
        printf("File cannot be read\n");
        
    }else{
    
        /* Kirjoitetaan käyttäjän input tiedostoon */
        fprintf(fp, "%s", s); 
        
        /* Suljetaan tiedosto */
        fclose(fp);
    }
    
}
