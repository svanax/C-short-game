#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define DEFAULT 0
#define BLUE   "\x1B[36m"
#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define PINK   "\x1B[35m"
#define RESET "\x1B[0m"

struct stats
{
    int hp;
    int dmg;
    int dex;
    int wpots;
    int hppots;
    int money;
};

void debug(struct stats *character);
void fight(struct stats *character, struct stats *mob, int *);
void welcome();
void namecheck();
void erklaerung();
void death();
void mainhall();
void fluss();
void wiese();
void baum();
void festung();
void shop();
void infestung();
void firsten();
void aftermath();
void secen();
void win();

int main()
{
    struct stats character = {100,10,2,0,0};
    struct stats skelett = {80,20,2,0,0};
    struct stats kobold = {250,40,3,0,0};

    char name[20];
    int decision;
    int area = 1;
    int done = DEFAULT;
    int axt = DEFAULT;
    int schlussel = DEFAULT;
    int mantel = DEFAULT;
    welcome();

    scanf("%s",name);
    namecheck(name);
    sleep(3);

    system("clear");
    erklaerung();
    sleep(15);

    system("clear");
    printf("Du befindest dich in am Eingang eines Walds.\n");

    do{

        switch (area)
        {
            case 0: //death
                death();
                done = 1;
            break;

            case 1: //mainhall
                
                mainhall();
                decision = 0;
                do{
                    scanf("%i", &decision);
                    while(getchar() != '\n');

                    switch (decision)
                    {
                        case 1:
                            system("clear");
                            printf("Je weiter du läufst, desto lauter wird das Geräusch eines Flusses.\n");
                            printf("Nachdem du eine Weile in Richtung des plätschern gelaufen bist kommst du endlich an die Quelle. Ein Fluss.\n");
                            area = 2;
                        break;

                        case 2:
                            system("clear");
                            printf("Du läufst eine Weile einen Weg entlang, der weg vom Wäld führt.\n");
                            printf("Nach einer Weile erblickst du eine Festung in der Ferne, jedoch musst du dich nun für einen Weg entscheiden\n");
                            area = 4;
                        break;

                        case 3:
                            system("clear");
                            printf("Erst schaust du dich etwas um, doch dann erblickst du einen großen Baum in der ferne.\n");
                            printf("Ein paar Minuten später erreichts du besagten Baum. Was willst du tun?\n");
                            area = 3;
                        break;
                    }
                }while(decision<01 && decision>03);
            break;

            case 2: //fluss
                fluss();
                decision = 0;
                do{
                    scanf("%i", &decision);
                    while(getchar() != '\n');

                    switch (decision)
                    {
                        case 1:
                            system("clear");
                            printf("Du hast eine Glasflashe mit Wasser befüllt. Das könnte später Nützlich werden.\n");
                            character.wpots =  1;
                        break;

                        case 2:
                            system("clear");
                            printf("Autsch! Du hast versucht den Fluss zu überqueren, jedoch bist du dabei hingefallen und wieder zurückgekehrt.\n");
                            character.hp = character.hp - 1;
                        break;

                        case 3:
                            system("clear");
                            printf("Du befindest dich in am Eingang eines Walds.\n");
                            area = 1;
                        break;
                    }
                }while(decision<01 && decision>03);
            break;

            case 3: //baum
                baum();
                decision = 0;
                do{
                    scanf("%i", &decision);
                    while(getchar() != '\n');

                    switch (decision)
                    {
                        case 1:
                            system("clear");
                            printf("Du greifst in dem Baum und findest eine alte Axt. Wer diese dort wohl hinterlassen hat?\n");
                            axt = 1;
                        break;

                        case 2:
                            system("clear");
                            if(axt == 0)
                            {
                                printf("Du schlägst gegen den Baum. Jedoch passiert nichts.\n");
                            }
                            else
                            {
                                printf("Nachdem du nun ein paar mal auf den Baum eingschlagen hast, offenbart sich ein Schwert im Holz, welches du aufsammelst.\n");
                                character.dmg =  20;
                            }
                        break;

                        case 3:
                            system("clear");
                            printf("Du befindest dich in am Eingang eines Walds.\n");
                            area = 1;
                        break;
                    }
                }while(decision<01 && decision>03);
            break;

            case 4: //wiese
                wiese();
                decision = 0;
                do{
                    scanf("%i", &decision);
                    while(getchar() != '\n');

                    switch (decision)
                    {
                        case 1:
                            system("clear");
                            printf("Du näherst dich der Festung und stehst nun vor ihr.\n");
                            area = 5;
                        break;

                        case 2:
                            system("clear");
                            printf("Du entscheidest dich abzubiegen und befindest dich nach einer Weile vor einem heruntergekommenen Haus, in welches du Eintrittst.\n");
                            printf("Du hast %i Gold und %i Wasserflaschen\n", character.money, character.wpots);
                            area = 6;
                        break;

                        case 3:
                            system("clear");
                            printf("Du befindest dich in am Eingang eines Walds.\n");
                            area = 1;
                        break;
                    }
                }while(decision<01 && decision>03);
            break;
            case 5: //festung
                festung();
                decision = 0;
                do{
                    scanf("%i", &decision);
                    while(getchar() != '\n');

                    switch (decision)
                    {
                        case 1:
                            system("clear");
                            printf("Mühsam öffnest du die Tür und befindest dich nun im inneren der Festung.\n");
                            area = 7;
                        break;

                        case 2:
                            system("clear");
                            printf("Du nimmst dir die Zeit um um die Festung zu gehen. Du findest etwas Kleingeld und einen komischen Schlüssel auf deiner Tour.\n");
                            character.money = character.money + 20;
                            schlussel = 1;
                        break;

                        case 3:
                            system("clear");
                            printf("Du läufst wieder eine Weile einen Weg entlang, der weg von der Festung führt.\n");
                            area = 4;
                        break;
                    }
                }while(decision<01 && decision>03);
            break;

            case 6: //shop
                shop();
                decision = 0;
                do{
                    scanf("%i", &decision);
                    while(getchar() != '\n');

                    switch (decision)
                    {
                        case 1:
                            system("clear");
                            if(character.money>=20)
                            {
                                printf("Du kaufst ein Schwert und musst so nicht mehr mit deinen Händen Kämpfen.\n");

                                character.money = character.money - 20;
                                character.dmg = 50;
                                printf("Du hast %i Gold und %i Wasserflaschen\n", character.money, character.wpots);
                            }
                            else
                            {
                                printf("Du hast nicht genug Geld.\n");
                            }
                            
                            
                        break;


                        case 2:
                            system("clear");
                            if(character.wpots>=1)
                            {
                                printf("Der Händler verwandelt das Wasser, welches in einer deiner Behälter ist, in eine rote Flüssigkeit um.\n");
                                character.wpots = character.wpots - 1;
                                character.hppots = character.hppots + 1;
                                printf("Du hast %i Gold und %i Wasserflaschen\n", character.money, character.wpots);
                            }
                            else
                            {
                                printf("Du hast nicht genug Wasser.\n");
                            }
                        break;

                        case 3:
                            system("clear");
                            printf("Du läufst wieder eine Weile einen Weg entlang, der weg vom Haus führt.\n");
                            area = 4;
                        break;
                    }
                }while(decision<01 && decision>03);
            break;
            
            case 7: //infestung
                infestung();
                decision = 0;
                do{
                    scanf("%i", &decision);
                    while(getchar() != '\n');

                    switch (decision)
                    {
                        case 1:
                            system("clear");
                            printf("Du öffnest die Tür vor dir und gehst hinein. Vor dir erscheint ein Skelett mit einem kaputten schwert.\n");
                            area = 8;
                        break;

                        case 2:
                            system("clear");
                            printf("Du öffnest die Links von dir und findest dort eine Kiste, welche du versuchst zu öffnen.\n");
                            if(schlussel == 0)
                            {
                                printf("Mist.. Um die Kiste zu öffnen scheinst du einen Schlüssel zu brauchen.\n");
                            }
                            else
                            {
                                printf("Du versuchst die Kiste mit dem Schlüssel zu öffnen, den du um das Schloss gefunden hast. Du hast glück und die Kiste öffnet sich.\n");
                                printf("In der Kiste befindet sich ein Umhang. Du weißt zwar nicht für was dieser Gut sein soll, jedoch ziehst du ihn trotzdem mal an.\n");
                                character.dex = character.dex + 3;
                                mantel = 1;
                            }
                        break;

                        case 3:
                            system("clear");
                            printf("Du gehst wieder aus der Festung und stehst nun vor ihr.\n");
                            area = 5;
                        break;
                    }
                }while(decision<01 && decision>03);
            break;
            case 8: //firsten
                firsten();
                decision = 0;
                do{
                    scanf("%i", &decision);
                    while(getchar() != '\n');

                    switch (decision)
                    {
                        case 1:
                            system("clear");
                            printf("Du stürzt dich auf das Skelett und der Kampf bricht aus.\n");
                            fight(&character, &skelett, &area);
                            
                        break;

                        case 2:
                            system("clear");
                            printf("Du versuchst dich langs am um das Skelett zu schleichen.\n");
                            if(mantel == 0)
                            {
                                printf("Es hat dich bemerkt und stürzt sich nun auf dich.\n");
                                fight(&character, &skelett, &area);
                                
                            }
                            else
                            {
                                printf("Magischer Weise sieht dich das Skelett nicht. Ob das wohl etwas mit dem Umhang zu tun hat?\n");
                                area = 9;
                            }
                            
                        break;

                        case 3:
                            system("clear");
                            printf("Du rennst rasch aus den Raum heraus und verschließt die Tür wieder.\n");
                            area = 7;
                        break;
                    }
                }while(decision<01 && decision>03);
            break;
            case 9: //nach kampf
                aftermath();
                decision = 0;
                do{
                    scanf("%i", &decision);
                    while(getchar() != '\n');

                    switch (decision)
                    {
                        case 1:
                            system("clear");
                            printf("Du öffnest die Tür vor dir wobei dich ein Kobold anspringt.\n");
                            fight(&character, &kobold, &area);
                            
                        break;

                        case 2:
                            system("clear");
                            printf("Du schaust in deine Tasche und suchst nach einem Heiltrank.\n");
                            if(character.hppots > 0)
                            {
                                printf("Du findest einen und Trinkst diesen\n");
                                character.hppots = character.hppots - 1;
                                character.hp = character.hp + 100;
                            }
                            else
                            {
                                printf("Du findest keinen Heiltrank..\n");
                            }
                            
                        break;

                        case 3:
                            system("clear");
                            printf("Du drehst dich um und versuchst vergeblich die Tür zu öffnen. Sie ist verschlossen.\n");
                        break;
                    }
                }while(decision<01 && decision>03);
            break;
            case 10: // win 
                win();
                done = 1;
            break;
        }

    }while(done!= 1);
     
    return 0;
}

