/**
.cpp
====

This is the .cpp you should define and implement the functions and classes that are declared in the .h file.
Add any non-required functions here.
**/

#include "managing_hierarchies.h"

const string USERNAME = "ebmy83";
const string STUDENT_ID = "12422230";

void get_identity(string my_id[])
{
    my_id[0] = USERNAME;
    my_id[1] = STUDENT_ID;
}

//Functions for MyExecption
const char * MyException::what() const throw()
{
  return "Custom error has occured";
}

//Functions for Machine Class
string Machine::get_function()
{
    cout << my_function;

    return my_function;
}

//Custom Functions
bool numValidate(string phoneNum)
{
  bool good_num = true;
  
  if(phoneNum.length() != 16)
   good_num = false;
  else if(phoneNum[0] != '+')
    good_num = false;
  else if(phoneNum[1] != '1')
	good_num = false;
  else if(phoneNum[2] != '(')
	good_num = false;
  else if(!(phoneNum[3] >= '0' && phoneNum[3] <= '9'))
	good_num = false;
  else if(!(phoneNum[4] >='0' && phoneNum[4] <='9'))
	good_num = false;
  else if(!(phoneNum[5] >='0' && phoneNum[5] <='9'))
	good_num = false;
  else if(phoneNum[6] != ')')
	good_num = false;
  else if(phoneNum[7] != '-')
	good_num = false;
  else if(!(phoneNum[8] >='0' && phoneNum[8] <='9'))
	good_num = false;
  else if(!(phoneNum[9] >='0' && phoneNum[9] <='9'))
	good_num = false;
  else if(!(phoneNum[10] >='0' && phoneNum[10] <='9'))
	good_num = false;
  else if(phoneNum[11] != '-')
	good_num = false;
  else if(!(phoneNum[12] >='0' && phoneNum[12] <='9'))
	good_num = false;
  else if(!(phoneNum[13] >='0' && phoneNum[13] <='9'))
	good_num = false;
  else if(!(phoneNum[14] >='0' && phoneNum[14] <='9'))
	good_num = false;
  else if(!(phoneNum[15] >='0' && phoneNum[15] <='9'))
	good_num = false;
	
  return good_num;	
}

//Functions for X86
X86::X86()
{
  my_function = "Backward compatibile";
  num_cores = new bool[2];
}

X86::X86(string init_function, int init_cores)
{
  /*
   if((init_cores % 2) != 0)
      throw my_ex;
  */

  my_function = init_function;
  num_cores = new bool[init_cores];
        
}

X86::~X86()
{
  delete[] num_cores;
}

void X86::set_core_pos(int position, bool value)
{
  num_cores[position] = value;
}

bool X86::get_core_pos(int index)
{
  return num_cores[index];
}

//Functions for ARM
ARM::ARM()
{
  my_function = "Reduced Instruction Set";
  num_bits = 64;
}

ARM::ARM(string init_function, short init_bits)
{
  /*
  if(!(init_bits == 32 || num_bits == 64))
    throw my_ex;
  */

  my_function = init_function;
  num_bits = init_bits;
}

void ARM::set_num_bits(short set_bits)
{
  /*
  if(!(init_bits == 32 || num_bits == 64))
    throw my_ex;
  */

  num_bits = set_bits;
}

short ARM::get_num_bits()
{
  return num_bits;
}


//Functions for Operating_system
string Operating_system::get_purpose()
{
  cout << purpose; 
  return purpose;
}

//Functions for Linux
Linux::Linux()
{
  purpose = "Anything you want";
}

Linux::Linux(string init_purpose)
{
  purpose = init_purpose;
}

//Functions for Android
Android::Android()
{
  purpose = "Uploading your converstations to google";
  pretend_encryption = 0;
}

void Android::set_pretend_encryption()
{
  //If pretend_encryption is 1
  if(pretend_encryption){
    pretend_encryption = 0; 
    cout << "Encryption is now off";
  }
  //If pretend_encryption is 0
  else{
     pretend_encryption = 1;
     cout << "Your device is now securely encrypted" << endl;
  }

}

//Functions for Cluster
string Cluster::get_func_purpose()
{
  string phrase = "Your phone architecture is ";
  
  phrase = phrase + '"' + my_function + '"' + ", and its purpose is "
           + '"' + purpose + '"' + ", and lots of it!";
  
  cout << phrase;
  
  return phrase;
}


void Cluster::set_version_number(int set_ver_num)
{
  version_number = set_ver_num;
}

int Cluster::get_version_number()
{
  cout << version_number;
  return version_number;
}

//Functions for Personal_surveillance_device
Personal_surveillance_device::Personal_surveillance_device()
{
  my_IMEI = new long;
  *my_IMEI = 0000;
}

Personal_surveillance_device::Personal_surveillance_device(long input_my_IMEI)
{
  my_IMEI = new long;
  *my_IMEI = input_my_IMEI;
}

Personal_surveillance_device::~Personal_surveillance_device()
{
  delete my_IMEI;
}

void Personal_surveillance_device::set_phone_number(string init_phone)
{ 
  MyException Expt;  
  
  if(!numValidate(init_phone)){
	throw Expt; 
  }
  
  my_phone_number = init_phone;
}

string Personal_surveillance_device::get_phone_number()
{
  cout << my_phone_number;
  return my_phone_number;
}

void Personal_surveillance_device::set_version_number(int set_ver_num)
{
  version_number = set_ver_num;
}

int Personal_surveillance_device::get_version_number()
{
  return version_number;
}

string Personal_surveillance_device::get_func_purpose()
{
  string phrase = "Your phone architecture is ";
  
  phrase = phrase + '"' + my_function + '"' + ", and its purpose is "
           + '"' + purpose + '"' + ", and I follows you around!";
  
  return phrase;
}

Personal_surveillance_device::Personal_surveillance_device(const Personal_surveillance_device &source)
{
  set_phone_number(source.my_phone_number);
  
  my_IMEI = new long;
  long * temp;
  temp = source.my_IMEI;
  *my_IMEI = *temp;

}

Personal_surveillance_device & Personal_surveillance_device::operator=(const Personal_surveillance_device &rhs)
{
  set_phone_number(rhs.my_phone_number);
	
  my_IMEI = new long; 
  long * temp;
  temp = rhs.my_IMEI;
  *my_IMEI = *temp;
 
 
}

