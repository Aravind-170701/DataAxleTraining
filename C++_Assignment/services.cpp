#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

//User Class
class User {

  public:
    string matchCode;
    string lastName;
    string firstName;
    string middleName;
    string AKA;
    string houseNo;
    string streetAddress;
    string city;
    string state;
    string zip;

    User(){}

    User(string matchCode, string lastName, string firstName, string middleName, string AKA, string houseNo, string streetAddress, string city, string state, string zip)
    {
      this->lastName = lastName;
      this->firstName = firstName;
      this->middleName = middleName;
      this->AKA = AKA;
      this->houseNo = houseNo;
      this->streetAddress = streetAddress;
      this->city = city;
      this->state = state;
      this->zip = zip;
    }
};
//

//Global Variables
vector<User> users;
bool setNickname = false;
bool setMatchcode = false;
bool setUppercase = false;
bool setTitlecase = false;
string file_name;
string output_format;
//

//Functions Declaration
string removeSpaces();
void printEnvelopeFormat();
void printFixedFormat();
void printCsvFormat();
void createUsersFromFile();
void updateFirstnameWithNickname();
void addMatchcode();
void setDataUppercase();
void setFirstUpperCase();
string upperCase(string str);
string firstUpperCase(string str);
void printOutput();
//

void processArgs(int argc, char** argv)
{
    const char* const short_opts = "i:o:nmut";

    const option long_opts[] = {
            {"input_file", required_argument, nullptr, 'i'},
            {"output_format", required_argument, nullptr, 'o'},
            {"nick_name", no_argument, nullptr, 'n'},
            {"matchcode", no_argument, nullptr, 'm'},
            {"uppercase", no_argument, nullptr, 'u'},
            {"titlecase", no_argument, nullptr, 't'},
            {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt)
        {
          case 'i':
              file_name = optarg;
              break;

          case 'o':
              output_format = optarg;
              break;

          case 'n':
              setNickname = true;
              break;

          case 'm':
              setMatchcode = true;
              break;

          case 'u': 
              setUppercase = true;
              break;

          case 't': 
              setTitlecase = true;
              break;

          default:
              break;
        }
    }
}

int main(int argc, char **argv)
{

  processArgs(argc,argv);

  createUsersFromFile();

  if(setNickname)
  {
    updateFirstnameWithNickname();
  }

  if(setMatchcode)
  {
    addMatchcode();
  }

  if(setUppercase)
  {
    setDataUppercase();
  }

  if(setTitlecase)
  {
    setFirstUpperCase();
  }

  printOutput();
  return 0;
}

//Creating Users from File
void createUsersFromFile()
{
  ifstream fin;

  string row;
  string input;

  fin.open(file_name);

  if(!fin) 
  { 
    cerr << "Error: file could not be opened" << endl;
    exit(1);
  }

  getline(fin,row);
  input = row;

  while (!fin.eof() ) 
  { 
    getline(fin,row);
    input.append(row);
  }
  
  int size[9] = {15,15,15,10,5,20,15,15,6};
  string temp[9];

  int i = 0;
  int j = 0;

  while(i < input.size())
  {
    while(j < 9)
    {
      temp[j] = input.substr(i,size[j]);
      i += size[j];
      j++;
    }
    j = 0;
    User u("",temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8]);
    users.push_back(u);
  }

  fin.close();
}

void printOutput()
{
  if(output_format == "envelope")
  {
    printEnvelopeFormat();
  }

  else if(output_format == "fixed_length")
  {
    printFixedFormat();
  }

  else
  {
    printCsvFormat();
  }
}

void updateFirstnameWithNickname()
{
  for(int i=0;i<users.size();i++)
  {
    users[i].firstName = users[i].AKA;
  }
}

void addMatchcode()
{
  string code = "";
  string street;
  string firstname;
  string temp;

  for(int i=0;i<users.size();i++)
  {
    street = (users[i].streetAddress)[0];
    firstname = (users[i].firstName)[0];
    temp = street + firstname;
    code = temp + users[i].zip;
    
    users[i].matchCode = code;
  }
}

void setDataUppercase()
{
  for(int i=0;i<users.size();i++)
  {
    users[i].lastName = upperCase(users[i].lastName);
    users[i].firstName = upperCase(users[i].firstName);
    users[i].middleName = upperCase(users[i].middleName);
    users[i].AKA = upperCase(users[i].AKA);
    users[i].streetAddress = upperCase(users[i].streetAddress);
    users[i].city = upperCase(users[i].city);
    users[i].state = upperCase(users[i].state);
  }
}

void setFirstUpperCase()
{
  for(int i=0;i<users.size();i++)
  {
    users[i].lastName = firstUpperCase(users[i].lastName);
    users[i].firstName = firstUpperCase(users[i].firstName);
    users[i].middleName = firstUpperCase(users[i].middleName);
    users[i].AKA = firstUpperCase(users[i].AKA);
    users[i].streetAddress = firstUpperCase(users[i].streetAddress);
    users[i].city = firstUpperCase(users[i].city);
    users[i].state = firstUpperCase(users[i].state);
  }
}

string upperCase(string str)
{
  for(int i=0;i<str.size();i++)
  {
    str[i] = toupper(str[i]);
  }

  return str;
}

string firstUpperCase(string str)
{
  str[0] = toupper(str[0]);
  return str;
}

string removeSpaces(string str){

    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    return str;

}

void printEnvelopeFormat()
{
  for(int i=0;i<users.size();i++)
  {
    cout<<users[i].matchCode << " "<< removeSpaces(users[i].firstName) << " " << removeSpaces(users[i].lastName) << ","<<endl;
    cout<<removeSpaces(users[i].houseNo) << " " << removeSpaces(users[i].streetAddress) << ","<<endl;;
    cout<<removeSpaces(users[i].city) << ", " << removeSpaces(users[i].state) <<" "<< removeSpaces(users[i].zip) << "\n\n\n";
    
  }
}


void printFixedFormat()
{
  for(int i=0;i<users.size();i++)
  {
    string name = removeSpaces(users[i].firstName) + " " + removeSpaces(users[i].lastName);
    int width = 30 - name.size();

    cout<<users[i].matchCode << " "<< name <<setw(width)<<" ";

    string address1 = removeSpaces(users[i].houseNo) + " " + removeSpaces(users[i].streetAddress);
    width = 25 - address1.size();

    cout<<address1<<setw(width)<<" ";

    string address2 = removeSpaces(users[i].city) + ", " + removeSpaces(users[i].state) + " " + removeSpaces(users[i].zip);
    width = 36 - address2.size();

    cout<<address2<<setw(width)<<"\n\n\n";
    
  }
}


void printCsvFormat()
{
  for(int i=0;i<users.size();i++)
  {
    string name = removeSpaces(users[i].firstName) + " " + removeSpaces(users[i].lastName);
    string address1 = removeSpaces(users[i].houseNo) + " " + removeSpaces(users[i].streetAddress);
    string address2 = removeSpaces(users[i].city) + ", " + removeSpaces(users[i].state) + " " + removeSpaces(users[i].zip);

    cout<<users[i].matchCode << " "<< name<<","<<address1<<","<<address2<<"\n\n\n";
  }

}