void debug(struct stats *character)
{
    printf("%i %i %i %i %i\n",character -> hp,character -> dmg,character -> dex,character -> wpots,character -> hppots);
}

void welcome()
{
    printf("Sven's Textadventure\n");
    printf("Was ist dein Name?\n");
}

void namecheck(char name [])
{
    printf("Sehr schön, du erinnerst doch noch an deinen Namen, %s.\n\n", name);
}

void erklaerung()
{
    printf("Du befindest dich gerade in einem Textadventure.\nEin Text Adventure erzählt eine Geschichte, in der du selbst der Hauptdarsteller bist.\nIn diesem hier kannst du die virtuelle Welt erkunden, Rätsel lösen, dich ausrüsten und Monster besiegen.\nDu wirst im Laufe des Spieles verschiedene Auswahlmöglichkeiten bekommen was du tun möchtest.\nEigentlich sollte alles selbsterklärend sein.\n\n");
}

void mainhall()
{
    printf(PINK "--------------------------------\n");
    printf("| (1) Gehe tiefer in den Wald  |\n");
    printf("| (2) Bewege dich vom Wald weg |\n");
    printf("| (3) Gehe am Rand entlang     |\n");
    printf("--------------------------------\n" RESET);
}

void fluss()
{

    
    printf(BLUE "--------------------------------\n");
    printf("| (1) Wasser auffüllen         |\n");
    printf("| (2) Den Fluss überqueren     |\n");
    printf("| (3) Zurück gehen             |\n");
    printf("--------------------------------\n" RESET);
    
}

