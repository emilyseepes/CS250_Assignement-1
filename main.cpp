#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


void PrintFauna();
void PrintCharacters();
void PrintStructure();
void PrintHealthRange();
void PrintAverages();

//Dimension structure which will be called in other strcutures
struct Dimension {
double length;
double width;
double height;
};

struct Fauna {
int id;
string texture;
string color;
double health;
struct Dimension Fauna_Dimension; //Dimension for Fauna
bool hostile;
}fauna[10]; //Number of elements in file

struct Character {
int id;
string first_name;
string last_name;
double health;
struct Dimension Character_Dimension; //Dimension for Character
}character[7]; //Number of elements in file

struct Structure {
int id;
string texture;
struct Dimension Structure_Dimension; //Dimension for Structure
}structure[8];//Number of elements in file

void Menu(){
cout << setw(25) << "Menu" << endl;
cout << "Print Fauna:" << setw(28) << "1" << endl;
cout << "Print Characters:" << setw(23) << "2" << endl;
cout << "Print Structures:" << setw(23) << "3"<< endl;
cout << "Print Averages:" << setw(25) << "4" << endl;
cout << "Print Characters with Health in Range:" << setw(2) << "5" << endl;
cout << "Exit:" << setw(35) << "0" << endl;
cout << endl << endl << "Action: ";

int action;

cin >> action; //Calls for user input

//Using switch function to implement case by case functions
switch(action){
    case 0: exit(0); //Terminates
        break;
    case 1:PrintFauna();
        break;
    case 2:PrintCharacters();
        break;
    case 3:PrintStructure();
        break;
    case 4:PrintAverages();
        break;
    case 5:PrintHealthRange();
        break;
}
}


void PrintFauna(){
int intFauna = 0;
ifstream faunafile;
string file1 = "fauna.txt";

faunafile.open(file1.c_str());

faunafile >> intFauna; //Reads elements from file

    cout << "ID" << setw(13) << "TEXTURE" << setw(10) << "COLOR" << setw(15) << "HEALTH" << setw(10) << "LENGTH" <<setw(10) << "WIDTH" << setw(10) << "HEIGHT" << setw(10) << "HOSTILE" << endl;
//Prints all elements in file
    for(int i=0;i<intFauna;i++){
        faunafile >> fauna[i].id >> fauna[i].texture >> fauna[i].color >> fauna[i].health >> fauna[i].Fauna_Dimension.length >> fauna[i].Fauna_Dimension.width >> fauna[i].Fauna_Dimension.height >> fauna[i].hostile;
        cout << left << setw (8) << fauna[i].id << setw(12) << fauna[i].texture << setw(14) << fauna[i].color << setw(10) << fauna[i].health << setw(11) << fauna[i].Fauna_Dimension.length <<setw(9) << fauna[i].Fauna_Dimension.width << setw(9) << fauna[i].Fauna_Dimension.height << fauna[i].hostile << endl;}

    faunafile.close();

}
void PrintCharacters(){
int intCharacters = 0;
ifstream charactersfile;
string file2 = "characters.txt";

charactersfile.open(file2.c_str());

charactersfile >> intCharacters;

    cout << "ID" << setw(13) << "FNAME" << setw(15) << "LNAME" << setw(15) << "HEALTH" << setw(10) << "LENGTH" <<setw(10) << "WIDTH" << setw(10) << "HEIGHT" << endl;

    for(int i=0;i<intCharacters;i++){
        charactersfile >> character[i].id >> character[i].first_name >> character[i].last_name >> character[i].health >> character[i].Character_Dimension.length >> character[i].Character_Dimension.width >> character[i].Character_Dimension.height;
        cout << left << setw(10) << character[i].id << setw(10) << setw(15) << character[i].first_name << setw(14) <<  character[i].last_name << setw(10) << character[i].health << setw(11) << character[i].Character_Dimension.length <<setw(9) << character[i].Character_Dimension.width << character[i].Character_Dimension.height << endl;}

    charactersfile.close();
}

void PrintStructure(){
int intStructure = 0;
ifstream structurefile;
string file3 = "structures.txt";

structurefile.open(file3.c_str());

structurefile >> intStructure;

    cout << "ID" << setw(13) << "TEXTURE" << setw(10) << "LENGTH" <<setw(10) << "WIDTH" << setw(10) << "HEIGHT" << endl;

    for(int i=0;i<intStructure;i++){
        structurefile >> structure[i].id >> structure[i].texture >> structure[i].Structure_Dimension.length >> structure[i].Structure_Dimension.width >> structure[i].Structure_Dimension.height;
        cout << left << setw(8) << structure[i].id << setw(11) << structure[i].texture << setw(11) << structure[i].Structure_Dimension.length <<setw(9) << structure[i].Structure_Dimension.width << structure[i].Structure_Dimension.height << endl;}

    structurefile.close();
}

