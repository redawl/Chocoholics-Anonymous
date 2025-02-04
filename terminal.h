#ifndef TERMINAL_H
#define TERMINAL_H

#include <map>
#include <unordered_map>
#include "people.h"


// Data_center and Terminal Classes


class Data_center{

    public:
        Data_center();
        ~Data_center();
        /*Reads all maps from the txt file. It returns 0 if
        * the reading or map creation failed, otherwise
        * it returns 1.*/
        int read_files();
        void write_file();
        int check_valid(const std::string & input); 
        void disp_map(int map_type);
        int person_report(const std::string & num);
        int write_EFT(float fee) const;
        int sum_report() const;
        int add_person(const Address & to_add, int type);
        int remove(const std::string & num); 
        int update(const std::string & num, const Address & to_update);
        void add_service();
        void set_serv_test();
        std::string disp_name(const std::string & num);

    private:
        std::unordered_map<std::string, Provider> provider_list;
        std::unordered_map<std::string, Member> member_list;
        std::unordered_map<std::string, Name> manager_list;
        std::map<std::string, Service> prov_dir;
        Provider * curr_provider;
        Member * curr_member;
};

class Terminal{

    public:
        Terminal(Data_center & link);
        void provider_menu(const std::string & num);
        void manager_menu(const std::string & num);
        void start_menu();
        void interactive_mode();
        int validate(std::string & ID_num) const;
        int mem_validate(const std::string & ID_num) const;
    
    private:
        Data_center * data_link;
};
#endif