void wiese()
{
    
    printf(GREEN "--------------------------------\n");
    printf("| (1) Gerade aus               |\n");
    printf("| (2) Nach links               |\n");
    printf("| (3) Gehe Zurück              |\n");
    printf("--------------------------------\n" RESET);
}

void baum()
{
    
    printf(GREEN "--------------------------------\n");
    printf("| (1) Greife in den Baum       |\n");
    printf("| (2) Zerstöre den Baum        |\n");
    printf("| (3) Gehe Zurück              |\n");
    printf("--------------------------------\n" RESET);
}

void festung()
{
    
    printf(RED "--------------------------------\n");
    printf("| (1) Gehe in die Festung      |\n");
    printf("| (2) Gehe um die Festung herum|\n");
    printf("| (3) Gehe Zurück              |\n");
    printf("--------------------------------\n" RESET);
}

void shop()
{
    
    printf(YELLOW"--------------------------------\n");
    printf("| (1) Kaufe ein Schert (20 G)  |\n");
    printf("| (2) Verwandel dein Wasser    |\n");
    printf("| (3) Gehe Zurück              |\n");
    printf("--------------------------------\n"RESET);
}

void infestung()
{
    
    printf(RED "--------------------------------\n");
    printf("| (1) Tür gerade aus nehmen    |\n");
    printf("| (2) Tür nach links nehmen    |\n");
    printf("| (3) Gehe Zurück              |\n");
    printf("--------------------------------\n" RESET);
}

