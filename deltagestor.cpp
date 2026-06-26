//Deltag code property
#include <filesystem>
#include <iostream>
#include <cstdlib>
#include <string>
  namespace fs = std::filesystem;
std::string ruta = "none";
//rute is BASSICALLY ALL DELTAGESTOR PLEASE DONT CHANGE THE ROUTE OR DELTA GESTOR WILL DIEEEEEEEE!
void calculator(){
  std::string tipo = "+";
  double resultado = 0;
  double n1 = 0.0000;
  double n2 = 0.0000;
  std::cin >> n1;
  std::cin >> n2;
  std::cin >> tipo;
  if (tipo == "+"){
  resultado = n1 + n2;}
  else if (tipo == "×" || tipo == "*" || tipo == "x" ){
      resultado = n1 * n2;}
      else if(tipo == "-"){
          resultado = n1 - n2;}
          else if(tipo == "÷" || tipo == "/" ){
              resultado = n1 / n2;}
  std::cout << resultado << std::endl;
}
//GOTCHA FOR YOUR HOMEWORK BUDDY YOUR POOR CALCULATOR IS UP FROM VOID TO } AJAJAJJAJAJA
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
    //HEY GOTCHA YOU DONT KNOW COMMANDS FROM DELTA MAGIC AND ""BETTER"" GESTOR THERE THE ARE
    void delete_(){
    	       
    	       log("what will you delete?");
	       std::cin >> ruta;
	       try{
	           if(fs::remove(ruta)){
	               log("file deleted succesfull ex 913");
	               }
	           else{ 
	           throw "err";
	           }
	           }catch(const char* e){
	               log("console error file does not exist, error 214");
	           }
    }
    void deleteevery_(){
    	       
    	       log("what will you delete?");
	       std::cin >> ruta;
	       try{
	           if(fs::remove_all(ruta)){
	               log("file deleted succesfull ex 913");
	               }
	           else{ 
	           throw "err";
	           }
	           }catch(const char* e){
	               log("console error file does not exist, error 214");
	           }
    }

int main(int argc, char *argv[]) //CALLER IS HEEEERE
{
	
	bool t = true;
	std::string acc = "";
	log("delta gestor, in cpp (write help to get commands indications)");
	while(t){
	    std::cin >> acc;
	    //BLAH BLAH BLAH DELETE
	    if(acc == "delete"){
	       t = false;
delete_();
	           t = true;
	           }
	           if(acc == "create"){
	              log("name your repository");
	              std::cin >> ruta;
	              try{
	               if(fs::create_directory(ruta)){
	                   log("created succesfully");
	                   }
	                   else{
	                       throw "err";
	                       }
	                       
	               }catch(const char* e){log("firectory not created error 901");
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
	                       log("Deltagestor (console cleared)");//YEEE NO MORE TRASH CLEAN CONSOLE
	                   }
	                   if(acc == "deletef"){
	                       deleteevery_();
	                   }
	                   if(acc == "help"){
	                       help();
	                   }
	               }
}