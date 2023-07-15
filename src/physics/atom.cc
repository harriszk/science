// @file atom.cc
// Created on 05/17/2023
// 
// Implementation of the Atom class.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "physics/atom.h"

Atom::Atom() {

}

Atom::Atom(std::string name, std::string symbol, int atomic_number, double atomic_mass)
    : name_(std::move(name)),
      symbol_(std::move(symbol)),
      atomic_number_(atomic_number),
      atomic_mass_(atomic_mass) {

}

Atom::~Atom() {

}

std::string Atom::get_name() {
  return name_;
}

std::string Atom::get_symbol() {
  return symbol_;
}

int Atom::get_atomic_number() {
  return atomic_number_;
}

double Atom::get_atomic_mass() {
  return atomic_mass_;
}

void Atom::set_name(std::string name) {
  name_ = name;
}

void Atom::set_symbol(std::string symbol) {
  symbol_ = symbol;
}

void Atom::set_atomic_number(int number) {
  atomic_number_ = number;
}

void Atom::set_atomic_mass(double mass) {
  atomic_mass_ = mass;
}