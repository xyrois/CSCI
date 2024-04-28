//
/*

This progam reads a csv file containing arithmetic expressions and their corresponding
answers, generates questions, and answers them. Then, calculates and reports the correct rate, 
based on the correct percentage, and prints the corresponding letter grade.

*/
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>
using namespace std;

int main()
{  
    string fileName="problems.csv";
    ifstream fin(fileName);
    if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); 
    }
    string txt,answ;
    double questions=0;
    double numques=0;
    double ans;
    vector <string> txtvector;
    vector <string> ansvector;
    double correct=0;
    double percentage;
    
    while (getline(fin, txt, ',') && getline(fin, answ)){
        txtvector.push_back(txt);
        ansvector.push_back(answ);
        questions+=1;
    }
    for (int i=0;i<questions;i++){
        int r=rand()%txtvector.size();
        numques++;
        cout<<"\n"<<"("<<numques<<") "<<"what is "<<txtvector[r]<<"? ";
        cin>>ans;
        if (ans==stof(ansvector[r])){
                cout<<"true"<<endl;
                correct++;
        }else{
            cout<<"false"<<endl;
        }
        swap(txtvector[r], txtvector.back());
        swap(ansvector[r], ansvector.back());
        txtvector.pop_back();
        ansvector.pop_back();
                
            percentage=(correct/questions)*100.0;
            if (percentage>=60){
                cout<<"\n"<<"At least 60"<<"%"<<" is correct. Stop."<<endl;
                cout<<"\n"<<"percentage correct: "<<percentage<<"%"<<endl ;
                return 0;
            }
    }
    cout<<"\n"<<"percentage correct: "<<percentage<<"%";
    return 0;
}
