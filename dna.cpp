// d is flaoting... cant have decimals
//you can put all in main but u can also use othre way
// tons of variables
// cant use arrays
//start reading from the file
//bunch of variables keeping track of a count, c count, total count, etc.
//mean std variance ... plug into formula

//could use classes to simulate arrays
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv){
  ifstream inFS;
  ofstream outFS;

  //variables
  int lineCount = 0;
  string line = 0;
  string fName = argv[1];
  int aCount = 0;
  int cCount = 0;
  int tCount = 0;
  int gCount = 0;
  int totalcount = 0; //total count of acgt

//counts of possible pairs
  int aa = 0;
  int ac = 0;
  int at = 0;
  int ag = 0;

  int ca = 0;
  int cc = 0;
  int ct = 0;
  int cg = 0;

  int ta = 0;
  int tc = 0;
  int tt = 0;
  int tg = 0;

  int ga = 0;
  int gc = 0;
  int gt = 0;
  int gg = 0;


  // take command line input filename with DNA
  if (argc > 1){


    string fName = argv[1];
    cout << "opening file" << fName << endl;
    inFS.open(fName);
  }if (!inFS.is_open()){
    cout << "could not open" << fName << endl;
    return 1;
  }
//while we are not at the end of file ... take input
while (!inFS.eof()){
  if (!inFS.fail()){
    while (getline(inFS, line)){
      lineCount++;
      for(int i = 0; i < line.size(); ++i){
        //line at position i (where we are iterating) convert to lowecase
        // is equal to a, c, t, g ... add to prespective count
        if(tolower(line.at(i)) == 'a'){
          aCount++;
        }else if(tolower(line.at(i)) == 'c'){
          cCount++;
        }else if(tolower(line.at(i)) == 't'){
          tCount++;
        }else if(tolower(line.at(i)) == 'g'){
          gCount++;
        }
      }
    }
  }
}
//finding the pair counts same way we did above...
// convert everything to lowercase and check conditions and add to corresponding variables
for (int j = 0; j < line.size(); j+=2){
      if(tolower(line.at(j)) == 'a' && tolower(line.at(j + 1)) == 'a'){
        aa++;
        cout << "found" << endl;

      }else if(tolower(line.at(j)) == 'a' && tolower(line.at(j + 1)) == 't'){
        at++;

      }else if(tolower(line.at(j)) == 'a' && tolower(line.at(j + 1)) == 'g'){
        ag++;

      }else if(tolower(line.at(j)) == 'a' && tolower(line.at(j + 1)) == 'c'){
        ac++;

      }else if(tolower(line.at(j)) == 'c' && tolower(line.at(j + 1)) == 'a'){
        ca++;

      }else if(tolower(line.at(j)) == 'c' && tolower(line.at(j + 1)) == 'c'){
        cc++;

      }else if(tolower(line.at(j)) == 'c' && tolower(line.at(j + 1)) == 'g'){
        cg++;

      }else if(tolower(line.at(j)) == 'c' && tolower(line.at(j + 1)) == 't'){
        ct++;

      }else if(tolower(line.at(j)) == 'g' && tolower(line.at(j + 1)) == 'a'){
        ga++;

      }else if(tolower(line.at(j)) == 'g' && tolower(line.at(j + 1)) == 'c'){
        gc++;

      }else if(tolower(line.at(j)) == 'g' && tolower(line.at(j + 1)) == 'g'){
        gg++;

      }else if(tolower(line.at(j)) == 'g' && tolower(line.at(j + 1)) == 't'){
        gt++;

      }else if(tolower(line.at(j)) == 't' && tolower(line.at(j + 1)) == 'a'){
        ta++;

      }else if(tolower(line.at(j)) == 't' && tolower(line.at(j + 1)) == 'g'){
        tg++;

      }else if(tolower(line.at(j)) == 't' && tolower(line.at(j + 1)) == 'c'){
        tc++;

      }else if(tolower(line.at(j)) == 't' && tolower(line.at(j + 1)) == 't'){
        tt++;
      }
    }
    totalcount = aCount + cCount + tCount + gCount;
  }
