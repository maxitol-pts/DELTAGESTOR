//Deltag code property
#include <filesystem>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>
  namespace fs = std::filesystem;
std::string rute = "none";
//rute is a global variable can be changed by anything i know this is bad practive is just to void's before main can use it
void calculator(){
  std::string type = "+";
  double answer = 0;
  double n1 = 0.0000;
  double n2 = 0.0000;
  std::cin >> n1;
  std::cin >> n2;
  std::cin >> type;
  if (type == "+"){
  answer = n1 + n2;}
  else if (type == "×" || type == "*" || type == "x" ){
      answer = n1 * n2;}
      else if(type== "-"){
          answer = n1 - n2;}
          else if(type == "÷" || type == "/" ){
              answer = n1 / n2;}
  std::cout << answer << std::endl;
}
//here is calculator an extra fuction!
void log(std::string text){
    std::cout << text << std::endl;
    }
    
    void help(){
        log("--------  DELTAG help menu?!-------------");
       log("write delete to delete a folder");
       log("input deletef to delete everything on a folder");
       log("write create to create a folder");
       log("write calculate to calculate operations example: 1 > 1 > ÷");
       log("write cls for clean all the console");
       log("---------------------------‐--------------------------");
        }
    //help menu! write help to get this menu in console
    void delete_(){
    	       
    	       log("what will you delete?");
	       std::cin >> rute;
	       try{
	           if(fs::remove(rute)){
	               log("file deleted succesfull ex 913");
	               }
	           else{ 
	           throw std::runtime_error("err");
	           }
	           }catch (const std::exception& e) {
    log("Console error: " + std::string(e.what()));
}
    }
    void deleteevery_(){
    	       
    	       log("what will you delete?");
	       std::cin >> rute;
	       try{
	           if(fs::remove_all(rute)){
	               log("file deleted succesfull ex 913");
	               }
	           else{ 
	           throw std::runtime_error("err");
	           }
	           }catch (const std::exception& e) {
    log("Console error: " + std::string(e.what()));
}
    }

int main(int argc, char *argv[]) //main inits!
{
	
	bool t = true;
	std::string acc = "";
	log("delta gestor, in cpp (write help to get commands indications)");
	while(t){
	    std::cin >> acc;
	    //this is actually delete fuction in where if statements live
	    if(acc == "delete"){
	       t = false;
delete_();
	           t = true;
	           }
	           if(acc == "create"){
	              log("name your repository");
	              std::cin >> rute;
	              try{
	               if(fs::create_directory(rute)){
	                   log("created succesfully");
	                   }
	                   else{
	                       throw std::runtime_error("err");
	                       }
	                       
	               }catch (const std::exception& e) {
    log("Console error: " + std::string(e.what()));
}
	           }
	           if(acc == "calculate"){
	               t = false;
	               calculator();
	               t = true;
	               }
	               if(acc == "clear"){
	                   system("clear");
	                   }
	                   if(acc == "cls"){
	                       system("cls");
	                       log("Deltagestor (console cleared)");
	                       //this line actually deletes console trash is you are on Windows write cls and Linux clear
	                   }
	                   if(acc == "deletef"){
	                       deleteevery_();
	                   }
	                   //if you gonna use deletf make sure of write the rutes good
	                   if(acc == "help"){
	                       help();
	                   }
	               }
}