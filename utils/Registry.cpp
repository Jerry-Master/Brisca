#include "Registry.hh"


using dict_ = map<string, Registry::Factory>;


dict_ reg_;


int Registry::Register (const char* name, Factory factory) {
  reg_[name] = factory;
  return 0;
}


Strategy* Registry::new_strategy (string name, card* cards) {
  auto it = reg_.find(name);
  _my_assert(it != reg_.end(), "Strategy " + name + " not registered.");
  return (it->second)(cards);
}


void Registry::print_strategies (ostream& os) {
  for (auto it=reg_.begin(); it!=reg_.end(); ++it) 
    cout << it->first << endl;
}
