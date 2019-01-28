#ifndef DEPOT__H__
#define DEPOT__H__

  #include "stack.h"

  #define STACK_SIZE_LIMIT 3

  typedef struct DepotImp* Depot;

  struct Product {
      int serial_no;
  };

  Depot create_depot();
  void delete_depot(Depot depot);
  int get_count(Depot depot);
  void push_depot(Depot depot, Product* product);
  Product* pop_depot(Depot depot);

#endif
