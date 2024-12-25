//***************************************************************************** */
//program: main.cpp
//Course: CCP6114 Programming Fundamentals
//Lecture class: TC7L
//Tutorial class: T13L
//Trimester: 2430
//Member_1: 243UC247CA || ALDY TSEN LI HENG || ALDY.TSEN.LI@student.mmu.edu.my || 0165528686
//Member_2: 242UC241YY || MUHAMMAD DANISH WAFIQ BIN NASRAH || MUHAMMAD.DANISH.WAFIQ@student.mmu.edu.my || 0172706272
//Member_3: 243UC245G0 || FUGABAN, PAUL CARLO || FUGABAN.PAUL.CARLO@student.mmu.edu.my || +63 906 364 5322
//******************************************************************************* */
//task distribution
//Member_1: CRUD functions , pseudocode
//Member_2: main application , 
//Member_3: file reading , 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int Maxrow = 10 ;

string itemname[Maxrow] = {};
string itemid[Maxrow] = {};

//delete row
void rowdelete(string search){
int counter = 0;
for (int i = 0 ;i < Maxrow; i++)
{
if (itemid[i] == search){
counter++;
itemid[i]="";
itemname[i]= "";
cout << "deleted" << endl;
break;

}
}}
// change item names
void update(string search){
 char name[50];
 char id[10];
 int counter;

 for (int i = 0 ; i < Maxrow; i++  ){
if (itemid[i] == search){
counter++;
cout << "item name" << endl;
cin.getline(name, 50);
itemname[i]=name;
cout << "success" << endl;
break;


}
 }
 if (counter == 0)
 {
    cout << "id doesnt exist" << endl;



 } 
}


// display as array
void displayitems() {
    cout << "\n-------------------------------------------------------------" << endl;
    cout << setw(10) << "No." << setw(20) << "Item Id" << setw(30) << "Item Name" << endl;
    cout << "--------------------------------------------------------------" << endl;

    bool isEmpty = true;

    int counter = 0;
    for (int i = 0; i < Maxrow; i++) {
        if (!itemid[i].empty()) {
            counter++;
            cout << setw(10) << counter << setw(20) << itemid[i]<< setw(30) << itemname[i] << endl;
            isEmpty = false;
        }
    }

    if (isEmpty) {
        cout << "No items to display." << endl;
    }

    cout << "--------------------------------------------------------------" << endl;
}


//add new items
void additem(){
char name[50];
char id[10];

cin.ignore();
cout << "Item ID --" << endl;
cin.getline(id, 10);
cout << "item name--" << endl;
cin.getline(name, 50);


for (int i = 0 ; i < Maxrow; i++)
{
    
    if ( itemid[i] == "\0"){
        itemid[i] = id;
        itemname[i] = name;
        cout << "item added" <<endl;
        break;
    }
}
}

//file reading
void OpenFile() {
    ifstream myfile("items.txt");
    if (!myfile.is_open()) {
        cout << "Error: Unable to open file!" << endl;
        return;
    }

    string line;
    int index = 0;

    while (getline(myfile, line)) {
        if (index < Maxrow) {
            // Split the line into itemid and itemname
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                itemid[index] = line.substr(0, commaPos);
                itemname[index] = line.substr(commaPos + 1);
                index++;
            } else {
                cout << "Error: Malformed line, skipping: " << line << endl;
            }
        } else {
            cout << "Error: Maximum rows exceeded. Additional data ignored." << endl;
            break;
        }
    }

    myfile.close();
    cout << "Items loaded from file successfully." << endl;
}

//write to file
void savetofile(){
ofstream myfile;
myfile.open("items.txt");
for (int i = 0 ; i < Maxrow ; i++){
if (itemid[i] == "\0"){
    break;
}else{
myfile << itemid[i] + "," + itemname[i] << endl;

}

}

}
//display as cvs
void displayAsCSV() {
    cout << "ItemID,ItemName" << endl;

    for (int i = 0; i < Maxrow; i++) {
        if (!itemid[i].empty()) { 
            cout << itemid[i] << "," << itemname[i] << endl;
        }
    }
}



int main()
{
    int option;
    string itemidnum;
    OpenFile();
    string yesorno;
    do
    
    {
 cout << "1. create new row" << endl << "2. update table"<< endl << "3. delete item " << endl << "4.display items " << endl << "5. save table"<< endl << "6. Exit" << endl << "select option--";
cin >> option;
switch (option)
{
case 1:
 additem();
break;
case 2:
    cin.ignore();
    cout << "what is the id?--" << endl;
    getline(cin, itemidnum);
    update(itemidnum);
    break;
case 3:
    cin.ignore();
    cout << "delete by id -- "<< endl;
    getline(cin,itemidnum);
    rowdelete(itemidnum);
    break;

case 4:
    cout << "view as csv? y or n" << endl;
    cin >> yesorno;

if (yesorno == "y" || yesorno == "Y"){
    displayAsCSV();
}else{
    displayitems();}
break;

case 5:
    savetofile();
    break;


case 6:
 cout << "exitting" << endl;
}



}while (option != 6 );





    return 0;
}


