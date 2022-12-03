#include <iostream>
#include<fstream>
#include<stdexcept>
using namespace std;


class EntryError: public exception{
  public:
    void display_Name_error(string name,char symbol){
      cout<<"Name Entered: "<<name<<endl;
      cout<<"Illegal character/symbol used --> "<<symbol<<endl;
    }
    void display_Dob_error(string dob,char symbol){
      cout<<"Dob Entered: "<<dob<<endl;
      cout<<"Illegal character/symbol used --> "<<symbol<<endl;
    }
    void display_Phone_error(string phone,char symbol){
      cout<<"Phone no. Entered: "<<phone<<endl;
      cout<<"Illegal character/symbol used --> "<<symbol<<endl;
    }
    void display_email_error(string email){
      cout<<"Email Entered: "<<email<<endl;
      cout<<"Illegal character/symbol used"<<endl;
    }
    const char* what(){
      return "Error While Entering Data: ";
    }
    
};
class check{
  private:
  
  public:
    char name_check(string name){
      char illegalSymbol[38] = {'1','2','3','4','5','6','7','8','9','0','!','@','#','$','%','^','&','*','(',')','-','_','+','=','{','}',':',';','"','\'','<','>',',','.','?','/','\\','|'};
      char length = name.length();
      for(int i=0;i<length;i++){
        for(int j=0;j<38;j++){
          if (name[i]==illegalSymbol[j]){
            return illegalSymbol[j];
          }
        }
      }
      return '0';
    }
    char dob_check(string dob){
      char illegalSymbol[79] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','!','@','#','$','%','^','&','*','(',')','-','_','+','=','{','}',':',';','"','\'','<','>',',','.','?','\\','|'};
      int length = dob.length();
      for(int i=0;i<length;i++){
        for(int j=0;j<79;j++){
          if (dob[i]==illegalSymbol[j]){
            return illegalSymbol[i];
          }
        }
      }
      return '0';
    }
    
    char phone_check(string phone){
      char illegalSymbol[80] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','!','@','#','$','%','^','&','*','(',')','-','_','+','=','{','}',':',';','"','\'','<','>',',','.','?','/','\\','|'};
      int length = phone.length();
      for(int i=0;i<length;i++){
        for(int j=0;j<80;j++){
          if (phone[i]==illegalSymbol[j]){
            return illegalSymbol[i];
          }
        }
      }
      return '0';
    }

};



int main() {
  ofstream data("data.txt",std::ios_base::app);

  try{
    if(data.is_open()==false){
      throw "File Couldn't be opened\n";
    } 
  }catch(const char* a){
    cout<<"Error Occured: "<<a<<endl;
    return 0;
  }
    
  cout<<"Enter First Name,DOB(dd/mm/yyyy),phone no,email"<<endl;
  cout<<"Enter '-1' to exit"<<endl;

  string name,email,phone,dob; 
  while(name!="-1"||dob!="-1"||phone!="-1"||email!="-1"){
    cout<<"\nFirst Name:";
    cin>>name;
    if (name=="-1"){
      data.close();
      break;
    }

    if(name!="-1"){
      check c;
      if((c.name_check(name))!='0'){
        EntryError e;
        e.display_Name_error(name,c.name_check(name));
        break;
      }  
    }
    
    cout<<"\nDOB (dd/mm/yyyy):";
    cin>>dob;
    
    if (dob=="-1"){
      data.close();
      break;
    }

    if(name!="-1"){
      check c;
      if((c.dob_check(dob))!='0'){
        EntryError e;
        e.display_Name_error(dob,c.dob_check(dob));
        break;
      }  
    }
    
    cout<<"\nPhone:";
    cin>>phone;
    
    if (phone=="-1"){
      data.close();
      break;
    }

    if(phone!="-1"){
      check c;
      if((c.phone_check(phone))!='0'){
        EntryError e;
        e.display_Phone_error(phone,c.phone_check(phone));
        break;
      }  
    }

    cout<<"\nemail:";
    cin>>email;

    if(name!="-1"||dob!="-1"||phone!="-1"||email!="-1"){
      data << name <<","<< dob <<","<< phone <<","<< email <<"\n";
    }
  
  }
  
  data.close();
  return 0;
  
}
