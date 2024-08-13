#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <string>

using std::string;

void input_reset(){

    char input;
    std::cout << "Enter any key to continue: ";
    std::cin >> input;
    input = '\0';
}

class Books{

    private:
        
        string title, author, description, status;
        int publication_year;
    
    public:

        Books(string name, string person, string desc, int year, string stats): title(name), author(person), description(desc), publication_year(year), status(stats){}

        void set_title(string enter_title){

            title = enter_title;
        }

        string get_title(){

            return title;
        }

        void set_author(string enter_author){

            author = enter_author;
        }

        string get_author(){

            return author;
        }

        void set_desc(string enter_desc){

            description = enter_desc;
        }

        string get_desc(){

            return description;
        }

         void set_status(string enter_status){

            status = enter_status;
        }

        string get_status(){

            return status;
        }

        void set_year(int enter_year){

            publication_year = enter_year;
        }

        int get_year(){

            return publication_year;
        }
};

Books* Work[10] = {

    new Books("Book of Life", "John Clark Honrado", "To the one I shall give thee, thou shall receive.", 2004, "Available"),
    new Books("Shine Bright to the Moon", "Vienn Portes", "I love moon, as for all many... It is what I desire.", 2016, "Available"),
    new Books("Stirring into the Nightshine", "Zildjan Ponce", "For I have no regrets of loving you my dear", 2024, "Available"),
    new Books("", "", "", 0, ""),
    new Books("", "", "", 0, ""),
    new Books("", "", "", 0, ""),
    new Books("", "", "", 0, ""),
    new Books("", "", "", 0, ""),
    new Books("", "", "", 0, ""),
    new Books("", "", "", 0, ""),

};

class Library{

    public:

        void View_Books(){

            std::cout << "===================================================================" << "\n"
                    <<   "||         These are the books available in the library          ||" << "\n"
                    <<   "===================================================================" << std::endl;

            for (int i = 0; i < 10; i++){
                
                std::cout << "===================================================================" << "\n";

                if (Work[i]->get_status() == "Available" || Work[i]->get_status() == "Borrowed"){
                std::cout << "Shelf " << i+1 << "\n"
                        <<   "Name: " << Work[i]->get_title() << "\n"
                        <<   "Author: " << Work[i]->get_author() << "\n"
                        <<   "About: " << Work[i]->get_desc() << "\n"
                        <<   "Publication year: " << Work[i]->get_year() << "\n"
                        <<   "Status: " << Work[i]->get_status() << "\n\n";
                }

                else{

                    std::cout << "Shelf " << i+1 << " is vacant" << "\n\n";
                }
            }

            std::cout << "===================================================================" << std::endl;
            input_reset();
            system("cls");
        }

        void Add_Book(){

            string title, author, description;
            int publication_year, vacant = -1;

            for (int i = 0; i < 10; i++){

                if (Work[i]->get_status() != "Available" && Work[i]->get_status() != "Borrowed"){
                    
                    vacant = i;
                    break;
                }
            }

            if (vacant == -1){

                std::cout << "No vacant available!" << std::endl;
                return;
            }


            std::cout << "===================================================" << "\n"
                    <<   "|| Enter the following information for your book ||" << "\n"
                    <<   "===================================================" << std::endl;
            
            std::cout << "Name: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            Work[vacant]->set_title(title);

            std::cout << "Author: ";
            std::getline(std::cin, author);
            Work[vacant]->set_author(author);

            std::cout << "About: ";
            std::getline(std::cin, description);
            Work[vacant]->set_desc(description);

            std::cout << "Publication year: ";
            std::cin >> publication_year;
            Work[vacant]->set_year(publication_year);

            Work[vacant]->set_status("Available");

            std::cout << "==================================================" << "\n"
                    << "Successfully added!" << std::endl;
                    input_reset();
                    system("cls");
        }

        void Remove_Book(){

            int removal;

            std::cout << "===================================================" << "\n"
                    <<   "||        Enter the shelf number to remove       ||" << "\n"
                    <<   "===================================================" << std::endl;

            std::cout << "Shelf number: ";
            std::cin >> removal;
            
            if (Work[removal-1]->get_status() == ""){
            	
            	system("cls");
                std::cout << "No book was found in that shelf!" << std::endl;
                return;
            	
			}

            Work[removal-1]->set_title("");
            Work[removal-1]->set_author("");
            Work[removal-1]->set_desc("");
            Work[removal-1]->set_year(0);
            Work[removal-1]->set_status("");

            std::cout << "==================================================" << "\n"
                    << "Successfully removed!" << std::endl;
                    input_reset();
                    system("cls");
        }

        void Borrow_Book(){

            int borrow;

            std::cout << "===================================================" << "\n"
                    <<   "||        Enter the shelf number to borrow       ||" << "\n"
                    <<   "===================================================" << std::endl;

            std::cout << "Shelf number: ";
            std::cin >> borrow;

            if (Work[borrow-1]->get_status() == "Borrowed"){
            	
				Work[borrow-1]->set_status("Available");

            	std::cout << "==================================================" << "\n"
                    	<< "The shelf has successfully retrieved the book!" << std::endl;
                    input_reset();
                    system("cls");
                	return;
            }

            if (Work[borrow-1]->get_status() == ""){

                system("cls");
                std::cout << "No book was found in that shelf!" << std::endl;
                return;
            }


            Work[borrow-1]->set_status("Borrowed");

            std::cout << "==================================================" << "\n"
                    << "Successfully borrowed!" << std::endl;
                    input_reset();
                    system("cls");
        }

};

Library* Shelf;


void Main_menu(){
    
    int option_pick;

    do{
        std::cout << "============================================" << "\n"
                <<   "||         Welcome to the Library!        ||" << "\n"
                <<   "============================================" << "\n"
                <<   "||  Please choose an option (between 1-5) ||" << "\n"
                <<   "============================================" << "\n"
                <<   "|| [1] View the list of books             ||" << "\n"
                <<   "|| [2] Add a new book                     ||" << "\n"
                <<   "|| [3] Borrow or unborrow a book          ||" << "\n"
                <<   "|| [4] Remove a book                      ||" << "\n"
                <<   "|| [5] Quit Program                       ||" << "\n"
                <<   "============================================" << "\n";


        std::cout <<   "Selected option: ";
        std::cin >> option_pick;

        switch(option_pick){

            case 1:

                system("cls");
                Shelf->View_Books();
                break;

            case 2:

                system("cls");
                Shelf->Add_Book();
                break;

            case 3:

                system("cls");
                Shelf->Borrow_Book();
                break;
            
            case 4:

                system("cls");
                Shelf->Remove_Book();
                break;

            case 5:

                system("cls");

                for (int i = 0; i < 10; ++i) {

                    delete Work[i];
                }
                delete Shelf;
                exit(0);
                break;


            default:

				system("cls");
                std::cout << "Invalid input! Please try again!" << std::endl;
                break;
        }
    }while(option_pick != 5);
}


int main(){


    Main_menu();
    

    return 0;
}
