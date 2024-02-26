#include <iostream>
#include <iomanip>   // library used for setfill() and setw()
using namespace std;

// function that outputs the main menu 
void mainMenu(){
  cout << "Molar Mass Calculator" << endl;  // prints what the program does 
  cout << setfill('-') << setw(50) << "" << endl;  // used to separate the instructions 

  // states some simple instructions to follow 
  cout << endl << "To get total molar mass/ terminate: Input STOP or NO" << endl;
  cout << "Please enter the abbreviation of the element" << endl; 
  cout << setfill('*') << setw(50) << "" << endl; // separtes insturctions from rest of program
}

// global array. it stores the abbreviation of the elements 
string elementsArray [118] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Ti", "Pd", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

// global array. it stores the masses of the elements. directly corresponds with elementsArray
float massArray [118] = {1.0008, 4.003, 6.941, 9.012, 10.81, 12.01, 14.01, 16.00, 19.00, 20.18, 22.99, 24.31, 26.98, 28.09, 30.97, 32.07, 35.45, 39.95, 39.10, 40.08, 44.96, 47.88, 50.94, 52.00, 54.94, 55.85, 58.93, 58.69, 63.55, 65.39, 69.72, 72.61, 74.92, 78.96, 79.90, 83.80, 85.47, 87.62, 88.91, 91.22, 92.91, 95.94, 98.00, 101.1, 102.9, 106.4, 107.9, 112.4, 114.8, 118.7, 121.8, 127.6, 126.9, 131.3, 132.9, 137.3, 138.9, 140.1, 140.9, 144.2, 145.0, 150.4, 152.0, 157.3, 158.9, 162.5, 164.9, 167.3, 168.9, 173.0, 175.0, 178.5, 180.9, 183.8, 186.2, 190.2, 192.2, 195.1, 197.0, 200.6, 204.4, 207.2, 209.0, 209.0, 210.0, 222.0, 223.0, 226.0, 227.0, 232.0, 231.0, 238.0, 237.0, 244.0, 243.0, 247.0, 247.0, 251.0, 252.0, 257.0, 258.0, 259.0, 262.0, 261.0, 262.0, 263.0, 262.0, 265.0, 266.0, 269.0, 272.0, 277.0, 286.00, 289.00,280.0, 293.0, 294.0, 294.0};

// function which calculates molar mass 
int calculation(){
  string element; // defines string 
  int numOfElement; // defines int 
  int i = 0; // defines int i. used multiple times in for loops

  bool b = false; // defines boolean 
  float count = 0; // defines float that calculates molar mass 

  cout << endl << "Enter the Element: " << endl; // asks user for element
  cin >> element; // takes user input and sets it to element

  // while loop that repeats until user wants to get molar mass
  while (element != "STOP" && element != "NO"){
    // this while loop ensures the user input is the abbreviation of elements 
    while (b == false){
      // for loop to check if user input is present in elementsArray
      for (i= 0; i < 118; i++){
        if (element == elementsArray[i]){
          b = true; // if user input is in elementsArray it stops the while loop
        }
      }
      // tells the user if their input is valid or not 
      if(b == false){
        cout << "Remember to use the abbreviation of the element!" << endl;
        cout << "Please try again." << endl;
        cout << "Enter the Element: " << endl;
        cout << endl;
        cin >> element; // allowing the user to input another input for element
      }
    }

    // asks user how many atoms of element there are 
    cout << "Enter how many atoms of " << element << ": " << endl;
    cin >> numOfElement; // user input set to numOfElement

    // validates user input for numOfElement is a positive int
    while(numOfElement < 0){
      cout << "It must be a positive integer!" << endl; 
      cout << "Please try again." << endl; 
      cout << "Enter how many atoms of " << element << ": " << endl;
      cin >> numOfElement; // allows user to input another input for numOfElement
    }

    // for loop calculates the total molar mass
    for (i=0; i < 118; i++){
      if(element == elementsArray[i]){
        count += (massArray[i] * numOfElement); // multiplies elements * numOfElement and sets it to count 
      }
    }

    // again asks the user for an input to element. determines if while loop continues 
    cout << endl << "Enter the Element: " << endl;
    cin >> element;
  }
  // prints the total molar mass to user 
  cout << "The molar mass is: " << count << " g/mol" << endl; 
  return 0; 
}

int main() {
  mainMenu(); // calls mainMenu() function 
  calculation(); // calls calculation() function 
}