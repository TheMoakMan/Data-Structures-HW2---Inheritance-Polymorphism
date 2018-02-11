/**
main
====

Solve the main input and output here.
Within the main loop of your program, you must use the same polymorphic pointer to an Operating_system to manage multiple objects of type Cluster and Personal_surveillance_device.
Do not reference the objects directly.
Note: only a small fraction of your cpp implementations are tested in main.
**/

#include "managing_hierarchies.h"

/*
  Function to check if the phone number is in the format +1(573)-465-1111
  --Returns true if format is correct
  --Returns false when it finds the first instance on an incorrect character or if
  --the input number is not of the correct size.
*/
bool numValidate(string phoneNum);

int main()
{
  string device;                      //Choice the user will make as to which device to manage
  string encrypt_choice;              //The user's choice to encrypt the device or not
  bool exit = false;                  //Flag to exit menu
  
  int vers_num;                      //OS Version number input by user
  long imei;                         //IMEI # of phone device
  string phone_num;                  //User Input Phone Number
  bool valid_Num;                    //Flag to check if number is input correctly
  
  while(!exit){
    cout << "\nWhat devices do you need to manage (choose one or enter 0 to exit): "
	     << "phone, cluster ";
    cin >> device;
	
    if(device == "phone")
	{
      //Read in the IMEI
	  cout << "What is your IMEI? ";
	  cin >> imei;
		
	  //Create the class object
	  Personal_surveillance_device phone(imei);
	  Operating_system *PhoneOS = &phone;
		
	  //Output Purpose
	  cout << phone.get_func_purpose() << endl;
		
	  //Get Version number
      cout << "What is the version number of your operating system? ";
	  cin >> vers_num;

      //Update and output Version Number
      PhoneOS->set_version_number(vers_num);
      cout << "Your OS version number is: " << PhoneOS->get_version_number() << endl;
		
	  //Get phone number
	  cout << "What is your phone number?";
	  cin.ignore();
		
	  valid_Num = false;
	  while(!valid_Num){
		try{
		  getline(cin, phone_num);
		   
		  phone.set_phone_number(phone_num);
		  valid_Num = true;
		}
		catch(MyException Expt){
		  cout << "That was not a valid phone number, please try again. ";
		}

	  }
		
	  //Output phone number
      cout << "Your phone number is ";
	  phone.get_phone_number();
	  cout << endl;
		
	  //Encrypt Device
	  cout << "Would you like to encrypt your phone (type yes or no)? ";
	  cin >> encrypt_choice;
		
	  Android * OREO = &phone;
	  if(encrypt_choice == "yes" || encrypt_choice == "Yes")
	    OREO->set_pretend_encryption(); 
	  else{}
		
	  OREO = NULL;

	}
	else if(device == "cluster"){
	   Cluster Cluster_Obj;
       Operating_system *ClusterOS = &Cluster_Obj;
 
      cout << Cluster_Obj.get_func_purpose() << endl;
		
	  //Read in the version number
	  cout << "What is the version number of your operating system? ";
	  cin >> vers_num;
		
	  //Update and output Version Number
	  ClusterOS->set_version_number(vers_num);
	  cout << "Your OS version number is: ";
	  ClusterOS->get_version_number();
		
	  cout << endl;
	}
	else if(device == "0")
	  exit = true;
	
	}
	
  return 0;
}