void PrintAverages(){
int intAverage = 0; //Set Average to zero
ifstream file4;
string file1 = "fauna.txt";
string file2= "characters.txt";
string file3 = "structures.txt";

file4.open(file1.c_str());
file4 >> intAverage;
double Avglength = 0.0; //Set all dimension variables to a double zero
double Avgwidth = 0.0;
double Avgheight = 0.0;
double OverallLength = 0.0;
double OverallWidth = 0.0;
double OverallHeight = 0.0;


//Calls for dimensions from fauna.txt file
for(int i=0; i< intAverage; i++){
    file4 >>fauna[i].Fauna_Dimension.length >> fauna[i].Fauna_Dimension.width >> fauna[i].Fauna_Dimension.height;
    }


for(int i=0;i<intAverage;i++)
{
OverallLength += fauna[i].Fauna_Dimension.length;
OverallWidth += fauna[i].Fauna_Dimension.width;
OverallHeight += fauna[i].Fauna_Dimension.height;
}
Avglength = OverallLength/intAverage;
Avgwidth = OverallWidth/intAverage;
Avgheight = OverallHeight/intAverage;
file4.close();

file4.open(file2.c_str());
file4 >> intAverage;
double Avglength2 = 0.0;
double Avgwidth2 = 0.0;
double Avgheight2 = 0.0;
double OverallLength2 = 0.0;
double OverallWidth2 = 0.0;
double OverallHeight2 = 0.0;

for(int i=0; i< intAverage; i++){
    file4 >> character[i].Character_Dimension.length >> character[i].Character_Dimension.width >> character[i].Character_Dimension.height;
}
for(int i=0;i<intAverage;i++)
{
OverallLength2 += character[i].Character_Dimension.length;
OverallWidth2 += character[i].Character_Dimension.width;
OverallHeight2 += character[i].Character_Dimension.height;
}
Avglength2 = OverallLength2/intAverage;
Avgwidth2= OverallWidth2/intAverage;
Avgheight2 =OverallHeight2/intAverage;
file4.close();


file4.open(file3.c_str());
file4 >> intAverage;
double Avglength3 = 0.0;
double Avgwidth3 = 0.0;
double Avgheight3= 0.0;
double OverallLength3= 0.0;
double OverallWidth3=0.0;
double OverallHeight3= 0.0;

for(int i=0; i< intAverage; i++){
    file4 >> structure[i].Structure_Dimension.length >> structure[i].Structure_Dimension.width >>structure[i].Structure_Dimension.height;
}
for(int i=0;i<intAverage;i++)
{
OverallLength3+= structure[i].Structure_Dimension.length;
OverallWidth3+= structure[i].Structure_Dimension.width;
OverallHeight3+= structure[i].Structure_Dimension.height;
}
Avglength3= OverallLength3/intAverage;
Avgwidth3= OverallWidth3/intAverage;
Avgheight3= OverallHeight3/intAverage;
file4.close();

//PRINT
cout << setw(20) << "Fauna" << setw(30) << "Characters" << setw(30) << "Structures" << endl;
cout << "Length" << setw(10) << Avglength << setw(30) << Avglength2 << setw(30) << Avglength3 << endl;
cout << "Width" << setw(11) << Avgwidth << setw(30) << Avgwidth2 << setw(30) << Avgwidth3 << endl;
cout << "Height" << setw(10) << Avgheight << setw(30) << Avgheight2 << setw(30) << Avgheight3 << endl;

}


void PrintHealthRange()
{
int intHealthRange = 0;
ifstream fileHealthRange;
string HealthRange = "characters.txt";

fileHealthRange.open(HealthRange.c_str());
fileHealthRange >> intHealthRange;

int min;
int max;

cout << endl << "Enter Max Health: ";
cin >> max;

cout << endl << "Enter Min Health: ";
cin >> min;

while(min > max){
cout << "Maximum Value must be Larger Than the Minimum Value" << endl;
cout << endl << "Enter Max Health: ";
cin >> max;

cout << "Enter Min Health: ";
cin >> min;
}
cout << endl << "ID" << setw(13) << "FNAME" << setw(15) << "LNAME" << setw(12) << "HEALTH" << setw(10) << "LENGTH" << setw(10) << "WIDTH" << setw(10)
<< "HEIGHT" << endl;

for(int i = 0; i < intHealthRange; i++)
{
fileHealthRange >> character[i].id >> character[i].first_name >> character[i].last_name >> character[i].health >> character[i].Character_Dimension.length
>> character[i].Character_Dimension.width >> character[i].Character_Dimension.height;

if(character[i].health >= min && character[i].health <= max){
    cout << left << setw(10) << character[i].id << setw(15) << character[i].first_name << setw(11) << character[i].last_name << setw(10) << character[i].health << setw(10) <<
character[i].Character_Dimension.length <<setw(11) << character[i].Character_Dimension.width << setw(11) << character[i].Character_Dimension.height << endl;
}
}
fileHealthRange.close();

}

int main(){
Menu();

}

