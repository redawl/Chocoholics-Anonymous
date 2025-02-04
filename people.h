#ifndef PEOPLE_H
#define PEOPLE_H
#include <list>
#include "services.h"


// Address, Provider, and Member Classes


/*Consts for string lengths. 
 * size_t because that is what 
 * the string methods that
 * check length return.*/
const size_t STRT_MAX = 25;
const size_t CITY_MAX = 14;
const size_t STATE_MAX = 2;
const size_t ZIP_MAX = 5;


class Address: public Name{

    public:
        Address();
        Address(std::ifstream & in);
        void write_file(std::ofstream & out) const;
        void write_report(std::ofstream & out) const;
        void display() const;
        void read();
        void change_address();
        void update(const Address & update_to);
        //For testing, calls Name display
        void display_all() const;

    protected:
        std::string street;
        std::string city;
        std::string state;
        std::string zip;
};


class Provider: public Address{

    public:
        Provider();
        Provider(std::ifstream & in);
        Provider(const Address & to_add);
        void write_file(std::ofstream & out) const;
        bool check_week(int type) const;
        void write_report(std::ofstream & out) const;
        void write_rec_curr_DT(std::ofstream & out) const;
        int add_service(const Provider_service & to_add);
        //For testing. Displays all info in hierarchy.
        void display_all() const;
        float get_fees() const;
        unsigned short get_num_billed() const;

    private:
        unsigned short num_consults;
        unsigned short num_billed;
        float total_fees;
        std::list<Provider_service> serv_list;
};


class Member: public Address{

    public:
        Member();
        Member(char first_num);
        Member(const Address & to_add);
        Member(std::ifstream & in);
        bool check_week() const;
        void write_file(std::ofstream & out) const;
        void write_report(std::ofstream & out) const;
        int add_service(const Member_service & to_add);
        bool check_susp() const;
        //For testing. Displays all info in hierarchy.
        void display_all() const;

    private:
        bool suspended;
        std::list<Member_service> serv_list;
};
#endif
