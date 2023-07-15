/**
 * @file periodic_table.cc
 * Created on 05/17/2023
 * 
 * Implementation of PeriodicTable class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "physics/periodic_table.h"

#include <cstdio>
#include <iostream>

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

#define kNumberOfElements 118

PeriodicTable::PeriodicTable() {
  LoadAllElements();
}

PeriodicTable::~PeriodicTable() {
  for (auto atom : elements_) {
    delete atom;
  }
}

PeriodicTable& PeriodicTable::get_instance() {
  static PeriodicTable instance;
  return instance;
}

Atom& PeriodicTable::get_element(int atomic_number) {
    //std::cout << elements_.at(atomic_number_ - 1)->get_name() << " " << elements_.at(atomic_number - 1)->get_symbol() << "\n";

    return *(elements_.at(atomic_number - 1));
}

void PeriodicTable::LoadAllElements() {
#ifdef _WIN32
  FILE* file_pointer = fopen("../src/physics/JSON/PeriodicTable.json", "rb");
#else
  FILE* file_pointer = fopen("../src/physics/JSON/PeriodicTable.json", "r");
#endif
 
  char read_buffer[65536];
  rapidjson::FileReadStream input_stream(file_pointer, read_buffer, sizeof(read_buffer));
  
  rapidjson::Document document;
  document.ParseStream(input_stream);
  
  fclose(file_pointer);

  for(int index = 0; index < kNumberOfElements; index++)
  {
      Atom* atom = new Atom();

      atom->set_name(document["elements"][index]["name"].GetString());
      atom->set_symbol(document["elements"][index]["symbol"].GetString());
      atom->set_atomic_number(index + 1);
      atom->set_atomic_mass(document["elements"][index]["atomic_mass"].GetDouble());

      elements_.push_back(atom);
  }
}

void PeriodicTable::LoadElement(int atomic_number) {

}