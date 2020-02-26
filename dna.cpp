
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
#include <cmath>
using namespace std;

int main(int argc, char** argv){

  if (argc > 1) {
  } else {
    cout << "USAGE: ./a.out [input_string]" << endl;
    return 0;
  }

  //variables
  float lineCount = 0.0;
  string fName = argv[1];
  float aCount = 0.0;
  float cCount = 0.0;
  float tCount = 0.0;
  float gCount = 0.0;
  ifstream inFS;
  ofstream outFS;
  string line = "";
  string dna = "";
  string answer = "yes";
  int totalcount = 0;
  float totalcountdiv = 0.0;

//counts of possible pairs
  float aa = 0.0;
  float ac = 0.0;
  float at = 0.0;
  float ag = 0.0;

  float ca = 0.0;
  float cc = 0.0;
  float ct = 0.0;
  float cg = 0.0;

  float ta = 0.0;
  float tc = 0.0;
  float tt = 0.0;
  float tg = 0.0;

  float ga = 0.0;
  float gc = 0.0;
  float gt = 0.0;
  float gg = 0.0;

  float mean = 0.0;
  float variance1 = 0.0;
  float variTotal = 0.0; //tVariance;
  float tVariance = 0.0;
  float variance = 0.0;

  float aProb = 0.0;
  float cProb = 0.0;
  float tProb = 0.0;
  float gProb = 0.0;

  float lineLength = 0.0;
  float std = 0.0;
  float c = 0.0;
  float a = 0.0;
  float b = 0.0;
  float d = 0.0;
  float num = 0.0;

  float aaProb = 0.0;
  float acProb = 0.0;
  float agProb = 0.0;
  float atProb = 0.0;
  float caProb = 0.0;
  float ccProb = 0.0;
  float cgProb = 0.0;
  float ctProb = 0.0;
  float gtProb = 0.0;
  float gcProb = 0.0;
  float gaProb = 0.0;
  float ggProb = 0.0;
  float taProb = 0.0;
  float tcProb = 0.0;
  float tgProb = 0.0;
  float ttProb = 0.0;

//take command line input filename with DNA
if(argc > 1){

  cout << "Opening file: " << fName << "." << endl;
  outFS.open("thomasmoore.out");
  outFS << "thomas moore" << endl;
  outFS << "student ID: 2318524" << endl;
  outFS << "tmoore@chapman.edu" << endl;
  outFS << "assignment 1" << endl;
  outFS << endl;

  while (answer == "yes"){
    inFS.open(fName);


    if (!inFS.is_open()){
      cout << "Could not open file: " << fName << "." << endl;
      return 1;
      }

    //while we are not at the end of file ... take input
    while (!inFS.eof()){
      if (!inFS.fail()){
        while (getline(inFS, line)){
          lineCount++;

          //line at position i (where we are iterating) convert to lowecase
          // is equal to a, c, t, g ... add to prespective count
          for(int i = 0; i < line.size(); ++i){
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

          //sum of all nucleotides
          totalcount = aCount + cCount + tCount + gCount;
          totalcountdiv = totalcount;
        }
      }
    inFS.close();
    }

    //probabiltiy
    aProb = aCount / totalcount;
    cProb = tCount / totalcount;
    tProb = gCount / totalcount;
    gProb = cCount / totalcount;

    //prob of each bigram
    totalcountdiv /= 2;
    aaProb = aa / totalcountdiv;
    acProb = ac / totalcountdiv;
    agProb = ag / totalcountdiv;
    atProb = at / totalcountdiv;
    caProb = ca / totalcountdiv;
    ccProb = cc / totalcountdiv;
    cgProb = cg / totalcountdiv;
    ctProb = ct / totalcountdiv;
    gtProb = gt / totalcountdiv;
    gcProb = gc / totalcountdiv;
    gaProb = ga / totalcountdiv;
    ggProb = gg / totalcountdiv;
    taProb = ta / totalcountdiv;
    tcProb = tc / totalcountdiv;
    tgProb = tg / totalcountdiv;
    ttProb = tt / totalcountdiv;

    mean = totalcount / lineCount;

    //open file again
    inFS.open(fName);
    while (!inFS.eof()){ //while not at end
      if (!inFS.fail()){ //if it doesnt fail to open

        while (getline(inFS, line)){
            lineLength = line.size();

            variance1 = pow(lineLength - mean, 2); //variance
            tVariance += variance1;
        }

        variance = (tVariance / lineCount) - 1;
        std = sqrt(variance);
      }

    cout << "Closing file: " << fName << endl;
    inFS.close();
    }


    //Printing statistics to .out file
    outFS << "Statistics for file: " << fName << endl;
    outFS << endl;
    outFS << "Sum of the length of the DNA strings: " << totalcount << endl;
    outFS << "Mean of the length of the DNA strings is: " << mean << endl;
    outFS << "Varience of the length of the DNA strings is: " << variance << endl;
    outFS << "Standard Deviation of the length of the DNA strings is: " << std << endl;
    outFS << "relative probability of each nucleotide: " << endl;
    outFS << "a: " << aProb << endl;
    outFS << "c: " << aProb << endl;
    outFS << "t: " << aProb << endl;
    outFS << "g: " << aProb << endl;
    outFS << endl;

    outFS << "relative probability of each nucleotide bigram: " << endl;
    outFS << "aa: " << aaProb << endl;
    outFS << "ac: " << acProb << endl;
    outFS << "at: " << atProb << endl;
    outFS << "ag: " << agProb << endl;
    outFS << "ca: " << caProb << endl;
    outFS << "cc: " << ccProb << endl;
    outFS << "ct: " << ctProb << endl;
    outFS << "cg: " << cgProb << endl;
    outFS << "ta: " << taProb << endl;
    outFS << "tc: " << tcProb << endl;
    outFS << "tt: " << ttProb << endl;
    outFS << "tg: " << tgProb << endl;
    outFS << "ga: " << gaProb << endl;
    outFS << "gc: " << gcProb << endl;
    outFS << "gt: " << gtProb << endl;
    outFS << "gg: " << ggProb << endl;

    for(int i = 0; i < 1000; ++i){ //1000 strands

      //random
      a = (rand())/(double)(RAND_MAX);
      b = (rand())/(double)(RAND_MAX);
      c = (sqrt(-2 * log(a)) * (cos(2*M_PI*b)));
      d = std * c + mean;
      d = round(d); // change to whole number

      //Taking into account the prior nucleotide probabilities a new random dna string is created
      for(int j = 0; j < d; ++j){
      num = (rand())/(double)(RAND_MAX);

      if(num <= aProb){
        dna += "a";
      }else if(num <= aProb + cProb){
        dna += "c";

      }else if(num <= aProb + cProb + gProb){
        dna += "g";

      }else if(num <= aProb + cProb + gProb + tProb){
        dna += "t";
        }
      }

      outFS << dna << endl;
      dna = ""; //override the value
    }

    outFS << endl;

    cout << "continue with another list? yes/no?" << endl;
    cin >> answer;

    if (answer == "yes"){
      cout << "enter new file name: " << endl;
      cin >> fName;
      continue;

    }else if (answer == "no"){
      cout << "exiting" << endl;
      outFS.close();
      break;

    }else{
      cout << "invalid input" << endl;

    }
  }
}

  return 0;

}
