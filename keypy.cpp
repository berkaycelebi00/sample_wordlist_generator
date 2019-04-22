#include <string>
#include <vector>
#include <iostream>
using namespace std;

//To generate suitable wordlist you must give at least '2' length
//This program only works with ASCII chars and does not suppert any other unicode letters

const int WORDS_LEN = 9; /* Default value of number of words. If you want to change your wordlist without any errors,
                            please update this value with the number of values you entered*/

char wordlist[WORDS_LEN]={'1','2','3','4','5','6','7','8','9'}; // You can modify wordlist.




vector<string> make_permutations(int length,char wordlist[],int len) {
  if (length == 0) {
    return vector<string>{};
  }
  vector<string> results;
  vector<string> children = make_permutations(length - 1,wordlist,9);
  for (int i=0;i<len;i++) { 
    results.emplace_back(1, wordlist[i]);
    for(auto child : children) {
      results.push_back(std::string(1, wordlist[i]) + child);
      cout<<wordlist[i]+child<<endl;
    }
  }
  return results;
}

void startFunction(int argc,char **argv)
{

  if (argc<3)
  {
    cout<<"Please write maximum length of wordlist. (./filename.out -l 12) \n";
  }
  else
  {
    string temp_s=argv[1];
    if(temp_s=="-l")
    {
      char y_n;
      temp_s=argv[2];
      int len=stoi(temp_s);
      cout<<"Your maximum length is: "<<len<<"\nDou you want to start program? (y/n): ";cin>>y_n;
      if(y_n=='y')make_permutations(len,wordlist,WORDS_LEN);
      else cout<<"GOOD BYE!";
    }
  }
}




int main(int argc,char **argv)
{

  
  startFunction(argc,argv);


}