void firsten()
{
    
    printf(RED "--------------------------------\n");
    printf("| (1) Bekämpfe das Skelett     |\n");
    printf("| (2) Schleiche dich drum herum|\n");
    printf("| (3) Fliehe                   |\n");
    printf("--------------------------------\n" RESET);
}
void aftermath()
{
    
    printf(RED "--------------------------------\n");
    printf("| (1) Gehe in die nächste Tür  |\n");
    printf("| (2) Heile dich               |\n");
    printf("| (3) Versuche zu fliehen      |\n");
    printf("--------------------------------\n" RESET);
}
void fight(struct stats *character, struct stats *mob, int *parea)
{
    int rdamage;
    int dodge;
    int fightover = DEFAULT;
    if(character->dex > mob->dex)
    {
        printf(YELLOW "Du bist wendiger als dein Gegner und triffst somit den ersten Schlag.\n" RESET);
        do{
            rdamage = character->dmg - (rand() % character->dmg * 0.5);
            dodge = rand() % 11;
            if(dodge<mob->dex)
            {
                rdamage = 0;
                printf(YELLOW"Der Gegner ist ausgewichen\n"RESET);
            }
            printf(GREEN"Du fügst ihm %i schaden zu.\n", rdamage);
            mob->hp = mob->hp - rdamage;
            printf("Der Gegner hat noch %i Leben.\n"RESET , mob->hp);
            sleep(2);
            if(mob->hp < 1)
            {
              fightover = 2;
              break;  
            }
            printf(RED "Der Gegner holt zum Gegenschlag aus.\n");
            rdamage = mob->dmg - (rand() % mob->dmg * 0.5);
            dodge = rand() % 11;
            if(dodge<character->dex)
            {
                rdamage = 0;
                printf(YELLOW"Du bist ausgewichen\n"RESET);
            }
            printf(RED"Du erleidest %i schaden.\n", rdamage);
            character->hp = character->hp - rdamage;
            printf("Du hast noch %i Leben.\n"RESET , character->hp);
            sleep(2);
            if(character->hp < 1)
            {
              fightover = 1;
              break;  
            }
        }while(fightover < 1);
    }
    else
    {
        printf(YELLOW "Der Gegner ist schneller als du und schlägt dich zuerst.\n" RESET);
        do{
            rdamage = mob->dmg - (rand() % mob->dmg * 0.5);
            dodge = rand() % 11;
            if(dodge<character->dex)
            {
                rdamage = 0;
                printf(YELLOW"Du bist ausgewichen\n"RESET);
            }
            printf(RED "Du erleidest %i schaden.\n", rdamage);
            character->hp = character->hp - rdamage;
            printf("Du hast noch %i Leben.\n"RESET , character->hp);
            sleep(2);
            if(character->hp < 1)
                {
                    fightover = 1;
                    break;  
                }
            printf(GREEN"Du holst zum Gegenschlag aus.\n");
            rdamage = character->dmg - (rand() % character->dmg * 0.5);
            if(dodge<mob->dex)
            {
                rdamage = 0;
                printf(YELLOW"Der Gegner ist ausgewichen\n"RESET);
            }
            printf(GREEN"Der Gegner erleidet %i schaden.\n", rdamage);
            mob->hp = mob->hp - rdamage;
            printf("Der Gegner hat noch %i Leben.\n"RESET , mob->hp);
            sleep(2);
            if(mob->hp < 1)
                {
                    fightover = 2;
                    break;  
                }
        }while(fightover < 1);
    }

    if(fightover == 2)
    {
        
        printf("Du hast gewonnen!\n");
        *parea = *parea + 1;
    }
    else
    {
        
        printf("Du hast verloren!\n");
        *parea = 0;
    }
    fightover = DEFAULT;
}

void death()
{   
    sleep(3);
    system("clear");
    printf(RED "--------------------------------\n");
    printf("|                              |\n");
    printf("|       Du bist gestorben      |\n");
    printf("|                              |\n");
    printf("--------------------------------\n" RESET);
}

void win()
{
    sleep(3);
    system("clear");
    printf(GREEN "--------------------------------\n");
    printf("|                              |\n");
    printf("|       Du hast gewonnen       |\n");
    printf("|                              |\n");
    printf("--------------------------------\n" RESET);
}